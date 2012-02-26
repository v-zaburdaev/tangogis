/*
 * google_geocode.c
 *
 *  Created on: 21.02.2012
 *      Author: vz
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <glib.h>
#include <curl/curl.h>
#include <yajl/yajl_parse.h>
#include <yajl/yajl_gen.h>
#include "globals.h"
#include "geocode_read.h"



struct MemoryStruct {
  char *memory;
  size_t size;
};

GHashTable *hash;

int lvl,maplvl;
char * path[20];

char *answer;
char *tmp;


int array_num[20],map_num[20];

yajl_handle hand;
yajl_gen g;
yajl_status yajl_stat;
void * get_yandex_geocode_by_point(float lat,float lon)
{
	//http://geocode-maps.yandex.ru/1.x/?geocode=%f,%f&format=json&key=AGb1RU8BAAAAuqcaSQIAlBKg-HJK6XT18hCtvajy2bwUNB8AAAAAAAAAAAC_fb5Vj7YlobpzSJGPpLtx3xuxIg==
	if (host_failed) return NULL;
	CURL *curl;
	answer=NULL;
	struct MemoryStruct chunk;

	chunk.memory = malloc(1);  /* will be grown as needed by the realloc above */
	chunk.size = 0;    /* no data at this point */

	CURLcode res;
	char err_buffer[CURL_ERROR_SIZE+1]="";
	for(int i=0;i<=20;i++)
	{
		array_num[i]=0;
		map_num[i]=0;
		if (path[i]) free(path[i]);
	}

	lvl=0;
	char url[2048];

	sprintf(url,"http://geocode-maps.yandex.ru/1.x/?geocode=%f,%f&format=json&key=AGb1RU8BAAAAuqcaSQIAlBKg-HJK6XT18hCtvajy2bwUNB8AAAAAAAAAAAC_fb5Vj7YlobpzSJGPpLtx3xuxIg==",lon,lat);
	printf("%f, %f  url=%s\n",lon,lat,url);
	 yajl_gen_config conf={1," "};

	 //size_t rd;
	 yajl_parser_config cfg = { 1, 1 };

	curl = curl_easy_init();
	if (curl)
	{
		 g=yajl_gen_alloc(&conf,NULL);
		 hand = yajl_alloc(&callbacks, &cfg, NULL, (void *) g);

		curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, \
				"libcurl-agent/1.0 | tangogps " VERSION " | " __VERSION__);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,	 google_geocode_cb_write_func);
		//curl_easy_setopt(curl, CURLOPT_READFUNCTION,	 google_geocode_cb_read_func);
		curl_easy_setopt(curl, CURLOPT_NOPROGRESS, TRUE);
		//curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, cb_progress_func);
		//curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, Bar);
		curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, err_buffer);
		curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1);
		res = curl_easy_perform(curl);
		if (res!=0)
		{
		printf("Error");

		} else
		{
			printf("%s",chunk.memory);


					 hash=g_hash_table_new(g_direct_hash,g_str_equal);
//						array_num=0;map_num=0;
						 lvl=0;
						 maplvl=0;
					 yajl_handle hand;
					 yajl_gen_config conf={1," "};
					 yajl_gen g;
					 yajl_status stat;
					 //size_t rd;
					 yajl_parser_config cfg = { 1, 1 };

					 g=yajl_gen_alloc(&conf,NULL);
					 hand = yajl_alloc(&callbacks, &cfg, NULL, (void *) g);
  		             stat = yajl_parse(hand, chunk.memory, chunk.size);

					if (stat != yajl_status_ok &&
						stat != yajl_status_insufficient_data)
					{
						//fprintf(stderr, (const char *) str);
						//yajl_free_error(hand, str);
					} else {
						const unsigned char * buf;
						unsigned int len;
						yajl_gen_get_buf(g, &buf, &len);
						yajl_gen_clear(g);
					}


					yajl_gen_free(g);
					yajl_free(hand);

//					if (g_hash_table_find(hash,find_hash,"/status[1]"))
//					{
						g_hash_table_foreach(hash,foreach_hash,"/response/GeoObjectCollection/featureMember/GeoObject/metaDataProperty/GeocoderMetaData/text");

						printf("addr=%s",answer);
						return answer;
//					}
		}

	}

return NULL;
}


