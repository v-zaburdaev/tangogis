/*
 * track_route_google.c
 *
 *  Created on: 04.03.2012
 *      Author: vz
 */

#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <ctype.h>
#include "globals.h"

#include <curl/curl.h>
#include "track_route_google.h"
#include "converter.h"

struct MemoryStruct {
  char *memory;
  size_t size;
};
static char *path[10];
//static char *last_element;
static int lvl;
//static int array_num;
static int count;

int cnt[32];

route_step_t *step;
//track_data_t *track_out;



void get_google_route(waypoint_t *startpoint, waypoint_t *endpoint, GSList *waypoints)
{
  loading=TRUE;
	gchar * url=malloc(2048);
	sprintf(url,"http://maps.googleapis.com/maps/api/directions/xml?mode=driving&origin=%f,%f&destination=%f,%f&sensor=false",startpoint->lat,startpoint->lon,endpoint->lat,endpoint->lon);
//	for(list=trackpoints;list!=NULL;list=list->next)
//	{

//	}
	printf("%s\n",url);
	char *m = my_curl_get(url);


	if (m!=NULL)
	{
		if (strlen(m)>0)
		{
		route_parse(m);
		}
	}
	printf("route_track count=%d\n",g_slist_length(route_track->trackpoints));
	loading=FALSE;
	free(url);
}


char *trim_spaces(char *str)
{
   char *out = str;
   int len = strlen(str);
   for (int i=0; i<len && isspace(str[i]); i++, out++);
   for (int i=len-1; i>=0 && isspace(str[i]); str<i>=0, i--);
   return out;
}

char * myfullpath()
{
	char *tm,*ret;
		ret=malloc(100);
		ret[0]=0;
		tm=malloc(100);

		//printf("PATH=");
	    for (int i=1;i<=lvl;i++)
	    {
	    //printf("/%s\n",path[i]);
	    sprintf(tm,"%s/%s",ret,path[i]);
	    ret=tm;

	    }
	    //printf("%s\n",ret);
	    return ret;
}


void *route_mystart_element (GMarkupParseContext *context,
     const gchar         *element_name,
     const gchar        **attribute_names,
     const gchar        **attribute_values,
     gpointer             user_data,
     GError             **error)
     {

		lvl++;
		cnt[lvl]++;

		path[lvl]=malloc(sizeof(element_name)+1);
		sprintf(path[lvl],"%s", element_name);

	   // last_element=element_name;

		if (strcmp(element_name,"step")==0)
		{
			// start step
			printf("new step\n");
			step=g_new(route_step_t,1);
			step->startpoint=g_new(waypoint_t,1);
			step->endpoint=g_new(waypoint_t,1);
		}

		return NULL;
     }
void *route_myend_element    (GMarkupParseContext *context,
                          const gchar         *element_name,
                          gpointer             user_data,
                          GError             **error)
{

	lvl--;

	if (strcmp(element_name,"step")==0)
	{
		printf("save step\n");
		 route_track->steps=g_slist_append(route_track->steps,step);
	}
return NULL;
}

  /* Called for character data */
  /* text is not nul-terminated */
void *route_mytext(GMarkupParseContext *context,
                          const gchar         *text,
                          gsize                text_len,
                          gpointer             user_data,
                          GError             **error)
{

	char * trimtext=trim_spaces(text);
	char *f_path=myfullpath();

	if (strlen(trimtext)>0)
	{
		//count++;
		//printf("%d %s : '%s' %d\n",count,f_path,trimtext,text_len);
		if (strcmp(f_path,"/DirectionsResponse/route/leg/step/start_location/lat")==0)
		{
			//if (step->startpoint==NULL) step->startpoint=g_new (waypoint_t,1);
		//	printf("startpoint->lat=%s\n",trimtext);
			step->startpoint->lat=deg2rad(atof(trimtext));

		}
		if (strcmp(f_path,"/DirectionsResponse/route/leg/step/start_location/lng")==0)
		{
			//if (step->startpoint==NULL) step->startpoint=g_new (waypoint_t,1);
		//	printf("startpoint->lon=%s\n",trimtext);
			step->startpoint->lon=deg2rad(atof(trimtext));

		}
		if (strcmp(f_path,"/DirectionsResponse/route/leg/step/end_location/lat")==0)
		{
			//if (step->endpoint==NULL) step->endpoint=g_new (waypoint_t,1);
		//	printf("endpoint->lat=%s\n",trimtext);
			step->endpoint->lat=deg2rad(atof(trimtext));

		}
		if (strcmp(f_path,"/DirectionsResponse/route/leg/step/end_location/lng")==0)
		{
			//if (step->startpoint==NULL) step->endpoint=g_new (waypoint_t,1);
		//	printf("endpoint->lon=%s\n",trimtext);
			step->endpoint->lon=deg2rad(atof(trimtext));

		}
		if (strcmp(f_path,"/DirectionsResponse/route/leg/step/distance/value")==0)
		{
		//	printf("distance=%s\n",trimtext);
			step->distance=atof(trimtext);

		}
		if (strcmp(f_path,"/DirectionsResponse/route/leg/step/duration/value")==0)
		{
		//	printf("duration=%s\n",trimtext);
			step->duration=atof(trimtext);

		}
		 // /DirectionsResponse/route/leg/step/polyline/points
		if (strcmp(f_path,"/DirectionsResponse/route/leg/step/polyline/points")==0)
		{
		//	printf("polyline=%s\n",trimtext);
		}
		if (strcmp(f_path,"/DirectionsResponse/route/leg/step/html_instructions")==0)
				{
		//			printf("instructions=%s\n",trimtext);
					step->instructions=malloc(strlen(trimtext)+1);
					strcpy(step->instructions,trimtext);
				}


		 ///DirectionsResponse/route/bounds/southwest/lat
		if (strcmp(f_path,"/DirectionsResponse/route/bounds/southwest/lat")==0)
				{
		//			printf("max lat=%s\n",trimtext);
					route_track->max_lat=atof(trimtext);
				}
		if (strcmp(f_path,"/DirectionsResponse/route/bounds/southwest/lng")==0)
				{
		//			printf("max lon=%s\n",trimtext);
					route_track->max_lon=atof(trimtext);
				}
		if (strcmp(f_path,"/DirectionsResponse/route/bounds/northeast/lat")==0)
				{
		//			printf("min lat=%s\n",trimtext);
					route_track->min_lat=atof(trimtext);
				}
		if (strcmp(f_path,"/DirectionsResponse/route/bounds/northeast/lng")==0)
				{
		//			printf("min lon=%s\n",trimtext);
					route_track->min_lon=atof(trimtext);
				}
		///DirectionsResponse/route/leg/step/polyline/points
		if (strcmp(f_path,"/DirectionsResponse/route/leg/step/polyline/points")==0)
		                {
				        trackpoint_t *tmp=g_new(trackpoint_t,1);
					gpolyline_decode(trimtext,"");
//						for(GSList *list1=route_track->trackpoints;list1!=NULL;list1=list1->next)
//							{

						//	route_track->trackpoints=g_slist_append(route_track->trackpoints,list1->data);

							//memcpy (tmp , list1->data, sizeof(trackpoint_t));
							//printf("3\n");
							//tmp=list1->data;
							//printf("track : %f %f\n",tmp->lat,tmp->lon);


//							}
//						printf("4\n");
						}
	}
return NULL;
}


