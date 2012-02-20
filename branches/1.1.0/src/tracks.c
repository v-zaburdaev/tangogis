#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <gtk/gtk.h>
#include <glib.h>
#include <glib/gstdio.h>

#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>

#include "globals.h"
#include "tracks.h"
#include "interface.h"
#include "support.h"
#include "converter.h"
#include "map_management.h"
#include "tile_management.h"
GtkWidget *
make_file_label(const char *file, char *full_file);

trackpoint_t *tp;

double colr(int n)
{
return (double)((double)1/255)*n;
}

int
load_tracks(GSList *track_to_show,int mode)
{
	/// todo: эта часть кода будет серьезно меняться, чтоб брать только нужные данные из базы sqlite
	//
	// mode = 0 - Дорисовать текущий трек
	// !0 - Отрисовать весь трек
	//local->progress = 2;
	printf("* load tracks()\n");
	int step=60;
	if (global_zoom>=13) {step=60;}
		if ((global_zoom<=12) && (global_zoom>=11)) {step=300;}
		if ((global_zoom<=10) && (global_zoom>=8)) {step=1800;}
		if ((global_zoom<=7) && (global_zoom>=5)) {step=3600;}
		if (global_zoom<=4) {step=7200;}

	GSList *list;
	int pixel_x, pixel_y, x,y, last_x = 0, last_y = 0;
	float lat, lon;
	GdkColor color;
	//GdkGC *gc2;
	float latmin,lonmin,latmax,lonmax;

// настройки отображения трека

	double alpha_ch=0.5;
	double line_width=3.5;
	double point_size=3;

	bbox_t bbox;
	bbox=get_bbox(); // текущий view (нужны координаты, чтоб не рисовать все то,что за пределами экрана)

	static int width = 0, height = 0;
	time_t starttime;

	float tremor=0.0001,tremor_lat,tremor_lon;





	GSList * timepoints=NULL;


	//gdk_threads_enter();

	GdkGC *gc;
	//GdkGC *gc1;
	gboolean is_line = FALSE;
	gboolean first_point=TRUE;


	//cairo_t * ct = gdk_cairo_create(map_drawable->window);

	cairo_t * ct = gdk_cairo_create(pixmap);

	cairo_set_antialias (ct,CAIRO_ANTIALIAS_SUBPIXEL);
	cairo_set_line_cap(ct,CAIRO_LINE_CAP_ROUND);
	cairo_set_line_width(ct,line_width);

	//printf("Pixmap created\n");

	trackpoint_t *tp=NULL;
	int listcount=g_slist_length(track_to_show);
	for(list = track_to_show; list != NULL; list = list->next)
	{
		listcount--;



		tp = list->data;
		if (list->data==NULL) continue;
		//printf("data=%d\n",list->data);
		//printf("listcount=%d lat=%f , lon=%f\n",listcount,tp->lat,tp->lon);

		lat = tp->lat;
		lon = tp->lon;
		pixel_x = lon2pixel(global_zoom, tp->lon);
		pixel_y = lat2pixel(global_zoom, tp->lat);

		x=pixel_x-global_x;
		y=pixel_y-global_y;

		if (first_point) {
			// первая точка трека
			latmin=pixel2lat(global_zoom,global_y+y);
			lonmin=pixel2lon(global_zoom,global_x+x);
			latmax=pixel2lat(global_zoom,global_y+y+TILESIZE);
			lonmax=pixel2lon(global_zoom,global_x+x+TILESIZE);

			/*
			cairo_set_source_rgba(ct,colr(0),colr(255),colr(0),1.0);
			cairo_arc(ct,x,y,4,0,2*M_PI);
			cairo_fill_preserve(ct);
			 */
			last_y=y;
			last_x=x;
			is_line=TRUE;
			starttime=tp->datetime;
			timepoints = g_slist_append(timepoints,tp);
			first_point=FALSE;
			continue;

		} /// определение времени начала трека для вывода точек

		/// игнорируем остановки
		//if (tp->tpspeed<2) continue;


	//printf ("coords %f < %f < %f %d , %d , %d\n",latmin,tp->lat,latmax,(latmin,tp->lat,latmax),(lonmin < tp->lon  < lonmax),(latmin < tp->lat < latmax) && (lonmin < tp->lon  < lonmax));
		if ((bbox.lat1 > tp->lat && tp->lat > bbox.lat2)==TRUE && (bbox.lon1 < tp->lon  && tp->lon < bbox.lon2)==TRUE)
		//if ((latmin < tp->lat && tp->lat < latmax)==TRUE && (lonmin < tp->lon  && tp->lon < lonmax)==TRUE)
		//if(1)
		{
		//printf("coords: %f<%f<%f\n",bbox.lon1,tp->lon,bbox.lon2);


		//if (tp->lan)
		//lat = tp->lat;
		//lon = tp->lon;
/*
		pixel_x = lon2pixel(global_zoom, lon);
		pixel_y = lat2pixel(global_zoom, lat);



		x = pixel_x - global_x;
		y = pixel_y - global_y;

*/
		if(is_line)
		{
			// вывод линии трека
			//printf("line %d %d - %d %d\n",last_x,last_y,x,y);

			cairo_set_source_rgba(ct,colr(78),colr(201),colr(229),alpha_ch);

			//cairo_set_source_rgba(ct,0.0,0.0,1.0,0.8);
			cairo_move_to(ct,last_x,last_y);
			cairo_line_to(ct,x,y);
			cairo_stroke (ct);
			//cairo_clip(ct);


		}

		//if (abs((tp->datetime-starttime)/step)==(double)((double)(tp->datetime-starttime)/step))
		if ((starttime+step) <= tp->datetime)
		{
			// точки трека
			//printf("%d + %d  %d\n",starttime,step,tp->datetime);
			timepoints = g_slist_append(timepoints,tp);
			starttime=tp->datetime;
		}



		last_x = x;
		last_y = y;

		is_line = TRUE;
		} else
		{
			is_line=FALSE;
		}


	} // end for

	/// последняя точка трека
	if (tp!=NULL)
	{
		if (mode!=0) {timepoints = g_slist_append(timepoints,tp);}
	}





	//printf("Points count=%d\n",g_slist_length(prevxy));

	//g_slist_free(list);
//// вывод точек и подписей на трек
	first_point=TRUE;
	int prev_x=0,prev_y=0;
	for(list = timepoints; list != NULL; list = list->next)
		{
			gchar *buffer;
			trackpoint_t *tp = list->data;
			x = lon2pixel(global_zoom, tp->lon) - global_x;
			y = lat2pixel(global_zoom, tp->lat) - global_y;
			if (first_point || list->next==NULL)
			{
				cairo_set_source_rgba(ct,colr(239),colr(0),colr(0),alpha_ch);
				first_point=FALSE;
			} else
			{
				cairo_set_source_rgba(ct,colr(0),colr(0),colr(128),alpha_ch);
			}
/*				gdk_draw_drawable (
								map_drawable->window,
								map_drawable->style->fg_gc[GTK_WIDGET_STATE (map_drawable)],
								pixmap,
								last_x-5, last_y-5,
								last_x-5, last_y-5,
								50+last_x-x,20+last_y-y);
								*/
				cairo_arc(ct,x,y,point_size,0,2*M_PI);
				cairo_fill(ct);

				if ((prev_x-20 < x && x < prev_x+20)==FALSE && (prev_y-15< y && y< prev_y+15)==FALSE)
				{
				/// выводим надпись со временем, проверяем, не выводилось ли уже рядом

						time_t utctime,badtime,diff;
						struct tm * ptm;
						badtime = time (NULL);
						ptm=gmtime(&badtime);
						utctime=mktime(ptm);
						diff=badtime-utctime+(time_t)tp->datetime;
						struct tm *ttt=localtime(&diff);
						buffer = g_strdup_printf("%02d:%02d",ttt->tm_hour,ttt->tm_min);
						if (mode==0)
									{
										cairo_set_source_rgba(ct,colr(0),colr(0),colr(128),alpha_ch);
									} else
									{
										cairo_set_source_rgba(ct,colr(239),colr(0),colr(0),alpha_ch);
									}
						cairo_move_to(ct,x+10,y+10);
						cairo_set_font_size (ct, 12.0);
						cairo_select_font_face(ct,"Sans",CAIRO_FONT_SLANT_NORMAL,CAIRO_FONT_WEIGHT_BOLD);
						cairo_show_text(ct,buffer);
						prev_x=x;
						prev_y=y;
						g_free(buffer);

				}

				//timepoints=g_slist_remove(timepoints,list->data);
		}
	//timepoints = g_slist_remove_all(timepoints,)
	//g_slist_free_full(timepoints,&freefunc);
	g_slist_free(timepoints);

	if ((bbox.lat1 > lat && lat > bbox.lat2)==TRUE || (bbox.lon1 < lon  && lon < bbox.lon2)==TRUE)
		{
		/// финиш трека
			pixel_x = lon2pixel(global_zoom, lon);
			pixel_y = lat2pixel(global_zoom, lat);
			x = pixel_x - global_x;
			y = pixel_y - global_y;
			if (mode!=0)
			{
				cairo_set_source_rgba(ct,colr(0),colr(0),colr(128),alpha_ch);
			} else
			{
				cairo_set_source_rgba(ct,colr(239),colr(0),colr(0),alpha_ch);
			}
			cairo_arc(ct,x,y,point_size*1.5,0,2*M_PI);
			cairo_set_source_rgba(ct,1.0,0.5,0.5,alpha_ch);
			cairo_arc(ct,x,y,point_size,0,2*M_PI);
		}
	cairo_clip(ct);

	//gtk_widget_queue_draw(map_drawable);
	cairo_destroy(ct);
	//gdk_threads_leave();

return 0;
}


