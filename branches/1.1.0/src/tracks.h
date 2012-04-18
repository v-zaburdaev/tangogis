#include <glib.h>
//#include "map_management.h"
//#include "globals.h"

void
print_track();

void
tracks_open_tracks_dialog();

void
paint_loaded_track();

gboolean
tracks_on_file_button_release_event      (	GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);


int load_tracks(track_data_t *trackdata,int mode);

track_data_t* tracks_read_from_log (gchar* filename);
track_data_t* tracks_read_from_gpx(gchar* filename);

time_t LocalTimeFromString(char* str);

