#include <glib.h>

gboolean
file_type_test(const char *file, char *type);

int
	sql_execute(char *db_name, char *sql, int (*cb_func)(void*,int,char**,char**));

gboolean file_exists(const char * filename);

gboolean check_connect(void);