void * get_google_geocode_by_point(float lat,float lon)
{
	//http://maps.googleapis.com/maps/api/geocode/json?latlng=40.714224,-73.961452&sensor=true_or_false
	if (host_failed) return NULL;
	CURL *curl;
	answer=NULL;
	struct MemoryStruct chunk;

	chunk.memory = malloc(1);  /* will be grown as needed by the realloc above */
	chunk.size = 0;    /* no data at this point */

	CURLcode res;
	char err_buffer[CURL_ERROR_SIZE+1]="";
	for(int i=0;i<=10;i++)
	{
		array_num[i]=0;
		map_num[i]=0;
		if (path[i]) free(path[i]);
	}

	lvl=0;
	char url[2048];
	sprintf(url,"http://maps.googleapis.com/maps/api/geocode/json?latlng=%f,%f&sensor=true&region=ru&language=ru",lat,lon);
	printf("url=%s\n",url);
	 yajl_gen_config conf={1," "};

	 //size_t rd;
	 yajl_parser_config cfg = { 1, 1 };

	curl = curl_easy_init();
	if (curl)
	{
		 g=yajl_gen_alloc(&conf,NULL);
		 hand = yajl_alloc(&callbacks, &cfg, NULL, (void *) g);

		curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3);
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, \
				"libcurl-agent/1.0 | tangogps " VERSION " | " __VERSION__);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,	 google_geocode_cb_write_func);
		//curl_easy_setopt(curl, CURLOPT_READFUNCTION,	 google_geocode_cb_read_func);
		curl_easy_setopt(curl, CURLOPT_NOPROGRESS, TRUE);
		//curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, cb_progress_func);
		//curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, Bar);
		curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, err_buffer);
		curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1);
		res = curl_easy_perform(curl);
		if (res!=0)
		{
		printf("Error");

		} else
		{
			printf("%s",chunk.memory);


					 hash=g_hash_table_new(g_direct_hash,g_str_equal);
//						array_num=0;map_num=0;
						 lvl=0;
						 maplvl=0;
					 yajl_handle hand;
					 yajl_gen_config conf={1," "};
					 yajl_gen g;
					 yajl_status stat;
					 //size_t rd;
					 yajl_parser_config cfg = { 1, 1 };

					 g=yajl_gen_alloc(&conf,NULL);
					 hand = yajl_alloc(&callbacks, &cfg, NULL, (void *) g);
  		             stat = yajl_parse(hand, chunk.memory, chunk.size);

					if (stat != yajl_status_ok &&
						stat != yajl_status_insufficient_data)
					{
						//fprintf(stderr, (const char *) str);
						//yajl_free_error(hand, str);
					} else {
						const unsigned char * buf;
						unsigned int len;
						yajl_gen_get_buf(g, &buf, &len);
						yajl_gen_clear(g);
					}


					yajl_gen_free(g);
					yajl_free(hand);

///					if (g_hash_table_find(hash,find_hash,"/status[1_6]"))
//					{
						g_hash_table_foreach(hash,foreach_hash,"/results/formatted_address");
						printf("addr=%s",answer);
						return answer;
//					}
		}

	}

return NULL;
}

void foreach_hash(gpointer key,
        gpointer value,
        gpointer user_data)
        {

	if (strcmp(key,user_data)==0)
			{
				//printf("hash key=%s  value=%s\n",key,value);
				//char * tmp;
				if (answer!=NULL)
				{
					if(strlen(answer)<strlen(value))
					{
						answer=malloc(strlen(value));
						strcpy(answer,value);
					}
				} else
				{
					answer=malloc(strlen(value));
					strcpy(answer,value);
				}

			} else
			{
				//printf("!hash key=%s  value=%s\n",key,value);

			}
return;
        }








size_t
google_geocode_cb_write_func(void *ptr, size_t size, size_t nmemb,void * userp)
{

	  size_t realsize = size * nmemb;
	  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

	  mem->memory = realloc(mem->memory, mem->size + realsize + 1);
	  if (mem->memory == NULL) {
	    /* out of memory! */
	    printf("not enough memory (realloc returned NULL)\n");
	    exit(EXIT_FAILURE);
	  }

	  memcpy(&(mem->memory[mem->size]), ptr, realsize);
	  mem->size += realsize;
	  mem->memory[mem->size] = 0;

	  return realsize;
}

/*
size_t
google_geocode_cb_read_func (void *ptr, size_t size, size_t nmemb, FILE *stream)
{
//	printf("readcurl\n" );
//	printf("%d\n",stream);
	return fread(ptr, size, nmemb, stream);
}
*/

int
google_geocode_cb_progress_func(GtkWidget *Bar,
                     double t,
                     double d,
                     double ultotal,
                     double ulnow)
{
  //printf("progress: %d / %d (%.0f%%)\n", d, t, d*100.0/t);

  return 0;


}