FILE *fp = NULL;

void
track_log()
{
	gchar buffer[256];
	gchar data[256];
	time_t time_sec;
	struct tm *ts;

	printf("*** %s(): \n",__PRETTY_FUNCTION__);

	if(gpsdata->valid)
	{

		time_sec = (time_t)gpsdata->fix.time;
		ts = localtime(&time_sec);


		strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%SZ", ts);


		sprintf(data, "%f,%f,%.1f,%.1f,%.1f,%.1f,%s\n",
				gpsdata->fix.latitude,
				gpsdata->fix.longitude,
				gpsdata->fix.altitude,
				gpsdata->fix.speed,
				gpsdata->fix.track,
				gpsdata->hdop,
				buffer);

		if (fp)
			{
			fprintf(fp,data);
			fflush(fp);
			}


	}
}

void
track_log_open()
{
	time_t time_epoch_sec;
	struct tm  *tm_struct;
	gchar buffer[256];
	gchar *filename = NULL;
	GtkLabel *label76;
	gchar *labeltext;

	label76 = GTK_LABEL(GTK_WIDGET (gtk_builder_get_object(interface, "label76")));


	time_epoch_sec = time(NULL);
	tm_struct = localtime(&time_epoch_sec);

	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S.log", tm_struct);

	filename = g_strconcat(global_track_dir, buffer,NULL);

	printf("*** %s(): %s\n",__PRETTY_FUNCTION__,filename);

	if(fp==NULL && trip_logger_on)
	{
		fp = fopen(filename,"w");
		if(!fp)
		{
			printf("oops: %s \n",strerror(errno));
			perror("Triplog open failed: ");
			gtk_label_set_label(label76,"<span foreground='#ff0000'>Error opening logfile</span>");
		}
		else
		{
			labeltext = g_strconcat("<b><span foreground='#0000ff'>Log: %s",buffer,"</span></b>",NULL);
			gtk_label_set_label(label76,labeltext);
			g_free(labeltext);
		}
	}

	g_free(filename);
}


