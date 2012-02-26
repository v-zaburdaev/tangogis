#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <glib.h>
#include <glib/gstdio.h>
#include <glib/gprintf.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <gdk/gdk.h>
#include <math.h>
#include <time.h>
#include <errno.h>

#include "globals.h"
#include "map_management.h"
#include "converter.h"
#include "gps_functions.h"
#include "support.h"
#include "callbacks.h"
#include "wp.h"
#include "interface.h"
#include "osd.h"

gboolean
cb_gps_timer() 
{

	get_gps();
	gps_info_show();
	//fill_tiles_pixel();
	return TRUE; 
}

void gps_info_show()
{
	int pixel_x, pixel_y, x, y, last_x, last_y;
	static float lat, lon;
	static float lat_tmp=0, lon_tmp=0;
	float trip_delta=0;

	static double trip_time_accumulated = 0;


	static gboolean trip_counter_got_stopped = FALSE;


	GdkColor color;
	static GdkGC *gc=NULL, *gc_2=NULL, *gc_3=NULL, *gc_4=NULL, *gc_5=NULL;

	if(gc == NULL)
	{
		gc   = gdk_gc_new(pixmap);
		gc_2 = gdk_gc_new(pixmap);
		gc_3 = gdk_gc_new(pixmap);
		gc_4 = gdk_gc_new(pixmap);
		gc_5 = gdk_gc_new(pixmap);
	}

	color.red = 0;
	color.green = 0;
	color.blue = 40000;
	gdk_gc_set_rgb_fg_color(gc, &color);
        gdk_gc_set_line_attributes(gc,
                        5, GDK_LINE_SOLID, GDK_CAP_ROUND, GDK_JOIN_ROUND);

	color.red = 5000;
	color.green = 5000;
	color.blue = 55000;
	gdk_gc_set_rgb_fg_color(gc_2, &color);

        gdk_gc_set_line_attributes(gc_2,
                        2, GDK_LINE_SOLID, GDK_CAP_ROUND, GDK_JOIN_ROUND);

	color.red = 25500;
	color.green = 35000;
	color.blue = 65500;
	gdk_gc_set_rgb_fg_color(gc_3, &color);
        gdk_gc_set_line_attributes(gc_3,
                        2, GDK_LINE_SOLID, GDK_CAP_ROUND, GDK_JOIN_ROUND);


	color.red = 35500;
	color.green = 5000;
	color.blue = 500;
	gdk_gc_set_rgb_fg_color(gc_4, &color);
        gdk_gc_set_line_attributes(gc_4,
                        7, GDK_LINE_SOLID, GDK_CAP_ROUND, GDK_JOIN_ROUND);


	color.red = 65500;
	color.green = 65500;
	color.blue = 65500;
	gdk_gc_set_rgb_fg_color(gc_5, &color);
        gdk_gc_set_line_attributes(gc_5,
                        11, GDK_LINE_SOLID, GDK_CAP_ROUND, GDK_JOIN_ROUND);


	//get_gps();

	if(gpsdata)
	{

		static int counter = 0;

		lat = deg2rad(gpsdata->fix.latitude);
		lon = deg2rad(gpsdata->fix.longitude);

		//printf("** %s() \n", __PRETTY_FUNCTION__);

		pixel_x = lon2pixel(global_zoom, lon);
		pixel_y = lat2pixel(global_zoom, lat);
		
		x = pixel_x - global_x;
		y = pixel_y - global_y;
		
		pixel_x = lon2pixel(global_zoom, lon_tmp);
		pixel_y = lat2pixel(global_zoom, lat_tmp);
		
		last_x = pixel_x - global_x;
		last_y = pixel_y - global_y;
		
		if(gpsdata->seen_vaild)
		{
			//printf("** %s() gpsdata valid\n", __PRETTY_FUNCTION__);
			int hand_x, hand_y, hand_wp_x, hand_wp_y;
			double heading_rad, bearing;

			heading_rad = (gpsdata->fix.track * (1.0 / 180.0)) * M_PI;

			if(gpsdata->fix.speed>0.3)
			{
				hand_x =  25 * sinf(heading_rad);
				hand_y = -25 * cosf(heading_rad);
			}
			else
			{
				hand_x = 0;
				hand_y = 0;
			}
////// 	вывод
		gdk_threads_enter();

		gdk_draw_drawable (
			map_drawable->window,
			map_drawable->style->fg_gc[GTK_WIDGET_STATE (map_drawable)],
			pixmap,
			last_x-29, last_y-29,
			last_x-29 + mouse_dx, last_y-29 + mouse_dy,
			80,58);



		//if (lat_tmp && lon_tmp)
		//	gdk_draw_line(pixmap, gc, last_x, last_y, x, y);



		gdk_window_process_all_updates();


		if(mouse_dx == 0 && mouse_dy == 0)
		{

			gdk_draw_arc (
				map_drawable->window,

				gc_2,
				FALSE,
				x-15 + mouse_dx, y-15 + mouse_dy,
				30,30,
				0, 360*64);


			if(global_wp_on && gpsdata->valid)
			{

				bearing = get_bearing(lat, lon, global_wp.lat, global_wp.lon);
				gpsdata->fix.bearing = bearing;
				printf("BEARING: %f\n", bearing);
				hand_wp_x =  25 * sinf(bearing);
				hand_wp_y = -25 * cosf(bearing);

				gdk_draw_line(map_drawable->window,
						gc_5,
						x + mouse_dx,
						y + mouse_dy,
						x + mouse_dx + hand_wp_x,
						y + mouse_dy + hand_wp_y);

				gdk_draw_line(map_drawable->window,
						gc_4,
						x + mouse_dx,
						y + mouse_dy,
						x + mouse_dx + hand_wp_x,
						y + mouse_dy + hand_wp_y);

				osd_wp();

			}

			gdk_draw_line(map_drawable->window,
					gc_5,
					x + mouse_dx,
					y + mouse_dy,
					x + mouse_dx + hand_x,
					y + mouse_dy + hand_y);

			gdk_draw_line(map_drawable->window,
					gc_3,
					x + mouse_dx,
					y + mouse_dy,
					x + mouse_dx + hand_x,
					y + mouse_dy + hand_y);
		}

		gdk_threads_leave();

		if(global_autocenter)
		{
		//printf("** %s() global_autocenter\n", __PRETTY_FUNCTION__);
			if(    (x < (global_drawingarea_width /2 - global_drawingarea_width /8) ||
				x > (global_drawingarea_width /2 + global_drawingarea_width /8) ||
				y < (global_drawingarea_height /2 - global_drawingarea_height /8) ||
				y > (global_drawingarea_height /2 + global_drawingarea_height /8) ) &&
				isnan(gpsdata->fix.latitude) ==0 &&
				isnan(gpsdata->fix.longitude)==0 &&
				gpsdata->fix.latitude  !=0 &&
				gpsdata->fix.longitude !=0
				)
			{
				set_mapcenter(gpsdata->fix.latitude, gpsdata->fix.longitude, global_zoom);
			}
		}

		if(trip_counter_on)
		{

			if( gpsdata->valid)
			{
				if(lat_tmp==0 || lon_tmp==0)
						{
							lat_tmp = lat;
							lon_tmp = lon;
						}

				trip_delta = 6371.0 * acos(sin(lat) * sin(lat_tmp) +
								cos(lat) * cos(lat_tmp) * cos(lon_tmp-lon) );
				if(isnan(trip_delta))
				{
					printf("WTF??? %f %f %f %f %f \n",lat,lon,lat_tmp,lon_tmp,trip_delta);
				}
				else
				{

					trip_distance += trip_delta;
					time_t t=(time_t)gpsdata->fix.time;
					trackpoint_t *tp = g_new0(trackpoint_t,1);
					tp->lat = lat;
					tp->lon = lon; ///TODO : дописать остальные параметры в tp
					tp->tpspeed=(float)gpsdata->fix.speed;
					tp->datetime=(time_t)gpsdata->fix.time;
					current_track->trackpoints = g_slist_append(current_track->trackpoints, tp);

					lat_tmp = lat;
					lon_tmp = lon;

					if(trip_delta> 0.002)
					{
						//counter++;
						//if(counter % 2 == 0 && global_current_track_show)
						if(global_current_track_show)
						{
							gdk_threads_enter();
							load_tracks(current_track,0);
							gdk_threads_leave();
						}

					}
				}
			}

			if(gpsdata->valid && gpsdata->fix.speed > trip_maxspeed)
				trip_maxspeed = gpsdata->fix.speed;

			if(trip_time == 0)
				trip_time_accumulated = 0;

			if(trip_counter_got_stopped)
			{
				//printf("counter had been stopped \n");
				trip_counter_got_stopped = FALSE;
				trip_time_accumulated = trip_time;
				trip_starttime = 0;
			}

			if(trip_starttime == 0 && gpsdata->seen_vaild)
			{
				trip_starttime = gpsdata->fix.time;
			}

			if(trip_starttime > 0 && gpsdata->seen_vaild)
			{
				trip_time = gpsdata->fix.time - trip_starttime + trip_time_accumulated;
			}

			if(trip_time < 0)
			{
				trip_time = 0;
				trip_starttime = 0;
				trip_distance = 0;
				trip_maxspeed = 0;
			}





					}

		}
		else
		{
			//printf("trip counter halted\n");
			trip_counter_got_stopped = TRUE;
			lat_tmp = lon_tmp = 0;
		}
		//printf("** %s() set label\n", __PRETTY_FUNCTION__);
		gdk_threads_enter();
		set_label();
		gdk_flush();
		gdk_window_process_all_updates();

		gdk_threads_leave();
		if(trip_logger_on && gpsdata->valid)
			track_log();
		

	}
	else
	{
//		printf("no gpsdata for timer\n");
		set_label_nogps();
	}
	//printf("** %s() end\n", __PRETTY_FUNCTION__);
	return TRUE;
}
void
g_key_get_repolist()
{
	GError **error = NULL;
	
	int repo_arr_len;
	char **repo_arr = g_key_file_get_keys(	global_tangogis_config,
						"repolist",
						&repo_arr_len,
						error);
	
	if (repo_arr == NULL)
	{
		repo_t *repo1 = g_new0(repo_t, 1);
		repo_t *repo2 = g_new0(repo_t, 1);
		repo_t *repo3 = g_new0(repo_t, 1);
		repo_t *repo4 = g_new0(repo_t, 1);
		repo_t *repo5 = g_new0(repo_t, 1);
		repo_t *repo6 = g_new0(repo_t, 1);
		repo_t *repo7 = g_new0(repo_t, 1);
		repo_t *repo8 = g_new0(repo_t, 1);
		repo_t *repo9 = g_new0(repo_t, 1);
		printf("\n\ntangogis_dir = %s\n\n",tangogis_dir);

		
		printf("REPOLIST == NULL\n");
		repo1->name = g_strdup("OSM");
		repo1->uri  = g_strdup("http://tile.openstreetmap.org/%d/%d/%d.png");
		repo1->dir  = g_strdup_printf("%s/Maps/OSM",tangogis_dir);
		repo1->inverted_zoom = 0;
		global_repo_list = g_slist_append(global_repo_list, repo1);

		repo2->name = g_strdup("Topo");
		repo2->uri  = g_strdup("http://maps-for-free.com/layer/relief/z%d/row%d/%d_%d-%d.jpg");
		repo2->dir  = g_strdup_printf("%s/Maps/maps4free",tangogis_dir);
		repo2->inverted_zoom = 0;
		global_repo_list = g_slist_append(global_repo_list, repo2);
		
		repo3->name = g_strdup("Aerial");
		repo3->uri  = g_strdup("http://tile.openaerialmap.org/tiles/1.0.0/openaerialmap-900913/%d/%d/%d.jpg");
		repo3->dir  = g_strdup_printf("%s/Maps/openaerial",tangogis_dir);
		repo3->inverted_zoom = 0;
		global_repo_list = g_slist_append(global_repo_list, repo3);
		
		repo4->name = g_strdup("Opencyclemap");
		repo4->uri  = g_strdup("http://a.andy.sandbox.cloudmade.com/tiles/cycle/%d/%d/%d.png");
		repo4->dir  = g_strdup_printf("%s/Maps/opencyclemap",tangogis_dir);
		repo4->inverted_zoom = 0;
		global_repo_list = g_slist_append(global_repo_list, repo4);
		
		repo5->name = g_strdup("Google Sat (testing only)");
		repo5->uri  = g_strdup("http://khm1.google.com/kh?v=34&hl=en&x=%d&s=&y=%d&z=%d");
		repo5->dir  = g_strdup_printf("%s/Maps/googlesat",tangogis_dir);
		repo5->inverted_zoom = 1;
		global_repo_list = g_slist_append(global_repo_list, repo5);

		repo6->name = g_strdup("Google Map");
		repo6->uri  = g_strdup("http://mt1.google.com/vt/v=w2.101&hl=ru&x=%d&y=%d&z=%d");
		repo6->dir  = g_strdup_printf("%s/Maps/googlemap",tangogis_dir);
		repo6->inverted_zoom = 1;
		global_repo_list = g_slist_append(global_repo_list, repo6);

		repo7->name = g_strdup("Yandex Sat");
		repo7->uri  = g_strdup("http://sat01.maps.yandex.ru/tiles?l=sat&v=1.10.0&x=%d&y=%d&z=%d");
		repo7->dir  = g_strdup_printf("%s/Maps/yandexsat",tangogis_dir);
		repo7->inverted_zoom = 1;
		global_repo_list = g_slist_append(global_repo_list, repo7);

		repo8->name = g_strdup("Yandex Map");
		repo8->uri  = g_strdup("http://vec03.maps.yandex.ru/tiles?l=map&v=2.15.0&x=%d&y=%d&z=%d");
		repo8->dir  = g_strdup_printf("%s/Maps/yandexmap",tangogis_dir);
		repo8->inverted_zoom = 1;
		global_repo_list = g_slist_append(global_repo_list, repo8);
		
		repo9->name = g_strdup("Marshruty.ru");
		repo9->uri  = g_strdup("http://maps.marshruty.ru/ml.ashx?x=%d&y=%d&z=%d&i=1&ss=be9bbf");
		repo9->dir  = g_strdup_printf("%s/Maps/marshruty",tangogis_dir);
		repo9->inverted_zoom = 1;
		global_repo_list = g_slist_append(global_repo_list, repo9);
		
	}
	else
	{
		for (int i=0; i<repo_arr_len; i++)
		{
			gchar **array;
			array = g_key_file_get_string_list(global_tangogis_config,
												"repolist",
												repo_arr[i],
												NULL,
												error);
			repo_t *repo = g_new0(repo_t, 1);
			
			repo->name = g_strdup(repo_arr[i]);
			repo->uri  = g_strdup(array[0]);
			repo->dir  = g_strdup(array[1]);
			repo->inverted_zoom = atoi(array[2]) == 1;
			
			global_repo_list = g_slist_append(global_repo_list, repo);

			printf(": \n -- name: %s \n -- uri: %s \n -- dir: %s \n",
				repo->name, repo->uri, repo->dir);
		}
		g_strfreev(repo_arr);

	}
//-----------------Traffic repository------------------	
		const int amount_trf_repo=2;
		repo_t *repo_trf[amount_trf_repo];
		repo_trf[0]= g_new0(repo_t, 1);
		repo_trf[0]->name = g_strdup("Yandex TRF");
		repo_trf[0]->uri  = g_strdup("http://jgo.maps.yandex.net/tiles?l=trf&x=%d&y=%d&z=%d&tm=%d");
		repo_trf[0]->dir  = g_strdup_printf("%s/Maps/TRF/yandex",global_home_dir);
		repo_trf[0]->inverted_zoom = 1;

		repo_trf[1] = g_new0(repo_t, 1);
		repo_trf[1]->name = g_strdup("Google TRF");
		repo_trf[1]->uri  = g_strdup("http://mt1.google.com/mapstt?zoom=%d&x=%d&y=%d&client=google");
		repo_trf[1]->dir  = g_strdup_printf("%s/Maps/TRF/google",global_home_dir);
		repo_trf[1]->inverted_zoom = 0;
		
		int i;
		for (i=0;i<amount_trf_repo;i++)
		{
			global_trf_list =  g_slist_append(global_trf_list, repo_trf[i]);
		}
//-----------------Traffic repository------------------	
	

//------------Traffic repo name remember------------	
	GSList	*list;
	if (curr_trf_name==NULL) 
	{
		curr_trf=repo_trf[0];
		curr_trf_name = curr_trf->name;
	}
	else
	{
		for (list = global_trf_list; list != NULL; list = list->next)
		{
	                repo_t  *repo;
	                gchar   *reponame;
	                repo = list->data;
	                reponame = g_strdup(repo->name);
									 
			if ((strstr(reponame, curr_trf_name) != NULL) && (strlen(reponame) == strlen(curr_trf_name)))
			{
				curr_trf = list->data;
				curr_trf_name = curr_trf->name;
				break;
			}
		}	
	}
//------------Traffic repo name remember------------	

	return global_repo_list;	
					
}