static GMarkupParser route_parser=
{
		route_mystart_element,
		route_myend_element,
		route_mytext,
		NULL,
		NULL
};

GError **error;
static gpointer *point;
//static gchar *path1;
//GHashTable hash;


void route_parse(char *parsexml)
{


	lvl=0;
	path[0]="/";
	count=0;
	for (int i=0;i>=32;i++) cnt[i]=0;
	//list=g_slist_alloc();
	if (route_track!=NULL)
	{
		if (route_track->trackpoints!=NULL)
		{
			if (g_slist_length(route_track->trackpoints)>0)
			{
				g_slist_free(route_track->trackpoints);
			}
		}
		if (route_track->steps!=NULL)
		{
			if (g_slist_length(route_track->steps)>0)
				{
					g_slist_free(route_track->steps);
				}
		}
	}
	route_track = g_new(track_data_t,1);
	route_track->steps=g_slist_alloc();
	route_track->trackpoints=g_slist_alloc();


	GMarkupParseContext * context=g_markup_parse_context_new        (&route_parser,
							 G_MARKUP_TREAT_CDATA_AS_TEXT,
							 point,
					         NULL);

//printf("xml=%s\nlen=%d",parsexml,strlen(parsexml));
	g_markup_parse_context_parse (context,parsexml,strlen(parsexml),error);



//	return route_track;
	return;
}



void gpolyline_decode(gchar * bytes,gchar* levels)
{
	//GSList *ret=g_slist_alloc();

		int length=strlen(bytes);
		int idx=0;
		int level_num=0;
		int final_lvl;
		//if (strlen(levels)!=(int)(length/8))
		//{
		//printf("Error - level num contains wroung count of data level_count=%d point_count=%d\n",strlen(levels),length);
		//}
		float latitude = 0;
	    float longitude = 0;
	    while (idx < length) {
	        char byte = 0;
	        int res = 0;
	        char shift = 0;

	        do {
	            byte = bytes[idx++] - 63;

	            res |= (byte & 0x1F) << shift;
	            shift += 5;
	        } while (byte >= 0x20);

	        float deltaLat = ((res & 1) ? ~(res >> 1) : (res >> 1));
	        latitude += deltaLat;



	        shift = 0;
	        res = 0;

	        do {
	            byte = bytes[idx++] - 0x3F;
	            res |= (byte & 0x1F) << shift;
	            shift += 5;
	        } while (byte >= 0x20);

	        float deltaLon = ((res & 1) ? ~(res >> 1) : (res >> 1));
	        longitude += deltaLon;

	        float finalLat = latitude * 1E-5;
	        float finalLon = longitude * 1E-5;
	        //final_lvl=levels[level_num++]-63;
	        final_lvl=0;
	        level_num++;
	        printf("lon: %f lat: %f level=%d\n",deg2rad(finalLon),deg2rad(finalLat),final_lvl);
	        trackpoint_t *tp;
	        tp=g_new(trackpoint_t,1);
	        tp->lat=deg2rad(finalLat);
	        tp->lon=deg2rad(finalLon);
	        tp->tpspeed=40;
	        route_track->trackpoints=g_slist_append(route_track->trackpoints,tp);

	       }
	    printf("count=%d\n",level_num);

}


size_t
google_route_cb_write_func(void *ptr, size_t size, size_t nmemb,void * userp)
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


char * my_curl_get(char *url)
{
	CURL *curl;
	struct MemoryStruct chunk;

		chunk.memory = malloc(1);  /* will be grown as needed by the realloc above */
		chunk.size = 0;    /* no data at this point */

		CURLcode res;
		char err_buffer[CURL_ERROR_SIZE+1]="";

		curl = curl_easy_init();

	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, \
				"libcurl-agent/1.0 | tangogps " VERSION " | " __VERSION__);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,	 google_route_cb_write_func);
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
//			printf("%s",chunk.memory);
		}
	} else
	{
		return NULL;
	}
	return chunk.memory;
}
