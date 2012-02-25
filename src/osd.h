/*
 * osd.h
 *
 *  Created on: 24.02.2012
 *      Author: vz
 */

#ifndef OSD_H_
#define OSD_H_

void * osd_all_callback();

void osd_hostfail_indicator(GtkWidget* widget);
void osd_hostfail_indicator_no_icon(GtkWidget* widget);


//void g_hash_table_find(osdcallbacks,osdcallbacks_find,NULL);

void osd_mouse_over(int x,int y);
void osdcallbacks_find  (gpointer key,    gpointer value,
    gpointer user_data);


gboolean osd_mouse_click(int x,int y);
gboolean osdcallbacks_click  (gpointer key,
        gpointer value,
        gpointer user_data);

#endif /* OSD_H_ */