void
g_key_set_repolist()
{
	GSList	*list;
	
	for(list = global_repo_list; list != NULL; list = list->next)
	{
		repo_t *repo = list->data;
		
		char *g_key_arr[3];
		g_key_arr[0]=repo->uri;
		g_key_arr[1]=repo->dir;
		if (repo->inverted_zoom)
			g_key_arr[2]="1";
		else 
			g_key_arr[2]="0";

		g_key_file_set_string_list(	global_tangogis_config,
							"repolist", 
							repo->name,
							g_key_arr,
							3);
	}
	g_file_set_contents(tangogis_conf_file_name, g_key_file_to_data(global_tangogis_config,NULL,NULL),-1,NULL);
}




void
repoconfig__populate_dialog()
{

}

void
repoconfig__set_current_list_pointer()
{
	
	
	GSList		*list;
	const gchar	*reponame;
	
	for(list = global_repo_list; list != NULL; list = list->next)
	{
		repo_t *repo;
		repo	= list->data;
		
		reponame = g_strdup(repo->name);
		
		if(	g_strrstr(reponame,global_curr_reponame) != NULL &&
			strlen(reponame) == strlen(global_curr_reponame)	
		)
			global_curr_repo = list;
	}
	if(!global_curr_repo)
	{
		printf("\n#\n#\n#  ERROR: repository %s is broken \n#\n#\n", global_curr_reponame);
		
		printf("Resetting repo_name and exiting now.\n\n");
		printf("If problem persists after restart, \n");
		exit(EXIT_FAILURE);		
	}
}


