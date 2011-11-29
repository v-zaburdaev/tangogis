#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
 
#include <locale.h>
#include <string.h>
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
	
  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");
  printf("%s, %s",PACKAGE_DATA_DIR, PACKAGE);


  global_server	= g_strdup("127.0.0.1");
  global_port	= g_strdup("2947");


	char *main_interface_file = g_strconcat(INTERFACE_INSTALL_INTERFACE_PATH,"interface.glade");
	interface = glade_xml_new( main_interface_file, NULL, NULL);
	if (!interface)
	{
		main_interface_file = g_strconcat(INTERFACE_NONINSTALL_INTERFACE_PATH,"interface.glade");
		printf("interface file - %s\n",main_interface_file);
		interface = glade_xml_new(main_interface_file, NULL, NULL);
	}
	if (interface)
	{
		free(main_interface_file);
		pre_init();
		window1 = create_window1 ();
		glade_xml_signal_autoconnect(interface);
	}
	else
	{
		printf ("\n\n\nfile \"interface.glade\" not found\n\n\n");
		return -10;
	}


//-----------geometry add-----------------------
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
				int  w,h,x,y;
				char ** temp,**temp1;
				temp=g_strsplit(argv[i+1],"x",2);
				if (!temp[0] || !temp[1])
				{
					printf ("incorrect --geometry option usage\n");
					return 1;
				}
				w=atoi(temp[0]);
				temp1=g_strsplit(temp[1],"+",3);
				if (!temp1[0] || !temp1[1] || !temp1[2])
				{
					printf ("incorrect --geometry option usage\n");
					return 1;
				}
				h=atoi(temp1[0]);
				x=atoi(temp1[1]);
				y=atoi(temp1[2]);
				g_strfreev(temp);
				g_strfreev(temp1);
				printf ("width = %d, height = %d, x = %d, y = %d\n",w,h,x,y);
				geometry_flag = 1;
				gtk_window_resize(GTK_WINDOW(window1), w, h);
				gtk_window_move(GTK_WINDOW(window1),x,y);
			}
		}
		if (!geometry_flag)
		{
			gtk_window_resize(GTK_WINDOW(window1), 320, 480);
			gtk_window_move(GTK_WINDOW(window1),350,100);
		}
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
