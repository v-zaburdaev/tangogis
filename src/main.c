#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
 
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"
#include "init.h"
#include "callbacks.h"
#include "globals.h"

#define G_THREADS_ENABLED

int
main (int argc, char *argv[])
{
	
#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif


  gtk_set_locale ();
	
  if (!g_thread_supported ()) g_thread_init (NULL);
  gdk_threads_init ();
  gdk_threads_enter ();


  gtk_init (&argc, &argv);
  
  setlocale (LC_NUMERIC, "C");
	
  add_pixmap_directory (PACKAGE_DATA_DIR "" PACKAGE "pixmaps");
  printf("%s, %s",PACKAGE_DATA_DIR, PACKAGE);


  global_server	= g_strdup("127.0.0.1");
  global_port	= g_strdup("2947");


	char *main_interface_file = g_strconcat(INTERFACE_INSTALL_INTERFACE_PATH,"interface.ui",NULL);
	printf("\ninterface file - %s\n",main_interface_file);
	if (!g_file_test (main_interface_file, G_FILE_TEST_EXISTS)) 
	{
		main_interface_file = g_strconcat(INTERFACE_NONINSTALL_INTERFACE_PATH,"interface.ui",NULL);
	}
	if (!g_file_test (main_interface_file, G_FILE_TEST_EXISTS)) 
	{
		printf ("\n\n\nInterface file not found\n\n\n");
		return -10;
	}
	GError* error = NULL;
	interface = gtk_builder_new ();
	if (!gtk_builder_add_from_file (interface, main_interface_file, &error))
	  {
		g_warning ("Couldn't load builder file: %s", error->message);
		g_error_free (error);
		return -20;
	  }
	if (interface)
	{
		g_free(main_interface_file);
		pre_init();
		window1 = create_window1 ();
		gtk_builder_connect_signals(interface,NULL);
	}
	else
	{
		printf ("\n\n\nfile \"interface.ui\" not found\n\n\n");
		return -10;
	}


//-----------geometry add-----------------------
	int temp;
	temp=g_key_file_get_integer(global_tangogis_config,"window size & position","main_window_width",&error);
	if (error)
		g_warning ("Couldn't load window position: %s", error->message);
	else
		window1_w=temp;

	temp=g_key_file_get_integer(global_tangogis_config,"window size & position","main_window_height",&error);
	if (error)
		g_warning ("Couldn't load window position: %s", error->message);
	else
		window1_h=temp;
	temp=g_key_file_get_integer(global_tangogis_config,"window size & position","main_window_x_pos",&error);
	if (error)
		g_warning ("Couldn't load window position: %s", error->message);
	else
		window1_x=temp;
	temp=g_key_file_get_integer(global_tangogis_config,"window size & position","main_window_y_pos",&error);
	if (error)
		g_warning ("Couldn't load window position: %s", error->message);
	else
		window1_y=temp;

	int geometry_flag=0;
//	if (argc>1)
//	{
		int i;
		for (i=1; i<argc; i++)
		{
			if (strcmp(argv[i], "-fullscreen") == 0)
			{
				on_button1_clicked(GTK_BUTTON(window1), NULL);
				break;
			}
			if (strcmp(argv[i], "-geometry") == 0)
			{
				if (i==argc-1)
				{
					printf ("USAGE -geometry option with argument [WxH][+x+y]\n");
					return 1;
				}
				char ** temp,**temp1;
				temp=g_strsplit(argv[i+1],"x",2);
				if (!temp[0] || !temp[1])
				{
					printf ("incorrect --geometry option usage\n");
					return 1;
				}
				window1_w=atoi(temp[0]);
				temp1=g_strsplit(temp[1],"+",3);
				if (!temp1[0] || !temp1[1] || !temp1[2])
				{
					printf ("incorrect --geometry option usage\n");
					return 1;
				}
				window1_h=atoi(temp1[0]);
				window1_x=atoi(temp1[1]);
				window1_y=atoi(temp1[2]);
				g_strfreev(temp);
				g_strfreev(temp1);
				printf ("width = %d, height = %d, x = %d, y = %d\n",window1_w,window1_h,window1_x,window1_y);
				geometry_flag = 1;
				gtk_window_resize(GTK_WINDOW(window1), window1_w, window1_h);
				gtk_window_move(GTK_WINDOW(window1),window1_x,window1_y);
			}
		}
		if (!geometry_flag)
		{
			gtk_window_resize(GTK_WINDOW(window1), window1_w, window1_h);
			gtk_window_move(GTK_WINDOW(window1),window1_x,window1_y);
		}
		g_key_file_set_integer(global_tangogis_config,"window size & position","main_window_width",window1_w);
		g_key_file_set_integer(global_tangogis_config,"window size & position","main_window_height",window1_h);
		g_key_file_set_integer(global_tangogis_config,"window size & position","main_window_x_pos",window1_x);
		g_key_file_set_integer(global_tangogis_config,"window size & position","main_window_y_pos",window1_y);
//	}
  gtk_widget_show (window1);

//-----------geometry add-----------------------
  window2 = create_window2();
  window3 = create_window3();
  menu1 = create_menu1();

  
  init();
  
  gtk_main ();
  
  gdk_threads_leave ();
  
  return 0;
}
