
#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include <glib.h>
#include <glib/gstdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "globals.h"
#include "tracks.h"
#include "interface.h"
#include "support.h"
#include "converter.h"
#include "map_management.h"

GtkWidget *
make_file_label(const char *file, char *full_file);

					
void
tracks_open_tracks_dialog()
{
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
			gtk_toggle_button_set_active (glade_xml_get_widget(interface,"togglebutton2"),TRUE);

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
			for (int i=0;i<g_slist_length(filenames);i++)
			{
				tracks_read(g_slist_nth_data(filenames,i),track_data_new);
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

track_data* tracks_read (char* file,track_data* data)
{
	GtkWidget *drawingarea, *range;
	char line[121];
	char **arr;
	FILE *fd;
	gboolean first_point = TRUE;
	int track_zoom, width, height;
	
	drawingarea = glade_xml_get_widget(interface, "drawingarea1");
	width  = drawingarea->allocation.width;
	height = drawingarea->allocation.height;
	
	file = (char *) file;
	
	printf("+++++++++++++++++++++++++++++++++++++++++++ %s \n", file);
	fd = fopen(file, "r");
	while(fgets(line,120, fd))
	{
		
		trackpoint_t *tp = g_new0(trackpoint_t,1);
		
		arr = g_strsplit(line, ",", 2);
		
		
		
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
		
		loaded_track = g_slist_append(loaded_track, tp);
	}
	
	gtk_notebook_set_current_page(GTK_NOTEBOOK(glade_xml_get_widget(interface,"notebook1")), 0);

	
	
	track_zoom = get_zoom_covering(width, height, data->max_lat, data->min_lon, data->min_lat, data->max_lon);
	track_zoom = (track_zoom > 15) ? 15 : track_zoom;
	
	if(data->lat!=0 && data->lon!=0)
		set_mapcenter((data->max_lat+data->min_lat)/2, (data->max_lon+data->min_lon)/2, track_zoom);

printf("%.0f - %.0f ## %.0f - %.0f\n, zoom=%d\n",data->max_lat,data->max_lon,data->min_lat,data->min_lon,track_zoom);
		
			range = glade_xml_get_widget(interface, "vscale1");
		gtk_range_set_value(GTK_RANGE(range), (double) global_zoom);
	
	return data;	
}


