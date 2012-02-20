#include "util.h"


#include <glib.h>
#include <glib/gprintf.h>
#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h> 

int
sql_execute(char *db_name, char *sql, int (*cb_func)(void*,int,char**,char**))
{
	sqlite3 *db;
	char *errmsg = 0;
	int rc;
	int result = 0;
	
	printf("*** %s(): \n",__PRETTY_FUNCTION__);


	rc = sqlite3_open(db_name, &db);
	if( rc ){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		result = -1;
	}
	else
	{
		rc = sqlite3_exec(db, sql, cb_func, 0, &errmsg);
	}
	
	if( rc!=SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", errmsg);
		sqlite3_free(errmsg);
		result = 1;
	}
  
	sqlite3_close(db);
	return result;
}

gboolean
file_type_test(const char *filename, char *type)
{
	if (strlen(filename)-strlen(type)>0)
	{
	gchar ext[4];
	//printf("filename=%s\n",filename+(strlen(filename)-3));
	strncpy(ext,filename+(strlen(filename)-strlen(type)),strlen(type));
	for (int k=0;k<=strlen(type);k++) ext[k]=g_ascii_toupper(ext[k]);
	for (int k=0;k<=strlen(type);k++) type[k]=g_ascii_toupper(type[k]);
	ext[3]=0;
	//printf("ext=%s\n",ext);
	if (strcmp(ext,type)==0)
		return TRUE;
	else
		return FALSE;
	} else
	{
		// длина имени файла меньше, чем длина предполагаемого расширения файла.
		return FALSE;
	}
}
