
void
tracks_open_tracks_dialog();

void
paint_loaded_track();

gboolean
tracks_on_file_button_release_event      (	GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);
//
// Данные расположения показываемого трека
typedef struct {
	float lat, lon, max_lat, max_lon, min_lat, min_lon, lat_tmp, lon_tmp;
} track_data;

track_data* tracks_read (char* file,track_data* data);