void
track_log_close()
{
	int ret;
	GtkLabel *label76;
	label76 = GTK_LABEL(GTK_WIDGET (gtk_builder_get_object(interface, "label76")));
	gtk_label_set_label(label76,"");

	printf("*** %s(): \n",__PRETTY_FUNCTION__);

	if(fp) {
		printf("closing FP\n");
		ret = fclose(fp);
		fp = NULL;

		if(ret) printf("ERROR closing file\n");
	}
}


void
tracks_open_tracks_dialog()
{
	int i;
	GDir *dir;
	GError *err = NULL;
	const char *file;
	gboolean isfile;
	GList *list = NULL;

	GtkWidget *label, *vbox, *eventbox;
	

	dir = g_dir_open(global_track_dir, 0, &err);
	
	if (err != NULL)
	{
		fprintf (stderr, "Problem opening directory: %s\n", err->message);
		g_error_free (err);
		return;
	}

	GtkWidget *dialog;
	dialog = gtk_file_chooser_dialog_new ("Load track...",
				      NULL,
				      GTK_FILE_CHOOSER_ACTION_OPEN,
				      GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
				      GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
				      NULL);

	gtk_file_chooser_set_current_folder(dialog,global_track_dir);
	gtk_file_chooser_set_select_multiple(dialog,TRUE);
	if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
		{
			gtk_toggle_button_set_active (GTK_WIDGET (gtk_builder_get_object(interface,"togglebutton2")),TRUE);

			GSList *filenames = gtk_file_chooser_get_filenames (GTK_FILE_CHOOSER (dialog));
			g_slist_free(loaded_track);
			loaded_track = NULL;
			track_data* track_data_new = g_new0(track_data,1);
			track_data_new->lat=0; 
			track_data_new->lon=0; 
			track_data_new->max_lat=-90; 
			track_data_new->max_lon=-180; 
			track_data_new->min_lat=90; 
			track_data_new->min_lon=180; 
			for (i=0;i<g_slist_length(filenames);i++)
			{
				gchar * filename = g_slist_nth_data(filenames,i);
			/*	gchar ext[4];
				printf("filename=%s\n",filename+(strlen(filename)-3));
				strncpy(ext,filename+(strlen(filename)-3),3);
				for (int k=0;k<=2;k++) ext[k]=g_ascii_toupper(ext[k]);
				ext[3]=0;
				printf("ext=%s\n",ext);*/
				if (file_type_test(filename,"LOG"))
					tracks_read(filename,track_data_new);
				if (file_type_test(filename,"GPX"))
					my_parse(filename);

			}
			g_free(track_data_new);
			g_slist_free (filenames);
		}
	gtk_widget_destroy (dialog);
}


