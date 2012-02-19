//--------New struct data for threads--------------
typedef struct {
	int i;
	int j;
	void* thread_id;
	int progress;
	int x;
	int y;
	int x_glob;
	int y_glob;
	int offset_x;
	int offset_y;
	int zoom;
	repo_t* repo;
} data_of_thread;
//--------New struct data for threads--------------

void show_tile(int offset_x, int offset_y);
int load_trf (data_of_thread* local);

gboolean auto_load_trf_timer();

int
load_map(data_of_thread* local);

void
fill_tiles_pixel();

void
fill_tiles_latlon(	float lat,
			float lon,
			int zoom);
			
void
fill_tiles_latlon_hack(	float lat,
			float lon,
			int zoom);
			
void
set_mapcenter(	float lat,
		float lon,
		int zoom);

void mercator_offset(int zoom, int pixel_x, int pixel_y, int* mercator_x, int* mercator_y);


