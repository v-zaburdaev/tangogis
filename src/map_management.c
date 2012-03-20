#include <stdlib.h>
#include <sys/stat.h>

#include <string.h>
#include <glib.h>
#include <gtk/gtk.h>
#include <glib/gstring.h>
#include <glib/gprintf.h>
#include <math.h>
#include "support.h"
#include "globals.h"
#include "map_management.h"
#include "converter.h"
#include "tile_management.h"
#include "callbacks.h"
#include "friends.h"
#include "gps_functions.h"
#include "geo_photos.h"
#include "poi.h"
#include "wp.h"

#define ERR_ZOOM   -1
#define ERR_LOAD   -2
#define ERR_REPO   -3
#define ERR_DOWN   -4
#define ERR_LIMITS -5
#define LOAD_OK     1

static GtkWidget *drawingarea1=NULL;

static GdkPixbuf ***showed_tile_maps;
static GdkPixbuf ***showed_tile_trf;
static int threads_data_size_x,threads_data_size_y;

static clock_t draw_time;//время в микросекундах

void
view_tile(data_of_thread  *local)
{
	if(drawingarea1==NULL)
		drawingarea1 = GTK_WIDGET (gtk_builder_get_object(interface, "drawingarea1"));
	static GStaticMutex mutex_thread = G_STATIC_MUTEX_INIT;
	if (local->thread_id)
//		if (local->zoom==global_zoom || 
//			abs(local->x_glob - global_x)>255 ||
//			abs(local->y_glob - global_y)>255
//			)
		{
			//printf("size of thread = %d\n",sizeof(g_thread_self()));
			while(local->thread_id)
				usleep(1000);
			if (local->thread_id_next!=g_thread_self()) 
				return;
		}
	local->thread_id=g_thread_self();
			
	local->progress = 0;
//	local->x_glob=global_x;
//	local->y_glob=global_y;//Чтобы отследить изменилось ли положение карты
	local->zoom=global_zoom;
	local->repo=global_curr_repo->data;
	number_threads = update_thread_number(1);
	printf("\n\n # of threads: %i \n\n", number_threads );

	if(!pixmap)
	{
		printf("no drawable -> NULL\n");
		local->thread_id = 0;
		return;
	}
//--------WGS84 offset----------
	int WGS84_x,WGS84_y;
	WGS84_offset(global_zoom, global_x, global_y, &WGS84_x, &WGS84_y);
//--------WGS84 offset----------
   	if (strcasestr(local->repo->name,"Yandex")!=NULL)
	{
		local->map_offset_x = - (WGS84_x) % TILESIZE;
		local->map_offset_y = - (WGS84_y) % TILESIZE;
		local->map_x =  floor((float)WGS84_x / (float)TILESIZE) + local->i;
		local->map_y =  floor((float)WGS84_y / (float)TILESIZE) + local->j;
	}
	else
	{
		local->map_offset_x = - global_x % TILESIZE;
		local->map_offset_y = - global_y % TILESIZE;
		local->map_x =  floor((float)(global_x) / (float)TILESIZE) + local->i;
		local->map_y =  floor((float)(global_y) / (float)TILESIZE) + local->j;
	}
	if (local->map_offset_x > 0) local->map_offset_x -= 256;
	if (local->map_offset_y > 0) local->map_offset_y -= 256;
	local->map_offset_x += TILESIZE*local->i;
	local->map_offset_y += TILESIZE*local->j;

	if (strcasestr(curr_trf->name,"Yandex")!=NULL)
	{
		local->trf_offset_x = - (WGS84_x) % TILESIZE;
		local->trf_offset_y = - (WGS84_y) % TILESIZE;
		local->trf_x =  floor((float)WGS84_x / (float)TILESIZE) + local->i;
		local->trf_y =  floor((float)WGS84_y / (float)TILESIZE) + local->j;
	}
	else
	{
		local->trf_offset_x = - global_x % TILESIZE;
		local->trf_offset_y = - global_y % TILESIZE;
		local->trf_x =  floor((float)(global_x) / (float)TILESIZE) + local->i;
		local->trf_y =  floor((float)(global_y) / (float)TILESIZE) + local->j;
	}
	if (local->trf_offset_x > 0) local->trf_offset_x -= 256;
	if (local->trf_offset_y > 0) local->trf_offset_y -= 256;
	local->trf_offset_x += TILESIZE*local->i;
	local->trf_offset_y += TILESIZE*local->j;


	load_map(local);
	if (global_trf_show)
	{
		if (local->pixbuf_map)
		{
			load_trf(local);
		}
	}

//	if (local->thread_id_next!=g_thread_self()) 
//		return;
GdkGC		*gc_map = NULL;
	gdk_threads_enter();
	if (local->pixbuf_map)
	{
			gdk_draw_pixbuf (
					pixmap,
					gc_map,
					local->pixbuf_map,
					0,0,
					local->map_offset_x/*-(global_x-local->x_glob)*/,local->map_offset_y/*-(global_y-local->y_glob)*/,
					TILESIZE,TILESIZE,
					GDK_RGB_DITHER_NONE, 0, 0);
	}
	else
	{
		gdk_draw_rectangle (
			pixmap,
			drawingarea1->style->white_gc,
			TRUE,
			local->map_offset_x, local->map_offset_y,
			256,
			256);
	}
//----------Trafic visualization---------------
	if (local->pixbuf_trf)
	{
			gdk_draw_pixbuf (
					pixmap,
					gc_map,
					local->pixbuf_trf,
					0,0,
					local->trf_offset_x/*-(global_x-local->x_glob)*/,local->trf_offset_y/*-(global_y-local->y_glob)*/,
					TILESIZE,TILESIZE,
					GDK_RGB_DITHER_NONE, 0, 0);

	}
	else
	{
	}
//----------Trafic visualization---------------
		gtk_widget_queue_draw_area (
			drawingarea1, 
			local->map_offset_x/*-(global_x-local->x_glob)*/,local->map_offset_y/*-(global_y-local->y_glob)*/,
			TILESIZE,TILESIZE);
	gdk_threads_leave();
	local->map_last_x = local->map_x;
	local->map_last_y = local->map_y;
	local->last_zoom = local->zoom;
	local->trf_last_x = local->trf_x;
	local->trf_last_y = local->trf_y;

	if (number_threads==1)
	{
		if (global_track_show)
			printf ("load_tracks returned %d",load_tracks(local));
		if (global_current_track_show)
			printf ("load_tracks returned %d",load_current_track(local));
printf ("draw time = %d\n",clock()-draw_time);//время в микросекундах
	}


number_threads = update_thread_number(-1);
	local->thread_id = 0;
}

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