GtkWidget *
make_file_label(const char *file, char *full_file)
{
	GtkWidget *label;
	
	label = gtk_label_new (g_strdup(file));
	
	return label;
}

time_t LocalTimeFromString(char *str)
{
struct tm t;
memset(&t, 0, sizeof(t));

sscanf(str, "%04d-%02d-%02dT%02d:%02d:%02dZ",
&t.tm_year, &t.tm_mon, &t.tm_mday, &t.tm_hour, &t.tm_min,&t.tm_sec);

t.tm_year -= 1900;
t.tm_mon -= 1;

//printf("dt=%04d-%02d-%02dT%02d:%02d:%02dZ\n",
//		&t.tm_year, &t.tm_mon, &t.tm_mday, &t.tm_hour, &t.tm_min,&t.tm_sec);

return mktime(&t);
}

track_data* tracks_read (char* file,track_data* data)
{
	GtkWidget *drawingarea, *range;
	char line[121];
	char **arr;
	FILE *fd;
	gboolean first_point = TRUE;
	int track_zoom, width, height;
	
	drawingarea = GTK_WIDGET (gtk_builder_get_object(interface, "drawingarea1"));
	width  = drawingarea->allocation.width;
	height = drawingarea->allocation.height;
	
	file = (char *) file;
	
	printf("+++++++++++++++++++++++++++++++++++++++++++ %s \n", file);
	fd = fopen(file, "r");
	while(fgets(line,120, fd))
	{
		
		
		arr = g_strsplit(line, ",", 7);
		
		if (g_strcmp0(arr[0],"nan")==0) continue;   /// в файле бывает почемуто запись с неизветными координатами, пропустить


		trackpoint_t *tp = g_new0(trackpoint_t,1);

						//[0]gpsdata->fix.latitude,
						//[1]gpsdata->fix.longitude,
						//[2]gpsdata->fix.altitude,
						//[3]gpsdata->fix.speed,
						//[4]gpsdata->fix.track,  направление движения в градусах (180 или 0 когда на стоим месте)
						//[5]gpsdata->hdop,
						//[6]date
		tp->datetime=LocalTimeFromString(arr[6]);
		data->time_tmp=tp->datetime;

		tp->tpspeed=atof(arr[3]);
		tp->vector=atof(arr[4]);

		data->lat_tmp = atof(arr[0]);
		data->lon_tmp = atof(arr[1]);



		tp->lat = deg2rad(data->lat_tmp);
		tp->lon = deg2rad(data->lon_tmp);
		
		if(first_point)
		{
			data->lat = atof(arr[0]);
			data->lon = atof(arr[1]);
			first_point = FALSE;
		}
		
		data->max_lat = (data->lat_tmp>data->max_lat) ? data->lat_tmp : data->max_lat;
		data->min_lat = (data->lat_tmp<data->min_lat) ? data->lat_tmp : data->min_lat;
		data->max_lon = (data->lon_tmp>data->max_lon) ? data->lon_tmp : data->max_lon;
		data->min_lon = (data->lon_tmp<data->min_lon) ? data->lon_tmp : data->min_lon;
		data->min_time = (data->time_tmp<data->min_time) ? data->time_tmp : data-> min_time;
		data->max_time = (data->time_tmp<data->max_time) ? data->time_tmp : data-> max_time;

		loaded_track = g_slist_append(loaded_track, tp);
	}
	
//	gtk_notebook_set_current_page(GTK_NOTEBOOK(GTK_WIDGET (gtk_builder_get_object(interface,"notebook1"))), 0);

	track_zoom = get_zoom_covering(width, height, data->max_lat, data->min_lon, data->min_lat, data->max_lon);
	track_zoom = (track_zoom > 15) ? 15 : track_zoom;
	
	if(data->lat!=0 && data->lon!=0)
		set_mapcenter((data->max_lat+data->min_lat)/2, (data->max_lon+data->min_lon)/2, track_zoom);

//printf("%.0f - %.0f ## %.0f - %.0f\n, zoom=%d\n",data->max_lat,data->max_lon,data->min_lat,data->min_lon,track_zoom);
		
		range = GTK_WIDGET (gtk_builder_get_object(interface, "vscale1"));
		gtk_range_set_value(GTK_RANGE(range), (double) global_zoom);
	
	return data;	
}