void
repoconfig__create_dropdown()
{
	GtkWidget	*combobox;
	GSList		*list;
	int 		i = 0;
	int		j = 0;
	const gchar	*reponame;
	
	combobox = GTK_WIDGET (gtk_builder_get_object(interface, "comboboxtext1"));
	for(list = global_repo_list; list != NULL; list = list->next)
	{
		repo_t	*repo;
		repo = list->data;
		reponame = g_strdup(repo->name);
		gtk_combo_box_text_append_text (GTK_COMBO_BOX(combobox), g_strdup(repo->name));
		
		if(	strcmp(reponame,global_curr_reponame) == 0)
		{
			j = i;
			global_curr_repo = list;
		}
		i++;
	}
	global_repo_cnt = i;
	gtk_combo_box_set_active(GTK_COMBO_BOX(combobox), j);
//	g_signal_connect ((gpointer) combobox, "changed",
//                    G_CALLBACK (on_comboboxtext1_changed),
//                    NULL);
//-------------Traffic combobox list------------------	
j=0;i=0;
	combobox = GTK_WIDGET (gtk_builder_get_object(interface, "comboboxtext_trf"));
	for(list = global_trf_list; list != NULL; list = list->next)
	{
		repo_t	*repo;
		
		repo = list->data;
		reponame = g_strdup(repo->name);
		gtk_combo_box_text_append_text (GTK_COMBO_BOX(combobox), g_strdup(repo->name));
		
		if(	g_strrstr(reponame,curr_trf->name) != NULL &&
			strlen(reponame) == strlen(curr_trf->name)	
		)
		{
			j = i;
		}
		i++;
	}
	gtk_combo_box_set_active(GTK_COMBO_BOX(combobox), j);
//	g_signal_connect ((gpointer) combobox, "changed",
//                    G_CALLBACK (on_comboboxtext_trf_changed),
//                    NULL);
//-------------Traffic combobox list------------------	
}