int
load_tracks(data_of_thread *local)
{
	local->progress = 2;
	printf("* load tracks()\n");
	GSList *list;
	int pixel_x, pixel_y, x,y, last_x = 0, last_y = 0;
	float lat, lon;
	GdkColor color;


gdk_threads_enter();
	GdkGC *gc;
	gboolean is_line = FALSE;
	
	gc = gdk_gc_new(pixmap);                  
	color.green = 50000;
	color.blue = 0;
	color.red = 0;
	gdk_gc_set_rgb_fg_color(gc, &color);
	gdk_gc_set_line_attributes(gc,
		5, GDK_LINE_SOLID, GDK_CAP_ROUND, GDK_JOIN_ROUND);

	for(list = loaded_track; list != NULL; list = list->next)
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
		
		last_x = x;
		last_y = y;
		
		is_line = TRUE;
	}
gdk_threads_leave();
return 0;
}

int
load_map(data_of_thread *local)
{

	local->progress = 1;

	//printf("* load MAP()\n");
	
GError		*error = NULL;
			
	if ((local->map_x < 0) || (local->map_y < 0) || (local->map_x > exp(local->zoom * M_LN2)) || (local->map_y > exp(local->zoom * M_LN2)))
	{
		g_object_unref(local->pixbuf_map);
		return ERR_LIMITS;
	}

	gchar *filename;
	filename = g_strdup_printf("%s/%u/%u/%u.png", local->repo->dir, local->zoom, local->map_x, local->map_y);
	printf("IMG: %s\n",filename);

//gdk_threads_enter();
	if (local->pixbuf_map==NULL)
	{
		local->pixbuf_map = gdk_pixbuf_new_from_file (filename, &error);
	}
	else if (local->map_last_x!=local->map_x || local->map_last_y != local->map_y  )
	{
		if (local->pixbuf_map)
			g_object_unref(local->pixbuf_map);
		local->pixbuf_map = gdk_pixbuf_new_from_file (filename, &error);
//		int i_new=local->i+(local->x-local->last_x);
//		int j_new=local->j+(local->y-local->last_y);
//		if ((i_new>threads_data_size_x && j_new>threads_data_size_y) || (i_new<0 && j_new<0))
//		{
////			g_object_unref(local->pixbuf_map);
//			local->pixbuf_map = gdk_pixbuf_new_from_file (filename, &error);
//		}
//		else
//			local->pixbuf_map = showed_tile_maps[i_new][j_new];
	}
//gdk_threads_leave();

	if (global_map_reload || (global_auto_download && local->pixbuf_map==0))
	{
		if (!host_failed )
		{
			char *status=g_hash_table_lookup(ht,filename);

			if (!status)
			{
				tile_t *tile=g_new0(tile_t,1);
				tile->x=local->map_x; tile->y=local->map_y;tile->zoom=local->zoom;tile->repo=local->repo;tile->local=local;
				g_thread_create(&download_tile,tile,FALSE,TRUE);
			}
			else
			{
			}
		}
	}
	g_free(filename);
}