static char *path[10];
static char *last_element;
static int lvl;
static int array_num;
static int count;

float tmp_lat,tmp_lon,tmp_speed,vector;
time_t tmp_datetime;

///// загрузка треков из GPX
char * myfullpath()
{
	char tm[100],*ret="";

		//tm=malloc(100);
		//printf("PATH=");
	    for (int i=1;i<=lvl;i++)
	    {
	    //printf("/%s",path[i]);
	    sprintf(tm,"%s/%s",ret,path[i]);
	    ret=tm;
	    }
	    //printf("%s\n",ret);
	    return ret;
}


void *mystart_element (GMarkupParseContext *context,
     const gchar         *element_name,
     const gchar        **attribute_names,
     const gchar        **attribute_values,
     gpointer             user_data,
     GError             **error)
     {
//		path[lvl]=malloc(stringLen+1);
//	    memcpy(path[lvl],stringVal,stringLen);
		lvl++;
	    path[lvl]=element_name;
	    last_element=element_name;




	    if(attribute_names!=NULL)
	    {
	    	int done1=0, n=0;
	    	while(!done1)
	    	{
	    		if (attribute_names[n]!=NULL)
	    		{
	    			if (strcmp( attribute_names[n],"lon")==0)
	    					{
							tmp_lon=atof(attribute_values[n]);
	    					}
	    			if (strcmp( attribute_names[n],"lat")==0)
	    					{
	    					tmp_lat=atof(attribute_values[n]);
	    					}

						//printf("%d %s/%s : %s\n",count,myfullpath(),attribute_names[n],attribute_values[n]);
						//count++;
	    		} else
	    		{
	    			done1=1;
	    		}
	    		n++;
	    	}

	    }

		//printf("start %s\n",element_name);

     }
