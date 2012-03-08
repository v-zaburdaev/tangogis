//--------Struct data for threads--------------
typedef struct {
	int i;//координата тайла
	int j;//координата тайла
	void* thread_id;
	void* thread_id_next;
	int progress;//Флаг места выполнения
	int x;		//Для показа
	int y;		//Для показа
	int mercator_x,mercator_y;	
	int zoom;		//Для показа
	int last_x;		//Для отслеживания изменений между вызовами перерисовки
	int last_y;		//Для отслеживания изменений между вызовами перерисовки
	int last_zoom;	//Для отслеживания изменений между вызовами перерисовки
	int x_glob;		//Для отслеживания изменений в пределах перерисовки
	int y_glob;		//Для отслеживания изменений в пределах перерисовки
	int offset_x;
	int offset_y;
	repo_t* repo;
	int download_map_flag;
	int download_trf_flag;
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

void mercator_offset(int zoom, int pixel_x, int pixel_y, int* mercator_x, int* mercator_y);