//--------------Traffic download--------------------------------
int
load_trf(data_of_thread *local)
{

		printf("\n----------Trafic visualization---------------\n");
		printf("\n\nshow=%d ,auto=%d ,down=%d\n",global_trf_show,global_trf_auto,global_auto_download);

GError		*error = NULL;
GdkGC		*gc_map = NULL;

	printf("* load_trf()\n");
	
	gchar* filename;

	gchar* key;


	filename = g_strdup_printf("%s/%d/%d/%d.png", curr_trf->dir, local->zoom, local->trf_x, local->trf_y);
	printf("IMG: %s\n",filename);
	char *status=g_hash_table_lookup(ht,filename);

	{
//Информация о загрузке данного тайла пробок
	if (local->trf_time==0)
		{
			struct stat file_info;
			if (!stat(filename,&file_info))
				local->trf_time=file_info.st_mtime;
		}

				global_time=time(NULL);
				struct tm*  local_time;
				local_time=localtime(&global_time);//local time of this machine
				printf ("%d:%d:%d\n", local_time->tm_hour,  local_time->tm_min,  local_time->tm_sec);
				int temptime=local_time->tm_min*60+local_time->tm_sec;//Прошло времени с момента начала нового часа
				traffic_time=global_time-temptime+(int)(temptime/240)*240-240;
				printf("Возраст пробок %i\n", global_time-traffic_time);//время с момента создания новых карт движения, т.е. возраст последних пробок на яндексе.
				printf("global_time = %i\n", global_time);
				printf("traffic_time = %i\n", traffic_time);
				printf("local->trf_time = %i\n", local->trf_time);
		 
	}

	if (local->trf_last_x!=local->trf_x || local->trf_last_y != local->trf_y)
	{
		local->trf_need_redraw=1;
		if (local->pixbuf_trf)
			g_object_unref(local->pixbuf_trf);
		local->pixbuf_trf = gdk_pixbuf_new_from_file (filename, &error);
	}
	else if (local->pixbuf_trf==NULL)
	{
		local->pixbuf_trf = gdk_pixbuf_new_from_file (filename, &error);
	}

	if ((!local->pixbuf_trf || (traffic_time > local->trf_time)) && (global_trf_auto && !host_failed))// Появились новые тайлы пробок
	{
		if (!host_failed )
		{
			if (!status)
			{
				tile_t *tile=g_new0(tile_t,1);
				tile->x=local->trf_x; tile->y=local->trf_y;tile->zoom=local->zoom;tile->repo=curr_trf;tile->time=traffic_time;tile->local=local;
				local->trf_time=traffic_time;
				g_thread_create(&download_tile,tile,FALSE,TRUE);
			}
			else //if (strcmp(status,"404"))
			{
			}
		}
	}
	else if (!status)
	{
		if (local->pixbuf_trf)
			g_object_unref(local->pixbuf_trf);
		local->pixbuf_trf = gdk_pixbuf_new_from_file (filename, &error);
	}

	g_free(filename);

return 0;
}
//--------------Traffic download--------------------------------
void
fill_tiles_pixel()
{
	int tile_count_x, tile_count_y;
	gboolean success = FALSE;
	GError *error = NULL;
//		if (gpsdata!=NULL)
//		{
//			printf("time=%f\n",gpsdata->fix.time);
//			global_time = gpsdata->fix.time;
//		}
//		else	
//		
	
	printf("*** %s(): xyz %d %d %d, time=%d\n",__PRETTY_FUNCTION__,global_x,global_y,global_zoom,global_time);
	
	tile_count_x = map_drawable->allocation.width / TILESIZE + 2;
	tile_count_y = map_drawable->allocation.height / TILESIZE + 2;
	
//------------------double dinamic array--------------------------1
	if ((threads_data_size_x != tile_count_x) || (threads_data_size_y != tile_count_y))
	{
		while (number_threads);
		if (threads_data)
		{
			for (int i=0; i<threads_data_size_x;i++)
			{
				for (int j=0;j<threads_data_size_y;j++)
				{
					g_object_unref(threads_data[i][j]->pixbuf_map);
					g_object_unref(threads_data[i][j]->pixbuf_trf);
					free(threads_data[i][j]);
					free(showed_tile_maps[i][j]);
					free(showed_tile_trf[i][j]);
				}
				free(threads_data[i]);
			}
			free(threads_data);
		}
		threads_data_size_x = tile_count_x;
		threads_data_size_y = tile_count_y;
		threads_data = malloc(threads_data_size_x*sizeof(void*)); 
		showed_tile_maps = malloc(threads_data_size_x*sizeof(void*)); 
		showed_tile_trf = malloc(threads_data_size_x*sizeof(void*)); 
		memset(threads_data,0,threads_data_size_x*sizeof(void*));
		for (int i=0;i<threads_data_size_x;i++)
		{
			threads_data[i] = malloc(threads_data_size_y*sizeof(void*));
			showed_tile_maps[i] = malloc(threads_data_size_x*sizeof(void*)); 
			showed_tile_trf[i] = malloc(threads_data_size_x*sizeof(void*)); 
			memset(threads_data[i],0,threads_data_size_y*sizeof(void*));
			for (int j=0;j<threads_data_size_y;j++)
			{
				threads_data[i][j] = malloc(sizeof(data_of_thread));
				memset(threads_data[i][j],0,sizeof(data_of_thread));
				threads_data[i][j]->i=i;
				threads_data[i][j]->j=j;
			}
		}
	}
draw_time=clock();//время в микросекундах
printf ("draw time fill = %d\n",draw_time);//время в тактах процессора
	for (int i=0; i<tile_count_x;i++)
	{
		for (int j=0;  j<tile_count_y; j++)
		{
			//if (threads_data[i][j]->thread_id)
				showed_tile_maps[i][j]=threads_data[i][j]->pixbuf_map; 
				showed_tile_trf[i][j]=threads_data[i][j]->pixbuf_trf; 
				threads_data[i][j]->thread_id_next=g_thread_create(&view_tile, threads_data[i][j], FALSE, NULL);
		}
	}
//------------------double dinamic array--------------------------1


/*
//		if (trf_old) traffic_old_factor++;
		if (global_trf_auto)
		{
			printf ("До загрузки пробок осталось %d секунд\n", (traffic_time + 250 +240 - global_time));
			g_timeout_add_seconds ((traffic_time + 250 - global_time), auto_load_trf_timer, NULL);
		}
	}	
*/

	g_key_file_set_integer(
				global_tangogis_config, 
				"map coordinates",
				"global_x",
				global_x
				);
	g_key_file_set_integer(
				global_tangogis_config, 
				"map coordinates",
				"global_y",
				global_y
				);
	g_key_file_set_integer(
				global_tangogis_config, 
				"map coordinates",
				"global_zoom",
				global_zoom
				);
}

