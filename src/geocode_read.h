/*
 * google_geocode.h
 *
 *  Created on: 21.02.2012
 *      Author: vz
 */

#ifndef GEOCODE_GOOGLE_H_
#define GEOCODE_GOOGLE_H_



#endif /* GOOGLE_GEOCODE_H_ */
#include <yajl/yajl_parse.h>
#include <yajl/yajl_gen.h>


void foreach_hash(gpointer key,
        gpointer value,
        gpointer user_data);

void * get_google_geocode_by_point(float lat,float lon);
void * get_yandex_geocode_by_point(float lat,float lon);

size_t
google_geocode_cb_write_func(void *ptr, size_t size, size_t nmemb, void * userdata);
size_t
google_geocode_cb_read_func (void *ptr, size_t size, size_t nmemb, FILE *stream);

static yajl_callbacks callbacks;

//static int reformat_null(void * ctx);

//static int reformat_boolean(void * ctx, int boolean);
static int reformat_number(void * ctx, const char * s, unsigned int l);
static int reformat_string(void * ctx, const unsigned char * stringVal,
                           unsigned int stringLen);
static int reformat_map_key(void * ctx, const unsigned char * stringVal,
                            unsigned int stringLen);
static int reformat_start_map(void * ctx);
static int reformat_end_map(void * ctx);
static int reformat_start_array(void * ctx);
static int reformat_end_array(void * ctx);