void *myend_element    (GMarkupParseContext *context,
                          const gchar         *element_name,
                          gpointer             user_data,
                          GError             **error)
{
	lvl--;
	if (strcmp(element_name,"trkpt")==0)
	{
		count ++;

		tp = g_new0(trackpoint_t,1);
		tp->lat=deg2rad(tmp_lat);
		tp->lon=deg2rad(tmp_lon);
		tp->datetime=tmp_datetime;


//printf("lat=%f lon=%f\n",tmp_lat,tmp_lon);

		//tp->tpspeed=atof(); // todo: это можно вычислить из текущего и предыдущего значения координат
		//tp->vector=atof();  //

		loaded_track=g_slist_append(loaded_track,tp);
	}

}

  /* Called for character data */
  /* text is not nul-terminated */
void *mytext(GMarkupParseContext *context,
                          const gchar         *text,
                          gsize                text_len,
                          gpointer             user_data,
                          GError             **error)
{
	if (strcmp(last_element,"time")==0)
				{
				tmp_datetime=LocalTimeFromString(text);
				}

	if (text_len>4)
	{
		//count++;
		printf("%d %s : %s\n",count,myfullpath(),text,text_len);
	}

}


static GMarkupParser parser=
{
		mystart_element,
		myend_element,
		mytext,
		NULL,
		NULL
};

GError **error;
static gpointer *point;
static gchar *path1;
//GHashTable hash;


void my_parse(gchar * filename)
{
	gchar xml[1024];
	FILE *f;
	path[0]="/";
	count=0;

	loaded_track=g_slist_alloc();

	GMarkupParseContext * context=g_markup_parse_context_new        (&parser,
							 G_MARKUP_TREAT_CDATA_AS_TEXT,
							 point,
					         NULL);

	f=fopen(filename,"r");
	if (f!=NULL)
	{
		int done=0;
		while(!done)
		{

			int rd=fread(&xml,1024,1,f);
				if (rd==0)
				{
					if (!feof(f))
						{
						printf("error reading file\n");
						//done=1;
						}
					done=1;
				}

				g_markup_parse_context_parse (context,xml,1024,error);



		}
printf("count=%d\n",count);

	}
}








/*
int test_paint_tile(data_of_thread *local,char * errtext)
{

	gdk_threads_enter();

	int x,y;
	GdkColor color;
	x=local->offset_x-(global_x-local->x_glob);
	y=local->offset_y-(global_y-local->y_glob);
	float latmin,lonmin,latmax,lonmax;
	latmin=pixel2lat(global_zoom,global_y+y);
	lonmin=pixel2lon(global_zoom,global_x+x);
	latmax=pixel2lat(global_zoom,global_y+y+TILESIZE);
	lonmax=pixel2lon(global_zoom,global_x+x+TILESIZE);


	GdkGC *gc;
	gc = gdk_gc_new(pixmap);
		color.green = 50000;
		color.blue = 0;
		color.red = 0;
		gdk_gc_set_rgb_fg_color(gc, &color);

	printf("test_paint_tile: x=%d y=%d \n",x,y);

	cairo_t * ct = gdk_cairo_create(pixmap);

	cairo_set_source_rgb(ct,0.0,0.0,1.0);
	//cairo_arc(ct,x,y,4,0,2*M_PI);

	cairo_move_to(ct,x,);
	cairo_line_to(ct,x+255,y);
	cairo_line_to(ct,x+255,y+255);
	cairo_line_to(ct,x,y+255);
	cairo_line_to(ct,x,y);


	const char * text=malloc(150);



	cairo_move_to(ct,x+10,y+10);
	sprintf(text,"screen coordinate x=%d,y=%d",x,y);
	cairo_show_text(ct,text);


	cairo_move_to(ct,x+10,y+20);
	sprintf(text,"zoom=%d",local->zoom);
	cairo_show_text(ct,text);

	cairo_move_to(ct,x+10,y+30);
	sprintf(text,"tile num local_x=%d, local_y=%d",local->x, local->y);
	cairo_show_text(ct,text);

	cairo_move_to(ct,x+10,y+40);
	sprintf(text,"local_x_glob=%d, local_y_glob=%d",local->x_glob, local->y_glob);
	cairo_show_text(ct,text);

	cairo_move_to(ct,x+10,y+50);
	sprintf(text,"global x=%d, y=%d",global_x, global_y);
	cairo_show_text(ct,text);

	gchar latlon[64];
	float lat_deg,lon_deg;

	latmin = pixel2lat(global_zoom, global_y+y);
	lonmin = pixel2lon(global_zoom, global_x+x);


		lat_deg = rad2deg(latmin);
		lon_deg = rad2deg(lonmin);

		switch (global_latlon_unit)
		{
			case 0:
				g_sprintf(latlon, "%f - %f", lat_deg, lon_deg);
				break;
			case 1:
				g_sprintf(latlon, "%s   %s",
					  latdeg2latmin(lat_deg),
					  londeg2lonmin(lon_deg));
				break;
			case 2:
				g_sprintf(latlon, "%s   %s",
					  latdeg2latsec(lat_deg),
					  londeg2lonsec(lon_deg));
		}


	cairo_move_to(ct,x+10,y+60);
	sprintf(text,"%s",latlon);
	cairo_show_text(ct,text);

		cairo_move_to(ct,x+10,y+100);
		cairo_show_text(ct,errtext);



	cairo_save(ct);
	cairo_stroke(ct);
	cairo_clip(ct);

	gtk_widget_queue_draw(map_drawable);

	gdk_threads_leave();
	return 1;
}

*/