void
pre_init()
{
	GError	*err = NULL;
	loading=TRUE;
/* Мне кажется, что это не нужно */
//	g_type_init();

	global_home_dir = getenv("HOME");
	tangogis_dir = g_strconcat(global_home_dir, "/.tangogis", NULL);
	tangogis_conf_file_name = g_strconcat(tangogis_dir,CONF_FILE,NULL);
	global_tangogis_config = g_key_file_new();
	if (g_key_file_load_from_file(global_tangogis_config, 
								tangogis_conf_file_name,
								G_KEY_FILE_KEEP_COMMENTS|G_KEY_FILE_KEEP_TRANSLATIONS,
								&err)
		)
		printf("Config loaded!\n\n");
	else
		printf("%s\n",err->message);
	global_curr_reponame	= g_key_file_get_string(global_tangogis_config,"repositories", "repo_name",err);
	
	curr_trf_name = g_key_file_get_string(global_tangogis_config,"repositories", "curr_trf",err);

	if(global_curr_reponame == NULL)
		global_curr_reponame = g_strdup("Yandex Map");
	g_key_get_repolist();	
	repoconfig__set_current_list_pointer();
	
	global_x = g_key_file_get_integer(
				global_tangogis_config,"map coordinates", 
				"global_x",
				err);
	global_y = g_key_file_get_integer(
				global_tangogis_config,"map coordinates", 
				"global_y",
				err);
	global_zoom = g_key_file_get_integer(
				global_tangogis_config,"map coordinates", 
				"global_zoom",
				err);
	//-----создаем хеш таблицу загрузки тайлов
	ht = g_hash_table_new (g_str_hash, g_str_equal);
	printf("init.c hash = %d\n",ht);
	


/* Здесь нужно поставить координаты географического центра России - черезвычайно красивого озера ВИВИ на плато Путорана */
	if(global_zoom <= 2) 
	{
		global_x=79083;
		global_y=40774;
		global_zoom=9;
	}
	
	if(g_key_file_get_boolean(global_tangogis_config,"other", "started_before", err))
	{
	// Чтение настроек автозагрузки карт
		if (g_key_file_get_boolean( global_tangogis_config,"visual", "auto_download", err))
			gtk_toggle_button_set_active (GTK_WIDGET (gtk_builder_get_object(interface,"checkbutton2")),TRUE);
		else
			global_auto_download = FALSE;

	// Чтение настроек автозагрузки пробок
		if (g_key_file_get_boolean( global_tangogis_config,"visual", "trf_auto", err))
			gtk_toggle_button_set_active (GTK_WIDGET (gtk_builder_get_object(interface,"checkbutton_trf_auto")),TRUE);
		else
			global_trf_auto = FALSE;

	// Чтение настроек показа пробок
		if (g_key_file_get_boolean( global_tangogis_config,"visual", "trf_show", err))
			gtk_toggle_button_set_active (GTK_WIDGET (gtk_builder_get_object(interface,"togglebutton_trf_show")),TRUE);
		else
			global_trf_show = FALSE;

	// Чтение настроек показа сетки
		if (g_key_file_get_boolean( global_tangogis_config,"visual", "grid_show", err))
		{
			gtk_toggle_button_set_active (GTK_WIDGET (gtk_builder_get_object(interface,"togglebutton1")),TRUE);
			gtk_widget_show(GTK_WIDGET (gtk_builder_get_object(interface,"label7")));
			gtk_widget_show(GTK_WIDGET (gtk_builder_get_object(interface,"label8")));
			gtk_widget_show(GTK_WIDGET (gtk_builder_get_object(interface,"label9")));
			gtk_widget_show(GTK_WIDGET (gtk_builder_get_object(interface,"label10")));
			gtk_widget_show(GTK_WIDGET (gtk_builder_get_object(interface,"label11")));
			gtk_widget_show(GTK_WIDGET (gtk_builder_get_object(interface,"label12")));
			gtk_widget_show(GTK_WIDGET (gtk_builder_get_object(interface,"label13")));
			gtk_widget_show(GTK_WIDGET (gtk_builder_get_object(interface,"label14")));
			gtk_widget_show(GTK_WIDGET (gtk_builder_get_object(interface,"label15")));
			gtk_widget_show(GTK_WIDGET (gtk_builder_get_object(interface,"label16")));
			gtk_widget_show(GTK_WIDGET (gtk_builder_get_object(interface,"label17")));
			gtk_widget_show(GTK_WIDGET (gtk_builder_get_object(interface,"label18")));
//			if (global_grid_show) 
//				for (int i=0;i<7;i+=2)
//				{
//					gtk_widget_show(label_grid_v[i]); 
//					gtk_widget_show(label_grid_h[0][i]); 
//					gtk_widget_show(label_grid_h[1][i]); 
//				}
//			else
//				for (int i=0;i<7;i+=2)
//				{
//					gtk_widget_hide(label_grid_v[i]); 
//					gtk_widget_hide(label_grid_h[0][i]); 
//					gtk_widget_hide(label_grid_h[1][i]); 
//				}
		}
		else
			global_grid_show = FALSE;
	}
	else
	{
		g_key_file_set_boolean(global_tangogis_config, "other", "started_before", TRUE);
		g_key_file_set_boolean(global_tangogis_config,"other", "auto_download", TRUE);
/*		Неуверен, но кажется это совсем ненужно*/
//		global_auto_download = TRUE;
//		global_trf_auto = TRUE;
//		global_trf_show = TRUE;
	}
}

