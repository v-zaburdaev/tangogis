/*
 * osd.c
 *
 *  Created on: 24.02.2012
 *      Author: vz
 */
#include <glib.h>
#include <math.h>

#include "globals.h"
#include "osd.h"

#define HOST_FAIL_INDICATOR 1
#define HOST_FAIL_INDICATOR_WIDTH 32
#define HOST_FAIL_INDICATOR_HEIGHT 32
static gboolean host_fail_indicator_mouseover;

static GHashTable *osdcallbacks;

GdkPixbuf *pixbuf_hostfail_indicator;
GError	   *error = NULL;
void osd_init()
{
	osdcallbacks=g_hash_table_new(g_str_hash,g_str_equal); /// TODO Написать hash func, возможно понадобится, чтоб под кнопками ничего не нарисовать и в этот хеш поместить
	GdkPixbuf * tmp = gdk_pixbuf_new_from_file (
			PACKAGE_PIXMAPS_DIR "Earth-Stop-icon.png",
					&error);

	pixbuf_hostfail_indicator = gdk_pixbuf_scale_simple(tmp,HOST_FAIL_INDICATOR_WIDTH,HOST_FAIL_INDICATOR_HEIGHT,GDK_INTERP_BILINEAR);
	host_fail_indicator_mouseover=FALSE;
}

void osd_mouse_over(int x,int y)
{
	char *tmp=malloc(12);

	sprintf(tmp,"%d,%d",x,y);
//	printf("FIND\n");
	g_hash_table_find(osdcallbacks,osdcallbacks_find,tmp);
}

void osdcallbacks_find  (gpointer key,
        gpointer value,
        gpointer user_data)
{
		int x,y,x1,y1;
		int mx,my;

//		printf("key=%s, value=%d, %s\n",(char*)key,value,user_data);

		sscanf((char*)key,"%d,%d,%d,%d",&x,&y,&x1,&y1);
		sscanf((char*)user_data,"%d,%d",&mx,&my);

		//printf("x=%d y=%d x1=%d y1=%d mx=%d my=%d\n",x,y,x1,y1,mx,my);

		if ((x<mx && mx<x1) && (y<my && my<y1))
		{
			if (value==HOST_FAIL_INDICATOR)
			{
				/// тут вызов идет с дребезгом, то есть на каждое движение мыши
				//printf("HOST_FAIL_INDICATOR\n");


			}


		}


}


gboolean osd_mouse_click(int x,int y)
{
	char *tmp=malloc(10);
	sprintf(tmp,"%d,%d",x,y);
	printf("hash count=%d\n",g_hash_table_size(osdcallbacks));
	gpointer find = g_hash_table_find(osdcallbacks,osdcallbacks_click,tmp);

	free(tmp);
	if (find!=NULL)
	{
		return TRUE;
	}
	return FALSE;
}

gboolean osdcallbacks_click  (gpointer key,
        gpointer value,
        gpointer user_data)
{
		int x,y,x1,y1;
		int mx,my;
		printf("key=%s, value=%d, %s\n",(char*)key,value,user_data);
		sscanf((char*)key,"%d,%d,%d,%d",&x,&y,&x1,&y1);
		sscanf((char*)user_data,"%d,%d",&mx,&my);

//		printf("x=%d y=%d x1=%d y1=%d mx=%d my=%d\n",x,y,x1,y1,mx,my);

		if ((x<mx && mx<x1) && (y<my && my<y1))
		{
			if (value==HOST_FAIL_INDICATOR)
			{
				/// тут вызов идет с дребезгом, то есть на каждое движение мыши
				printf("HOST_FAIL_INDICATOR CLICKED!\n");

			}

			return TRUE;
		}
printf("false\n");
return FALSE;
}

void osd_hostfail_indicator_no_icon(GtkWidget* widget)
{
	//printf("osd all\n");
	int xmax=map_drawable->allocation.width;
	int ymax=map_drawable->allocation.height;

	cairo_t * ct = gdk_cairo_create(widget->window);

	cairo_set_antialias (ct,CAIRO_ANTIALIAS_SUBPIXEL);
	cairo_set_line_cap(ct,CAIRO_LINE_CAP_ROUND);
	cairo_set_line_width(ct,1);
	if (host_failed)
	{
	cairo_set_source_rgba(ct,255,0,0,1);
	} else
	{
		cairo_set_source_rgba(ct,0,255,0,1);
	}
	cairo_arc(ct,xmax-(HOST_FAIL_INDICATOR_WIDTH/2+3),HOST_FAIL_INDICATOR_HEIGHT/2+3,16,0,2*M_PI);
	cairo_fill(ct);
	cairo_stroke (ct);




	char *key=malloc(22);
	sprintf(key,"%d,%d,%d,%d",xmax-(HOST_FAIL_INDICATOR_WIDTH+3),3,xmax-2,35);
	g_hash_table_insert (osdcallbacks, key,HOST_FAIL_INDICATOR);

}



void osd_hostfail_indicator(GtkWidget* widget)
{
	if(host_failed)
	{
		if (pixbuf_hostfail_indicator!=NULL)
		{
			int xmax=map_drawable->allocation.width;
			int ymax=map_drawable->allocation.height;
			GError		*error = NULL;
			GdkGC		*gc_map = NULL;

			if (host_fail_indicator_mouseover)
			{

				gdk_draw_pixbuf (
						widget->window,
						gc_map,
						pixbuf_hostfail_indicator,
						0,0,
						xmax-HOST_FAIL_INDICATOR_WIDTH-6,6,
						HOST_FAIL_INDICATOR_WIDTH,HOST_FAIL_INDICATOR_HEIGHT,
						GDK_RGB_DITHER_NONE, 0, 0);

			} else
			{

			gdk_draw_pixbuf (
					widget->window,
					gc_map,
					pixbuf_hostfail_indicator,
					0,0,
					xmax-HOST_FAIL_INDICATOR_WIDTH-3,3,
					HOST_FAIL_INDICATOR_WIDTH,HOST_FAIL_INDICATOR_HEIGHT,
					GDK_RGB_DITHER_NONE, 0, 0);

			}

			gtk_widget_queue_draw_area (
						widget->window,
						xmax-HOST_FAIL_INDICATOR_WIDTH-3,3,
						HOST_FAIL_INDICATOR_WIDTH,HOST_FAIL_INDICATOR_HEIGHT);

			char *key=malloc(22);
			sprintf(key,"%d,%d,%d,%d",xmax-HOST_FAIL_INDICATOR_WIDTH-3,3,xmax-2,3+HOST_FAIL_INDICATOR_HEIGHT);
			if (g_hash_table_lookup(osdcallbacks,key)==NULL)
			{
			g_hash_table_insert (osdcallbacks, key,HOST_FAIL_INDICATOR);
			}
		} else
		{

			osd_hostfail_indicator_no_icon(widget);

		}
	}

}