void
fill_tiles_latlon(	float lat,
			float lon,
			int zoom)
{
	int pixel_x, pixel_y;
	
	
	pixel_x = lon2pixel(zoom, lon);

	pixel_y = lat2pixel(zoom, lat);

 
	printf("fill_tiles_latlon(): lat %f  %i -- lon %f  %i\n",lat,pixel_y,lon,pixel_x);
	
	
	fill_tiles_pixel (pixel_x, pixel_y, zoom);
}

void
set_mapcenter(	float lat,
		float lon,
		int zoom)
{
	int pixel_x, pixel_y;
	
	lat = deg2rad(lat);
	lon = deg2rad(lon);
	
	
	pixel_x = lon2pixel(zoom, lon);
	pixel_y = lat2pixel(zoom, lat);

	printf("fill_tiles_latlon(): lat %f  %i -- lon %f  %i\n",
	lat,pixel_y,lon,pixel_x);
	
	osd_speed();
	global_x = pixel_x - global_drawingarea_width/2; 
	global_y = pixel_y - global_drawingarea_height/2; 
	global_zoom = zoom;
	fill_tiles_pixel (	pixel_x - global_drawingarea_width/2, 
				pixel_y - global_drawingarea_height/2,
				zoom);
//	print_track();
//	paint_friends();
//	paint_photos();
//	paint_pois();
//	paint_wp();
//	osd_speed(); 


}