void
init()
{
	loading=TRUE;
	gint timer;
	gpointer data = NULL;	
	
	GError	*err = NULL;
	const gchar *nick, *pass;
	GtkWidget *nick_entry, *pass_entry, *widget;
	gchar buffer[128];
	gboolean gconf_fftimer_running;
	char *str = NULL;
	int screen_height;
	
	current_track = g_new(track_data_t,1);
	current_track->trackpoints=g_slist_alloc();
	loaded_track =  g_new(track_data_t,1);
	loaded_track->trackpoints=g_slist_alloc();

	osd_init();

	screen_height = gdk_screen_get_height(gdk_screen_get_default());
	
	g_mkdir(tangogis_dir, 0700);

	repoconfig__create_dropdown();

	
	nick_entry  = GTK_WIDGET (gtk_builder_get_object(interface, "entry7"));
	pass_entry  = GTK_WIDGET (gtk_builder_get_object(interface, "entry8"));

	//global_tangogis_config,NULL	= g_key_file_get_default(); 
	nick			= g_key_file_get_string(global_tangogis_config,"other", "nick",&err);
	pass			= g_key_file_get_string(global_tangogis_config,"other", "pass",&err);
	
	global_speed_unit	= g_key_file_get_integer(global_tangogis_config,"other", "speed_unit",&err);
	global_alt_unit		= g_key_file_get_integer(global_tangogis_config,"other", "alt_unit",&err);
	global_latlon_unit	= g_key_file_get_integer(global_tangogis_config,"other", "latlon_unit",&err);
	
	switch (global_speed_unit)
	{
		case 1:
			widget = GTK_WIDGET (gtk_builder_get_object(interface, "radiobutton15"));
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), TRUE);
			break;
		case 2:
			widget = GTK_WIDGET (gtk_builder_get_object(interface, "radiobutton16"));
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), TRUE);
			break;
	}
	
	switch (global_alt_unit)
	{
		case 1:
			widget = GTK_WIDGET (gtk_builder_get_object(interface, "radiobutton18"));
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), TRUE);
			break;
	}
	
	switch (global_latlon_unit)
	{
		case 1:
			widget = GTK_WIDGET (gtk_builder_get_object(interface, "radiobutton20"));
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), TRUE);
			break;
		case 2:
			widget = GTK_WIDGET (gtk_builder_get_object(interface, "radiobutton21"));
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), TRUE);
			break;
	}
	
	gtk_entry_set_text( GTK_ENTRY(nick_entry), nick );
	gtk_entry_set_text( GTK_ENTRY(pass_entry), pass );
	
	widget = GTK_WIDGET (gtk_builder_get_object(interface, "vscale1"));
	gtk_range_set_value(GTK_RANGE(widget), (double) global_zoom);
	
	global_map_dir	= g_key_file_get_string(global_tangogis_config,"other", "map_dir",&err);
	if(!global_map_dir)
		global_map_dir = g_strdup_printf("%s/Maps/",tangogis_dir);
	if (g_mkdir_with_parents(global_map_dir,0700)) {
		perror("mkdir()");
		printf("MKDIR ERROR: %s\n", global_map_dir);
	}
	
	global_track_dir	= g_key_file_get_string(global_tangogis_config,"other", "track_dir",&err);
	if(!global_track_dir)
		global_track_dir = g_strdup_printf("%s/Tracks/",tangogis_dir);
	
	if (g_mkdir_with_parents(global_track_dir,0700)) {
		perror("mkdir()");
		printf("MKDIR ERROR: %s\n", global_track_dir);
	}
	
	
	global_myposition.lat = 0;
	global_myposition.lon = 0;