char * fullpath(char *path[])
{
//printf("Fullpath\n");
		char *tm=malloc(255);
		char *ret="";
	    for (int i=1;i<=lvl;i++)
	    {
		//printf("/%s",path[i]);
	    sprintf(tm,"%s/%s",ret,path[i]);
	    ret=tm;

	    }
	    return ret;
}

static yajl_callbacks callbacks = {
    NULL,
    NULL,
    NULL,
    NULL,
    reformat_number,
    reformat_string,
    reformat_start_map,
    reformat_map_key,
    reformat_end_map,
    reformat_start_array,
    reformat_end_array
};
/*
static int reformat_null(void * ctx)
{
	printf("reformat_null \n");
    return 1;
}

static int reformat_boolean(void * ctx, int boolean)
{
    return 1;
}
*/
static int reformat_number(void * ctx, const char * s, unsigned int l)
{
    //map_num[maplvl]++;
    char *st=malloc(l+1);
    memcpy(st,s,l);
    st[l]=0;
    printf("%s = %s\n",fullpath(path),st);
    g_hash_table_insert(hash,fullpath(path),st);
    //free (st); //??
    return 1;
}

static int reformat_string(void * ctx, const unsigned char * stringVal,
                           unsigned int stringLen)
{
	//printf("reformat_string\n");
    //map_num[maplvl]++;
    char *tmp=malloc(stringLen+1);
    strncpy(tmp,stringVal,stringLen);
    tmp[stringLen]=0;
    printf("%s : %s\n",fullpath(path),tmp);
    g_hash_table_insert(hash,fullpath(path),tmp);
    //free (tmp); //??
    return 1;
}

static int reformat_map_key(void * ctx, const unsigned char * stringVal,
                            unsigned int stringLen)
{

    char *tmp=malloc(stringLen+1);
   	snprintf(tmp,stringLen+1,"%s",stringVal);
   	path[lvl]=malloc(stringLen+9);
   	//sprintf(path[lvl],"%s[%d]",tmp,array_num[lvl]);
   	sprintf(path[lvl],"%s",tmp);
   	//path[lvl][stringLen+2]=0;

    //printf("map key %d = %s \n",lvl,path[lvl]);
    return 1;
}

static int reformat_start_map(void * ctx)
{
//    printf("start map %d\n",map_num[lvl]);
    lvl++;
    map_num[maplvl]++;
    maplvl++;

    return 1;
}


static int reformat_end_map(void * ctx)
{
    //printf("end\n");
	lvl--;
	map_num[maplvl]--;
	maplvl--;

    return 1;
}

static int reformat_start_array(void * ctx)
{
	array_num[lvl]++;

    return 1;
}

static int reformat_end_array(void * ctx)
{
	//printf("end array\n");
	//lvl--;
	//array_num[lvl]=0;
    return 1;
}




/*
json_test()
{
	struct stat filestat;
	char * filename="/home/vz/workspace/json1.txt";
	FILE *f=fopen(filename,"r");

if (f!=0)
{
	//int fd=fileno(f);
	if (stat(filename,&filestat)>0) return 1;

array_num=0;
lvl=0;
	char geocode [filestat.st_size];


		 static unsigned char fileData[65536];
		 //printf("geocode=%s",geocode);
		 yajl_handle hand;
		 yajl_gen_config conf={1," "};
		 yajl_gen g;
		 yajl_status stat;
		 size_t rd;
		 yajl_parser_config cfg = { 1, 1 };

		 g=yajl_gen_alloc(&conf,NULL);
		 hand = yajl_alloc(&callbacks, &cfg, NULL, (void *) g);
		 int done=0;
		    while (!done) {
		        rd = fread((void *) fileData, 1, sizeof(fileData) - 1, f);

		        if (rd == 0) {
		            if (!feof(f)) {
		                fprintf(stderr, "error on file read.\n");
		                break;
		            }
		            done = 1;
		        }
		        fileData[rd] = 0;

		        if (done)
		            //parse any remaining buffered data
		            stat = yajl_parse_complete(hand);
		        else
		            //read file data, pass to parser
		            stat = yajl_parse(hand, fileData, rd);

		        if (stat != yajl_status_ok &&
		            stat != yajl_status_insufficient_data)
		        {
		            unsigned char * str = yajl_get_error(hand, 1, fileData, rd);
		            fprintf(stderr, (const char *) str);
		            yajl_free_error(hand, str);
		        } else {
		            const unsigned char * buf;
		            unsigned int len;
		            yajl_gen_get_buf(g, &buf, &len);
		            //fwrite(buf, 1, len, stdout);
		            yajl_gen_clear(g);
		        }
		    }

		    yajl_gen_free(g);
		    yajl_free(hand);





	fclose(f);





	} else
	{
		printf("file not found");
	}
}
*/