void
fill_tiles_latlon_hack(	float lat,
			float lon,
			int zoom)
{
	int pixel_x, pixel_y;
	
	
	pixel_x = lon2pixel(zoom, lon);

	pixel_y = lat2pixel(zoom, lat);

	printf("fill_tiles_latlon(): lat %f  %i -- lon %f  %i\n",
	lat,pixel_y,lon,pixel_x);
	
	fill_tiles_pixel (pixel_x - 240, pixel_y - 300, zoom);
}



void WGS84_offset(int zoom, int pixel_x, int pixel_y, int* mercator_x, int* mercator_y)
{
//--------------Yandex repository offset ------------------------
	    {
            float lat=rad2deg(pixel2lat((float)zoom,pixel_y));
            float lon=rad2deg(pixel2lon((float)zoom,pixel_x));
//----Shmuma autor---
            float tmp = tan (M_PI_4 + deg2rad (lat) / 2.0);
            float pow_tmp = pow (tan (M_PI_4 +  asin (YANDEX_E * sin (deg2rad (lat))) / 2.0), YANDEX_E);
            *mercator_x = (int)((YANDEX_Rn * deg2rad (lon) + YANDEX_A) * YANDEX_F)>>(23-zoom);
            *mercator_y = (int)((YANDEX_A - (YANDEX_Rn * log (tmp / pow_tmp))) * YANDEX_F)>>(23-zoom);
        }
//--------------Yandex repository offset ------------------------
}

//--------------Traffic autodownloadtimer--------------------------------
gboolean auto_load_trf_timer()
{
	repaint_all();

	return FALSE;
}
//--------------Traffic autodownloadtimer--------------------------------