//	widget = GTK_WIDGET (gtk_builder_get_object(interface, "checkbutton2"));
//	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), global_auto_download);

//-----------------------Traffic download-------------------
//	widget = GTK_WIDGET (gtk_builder_get_object(interface, "checkbutton_trf_auto"));
//	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), global_trf_auto);
//	widget = GTK_WIDGET (gtk_builder_get_object(interface, "togglebutton_trf_show"));
//	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), global_trf_show);
//-----------------------Traffic download-------------------

	
	
	
	
	
	gconf_fftimer_running = g_key_file_get_boolean(global_tangogis_config,"other", "fftimer_running",&err);
	
	
	global_ffupdate_interval_minutes = g_key_file_get_double(global_tangogis_config,"other", "ffupdate_interval_minutes",&err);
	global_ffupdate_interval = (int)floor(global_ffupdate_interval_minutes) * 60000;
	widget = GTK_WIDGET (gtk_builder_get_object(interface, "entry16"));
	if (global_ffupdate_interval_minutes<10)
		g_sprintf(buffer, "%.1f", global_ffupdate_interval_minutes);
	else
		g_sprintf(buffer, "%.0f", global_ffupdate_interval_minutes);
	gtk_entry_set_text( GTK_ENTRY(widget), buffer );
	
	
	global_ffupdate_auto	= g_key_file_get_boolean(global_tangogis_config,"other", "ffupdate_auto",&err);
	if(global_ffupdate_auto)
	{
		widget = GTK_WIDGET (gtk_builder_get_object(interface, "radiobutton13"));
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget),TRUE);
	}

	
	if(gconf_fftimer_running)
	{
		widget = lookup_widget(menu1, "item19");
		gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(widget), TRUE);
	}
		
	
	global_ffcm_public	= g_key_file_get_boolean(global_tangogis_config,"other", "ffcm_public",&err);
	global_ffcm_registered	= g_key_file_get_boolean(global_tangogis_config,"other", "ffcm_registered",&err);
	global_ffcm_friends	= g_key_file_get_boolean(global_tangogis_config,"other", "ffcm_friends",&err);
	
	widget = GTK_WIDGET (gtk_builder_get_object(interface, "checkbutton3"));
	if(global_ffcm_public)
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), TRUE);
	}
	else
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), FALSE);
	}


	widget = GTK_WIDGET (gtk_builder_get_object(interface, "checkbutton4"));
	if(global_ffcm_registered)
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), TRUE);
	}
	else
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), FALSE);
	}

	
	widget = GTK_WIDGET (gtk_builder_get_object(interface, "checkbutton5"));
	if(global_ffcm_friends)
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), TRUE);
	}
	else
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), FALSE);
	}	
	
	
	
	
	global_ffcu_public	= g_key_file_get_boolean(global_tangogis_config,"other", "ffcu_public",&err);
	global_ffcu_registered	= g_key_file_get_boolean(global_tangogis_config,"other", "ffcu_registered",&err);
	global_ffcu_friends	= g_key_file_get_boolean(global_tangogis_config,"other", "ffcu_friends",&err);
	
	widget = GTK_WIDGET (gtk_builder_get_object(interface, "checkbutton6"));
	if(global_ffcu_public)
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), TRUE);
	}
	else
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), FALSE);
	}
	
	
	widget = GTK_WIDGET (gtk_builder_get_object(interface, "checkbutton7"));
	if(global_ffcu_registered)
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), TRUE);
	}
	else
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), FALSE);
	}

	
	widget = GTK_WIDGET (gtk_builder_get_object(interface, "checkbutton8"));
	if(global_ffcu_friends)
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), TRUE);
	}
	else
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), FALSE);
	}	
	
	str = g_key_file_get_string(global_tangogis_config,"other", "gpsd_host",&err);
	widget = GTK_WIDGET (gtk_builder_get_object(interface, "entry3"));
	gtk_entry_set_text(GTK_ENTRY(widget), g_strdup(str));
	g_free(str);
	
	str = g_key_file_get_string(global_tangogis_config,"other", "gpsd_port",&err);
	widget = GTK_WIDGET (gtk_builder_get_object(interface, "entry4"));
	gtk_entry_set_text(GTK_ENTRY(widget), g_strdup(str));
	g_free(str);
	
	if (g_key_file_get_boolean(global_tangogis_config,"tracks", "tracklog_on", NULL))
		gtk_button_clicked(GTK_BUTTON(GTK_WIDGET (gtk_builder_get_object(interface,"button18"))));
	
	timer = g_timeout_add (1000,cb_gps_timer,data);
	
	gtk_window_set_icon_from_file(GTK_WINDOW(window1), PACKAGE_PIXMAPS_DIR "" PACKAGE ".png" ,&err);
	if (err)
	{
		fprintf (stderr, "Failed to load pixbuf file:  %s\n", err->message);
		g_error_free (err);
	}
	loading=FALSE;
	printf("Init complete\n");
	repaint_all();

}