/*
void
print_track()
{
printf("*** %s(): \n",__PRETTY_FUNCTION__);
	GSList *list;
	int pixel_x, pixel_y, x,y, last_x = 0, last_y = 0;
	float lat, lon;
	GdkColor color;
	GdkGC *gc;
	gboolean is_line = FALSE;
	//time_t starttime;
	//time_t endtime;

	//memset(&starttime,1,sizeof(starttime));

	gc = gdk_gc_new(pixmap);
	color.green = 0;
	color.blue = 0;
	color.red = 60000;
	gdk_gc_set_rgb_fg_color(gc, &color);
	gdk_gc_set_line_attributes(gc,
		5, GDK_LINE_SOLID, GDK_CAP_ROUND, GDK_JOIN_ROUND);

	printf("*** %s(): \n",__PRETTY_FUNCTION__);

	for(list = trackpoint_list; list != NULL; list = list->next)
	{
		trackpoint_t *tp = list->data;

		lat = tp->lat;
		lon = tp->lon;




		pixel_x = lon2pixel(global_zoom, lon);
		pixel_y = lat2pixel(global_zoom, lat);

		x = pixel_x - global_x;
		y = pixel_y - global_y;




		if(is_line)
		{
			gdk_draw_line (pixmap, gc, x, y, last_x, last_y);
			gtk_widget_queue_draw_area (
				map_drawable,
				x-4, y-4,
				8,8);
		}

			// первая точка в треке
			//gdk_draw_arc(pixmap,gc,TRUE,x,y,15,15,0,360);
			/* gdk_draw_line(pixmap,gc,x,y,x,y+10);
			gtk_widget_queue_draw_area (
						map_drawable,
						x-8, y-8,
						8,8);
		last_x = x;
		last_y = y;


		is_line = TRUE;
	}





	if(
		gpsdata &&
		gpsdata->fix.longitude !=0 &&
		gpsdata->fix.latitude != 0 &&
		last_x != 0 &&
		last_y != 0
		)
	{
		pixel_x = lon2pixel(global_zoom, deg2rad(gpsdata->fix.longitude));
		pixel_y = lat2pixel(global_zoom, deg2rad(gpsdata->fix.latitude));

		x = pixel_x - global_x;
		y = pixel_y - global_y;


		gdk_draw_line (pixmap, gc, x, y, last_x, last_y);
		printf("LINE x y lx ly: %d %d %d %d\n",x,y,last_x,last_y);
			gtk_widget_queue_draw_area (
			map_drawable,
			x-4, y-4,
			8,8);
	}

}
*/
/*
int
load_current_track(data_of_thread *local)
{
	local->progress = 3;
	printf("* load current track()\n");
	GSList *list;
	int pixel_x, pixel_y, x,y, last_x = 0, last_y = 0;
	float lat, lon;
	GdkColor color;

	gdk_threads_enter();
	GdkGC *gc;
	gboolean is_line = FALSE;

	gc = gdk_gc_new(pixmap);
	color.green = 0;
	color.blue = 0;
	color.red = 60000;
	gdk_gc_set_rgb_fg_color(gc, &color);
	gdk_gc_set_line_attributes(gc,
		5, GDK_LINE_SOLID, GDK_CAP_ROUND, GDK_JOIN_ROUND);

	for(list = trackpoint_list; list != NULL; list = list->next)
	{
		trackpoint_t *tp = list->data;

		lat = tp->lat;
		lon = tp->lon;
		printf("track_point_lat = %d, trackpoint_lon = %d\n",lat,lon);

		pixel_x = lon2pixel(global_zoom, lon);
		pixel_y = lat2pixel(global_zoom, lat);

		x = pixel_x - global_x;
		y = pixel_y - global_y;

		if(is_line)
		{
			gdk_draw_line (pixmap, gc, x, y, last_x, last_y);
			gtk_widget_queue_draw_area (
				map_drawable,
				x-4, y-4,
				8,8);
		printf("draw_track_point_x = %d, draw_trackpoint_y = %d, draw_trackpoint_last_x = %d, draw_trackpoint_last_y = %d\n",x,y,last_x,last_y);
		}

		last_x = x;
		last_y = y;

		is_line = TRUE;
	}
gdk_threads_leave();
	return 0;
}

*/



