//--------Struct data for threads--------------
typedef struct {
	int i;//координата тайла
	int j;//координата тайла
	void* thread_id;
	void* thread_id_next;
	int progress;//Флаг места выполнения
	int map_x;		//Для показа
	int map_y;		//Для показа
	int map_offset_x;//Для показа
	int map_offset_y;//Для показа
	int map_last_x;		//Для отслеживания изменений между вызовами перерисовки
	int map_last_y;		//Для отслеживания изменений между вызовами перерисовки
	int trf_x;		//Для показа
	int trf_y;		//Для показа
	int trf_offset_x;//Для показа
	int trf_offset_y;//Для показа
	int trf_last_x;		//Для отслеживания изменений между вызовами перерисовки
	int trf_last_y;		//Для отслеживания изменений между вызовами перерисовки
	int zoom;		//Для показа
	int last_zoom;	//Для отслеживания изменений между вызовами перерисовки
//	int x_glob;		//Для отслеживания изменений в пределах перерисовки
//	int y_glob;		//Для отслеживания изменений в пределах перерисовки
	repo_t* repo;
	time_t trf_time;
	int trf_need_redraw;
	GdkPixbuf *pixbuf_map;
	GdkPixbuf *pixbuf_trf;
} data_of_thread;
static data_of_thread*** threads_data;
void view_tile(data_of_thread  *local);
//--------Struct data for threads--------------
typedef struct {
} data_of_download_thread;

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

void WGS84_offset(int zoom, int pixel_x, int pixel_y, int* mercator_x, int* mercator_y);


