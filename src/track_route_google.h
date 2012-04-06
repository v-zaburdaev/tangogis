/*
 * track_route_google.h
 *
 *  Created on: 04.03.2012
 *      Author: vz
 */

#ifndef TRACK_ROUTE_GOOGLE_H_
#define TRACK_ROUTE_GOOGLE_H_

char * my_curl_get(char *url);
void gpolyline_decode(gchar * bytes,gchar* levels);
void route_parse(char * xml);

#endif /* TRACK_ROUTE_GOOGLE_H_ */