/*

void
track_log()
{
	gchar buffer[256];
	gchar data[256];
	time_t time_sec;
	struct tm *ts;

	printf("*** %s(): \n",__PRETTY_FUNCTION__);

	if(gpsdata->valid)
	{

		time_sec = (time_t)gpsdata->fix.time;
		ts = localtime(&time_sec);


		strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%SZ", ts);


		sprintf(data, "%f,%f,%.1f,%.1f,%.1f,%.1f,%s\n",
				gpsdata->fix.latitude,
				gpsdata->fix.longitude,
				gpsdata->fix.altitude,
				gpsdata->fix.speed,
				gpsdata->fix.track,
				gpsdata->hdop,
				buffer);

		if (fp) fprintf(fp,data);
	}
}

void
track_log_open()
{
	time_t time_epoch_sec;
	struct tm  *tm_struct;
	gchar buffer[256];
	gchar *filename = NULL;
	GtkLabel *label76;
	gchar *labeltext;

	label76 = GTK_LABEL(GTK_WIDGET (gtk_builder_get_object(interface, "label76")));


	time_epoch_sec = time(NULL);
	tm_struct = localtime(&time_epoch_sec);

	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S.log", tm_struct);

	filename = g_strconcat(global_track_dir, buffer,NULL);

	printf("*** %s(): %s\n",__PRETTY_FUNCTION__,filename);

	if(fp==NULL && trip_logger_on)
	{
		fp = fopen(filename,"w");
		if(!fp)
		{
			printf("oops: %s \n",strerror(errno));
			perror("Triplog open failed: ");
			gtk_label_set_label(label76,"<span foreground='#ff0000'>Error opening logfile</span>");
		}
		else
		{
			labeltext = g_strconcat("<b><span foreground='#0000ff'>Log: %s",buffer,"</span></b>",NULL);
			gtk_label_set_label(label76,labeltext);
			g_free(labeltext);
		}
	}

	g_free(filename);
}


void
track_log_close()
{
	int ret;
	GtkLabel *label76;
	label76 = GTK_LABEL(GTK_WIDGET (gtk_builder_get_object(interface, "label76")));
	gtk_label_set_label(label76,"");

	printf("*** %s(): \n",__PRETTY_FUNCTION__);

	if(fp) {
		printf("closing FP\n");
		ret = fclose(fp);
		fp = NULL;

		if(ret) printf("ERROR closing file\n");
	}
}

/*
 * gps track generation
 * track draw
 * position draw
 * get trip information
 */
