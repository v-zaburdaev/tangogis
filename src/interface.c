

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "globals.h"
#include "interface.h"
#include "support.h"


#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_window1 (void)
{
  GtkWidget *window1 = GTK_WIDGET (gtk_builder_get_object(interface, "window1"));
  GtkWidget *notebook1 = GTK_WIDGET (gtk_builder_get_object(interface, "notebook1"));
  GtkWidget *vbox1 = GTK_WIDGET (gtk_builder_get_object(interface, "vbox1"));
//  GtkWidget *toolbar1 = GTK_WIDGET (gtk_builder_get_object(interface, "toolbar1"));
//  GtkIconSize tmp_toolbar_icon_size;
//  GtkWidget *toolitem1 = GTK_WIDGET (gtk_builder_get_object(interface, "toolitem1"));
  GtkWidget *button1 = GTK_WIDGET (gtk_builder_get_object(interface, "button1"));
//  GtkWidget *toolitem2 = GTK_WIDGET (gtk_builder_get_object(interface, "toolitem2"));
  GtkWidget *button4 = GTK_WIDGET (gtk_builder_get_object(interface, "button4"));
//  GtkWidget *toolitem3 = GTK_WIDGET (gtk_builder_get_object(interface, "toolitem3"));
  GtkWidget *button5 = GTK_WIDGET (gtk_builder_get_object(interface, "button5"));
//  GtkWidget *toolitem5 = GTK_WIDGET (gtk_builder_get_object(interface, "toolitem5"));
  GtkWidget *button3 = GTK_WIDGET (gtk_builder_get_object(interface, "button3"));
//  GtkWidget *toolitem6 = GTK_WIDGET (gtk_builder_get_object(interface, "toolitem6"));
  GtkWidget *togglebutton1 = GTK_WIDGET (gtk_builder_get_object(interface, "togglebutton1"));
  GtkWidget *drawingarea1 = GTK_WIDGET (gtk_builder_get_object(interface, "drawingarea1"));
  GtkWidget *vscale1 = GTK_WIDGET (gtk_builder_get_object(interface, "vscale1"));
  GtkWidget *label4 = GTK_WIDGET (gtk_builder_get_object(interface, "label4"));
  GtkWidget *label1 = GTK_WIDGET (gtk_builder_get_object(interface, "label1"));
//  GtkWidget *scrolledwindow6 = GTK_WIDGET (gtk_builder_get_object(interface, "scrolledwindow6"));
//  GtkWidget *viewport4 = GTK_WIDGET (gtk_builder_get_object(interface, "viewport4"));
//  GtkWidget *hbox12 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox12"));
  GtkWidget *vbox4 = GTK_WIDGET (gtk_builder_get_object(interface, "vbox4"));
  GtkWidget *frame1 = GTK_WIDGET (gtk_builder_get_object(interface, "frame1"));
//  GtkWidget *vbox16 = GTK_WIDGET (gtk_builder_get_object(interface, "vbox16"));
  GtkWidget *alignment1 = GTK_WIDGET (gtk_builder_get_object(interface, "alignment1"));
  GtkWidget *table3 = GTK_WIDGET (gtk_builder_get_object(interface, "table3"));
  GtkWidget *label28 = GTK_WIDGET (gtk_builder_get_object(interface, "label28"));
  GtkWidget *label65 = GTK_WIDGET (gtk_builder_get_object(interface, "label65"));
  GtkWidget *label67 = GTK_WIDGET (gtk_builder_get_object(interface, "label67"));
  GtkWidget *label68 = GTK_WIDGET (gtk_builder_get_object(interface, "label68"));
  GtkWidget *label69 = GTK_WIDGET (gtk_builder_get_object(interface, "label69"));
  GtkWidget *label70 = GTK_WIDGET (gtk_builder_get_object(interface, "label70"));
  GtkWidget *label45 = GTK_WIDGET (gtk_builder_get_object(interface, "label45"));
  GtkWidget *label66 = GTK_WIDGET (gtk_builder_get_object(interface, "label66"));
  GtkWidget *hbox5 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox5"));
  GtkWidget *button15 = GTK_WIDGET (gtk_builder_get_object(interface, "button15"));
  GtkWidget *button8 = GTK_WIDGET (gtk_builder_get_object(interface, "button8"));
  GtkWidget *label47 = GTK_WIDGET (gtk_builder_get_object(interface, "label47"));
  GtkWidget *frame2 = GTK_WIDGET (gtk_builder_get_object(interface, "frame2"));
  GtkWidget *alignment2 = GTK_WIDGET (gtk_builder_get_object(interface, "alignment2"));
  GtkWidget *table4 = GTK_WIDGET (gtk_builder_get_object(interface, "table4"));
  GtkWidget *label41 = GTK_WIDGET (gtk_builder_get_object(interface, "label41"));
  GtkWidget *label32 = GTK_WIDGET (gtk_builder_get_object(interface, "label32"));
  GtkWidget *label38 = GTK_WIDGET (gtk_builder_get_object(interface, "label38"));
  GtkWidget *label33 = GTK_WIDGET (gtk_builder_get_object(interface, "label33"));
  GtkWidget *label39 = GTK_WIDGET (gtk_builder_get_object(interface, "label39"));
  GtkWidget *label36 = GTK_WIDGET (gtk_builder_get_object(interface, "label36"));
  GtkWidget *label42 = GTK_WIDGET (gtk_builder_get_object(interface, "label42"));
  GtkWidget *label35 = GTK_WIDGET (gtk_builder_get_object(interface, "label35"));
  GtkWidget *label30 = GTK_WIDGET (gtk_builder_get_object(interface, "label30"));
  GtkWidget *label31 = GTK_WIDGET (gtk_builder_get_object(interface, "label31"));
  GtkWidget *label37 = GTK_WIDGET (gtk_builder_get_object(interface, "label37"));
  GtkWidget *label43 = GTK_WIDGET (gtk_builder_get_object(interface, "label43"));
  GtkWidget *label48 = GTK_WIDGET (gtk_builder_get_object(interface, "label48"));
//  GtkWidget *label95 = GTK_WIDGET (gtk_builder_get_object(interface, "label95"));
  GtkWidget *label7 = GTK_WIDGET (gtk_builder_get_object(interface, "label7"));
//  GtkWidget *hbox13 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox13"));
  GtkWidget *frame7 = GTK_WIDGET (gtk_builder_get_object(interface, "frame7"));
  GtkWidget *alignment7 = GTK_WIDGET (gtk_builder_get_object(interface, "alignment7"));
//  GtkWidget *vbox17 = GTK_WIDGET (gtk_builder_get_object(interface, "vbox17"));
//  GtkWidget *label75 = GTK_WIDGET (gtk_builder_get_object(interface, "label75"));
  GtkWidget *hbox6 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox6"));
  GtkWidget *button18 = GTK_WIDGET (gtk_builder_get_object(interface, "button18"));
  GtkWidget *button19 = GTK_WIDGET (gtk_builder_get_object(interface, "button19"));
//  GtkWidget *label76 = GTK_WIDGET (gtk_builder_get_object(interface, "label76"));
  GtkWidget *hbox7 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox7"));
  GtkWidget *button20 = GTK_WIDGET (gtk_builder_get_object(interface, "button20"));
//  GtkWidget *label133 = GTK_WIDGET (gtk_builder_get_object(interface, "label133"));
  GtkWidget *button36 = GTK_WIDGET (gtk_builder_get_object(interface, "button36"));
//  GtkWidget *label77 = GTK_WIDGET (gtk_builder_get_object(interface, "label77"));
//  GtkWidget *label74 = GTK_WIDGET (gtk_builder_get_object(interface, "label74"));
//  GtkWidget *label94 = GTK_WIDGET (gtk_builder_get_object(interface, "label94"));
//  GtkWidget *label73 = GTK_WIDGET (gtk_builder_get_object(interface, "label73"));
  GtkWidget *hbox11 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox11"));
//  GtkWidget *scrolledwindow2 = GTK_WIDGET (gtk_builder_get_object(interface, "scrolledwindow2"));
//  GtkWidget *viewport2 = GTK_WIDGET (gtk_builder_get_object(interface, "viewport2"));
  GtkWidget *vbox5 = GTK_WIDGET (gtk_builder_get_object(interface, "vbox5"));
//  GtkWidget *button35 = GTK_WIDGET (gtk_builder_get_object(interface, "button35"));
//  GtkWidget *label132 = GTK_WIDGET (gtk_builder_get_object(interface, "label132"));
  GtkWidget *frame6 = GTK_WIDGET (gtk_builder_get_object(interface, "frame6"));
  GtkWidget *alignment6 = GTK_WIDGET (gtk_builder_get_object(interface, "alignment6"));
//  GtkWidget *vbox14 = GTK_WIDGET (gtk_builder_get_object(interface, "vbox14"));
//  GtkWidget *hbox17 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox17"));
//  GtkWidget *label101 = GTK_WIDGET (gtk_builder_get_object(interface, "label101"));
//  GtkWidget *label99 = GTK_WIDGET (gtk_builder_get_object(interface, "label99"));
  GtkWidget *hbox4 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox4"));
  GtkWidget *radiobutton1 = GTK_WIDGET (gtk_builder_get_object(interface, "radiobutton1"));
  GSList *radiobutton1_group = NULL;
  GtkWidget *radiobutton13 = GTK_WIDGET (gtk_builder_get_object(interface, "radiobutton13"));
//  GtkWidget *entry16 = GTK_WIDGET (gtk_builder_get_object(interface, "entry16"));
//  GtkWidget *label113 = GTK_WIDGET (gtk_builder_get_object(interface, "label113"));
//  GtkWidget *vbox8 = GTK_WIDGET (gtk_builder_get_object(interface, "vbox8"));
//  GtkWidget *hbox14 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox14"));
//  GtkWidget *button11 = GTK_WIDGET (gtk_builder_get_object(interface, "button11"));
//  GtkWidget *button23 = GTK_WIDGET (gtk_builder_get_object(interface, "button23"));
//  GtkWidget *alignment13 = GTK_WIDGET (gtk_builder_get_object(interface, "alignment13"));
//  GtkWidget *label97 = GTK_WIDGET (gtk_builder_get_object(interface, "label97"));
//  GtkWidget *label51 = GTK_WIDGET (gtk_builder_get_object(interface, "label51"));
//  GtkWidget *label61 = GTK_WIDGET (gtk_builder_get_object(interface, "label61"));
  GtkWidget *frame3 = GTK_WIDGET (gtk_builder_get_object(interface, "frame3"));
  GtkWidget *alignment3 = GTK_WIDGET (gtk_builder_get_object(interface, "alignment3"));
  GtkWidget *vbox6 = GTK_WIDGET (gtk_builder_get_object(interface, "vbox6"));
  GtkWidget *vbox7 = GTK_WIDGET (gtk_builder_get_object(interface, "vbox7"));
//  GtkWidget *label52 = GTK_WIDGET (gtk_builder_get_object(interface, "label52"));
//  GtkWidget *checkbutton3 = GTK_WIDGET (gtk_builder_get_object(interface, "checkbutton3"));
//  GtkWidget *checkbutton4 = GTK_WIDGET (gtk_builder_get_object(interface, "checkbutton4"));
//  GtkWidget *checkbutton5 = GTK_WIDGET (gtk_builder_get_object(interface, "checkbutton5"));
//  GtkWidget *label50 = GTK_WIDGET (gtk_builder_get_object(interface, "label50"));
  GtkWidget *frame4 = GTK_WIDGET (gtk_builder_get_object(interface, "frame4"));
  GtkWidget *alignment4 = GTK_WIDGET (gtk_builder_get_object(interface, "alignment4"));
//  GtkWidget *vbox9 = GTK_WIDGET (gtk_builder_get_object(interface, "vbox9"));
//  GtkWidget *vbox11 = GTK_WIDGET (gtk_builder_get_object(interface, "vbox11"));
//  GtkWidget *label54 = GTK_WIDGET (gtk_builder_get_object(interface, "label54"));
//  GtkWidget *checkbutton6 = GTK_WIDGET (gtk_builder_get_object(interface, "checkbutton6"));
//  GtkWidget *checkbutton7 = GTK_WIDGET (gtk_builder_get_object(interface, "checkbutton7"));
//  GtkWidget *checkbutton8 = GTK_WIDGET (gtk_builder_get_object(interface, "checkbutton8"));
//  GtkWidget *label53 = GTK_WIDGET (gtk_builder_get_object(interface, "label53"));
  GtkWidget *frame5 = GTK_WIDGET (gtk_builder_get_object(interface, "frame5"));
  GtkWidget *alignment5 = GTK_WIDGET (gtk_builder_get_object(interface, "alignment5"));
//  GtkWidget *vbox13 = GTK_WIDGET (gtk_builder_get_object(interface, "vbox13"));
//  GtkWidget *label100 = GTK_WIDGET (gtk_builder_get_object(interface, "label100"));
//  GtkWidget *table5 = GTK_WIDGET (gtk_builder_get_object(interface, "table5"));
//  GtkWidget *label57 = GTK_WIDGET (gtk_builder_get_object(interface, "label57"));
//  GtkWidget *label58 = GTK_WIDGET (gtk_builder_get_object(interface, "label58"));
//  GtkWidget *entry7 = GTK_WIDGET (gtk_builder_get_object(interface, "entry7"));
//  GtkWidget *entry8 = GTK_WIDGET (gtk_builder_get_object(interface, "entry8"));
//  GtkWidget *label60 = GTK_WIDGET (gtk_builder_get_object(interface, "label60"));
//  GtkWidget *hbox18 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox18"));
//  GtkWidget *label59 = GTK_WIDGET (gtk_builder_get_object(interface, "label59"));
//  GtkWidget *entry9 = GTK_WIDGET (gtk_builder_get_object(interface, "entry9"));
//  GtkWidget *hbox15 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox15"));
//  GtkWidget *button13 = GTK_WIDGET (gtk_builder_get_object(interface, "button13"));
//  GtkWidget *label98 = GTK_WIDGET (gtk_builder_get_object(interface, "label98"));
//  GtkWidget *label62 = GTK_WIDGET (gtk_builder_get_object(interface, "label62"));
//  GtkWidget *label56 = GTK_WIDGET (gtk_builder_get_object(interface, "label56"));
//  GtkWidget *label93 = GTK_WIDGET (gtk_builder_get_object(interface, "label93"));
//  GtkWidget *label63 = GTK_WIDGET (gtk_builder_get_object(interface, "label63"));
//  GtkWidget *hbox30 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox30"));
//  GtkWidget *scrolledwindow1 = GTK_WIDGET (gtk_builder_get_object(interface, "scrolledwindow1"));
//  GtkWidget *viewport1 = GTK_WIDGET (gtk_builder_get_object(interface, "viewport1"));
  GtkWidget *vbox2 = GTK_WIDGET (gtk_builder_get_object(interface, "vbox2"));
  GtkWidget *label117 = GTK_WIDGET (gtk_builder_get_object(interface, "label117"));
//  GtkWidget *frame9 = GTK_WIDGET (gtk_builder_get_object(interface, "frame9"));
//  GtkWidget *alignment9 = GTK_WIDGET (gtk_builder_get_object(interface, "alignment9"));
//  GtkWidget *vbox19 = GTK_WIDGET (gtk_builder_get_object(interface, "vbox19"));
  GtkWidget *label81 = GTK_WIDGET (gtk_builder_get_object(interface, "label81"));
  GtkWidget *checkbutton2 = GTK_WIDGET (gtk_builder_get_object(interface, "checkbutton2"));
  GtkWidget *label80 = GTK_WIDGET (gtk_builder_get_object(interface, "label80"));
//  GtkWidget *frame8 = GTK_WIDGET (gtk_builder_get_object(interface, "frame8"));
//  GtkWidget *alignment8 = GTK_WIDGET (gtk_builder_get_object(interface, "alignment8"));
//  GtkWidget *vbox18 = GTK_WIDGET (gtk_builder_get_object(interface, "vbox18"));
  GtkWidget *label86 = GTK_WIDGET (gtk_builder_get_object(interface, "label86"));
  GtkWidget *hbox3 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox3"));
  GtkWidget *comboboxtext1 = GTK_WIDGET (gtk_builder_get_object(interface, "comboboxtext1"));
//  GtkWidget *hbox37 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox37"));
  GtkWidget *button7 = GTK_WIDGET (gtk_builder_get_object(interface, "button7"));
//  GtkWidget *label140 = GTK_WIDGET (gtk_builder_get_object(interface, "label140"));
  GtkWidget *button38 = GTK_WIDGET (gtk_builder_get_object(interface, "button38"));
  GtkWidget *table1 = GTK_WIDGET (gtk_builder_get_object(interface, "table1"));
//  GtkWidget *label20 = GTK_WIDGET (gtk_builder_get_object(interface, "label20"));
//  GtkWidget *checkbutton1 = GTK_WIDGET (gtk_builder_get_object(interface, "checkbutton1"));
  GtkWidget *label18 = GTK_WIDGET (gtk_builder_get_object(interface, "label18"));
//  GtkWidget *label19 = GTK_WIDGET (gtk_builder_get_object(interface, "label19"));
//  GtkWidget *entry1 = GTK_WIDGET (gtk_builder_get_object(interface, "entry1"));
//  GtkWidget *entry2 = GTK_WIDGET (gtk_builder_get_object(interface, "entry2"));
  GtkWidget *hbox8 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox8"));
//  GtkWidget *button6 = GTK_WIDGET (gtk_builder_get_object(interface, "button6"));
//  GtkWidget *label89 = GTK_WIDGET (gtk_builder_get_object(interface, "label89"));
  GtkWidget *label78 = GTK_WIDGET (gtk_builder_get_object(interface, "label78"));
//  GtkWidget *frame11 = GTK_WIDGET (gtk_builder_get_object(interface, "frame11"));
//  GtkWidget *alignment11 = GTK_WIDGET (gtk_builder_get_object(interface, "alignment11"));
//  GtkWidget *vbox32 = GTK_WIDGET (gtk_builder_get_object(interface, "vbox32"));
  GtkWidget *label114 = GTK_WIDGET (gtk_builder_get_object(interface, "label114"));
//  GtkWidget *hbox22 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox22"));
  GtkWidget *radiobutton14 = GTK_WIDGET (gtk_builder_get_object(interface, "radiobutton14"));
  GSList *radiobutton14_group = NULL;
  GtkWidget *radiobutton15 = GTK_WIDGET (gtk_builder_get_object(interface, "radiobutton15"));
  GtkWidget *radiobutton16 = GTK_WIDGET (gtk_builder_get_object(interface, "radiobutton16"));
  GtkWidget *label115 = GTK_WIDGET (gtk_builder_get_object(interface, "label115"));
  GtkWidget *hbox23 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox23"));
  GtkWidget *radiobutton17 = GTK_WIDGET (gtk_builder_get_object(interface, "radiobutton17"));
  GSList *radiobutton17_group = NULL;
  GtkWidget *radiobutton18 = GTK_WIDGET (gtk_builder_get_object(interface, "radiobutton18"));
//  GtkWidget *label116 = GTK_WIDGET (gtk_builder_get_object(interface, "label116"));
//  GtkWidget *hbox24 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox24"));
  GtkWidget *radiobutton19 = GTK_WIDGET (gtk_builder_get_object(interface, "radiobutton19"));
  GSList *radiobutton19_group = NULL;
  GtkWidget *radiobutton20 = GTK_WIDGET (gtk_builder_get_object(interface, "radiobutton20"));
  GtkWidget *radiobutton21 = GTK_WIDGET (gtk_builder_get_object(interface, "radiobutton21"));
  GtkWidget *label87 = GTK_WIDGET (gtk_builder_get_object(interface, "label87"));
//  GtkWidget *frame12 = GTK_WIDGET (gtk_builder_get_object(interface, "frame12"));
//  GtkWidget *alignment12 = GTK_WIDGET (gtk_builder_get_object(interface, "alignment12"));
//  GtkWidget *vbox22 = GTK_WIDGET (gtk_builder_get_object(interface, "vbox22"));
  GtkWidget *label91 = GTK_WIDGET (gtk_builder_get_object(interface, "label91"));
  GtkWidget *hbox2 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox2"));
  GtkWidget *label21 = GTK_WIDGET (gtk_builder_get_object(interface, "label21"));
  GtkWidget *label22 = GTK_WIDGET (gtk_builder_get_object(interface, "label22"));
  GtkWidget *entry3 = GTK_WIDGET (gtk_builder_get_object(interface, "entry3"));
  GtkWidget *label23 = GTK_WIDGET (gtk_builder_get_object(interface, "label23"));
  GtkWidget *entry4 = GTK_WIDGET (gtk_builder_get_object(interface, "entry4"));
  GtkWidget *hbox10 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox10"));
  GtkWidget *button9 = GTK_WIDGET (gtk_builder_get_object(interface, "button9"));
//  GtkWidget *label92 = GTK_WIDGET (gtk_builder_get_object(interface, "label92"));
//  GtkWidget *label90 = GTK_WIDGET (gtk_builder_get_object(interface, "label90"));
//  GtkWidget *frame10 = GTK_WIDGET (gtk_builder_get_object(interface, "frame10"));
//  GtkWidget *alignment10 = GTK_WIDGET (gtk_builder_get_object(interface, "alignment10"));
//  GtkWidget *vbox20 = GTK_WIDGET (gtk_builder_get_object(interface, "vbox20"));
//  GtkWidget *label83 = GTK_WIDGET (gtk_builder_get_object(interface, "label83"));
//  GtkWidget *hbox31 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox31"));
//  GtkWidget *entry6 = GTK_WIDGET (gtk_builder_get_object(interface, "entry6"));
//  GtkWidget *hbox16 = GTK_WIDGET (gtk_builder_get_object(interface, "hbox16"));
//  GtkWidget *button10 = GTK_WIDGET (gtk_builder_get_object(interface, "button10"));
//  GtkWidget *label96 = GTK_WIDGET (gtk_builder_get_object(interface, "label96"));
//  GtkWidget *label82 = GTK_WIDGET (gtk_builder_get_object(interface, "label82"));
//  GtkWidget *vbox31 = GTK_WIDGET (gtk_builder_get_object(interface, "vbox31"));
//  GtkWidget *label84 = GTK_WIDGET (gtk_builder_get_object(interface, "label84"));
//  GtkWidget *entry10 = GTK_WIDGET (gtk_builder_get_object(interface, "entry10"));
  GtkWidget *button16 = GTK_WIDGET (gtk_builder_get_object(interface, "button16"));
//  GtkWidget *entry11 = GTK_WIDGET (gtk_builder_get_object(interface, "entry11"));
  GtkWidget *button17 = GTK_WIDGET (gtk_builder_get_object(interface, "button17"));
//  GtkWidget *label88 = GTK_WIDGET (gtk_builder_get_object(interface, "label88"));
//  GtkWidget *label44 = GTK_WIDGET (gtk_builder_get_object(interface, "label44"));
  GtkWidget *checkbutton_trf_auto = GTK_WIDGET (gtk_builder_get_object(interface, "checkbutton_trf_auto"));
  GtkWidget *togglebutton_trf_show = GTK_WIDGET (gtk_builder_get_object(interface, "togglebutton_trf_show"));
  GtkWidget *comboboxtext_trf = GTK_WIDGET (gtk_builder_get_object(interface, "comboboxtext_trf"));



//---------label for grid
  label_grid_v[0] = GTK_WIDGET (gtk_builder_get_object(interface, "label15"));
  label_grid_v[2] = GTK_WIDGET (gtk_builder_get_object(interface, "label16"));
  label_grid_v[4] = GTK_WIDGET (gtk_builder_get_object(interface, "label17"));
  label_grid_v[6] = GTK_WIDGET (gtk_builder_get_object(interface, "label18"));

  label_grid_h[0][0] = GTK_WIDGET (gtk_builder_get_object(interface, "label7"));
  label_grid_h[0][2] = GTK_WIDGET (gtk_builder_get_object(interface, "label8"));
  label_grid_h[0][4] = GTK_WIDGET (gtk_builder_get_object(interface, "label9"));
  label_grid_h[0][6] = GTK_WIDGET (gtk_builder_get_object(interface, "label10"));

  label_grid_h[1][0] = GTK_WIDGET (gtk_builder_get_object(interface, "label11"));
  label_grid_h[1][2] = GTK_WIDGET (gtk_builder_get_object(interface, "label12"));
  label_grid_h[1][4] = GTK_WIDGET (gtk_builder_get_object(interface, "label13"));
  label_grid_h[1][6] = GTK_WIDGET (gtk_builder_get_object(interface, "label14"));
//---------label for grid


  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton1), radiobutton1_group);
  radiobutton1_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton1));
//
//  radiobutton13 = gtk_radio_button_new_with_mnemonic (NULL, _("every"));
//  gtk_widget_show (radiobutton13);
//  gtk_box_pack_start (GTK_BOX (hbox4), radiobutton13, FALSE, FALSE, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton13), radiobutton1_group);
  radiobutton1_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton13));

  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton15), radiobutton14_group);
  radiobutton14_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton15));
//
//  radiobutton16 = gtk_radio_button_new_with_mnemonic (NULL, _("nautical"));
//  gtk_widget_show (radiobutton16);
//  gtk_box_pack_start (GTK_BOX (hbox22), radiobutton16, FALSE, FALSE, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton16), radiobutton14_group);
  radiobutton14_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton16));
//
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton17), radiobutton17_group);
  radiobutton17_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton17));
//  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (radiobutton17), TRUE);
//
//  radiobutton18 = gtk_radio_button_new_with_mnemonic (NULL, _("feet"));
//  gtk_widget_show (radiobutton18);
//  gtk_box_pack_start (GTK_BOX (hbox23), radiobutton18, FALSE, FALSE, 4);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton18), radiobutton17_group);
  radiobutton17_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton18));
//
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton19), radiobutton19_group);
  radiobutton19_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton19));
//  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (radiobutton19), TRUE);
//
//  radiobutton20 = gtk_radio_button_new_with_mnemonic (NULL, _("d m.m'"));
//  gtk_widget_show (radiobutton20);
//  gtk_box_pack_start (GTK_BOX (hbox24), radiobutton20, FALSE, FALSE, 4);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton20), radiobutton19_group);
  radiobutton19_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton20));
//
//  radiobutton21 = gtk_radio_button_new_with_mnemonic (NULL, _("d m's.s\""));
//  gtk_widget_show (radiobutton21);
//  gtk_box_pack_start (GTK_BOX (hbox24), radiobutton21, FALSE, FALSE, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton21), radiobutton19_group);
  radiobutton19_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton21));
//

//---------------------Videocam togglebuttons---------------
//	for (int i=1;i<=4;i++)
//	{
//		GtkWidget *cam_button[i] = gtk_button_new_with_label("i");
//	}
//---------------------Videocam togglebuttons---------------


  g_signal_connect ((gpointer) window1, "delete_event",
                    G_CALLBACK (on_window1_delete_event),
                    NULL);
  g_signal_connect ((gpointer) window1, "destroy_event",
                    G_CALLBACK (on_window1_destroy_event),
                    NULL);
  g_signal_connect ((gpointer) button1, "clicked",
                    G_CALLBACK (on_button1_clicked),
                    NULL);
  g_signal_connect ((gpointer) button4, "clicked",
                    G_CALLBACK (on_button4_clicked),
                    NULL);
  g_signal_connect ((gpointer) button5, "clicked",
                    G_CALLBACK (on_button5_clicked),
                    NULL);
  g_signal_connect ((gpointer) button3, "clicked",
                    G_CALLBACK (on_button3_clicked),
                    NULL);
//  g_signal_connect ((gpointer) togglebutton1, "toggled",
//                    G_CALLBACK (on_togglebutton1_toggled),
//                    NULL);
  g_signal_connect ((gpointer) drawingarea1, "button_press_event",
                    G_CALLBACK (on_drawingarea1_button_press_event),
                    NULL);
  g_signal_connect ((gpointer) drawingarea1, "motion_notify_event",
                    G_CALLBACK (on_drawingarea1_motion_notify_event),
                    NULL);
  g_signal_connect ((gpointer) drawingarea1, "configure_event",
                    G_CALLBACK (on_drawingarea1_configure_event),
                    NULL);
  g_signal_connect ((gpointer) drawingarea1, "expose_event",
                    G_CALLBACK (on_drawingarea1_expose_event),
                    NULL);
  g_signal_connect ((gpointer) drawingarea1, "button_release_event",
                    G_CALLBACK (on_drawingarea1_button_release_event),
                    NULL);
  g_signal_connect ((gpointer) drawingarea1, "scroll_event",
                    G_CALLBACK (on_drawingarea1_scroll_event),
                    NULL);
  g_signal_connect ((gpointer) drawingarea1, "key_press_event",
                    G_CALLBACK (on_drawingarea1_key_press_event),
                    NULL);
  g_signal_connect ((gpointer) vscale1, "value_changed",
                    G_CALLBACK (on_vscale1_value_changed),
                    NULL);
  g_signal_connect ((gpointer) vscale1, "change_value",
                    G_CALLBACK (on_vscale1_change_value),
                    NULL);
  g_signal_connect ((gpointer) vscale1, "button_press_event",
                    G_CALLBACK (on_vscale1_button_press_event),
                    NULL);
  g_signal_connect ((gpointer) vscale1, "button_release_event",
                    G_CALLBACK (on_vscale1_button_release_event),
                    NULL);
  g_signal_connect ((gpointer) button15, "clicked",
                    G_CALLBACK (on_button15_clicked),
                    NULL);
  g_signal_connect ((gpointer) button8, "clicked",
                    G_CALLBACK (on_button8_clicked),
                    NULL);
  g_signal_connect ((gpointer) button18, "clicked",
                    G_CALLBACK (on_button18_clicked),
                    NULL);
  g_signal_connect ((gpointer) button19, "clicked",
                    G_CALLBACK (on_button19_clicked),
                    NULL);
  g_signal_connect ((gpointer) button20, "clicked",
                    G_CALLBACK (on_button20_clicked),
                    NULL);
  g_signal_connect ((gpointer) button36, "clicked",
                    G_CALLBACK (on_button36_clicked),
                    NULL);
//  g_signal_connect ((gpointer) button35, "clicked",
//                    G_CALLBACK (on_button35_clicked),
//                    NULL);
  g_signal_connect ((gpointer) radiobutton1, "toggled",
                    G_CALLBACK (on_radiobutton1_toggled),
                    NULL);
  g_signal_connect ((gpointer) radiobutton13, "toggled",
                    G_CALLBACK (on_radiobutton13_toggled),
                    NULL);
//  g_signal_connect ((gpointer) entry16, "changed",
//                    G_CALLBACK (on_entry16_changed),
//                    NULL);
//  g_signal_connect ((gpointer) button11, "clicked",
//                    G_CALLBACK (on_button11_clicked),
//                    NULL);
//  g_signal_connect ((gpointer) button11, "expose_event",
//                    G_CALLBACK (on_button11_expose_event),
//                    NULL);
//  g_signal_connect ((gpointer) button23, "clicked",
//                    G_CALLBACK (on_button23_clicked),
//                    NULL);
//  g_signal_connect ((gpointer) checkbutton3, "toggled",
//                    G_CALLBACK (on_checkbutton3_toggled),
//                    NULL);
//  g_signal_connect ((gpointer) checkbutton4, "toggled",
//                    G_CALLBACK (on_checkbutton4_toggled),
//                    NULL);
//  g_signal_connect ((gpointer) checkbutton5, "toggled",
//                    G_CALLBACK (on_checkbutton5_toggled),
//                    NULL);
//  g_signal_connect ((gpointer) checkbutton6, "toggled",
//                    G_CALLBACK (on_checkbutton6_toggled),
//                    NULL);
//  g_signal_connect ((gpointer) checkbutton7, "toggled",
//                    G_CALLBACK (on_checkbutton7_toggled),
//                    NULL);
//  g_signal_connect ((gpointer) checkbutton8, "toggled",
//                    G_CALLBACK (on_checkbutton8_toggled),
//                    NULL);
//  g_signal_connect ((gpointer) entry7, "changed",
//                    G_CALLBACK (on_entry7_changed),
//                    NULL);
//  g_signal_connect ((gpointer) entry8, "changed",
//                    G_CALLBACK (on_entry8_changed),
//                    NULL);
//  g_signal_connect ((gpointer) button13, "clicked",
//                    G_CALLBACK (on_button13_clicked),
//                    NULL);
  g_signal_connect ((gpointer) checkbutton2, "toggled",
                    G_CALLBACK (on_checkbutton2_toggled),
                    NULL);
//------------------Traffic callbacks-------------		    
  g_signal_connect ((gpointer) togglebutton_trf_show, "toggled",
                    G_CALLBACK (on_togglebutton_trf_show_toggled),
                    NULL);
  g_signal_connect ((gpointer) checkbutton_trf_auto, "toggled",
                    G_CALLBACK (on_checkbutton_trf_auto_toggled),
                    NULL);
  g_signal_connect ((gpointer) comboboxtext_trf, "changed",
                    G_CALLBACK (on_comboboxtext_trf_changed),
                    NULL);
//------------------Traffic callbacks-------------		    
  g_signal_connect ((gpointer) comboboxtext1, "changed",
                    G_CALLBACK (on_comboboxtext1_changed),
                    NULL);
  g_signal_connect ((gpointer) button7, "clicked",
                    G_CALLBACK (on_button7_clicked),
                    NULL);
  g_signal_connect ((gpointer) button38, "clicked",
                    G_CALLBACK (on_button38_clicked),
                    NULL);
//  g_signal_connect ((gpointer) checkbutton1, "toggled",
//                    G_CALLBACK (on_checkbutton1_toggled),
//                    NULL);
//  g_signal_connect ((gpointer) entry1, "changed",
//                    G_CALLBACK (on_entry1_changed),
//                    NULL);
//  g_signal_connect ((gpointer) entry2, "changed",
//                    G_CALLBACK (on_entry2_changed),
//                    NULL);
//  g_signal_connect ((gpointer) button6, "clicked",
//                    G_CALLBACK (on_button6_clicked),
//                    NULL);
  g_signal_connect ((gpointer) radiobutton14, "toggled",
                    G_CALLBACK (on_radiobutton14_toggled),
                    NULL);
  g_signal_connect ((gpointer) radiobutton15, "toggled",
                    G_CALLBACK (on_radiobutton15_toggled),
                    NULL);
  g_signal_connect ((gpointer) radiobutton16, "toggled",
                    G_CALLBACK (on_radiobutton16_toggled),
                    NULL);
  g_signal_connect ((gpointer) radiobutton17, "toggled",
                    G_CALLBACK (on_radiobutton17_toggled),
                    NULL);
  g_signal_connect ((gpointer) radiobutton18, "toggled",
                    G_CALLBACK (on_radiobutton18_toggled),
                    NULL);
  g_signal_connect ((gpointer) radiobutton19, "toggled",
                    G_CALLBACK (on_radiobutton19_toggled),
                    NULL);
  g_signal_connect ((gpointer) radiobutton20, "toggled",
                    G_CALLBACK (on_radiobutton20_toggled),
                    NULL);
  g_signal_connect ((gpointer) radiobutton21, "toggled",
                    G_CALLBACK (on_radiobutton21_toggled),
                    NULL);
  g_signal_connect ((gpointer) entry3, "changed",
                    G_CALLBACK (on_entry3_changed),
                    NULL);
  g_signal_connect ((gpointer) entry4, "changed",
                    G_CALLBACK (on_entry4_changed),
                    NULL);
  g_signal_connect ((gpointer) button9, "clicked",
                    G_CALLBACK (on_button9_clicked),
                    NULL);
//  g_signal_connect ((gpointer) button10, "clicked",
//                    G_CALLBACK (on_button10_clicked),
//                    NULL);
  g_signal_connect ((gpointer) button16, "clicked",
                    G_CALLBACK (on_button16_clicked),
                    NULL);
  g_signal_connect ((gpointer) button17, "clicked",
                    G_CALLBACK (on_button17_clicked),
                    NULL);

  gtk_widget_grab_focus (drawingarea1);
  return window1;
}

GtkWidget*
create_menu1 (void)
{
  GtkWidget *menu1;
  GtkWidget *item4;
  GtkWidget *item19;
  GtkWidget *item20;
  GtkWidget *item9;
  GtkWidget *item11;
  GtkWidget *item11_menu;
  GtkWidget *item12;
  GtkWidget *item14;
  GtkWidget *item16;
  GtkWidget *item16_menu;
  GtkWidget *item17;
  GtkWidget *item18;
  GtkWidget *item21;
  GtkWidget *item21_menu;
  GtkWidget *itemgeocode1;
  GtkWidget *item6;
  GtkWidget *item6_menu;
  GtkWidget *item5;
  GtkWidget *item7;
  GtkWidget *item8;

  menu1 = gtk_menu_new ();

  item4 = gtk_menu_item_new_with_mnemonic (_("this point"));
  gtk_widget_show (item4);
  gtk_container_add (GTK_CONTAINER (menu1), item4);

  item19 = gtk_check_menu_item_new_with_mnemonic (_("show friends"));
  gtk_widget_show (item19);
  gtk_container_add (GTK_CONTAINER (menu1), item19);

  item20 = gtk_check_menu_item_new_with_mnemonic (_("show POIs"));
  gtk_widget_show (item20);
  gtk_container_add (GTK_CONTAINER (menu1), item20);

  item9 = gtk_check_menu_item_new_with_mnemonic (_("show photos"));
  gtk_widget_show (item9);
  gtk_container_add (GTK_CONTAINER (menu1), item9);

  item11 = gtk_menu_item_new_with_mnemonic (_("POIs"));
  gtk_widget_show (item11);
  gtk_container_add (GTK_CONTAINER (menu1), item11);

  item11_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (item11), item11_menu);

  item12 = gtk_menu_item_new_with_mnemonic (_("add POI"));
  gtk_widget_show (item12);
  gtk_container_add (GTK_CONTAINER (item11_menu), item12);

  item14 = gtk_menu_item_new_with_mnemonic (_("select POIs"));
  gtk_widget_show (item14);
  gtk_container_add (GTK_CONTAINER (item11_menu), item14);

  item16 = gtk_menu_item_new_with_mnemonic (_("waypoints"));
  gtk_widget_show (item16);
  gtk_container_add (GTK_CONTAINER (menu1), item16);

  item16_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (item16), item16_menu);

  item17 = gtk_menu_item_new_with_mnemonic (_("set"));
  gtk_widget_show (item17);
  gtk_container_add (GTK_CONTAINER (item16_menu), item17);

  item18 = gtk_menu_item_new_with_mnemonic (_("unset"));
  gtk_widget_show (item18);
  gtk_container_add (GTK_CONTAINER (item16_menu), item18);

  item21 = gtk_menu_item_new_with_mnemonic (_("photos"));
  gtk_widget_show (item21);
  gtk_container_add (GTK_CONTAINER (menu1), item21);

  item21_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (item21), item21_menu);

  itemgeocode1 = gtk_menu_item_new_with_mnemonic (_("geocode"));
  gtk_widget_show (itemgeocode1);
  gtk_container_add (GTK_CONTAINER (item21_menu), itemgeocode1);

  item6 = gtk_menu_item_new_with_mnemonic (_("my position"));
  gtk_widget_show (item6);
  gtk_container_add (GTK_CONTAINER (menu1), item6);

  item6_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (item6), item6_menu);

  item5 = gtk_menu_item_new_with_mnemonic (_("set"));
  gtk_widget_show (item5);
  gtk_container_add (GTK_CONTAINER (item6_menu), item5);

  item7 = gtk_menu_item_new_with_mnemonic (_("unset"));
  gtk_widget_show (item7);
  gtk_container_add (GTK_CONTAINER (item6_menu), item7);

  item8 = gtk_menu_item_new_with_mnemonic (_("map download"));
  gtk_widget_show (item8);
  gtk_container_add (GTK_CONTAINER (menu1), item8);

  g_signal_connect ((gpointer) item4, "activate",
                    G_CALLBACK (on_item4_activate),
                    NULL);
  g_signal_connect ((gpointer) item19, "activate",
                    G_CALLBACK (on_item19_activate),
                    NULL);
  g_signal_connect ((gpointer) item20, "activate",
                    G_CALLBACK (on_item20_activate),
                    NULL);
  g_signal_connect ((gpointer) item9, "activate",
                    G_CALLBACK (on_item9_activate),
                    NULL);
  g_signal_connect ((gpointer) item11, "activate",
                    G_CALLBACK (on_item11_activate),
                    NULL);
  g_signal_connect ((gpointer) item12, "button_release_event",
                    G_CALLBACK (on_item12_activate),
                    NULL);
  g_signal_connect ((gpointer) item14, "button_release_event",
                    G_CALLBACK (on_item14_activate),
                    NULL);
  g_signal_connect ((gpointer) item17, "activate",
                    G_CALLBACK (on_item17_activate),
                    NULL);
  g_signal_connect ((gpointer) item18, "activate",
                    G_CALLBACK (on_item18_activate),
                    NULL);
  g_signal_connect ((gpointer) itemgeocode1, "activate",
                    G_CALLBACK (on_itemgeocode1_activate),
                    NULL);
  g_signal_connect ((gpointer) item6, "activate",
                    G_CALLBACK (on_item6_activate),
                    NULL);
  g_signal_connect ((gpointer) item5, "button_release_event",
                    G_CALLBACK (on_item5_activate),
                    NULL);
  g_signal_connect ((gpointer) item7, "button_release_event",
                    G_CALLBACK (on_item7_activate),
                    NULL);
  g_signal_connect ((gpointer) item8, "activate",
                    G_CALLBACK (on_item8_activate),
                    NULL);

  
  GLADE_HOOKUP_OBJECT_NO_REF (menu1, menu1, "menu1");
  GLADE_HOOKUP_OBJECT (menu1, item4, "item4");
  GLADE_HOOKUP_OBJECT (menu1, item19, "item19");
  GLADE_HOOKUP_OBJECT (menu1, item20, "item20");
  GLADE_HOOKUP_OBJECT (menu1, item9, "item9");
  GLADE_HOOKUP_OBJECT (menu1, item11, "item11");
  GLADE_HOOKUP_OBJECT (menu1, item11_menu, "item11_menu");
  GLADE_HOOKUP_OBJECT (menu1, item12, "item12");
  GLADE_HOOKUP_OBJECT (menu1, item14, "item14");
  GLADE_HOOKUP_OBJECT (menu1, item16, "item16");
  GLADE_HOOKUP_OBJECT (menu1, item16_menu, "item16_menu");
  GLADE_HOOKUP_OBJECT (menu1, item17, "item17");
  GLADE_HOOKUP_OBJECT (menu1, item18, "item18");
  GLADE_HOOKUP_OBJECT (menu1, item21, "item21");
  GLADE_HOOKUP_OBJECT (menu1, item21_menu, "item21_menu");
  GLADE_HOOKUP_OBJECT (menu1, itemgeocode1, "itemgeocode1");
  GLADE_HOOKUP_OBJECT (menu1, item6, "item6");
  GLADE_HOOKUP_OBJECT (menu1, item6_menu, "item6_menu");
  GLADE_HOOKUP_OBJECT (menu1, item5, "item5");
  GLADE_HOOKUP_OBJECT (menu1, item7, "item7");
  GLADE_HOOKUP_OBJECT (menu1, item8, "item8");

  return menu1;
}

GtkWidget*
create_dialog1 (void)
{
  GtkWidget *dialog1;
  GtkWidget *dialog_vbox1;
  GtkWidget *vbox3;
  GtkWidget *textview3;
  GtkWidget *label26;
  GtkWidget *entry5;
  GtkWidget *label136;
  GtkWidget *label137;
  GtkWidget *entry20;
  GtkWidget *label139;
  GtkWidget *entry21;
  GtkWidget *checkbutton12;
  GtkWidget *dialog_action_area1;
  GtkWidget *cancelbutton1;
  GtkWidget *okbutton1;
  GtkTooltips *tooltips;

  tooltips = gtk_tooltips_new ();

  dialog1 = gtk_dialog_new ();
  gtk_widget_set_size_request (dialog1, 360, -1);
  gtk_window_set_title (GTK_WINDOW (dialog1), _("New Repository"));
  gtk_window_set_position (GTK_WINDOW (dialog1), GTK_WIN_POS_CENTER_ON_PARENT);
  gtk_window_set_modal (GTK_WINDOW (dialog1), TRUE);
  gtk_window_set_destroy_with_parent (GTK_WINDOW (dialog1), TRUE);
  gtk_window_set_skip_taskbar_hint (GTK_WINDOW (dialog1), TRUE);
  gtk_window_set_skip_pager_hint (GTK_WINDOW (dialog1), TRUE);
  gtk_window_set_type_hint (GTK_WINDOW (dialog1), GDK_WINDOW_TYPE_HINT_DIALOG);

  dialog_vbox1 = GTK_DIALOG (dialog1)->vbox;
  gtk_widget_show (dialog_vbox1);

  vbox3 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox3);
  gtk_box_pack_start (GTK_BOX (dialog_vbox1), vbox3, FALSE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (vbox3), 8);

  textview3 = gtk_text_view_new ();
  gtk_widget_show (textview3);
  gtk_box_pack_start (GTK_BOX (vbox3), textview3, TRUE, TRUE, 5);
  gtk_text_view_set_editable (GTK_TEXT_VIEW (textview3), FALSE);
  gtk_text_view_set_accepts_tab (GTK_TEXT_VIEW (textview3), FALSE);
  gtk_text_view_set_justification (GTK_TEXT_VIEW (textview3), GTK_JUSTIFY_CENTER);
  gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (textview3), GTK_WRAP_WORD);
  gtk_text_view_set_cursor_visible (GTK_TEXT_VIEW (textview3), FALSE);
  gtk_text_buffer_set_text (gtk_text_view_get_buffer (GTK_TEXT_VIEW (textview3)), _("You can find more information about repositories on\n\nhttp://www.tangogps.org/\n"), -1);

  label26 = gtk_label_new (_("<b>Name for the new Repository</b>"));
  gtk_widget_show (label26);
  gtk_box_pack_start (GTK_BOX (vbox3), label26, FALSE, FALSE, 5);
  gtk_label_set_use_markup (GTK_LABEL (label26), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label26), 0, 0.5);

  entry5 = gtk_entry_new ();
  gtk_widget_show (entry5);
  gtk_box_pack_start (GTK_BOX (vbox3), entry5, FALSE, FALSE, 0);

  label136 = gtk_label_new (_(" "));
  gtk_widget_show (label136);
  gtk_box_pack_start (GTK_BOX (vbox3), label136, FALSE, FALSE, 0);

  label137 = gtk_label_new (_("<b>URI</b>"));
  gtk_widget_show (label137);
  gtk_box_pack_start (GTK_BOX (vbox3), label137, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label137), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label137), 0, 0.5);

  entry20 = gtk_entry_new ();
  gtk_widget_show (entry20);
  gtk_box_pack_start (GTK_BOX (vbox3), entry20, FALSE, FALSE, 0);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry20), 9679);

  label139 = gtk_label_new (_("<b>Cache Dir</b>"));
  gtk_widget_show (label139);
  gtk_box_pack_start (GTK_BOX (vbox3), label139, FALSE, FALSE, 3);
  gtk_label_set_use_markup (GTK_LABEL (label139), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label139), 0, 0.5);

  entry21 = gtk_entry_new ();
  gtk_widget_show (entry21);
  gtk_box_pack_start (GTK_BOX (vbox3), entry21, FALSE, FALSE, 0);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry21), 9679);

  checkbutton12 = gtk_check_button_new_with_mnemonic (_("xyz instead of zxy"));
  gtk_widget_show (checkbutton12);
  gtk_box_pack_start (GTK_BOX (vbox3), checkbutton12, FALSE, FALSE, 8);

  dialog_action_area1 = GTK_DIALOG (dialog1)->action_area;
  gtk_widget_show (dialog_action_area1);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area1), GTK_BUTTONBOX_END);

  cancelbutton1 = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_show (cancelbutton1);
  gtk_dialog_add_action_widget (GTK_DIALOG (dialog1), cancelbutton1, GTK_RESPONSE_CANCEL);
  GTK_WIDGET_SET_FLAGS (cancelbutton1, GTK_CAN_DEFAULT);

  okbutton1 = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_show (okbutton1);
  gtk_dialog_add_action_widget (GTK_DIALOG (dialog1), okbutton1, GTK_RESPONSE_OK);
  gtk_widget_set_sensitive (okbutton1, FALSE);
  GTK_WIDGET_SET_FLAGS (okbutton1, GTK_CAN_DEFAULT);
  gtk_tooltips_set_tip (tooltips, okbutton1, _("All fields must be filled in"), NULL);

  g_signal_connect ((gpointer) entry5, "changed",
                    G_CALLBACK (on_entry5_changed),
                    NULL);
  g_signal_connect ((gpointer) entry20, "changed",
                    G_CALLBACK (on_entry20_changed),
                    NULL);
  g_signal_connect ((gpointer) entry21, "changed",
                    G_CALLBACK (on_entry21_changed),
                    NULL);
  g_signal_connect ((gpointer) entry21, "activate",
                    G_CALLBACK (on_entry21_activate),
                    NULL);
  g_signal_connect ((gpointer) checkbutton12, "toggled",
                    G_CALLBACK (on_checkbutton12_toggled),
                    NULL);
  g_signal_connect ((gpointer) cancelbutton1, "clicked",
                    G_CALLBACK (on_cancelbutton1_clicked),
                    NULL);
  g_signal_connect ((gpointer) okbutton1, "clicked",
                    G_CALLBACK (on_okbutton1_clicked),
                    NULL);

  
  GLADE_HOOKUP_OBJECT_NO_REF (dialog1, dialog1, "dialog1");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog1, dialog_vbox1, "dialog_vbox1");
  GLADE_HOOKUP_OBJECT (dialog1, vbox3, "vbox3");
  GLADE_HOOKUP_OBJECT (dialog1, textview3, "textview3");
  GLADE_HOOKUP_OBJECT (dialog1, label26, "label26");
  GLADE_HOOKUP_OBJECT (dialog1, entry5, "entry5");
  GLADE_HOOKUP_OBJECT (dialog1, label136, "label136");
  GLADE_HOOKUP_OBJECT (dialog1, label137, "label137");
  GLADE_HOOKUP_OBJECT (dialog1, entry20, "entry20");
  GLADE_HOOKUP_OBJECT (dialog1, label139, "label139");
  GLADE_HOOKUP_OBJECT (dialog1, entry21, "entry21");
  GLADE_HOOKUP_OBJECT (dialog1, checkbutton12, "checkbutton12");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog1, dialog_action_area1, "dialog_action_area1");
  GLADE_HOOKUP_OBJECT (dialog1, cancelbutton1, "cancelbutton1");
  GLADE_HOOKUP_OBJECT (dialog1, okbutton1, "okbutton1");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog1, tooltips, "tooltips");

  return dialog1;
}

GtkWidget*
create_window2 (void)
{
  GtkWidget *window2;
  GtkWidget *vbox15;
  GtkWidget *vbox25;
  GtkWidget *eventbox4;
  GtkWidget *label64;
  GtkWidget *button14;

  window2 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window2), _("GPS Info"));
  gtk_window_set_position (GTK_WINDOW (window2), GTK_WIN_POS_MOUSE);
  gtk_window_set_destroy_with_parent (GTK_WINDOW (window2), TRUE);
  gtk_window_set_skip_taskbar_hint (GTK_WINDOW (window2), TRUE);
  gtk_window_set_skip_pager_hint (GTK_WINDOW (window2), TRUE);
  gtk_window_set_type_hint (GTK_WINDOW (window2), GDK_WINDOW_TYPE_HINT_MENU);

  vbox15 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox15);
  gtk_container_add (GTK_CONTAINER (window2), vbox15);

  vbox25 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox25);
  gtk_box_pack_start (GTK_BOX (vbox15), vbox25, TRUE, TRUE, 9);

  eventbox4 = gtk_event_box_new ();
  gtk_widget_show (eventbox4);
  gtk_box_pack_start (GTK_BOX (vbox25), eventbox4, FALSE, FALSE, 0);

  label64 = gtk_label_new (_("--"));
  gtk_widget_show (label64);
  gtk_container_add (GTK_CONTAINER (eventbox4), label64);
  gtk_label_set_use_markup (GTK_LABEL (label64), TRUE);
  gtk_label_set_line_wrap (GTK_LABEL (label64), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label64), 0, 0);
  gtk_misc_set_padding (GTK_MISC (label64), 4, 2);

  button14 = gtk_button_new_with_mnemonic (_("Close"));
  gtk_widget_show (button14);
  gtk_box_pack_start (GTK_BOX (vbox15), button14, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) window2, "delete_event",
                    G_CALLBACK (on_window2_delete_event),
                    NULL);
  g_signal_connect ((gpointer) eventbox4, "button_release_event",
                    G_CALLBACK (on_eventbox4_button_release_event),
                    NULL);
  g_signal_connect ((gpointer) button14, "clicked",
                    G_CALLBACK (on_button14_clicked),
                    NULL);

  
  GLADE_HOOKUP_OBJECT_NO_REF (window2, window2, "window2");
  GLADE_HOOKUP_OBJECT (window2, vbox15, "vbox15");
  GLADE_HOOKUP_OBJECT (window2, vbox25, "vbox25");
  GLADE_HOOKUP_OBJECT (window2, eventbox4, "eventbox4");
  GLADE_HOOKUP_OBJECT (window2, label64, "label64");
  GLADE_HOOKUP_OBJECT (window2, button14, "button14");

  return window2;
}

GtkWidget*
create_dialog2 (void)
{
  GtkWidget *dialog2;
  GtkWidget *dialog_vbox2;
  GtkWidget *dialog_action_area2;
  GtkWidget *closebutton1;

  dialog2 = gtk_dialog_new ();
  gtk_window_set_title (GTK_WINDOW (dialog2), _("unused"));
  gtk_window_set_type_hint (GTK_WINDOW (dialog2), GDK_WINDOW_TYPE_HINT_DIALOG);

  dialog_vbox2 = GTK_DIALOG (dialog2)->vbox;
  gtk_widget_show (dialog_vbox2);

  dialog_action_area2 = GTK_DIALOG (dialog2)->action_area;
  gtk_widget_show (dialog_action_area2);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area2), GTK_BUTTONBOX_END);

  closebutton1 = gtk_button_new_from_stock ("gtk-close");
  gtk_widget_show (closebutton1);
  gtk_dialog_add_action_widget (GTK_DIALOG (dialog2), closebutton1, GTK_RESPONSE_CLOSE);
  GTK_WIDGET_SET_FLAGS (closebutton1, GTK_CAN_DEFAULT);

  
  GLADE_HOOKUP_OBJECT_NO_REF (dialog2, dialog2, "dialog2");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog2, dialog_vbox2, "dialog_vbox2");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog2, dialog_action_area2, "dialog_action_area2");
  GLADE_HOOKUP_OBJECT (dialog2, closebutton1, "closebutton1");

  return dialog2;
}

GtkWidget*
create_dialog3 (void)
{
  GtkWidget *dialog3;
  GtkWidget *dialog_vbox3;
  GtkWidget *vbox21;
  GtkWidget *label85;
  GtkWidget *entry12;
  GtkWidget *dialog_action_area3;
  GtkWidget *cancelbutton2;
  GtkWidget *okbutton2;

  dialog3 = gtk_dialog_new ();
  gtk_window_set_title (GTK_WINDOW (dialog3), _("Trackdir Config"));
  gtk_window_set_type_hint (GTK_WINDOW (dialog3), GDK_WINDOW_TYPE_HINT_DIALOG);

  dialog_vbox3 = GTK_DIALOG (dialog3)->vbox;
  gtk_widget_show (dialog_vbox3);

  vbox21 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox21);
  gtk_box_pack_start (GTK_BOX (dialog_vbox3), vbox21, TRUE, TRUE, 0);

  label85 = gtk_label_new (_("Directory in which the tracks should be written:"));
  gtk_widget_show (label85);
  gtk_box_pack_start (GTK_BOX (vbox21), label85, FALSE, FALSE, 0);
  gtk_label_set_line_wrap (GTK_LABEL (label85), TRUE);

  entry12 = gtk_entry_new ();
  gtk_widget_show (entry12);
  gtk_box_pack_start (GTK_BOX (vbox21), entry12, FALSE, FALSE, 0);

  dialog_action_area3 = GTK_DIALOG (dialog3)->action_area;
  gtk_widget_show (dialog_action_area3);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area3), GTK_BUTTONBOX_END);

  cancelbutton2 = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_show (cancelbutton2);
  gtk_dialog_add_action_widget (GTK_DIALOG (dialog3), cancelbutton2, GTK_RESPONSE_CANCEL);
  GTK_WIDGET_SET_FLAGS (cancelbutton2, GTK_CAN_DEFAULT);

  okbutton2 = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_show (okbutton2);
  gtk_dialog_add_action_widget (GTK_DIALOG (dialog3), okbutton2, GTK_RESPONSE_OK);
  GTK_WIDGET_SET_FLAGS (okbutton2, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) cancelbutton2, "clicked",
                    G_CALLBACK (on_cancelbutton2_clicked),
                    NULL);
  g_signal_connect ((gpointer) okbutton2, "clicked",
                    G_CALLBACK (on_okbutton2_clicked),
                    NULL);

  
  GLADE_HOOKUP_OBJECT_NO_REF (dialog3, dialog3, "dialog3");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog3, dialog_vbox3, "dialog_vbox3");
  GLADE_HOOKUP_OBJECT (dialog3, vbox21, "vbox21");
  GLADE_HOOKUP_OBJECT (dialog3, label85, "label85");
  GLADE_HOOKUP_OBJECT (dialog3, entry12, "entry12");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog3, dialog_action_area3, "dialog_action_area3");
  GLADE_HOOKUP_OBJECT (dialog3, cancelbutton2, "cancelbutton2");
  GLADE_HOOKUP_OBJECT (dialog3, okbutton2, "okbutton2");

  return dialog3;
}

GtkWidget*
create_dialog4 (void)
{
  GtkWidget *dialog4;
  GtkWidget *dialog_vbox4;
  GtkWidget *frame13;
  GtkWidget *alignment14;
  GtkWidget *vbox23;
  GtkWidget *label103;
  GtkWidget *vbox24;
  GtkWidget *radiobutton2;
  GSList *radiobutton2_group = NULL;
  GtkWidget *radiobutton3;
  GtkWidget *radiobutton4;
  GtkWidget *radiobutton5;
  GtkWidget *radiobutton6;
  GtkWidget *radiobutton7;
  GtkWidget *label102;
  GtkWidget *dialog_action_area4;
  GtkWidget *cancelbutton3;
  GtkWidget *okbutton3;

  dialog4 = gtk_dialog_new ();
  gtk_window_set_title (GTK_WINDOW (dialog4), _("Map DL"));
  gtk_window_set_type_hint (GTK_WINDOW (dialog4), GDK_WINDOW_TYPE_HINT_DIALOG);

  dialog_vbox4 = GTK_DIALOG (dialog4)->vbox;
  gtk_widget_show (dialog_vbox4);

  frame13 = gtk_frame_new (NULL);
  gtk_widget_show (frame13);
  gtk_box_pack_start (GTK_BOX (dialog_vbox4), frame13, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (frame13), 5);

  alignment14 = gtk_alignment_new (0.5, 0.5, 1, 1);
  gtk_widget_show (alignment14);
  gtk_container_add (GTK_CONTAINER (frame13), alignment14);
  gtk_alignment_set_padding (GTK_ALIGNMENT (alignment14), 0, 0, 12, 0);

  vbox23 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox23);
  gtk_container_add (GTK_CONTAINER (alignment14), vbox23);

  label103 = gtk_label_new (_("Download maps of currently visible area:"));
  gtk_widget_show (label103);
  gtk_box_pack_start (GTK_BOX (vbox23), label103, FALSE, FALSE, 0);
  gtk_widget_set_size_request (label103, 250, -1);
  gtk_label_set_line_wrap (GTK_LABEL (label103), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label103), 0, 0.5);

  vbox24 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox24);
  gtk_box_pack_start (GTK_BOX (vbox23), vbox24, TRUE, TRUE, 0);

  radiobutton2 = gtk_radio_button_new_with_mnemonic (NULL, _("+ 1 zoom level"));
  gtk_widget_show (radiobutton2);
  gtk_box_pack_start (GTK_BOX (vbox24), radiobutton2, FALSE, FALSE, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton2), radiobutton2_group);
  radiobutton2_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton2));

  radiobutton3 = gtk_radio_button_new_with_mnemonic (NULL, _("+ 2 zoom levels"));
  gtk_widget_show (radiobutton3);
  gtk_box_pack_start (GTK_BOX (vbox24), radiobutton3, FALSE, FALSE, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton3), radiobutton2_group);
  radiobutton2_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton3));

  radiobutton4 = gtk_radio_button_new_with_mnemonic (NULL, _("+ 3 zoom levels"));
  gtk_widget_show (radiobutton4);
  gtk_box_pack_start (GTK_BOX (vbox24), radiobutton4, FALSE, FALSE, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton4), radiobutton2_group);
  radiobutton2_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton4));

  radiobutton5 = gtk_radio_button_new_with_mnemonic (NULL, _("+ 4 zoom levels (~25MB)"));
  gtk_widget_show (radiobutton5);
  gtk_box_pack_start (GTK_BOX (vbox24), radiobutton5, FALSE, FALSE, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton5), radiobutton2_group);
  radiobutton2_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton5));
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (radiobutton5), TRUE);

  radiobutton6 = gtk_radio_button_new_with_mnemonic (NULL, _("+ 5 zoom levels (~100MB)"));
  gtk_widget_show (radiobutton6);
  gtk_box_pack_start (GTK_BOX (vbox24), radiobutton6, FALSE, FALSE, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton6), radiobutton2_group);
  radiobutton2_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton6));

  radiobutton7 = gtk_radio_button_new_with_mnemonic (NULL, _("+ 6 zoom levels (~400MB)"));
  gtk_widget_show (radiobutton7);
  gtk_box_pack_start (GTK_BOX (vbox24), radiobutton7, FALSE, FALSE, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton7), radiobutton2_group);
  radiobutton2_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton7));

  label102 = gtk_label_new (_("<b> Map Download </b>"));
  gtk_widget_show (label102);
  gtk_frame_set_label_widget (GTK_FRAME (frame13), label102);
  gtk_label_set_use_markup (GTK_LABEL (label102), TRUE);

  dialog_action_area4 = GTK_DIALOG (dialog4)->action_area;
  gtk_widget_show (dialog_action_area4);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area4), GTK_BUTTONBOX_END);

  cancelbutton3 = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_show (cancelbutton3);
  gtk_dialog_add_action_widget (GTK_DIALOG (dialog4), cancelbutton3, GTK_RESPONSE_CANCEL);
  GTK_WIDGET_SET_FLAGS (cancelbutton3, GTK_CAN_DEFAULT);

  okbutton3 = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_show (okbutton3);
  gtk_dialog_add_action_widget (GTK_DIALOG (dialog4), okbutton3, GTK_RESPONSE_OK);
  GTK_WIDGET_SET_FLAGS (okbutton3, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) cancelbutton3, "clicked",
                    G_CALLBACK (on_cancelbutton3_clicked),
                    NULL);
  g_signal_connect ((gpointer) okbutton3, "clicked",
                    G_CALLBACK (on_okbutton3_clicked),
                    NULL);

  
  GLADE_HOOKUP_OBJECT_NO_REF (dialog4, dialog4, "dialog4");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog4, dialog_vbox4, "dialog_vbox4");
  GLADE_HOOKUP_OBJECT (dialog4, frame13, "frame13");
  GLADE_HOOKUP_OBJECT (dialog4, alignment14, "alignment14");
  GLADE_HOOKUP_OBJECT (dialog4, vbox23, "vbox23");
  GLADE_HOOKUP_OBJECT (dialog4, label103, "label103");
  GLADE_HOOKUP_OBJECT (dialog4, vbox24, "vbox24");
  GLADE_HOOKUP_OBJECT (dialog4, radiobutton2, "radiobutton2");
  GLADE_HOOKUP_OBJECT (dialog4, radiobutton3, "radiobutton3");
  GLADE_HOOKUP_OBJECT (dialog4, radiobutton4, "radiobutton4");
  GLADE_HOOKUP_OBJECT (dialog4, radiobutton5, "radiobutton5");
  GLADE_HOOKUP_OBJECT (dialog4, radiobutton6, "radiobutton6");
  GLADE_HOOKUP_OBJECT (dialog4, radiobutton7, "radiobutton7");
  GLADE_HOOKUP_OBJECT (dialog4, label102, "label102");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog4, dialog_action_area4, "dialog_action_area4");
  GLADE_HOOKUP_OBJECT (dialog4, cancelbutton3, "cancelbutton3");
  GLADE_HOOKUP_OBJECT (dialog4, okbutton3, "okbutton3");

  return dialog4;
}

GtkWidget*
create_window3 (void)
{
  GtkWidget *window3;
  GtkWidget *vbox27;
  GtkWidget *vbox26;
  GtkWidget *label104;
  GtkWidget *eventbox1;
  GtkWidget *drawingarea2;
  GtkWidget *hbox26;
  GtkWidget *button21;
  GtkWidget *button29;

  window3 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window3), _("Geo Photo"));
  gtk_window_set_position (GTK_WINDOW (window3), GTK_WIN_POS_MOUSE);
  gtk_window_set_decorated (GTK_WINDOW (window3), FALSE);
  gtk_window_set_type_hint (GTK_WINDOW (window3), GDK_WINDOW_TYPE_HINT_MENU);

  vbox27 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox27);
  gtk_container_add (GTK_CONTAINER (window3), vbox27);

  vbox26 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox26);
  gtk_box_pack_start (GTK_BOX (vbox27), vbox26, TRUE, TRUE, 0);

  label104 = gtk_label_new (_("--"));
  gtk_widget_show (label104);
  gtk_box_pack_start (GTK_BOX (vbox26), label104, FALSE, FALSE, 0);
  gtk_misc_set_alignment (GTK_MISC (label104), 0, 0.5);

  eventbox1 = gtk_event_box_new ();
  gtk_widget_show (eventbox1);
  gtk_box_pack_start (GTK_BOX (vbox26), eventbox1, TRUE, TRUE, 0);

  drawingarea2 = gtk_drawing_area_new ();
  gtk_widget_show (drawingarea2);
  gtk_container_add (GTK_CONTAINER (eventbox1), drawingarea2);
  gtk_widget_set_size_request (drawingarea2, 240, 180);
  gtk_widget_set_events (drawingarea2, GDK_EXPOSURE_MASK);

  hbox26 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox26);
  gtk_box_pack_start (GTK_BOX (vbox27), hbox26, FALSE, FALSE, 0);

  button21 = gtk_button_new_with_mnemonic (_("Big"));
  gtk_widget_show (button21);
  gtk_box_pack_start (GTK_BOX (hbox26), button21, TRUE, TRUE, 0);

  button29 = gtk_button_new_with_mnemonic (_("Go To"));
  gtk_widget_show (button29);
  gtk_box_pack_start (GTK_BOX (hbox26), button29, TRUE, TRUE, 0);

  g_signal_connect ((gpointer) window3, "delete_event",
                    G_CALLBACK (on_window3_delete_event),
                    NULL);
  g_signal_connect ((gpointer) eventbox1, "button_release_event",
                    G_CALLBACK (on_eventbox1_button_release_event),
                    NULL);
  g_signal_connect ((gpointer) drawingarea2, "configure_event",
                    G_CALLBACK (on_drawingarea2_configure_event),
                    NULL);
  g_signal_connect ((gpointer) drawingarea2, "expose_event",
                    G_CALLBACK (on_drawingarea2_expose_event),
                    NULL);

  
  GLADE_HOOKUP_OBJECT_NO_REF (window3, window3, "window3");
  GLADE_HOOKUP_OBJECT (window3, vbox27, "vbox27");
  GLADE_HOOKUP_OBJECT (window3, vbox26, "vbox26");
  GLADE_HOOKUP_OBJECT (window3, label104, "label104");
  GLADE_HOOKUP_OBJECT (window3, eventbox1, "eventbox1");
  GLADE_HOOKUP_OBJECT (window3, drawingarea2, "drawingarea2");
  GLADE_HOOKUP_OBJECT (window3, hbox26, "hbox26");
  GLADE_HOOKUP_OBJECT (window3, button21, "button21");
  GLADE_HOOKUP_OBJECT (window3, button29, "button29");

  gtk_widget_grab_focus (button21);
  return window3;
}

GtkWidget*
create_dialog5 (void)
{
  GtkWidget *dialog5;
  GtkWidget *dialog_vbox5;
  GtkWidget *dialog_action_area5;
  GtkWidget *cancelbutton4;
  GtkWidget *okbutton4;

  dialog5 = gtk_dialog_new ();
  gtk_window_set_title (GTK_WINDOW (dialog5), _("Add POI"));
  gtk_window_set_position (GTK_WINDOW (dialog5), GTK_WIN_POS_CENTER_ON_PARENT);
  gtk_window_set_default_size (GTK_WINDOW (dialog5), 470, 420);

  dialog_vbox5 = GTK_DIALOG (dialog5)->vbox;
  gtk_widget_show (dialog_vbox5);

  dialog_action_area5 = GTK_DIALOG (dialog5)->action_area;
  gtk_widget_show (dialog_action_area5);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area5), GTK_BUTTONBOX_END);

  cancelbutton4 = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_show (cancelbutton4);
  gtk_dialog_add_action_widget (GTK_DIALOG (dialog5), cancelbutton4, GTK_RESPONSE_CANCEL);
  GTK_WIDGET_SET_FLAGS (cancelbutton4, GTK_CAN_DEFAULT);

  okbutton4 = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_show (okbutton4);
  gtk_dialog_add_action_widget (GTK_DIALOG (dialog5), okbutton4, GTK_RESPONSE_OK);
  GTK_WIDGET_SET_FLAGS (okbutton4, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) dialog5, "delete_event",
                    G_CALLBACK (on_dialog5_delete_event),
                    NULL);
  g_signal_connect ((gpointer) cancelbutton4, "clicked",
                    G_CALLBACK (on_cancelbutton4_clicked),
                    NULL);
  g_signal_connect ((gpointer) okbutton4, "clicked",
                    G_CALLBACK (on_okbutton4_clicked),
                    NULL);

  
  GLADE_HOOKUP_OBJECT_NO_REF (dialog5, dialog5, "dialog5");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog5, dialog_vbox5, "dialog_vbox5");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog5, dialog_action_area5, "dialog_action_area5");
  GLADE_HOOKUP_OBJECT (dialog5, cancelbutton4, "cancelbutton4");
  GLADE_HOOKUP_OBJECT (dialog5, okbutton4, "okbutton4");

  return dialog5;
}

GtkWidget*
create_window4 (void)
{
  GtkWidget *window4;
  GtkWidget *scrolledwindow4;
  GtkWidget *treeview1;

  window4 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window4), _("unused cols"));

  scrolledwindow4 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow4);
  gtk_container_add (GTK_CONTAINER (window4), scrolledwindow4);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow4), GTK_SHADOW_IN);

  treeview1 = gtk_tree_view_new ();
  gtk_widget_show (treeview1);
  gtk_container_add (GTK_CONTAINER (scrolledwindow4), treeview1);

  
  GLADE_HOOKUP_OBJECT_NO_REF (window4, window4, "window4");
  GLADE_HOOKUP_OBJECT (window4, scrolledwindow4, "scrolledwindow4");
  GLADE_HOOKUP_OBJECT (window4, treeview1, "treeview1");

  return window4;
}

GtkWidget*
create_dialog6 (void)
{
  GtkWidget *dialog6;
  GtkWidget *dialog_vbox6;
  GtkWidget *combobox4;
  GtkWidget *dialog_action_area6;
  GtkWidget *cancelbutton5;
  GtkWidget *okbutton5;

  dialog6 = gtk_dialog_new ();
  gtk_window_set_title (GTK_WINDOW (dialog6), _("Show POIs"));
  gtk_window_set_type_hint (GTK_WINDOW (dialog6), GDK_WINDOW_TYPE_HINT_DIALOG);

  dialog_vbox6 = GTK_DIALOG (dialog6)->vbox;
  gtk_widget_show (dialog_vbox6);

  combobox4 = gtk_combo_box_new_text ();
  gtk_widget_show (combobox4);
  gtk_box_pack_start (GTK_BOX (dialog_vbox6), combobox4, FALSE, TRUE, 0);
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox4), _("-- Show All --"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox4), _("Accomodation"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox4), _("Businesses"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox4), _("Car"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox4), _("Cultural"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox4), _("Medical"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox4), _("Cafe / Pub / Nightlife"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox4), _("Place of Worship"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox4), _("Public Transportation"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox4), _("Restaurant"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox4), _("Services"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox4), _("Sights / Leisure"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox4), _("Shopping"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox4), _("Sport"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox4), _("My Personal Places"));

  dialog_action_area6 = GTK_DIALOG (dialog6)->action_area;
  gtk_widget_show (dialog_action_area6);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area6), GTK_BUTTONBOX_END);

  cancelbutton5 = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_show (cancelbutton5);
  gtk_dialog_add_action_widget (GTK_DIALOG (dialog6), cancelbutton5, GTK_RESPONSE_CANCEL);
  GTK_WIDGET_SET_FLAGS (cancelbutton5, GTK_CAN_DEFAULT);

  okbutton5 = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_show (okbutton5);
  gtk_dialog_add_action_widget (GTK_DIALOG (dialog6), okbutton5, GTK_RESPONSE_OK);
  GTK_WIDGET_SET_FLAGS (okbutton5, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) dialog6, "delete_event",
                    G_CALLBACK (on_dialog6_delete_event),
                    NULL);
  g_signal_connect ((gpointer) cancelbutton5, "clicked",
                    G_CALLBACK (on_cancelbutton5_clicked),
                    NULL);
  g_signal_connect ((gpointer) okbutton5, "clicked",
                    G_CALLBACK (on_okbutton5_clicked),
                    NULL);

  
  GLADE_HOOKUP_OBJECT_NO_REF (dialog6, dialog6, "dialog6");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog6, dialog_vbox6, "dialog_vbox6");
  GLADE_HOOKUP_OBJECT (dialog6, combobox4, "combobox4");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog6, dialog_action_area6, "dialog_action_area6");
  GLADE_HOOKUP_OBJECT (dialog6, cancelbutton5, "cancelbutton5");
  GLADE_HOOKUP_OBJECT (dialog6, okbutton5, "okbutton5");

  gtk_widget_grab_focus (okbutton5);
  return dialog6;
}

GtkWidget*
create_window5 (void)
{
  GtkWidget *window5;
  GtkWidget *vbox29;
  GtkWidget *vbox30;
  GtkWidget *label110;
  GtkWidget *scrolledwindow10;
  GtkWidget *viewport7;
  GtkWidget *label111;
  GtkWidget *label112;
  GtkWidget *table6;
  GtkWidget *button27;
  GtkWidget *alignment18;
  GtkWidget *hbox35;
  GtkWidget *image4;
  GtkWidget *label130;
  GtkWidget *button33;
  GtkWidget *alignment17;
  GtkWidget *hbox34;
  GtkWidget *image3;
  GtkWidget *label129;
  GtkWidget *button34;
  GtkWidget *alignment16;
  GtkWidget *hbox33;
  GtkWidget *image2;
  GtkWidget *label128;
  GtkWidget *button22;
  GtkWidget *alignment15;
  GtkWidget *hbox32;
  GtkWidget *image1;
  GtkWidget *label127;

  window5 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window5), _("POI"));
  gtk_window_set_position (GTK_WINDOW (window5), GTK_WIN_POS_MOUSE);
  gtk_window_set_type_hint (GTK_WINDOW (window5), GDK_WINDOW_TYPE_HINT_DIALOG);

  vbox29 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox29);
  gtk_container_add (GTK_CONTAINER (window5), vbox29);

  vbox30 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox30);
  gtk_box_pack_start (GTK_BOX (vbox29), vbox30, TRUE, TRUE, 0);

  label110 = gtk_label_new (_("<b>-----</b>"));
  gtk_widget_show (label110);
  gtk_box_pack_start (GTK_BOX (vbox30), label110, FALSE, FALSE, 0);
  gtk_widget_set_size_request (label110, 320, -1);
  gtk_label_set_use_markup (GTK_LABEL (label110), TRUE);
  gtk_label_set_line_wrap (GTK_LABEL (label110), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label110), 0, 0.5);
  gtk_misc_set_padding (GTK_MISC (label110), 0, 2);

  scrolledwindow10 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow10);
  gtk_box_pack_start (GTK_BOX (vbox30), scrolledwindow10, TRUE, TRUE, 0);
  gtk_widget_set_size_request (scrolledwindow10, -1, 200);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow10), GTK_POLICY_NEVER, GTK_POLICY_ALWAYS);

  viewport7 = gtk_viewport_new (NULL, NULL);
  gtk_widget_show (viewport7);
  gtk_container_add (GTK_CONTAINER (scrolledwindow10), viewport7);

  label111 = gtk_label_new (_("-"));
  gtk_widget_show (label111);
  gtk_container_add (GTK_CONTAINER (viewport7), label111);
  gtk_widget_set_size_request (label111, 320, -1);
  gtk_label_set_use_markup (GTK_LABEL (label111), TRUE);
  gtk_label_set_line_wrap (GTK_LABEL (label111), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label111), 0, 0);
  gtk_misc_set_padding (GTK_MISC (label111), 0, 2);

  label112 = gtk_label_new (_("<b>-</b>"));
  gtk_widget_show (label112);
  gtk_box_pack_start (GTK_BOX (vbox30), label112, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label112), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label112), 0, 0.5);

  table6 = gtk_table_new (2, 2, FALSE);
  gtk_widget_show (table6);
  gtk_box_pack_start (GTK_BOX (vbox29), table6, FALSE, TRUE, 0);
  gtk_table_set_col_spacings (GTK_TABLE (table6), 3);

  button27 = gtk_button_new ();
  gtk_widget_show (button27);
  gtk_table_attach (GTK_TABLE (table6), button27, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 2, 2);

  alignment18 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment18);
  gtk_container_add (GTK_CONTAINER (button27), alignment18);

  hbox35 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox35);
  gtk_container_add (GTK_CONTAINER (alignment18), hbox35);

  image4 = gtk_image_new_from_stock ("gtk-jump-to", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image4);
  gtk_box_pack_start (GTK_BOX (hbox35), image4, FALSE, FALSE, 0);

  label130 = gtk_label_new_with_mnemonic (_("Go To "));
  gtk_widget_show (label130);
  gtk_box_pack_start (GTK_BOX (hbox35), label130, FALSE, FALSE, 0);

  button33 = gtk_button_new ();
  gtk_widget_show (button33);
  gtk_table_attach (GTK_TABLE (table6), button33, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 2, 2);

  alignment17 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment17);
  gtk_container_add (GTK_CONTAINER (button33), alignment17);

  hbox34 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox34);
  gtk_container_add (GTK_CONTAINER (alignment17), hbox34);

  image3 = gtk_image_new_from_stock ("gtk-edit", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image3);
  gtk_box_pack_start (GTK_BOX (hbox34), image3, FALSE, FALSE, 0);

  label129 = gtk_label_new_with_mnemonic (_("Edit"));
  gtk_widget_show (label129);
  gtk_box_pack_start (GTK_BOX (hbox34), label129, FALSE, FALSE, 0);

  button34 = gtk_button_new ();
  gtk_widget_show (button34);
  gtk_table_attach (GTK_TABLE (table6), button34, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 2, 2);

  alignment16 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment16);
  gtk_container_add (GTK_CONTAINER (button34), alignment16);

  hbox33 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox33);
  gtk_container_add (GTK_CONTAINER (alignment16), hbox33);

  image2 = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image2);
  gtk_box_pack_start (GTK_BOX (hbox33), image2, FALSE, FALSE, 0);

  label128 = gtk_label_new_with_mnemonic (_("Delete"));
  gtk_widget_show (label128);
  gtk_box_pack_start (GTK_BOX (hbox33), label128, FALSE, FALSE, 0);

  button22 = gtk_button_new ();
  gtk_widget_show (button22);
  gtk_table_attach (GTK_TABLE (table6), button22, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 2, 2);

  alignment15 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment15);
  gtk_container_add (GTK_CONTAINER (button22), alignment15);

  hbox32 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox32);
  gtk_container_add (GTK_CONTAINER (alignment15), hbox32);

  image1 = gtk_image_new_from_stock ("gtk-close", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image1);
  gtk_box_pack_start (GTK_BOX (hbox32), image1, FALSE, FALSE, 0);

  label127 = gtk_label_new_with_mnemonic (_("Close"));
  gtk_widget_show (label127);
  gtk_box_pack_start (GTK_BOX (hbox32), label127, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) button22, "clicked",
                    G_CALLBACK (on_button22_clicked),
                    NULL);

  
  GLADE_HOOKUP_OBJECT_NO_REF (window5, window5, "window5");
  GLADE_HOOKUP_OBJECT (window5, vbox29, "vbox29");
  GLADE_HOOKUP_OBJECT (window5, vbox30, "vbox30");
  GLADE_HOOKUP_OBJECT (window5, label110, "label110");
  GLADE_HOOKUP_OBJECT (window5, scrolledwindow10, "scrolledwindow10");
  GLADE_HOOKUP_OBJECT (window5, viewport7, "viewport7");
  GLADE_HOOKUP_OBJECT (window5, label111, "label111");
  GLADE_HOOKUP_OBJECT (window5, label112, "label112");
  GLADE_HOOKUP_OBJECT (window5, table6, "table6");
  GLADE_HOOKUP_OBJECT (window5, button27, "button27");
  GLADE_HOOKUP_OBJECT (window5, alignment18, "alignment18");
  GLADE_HOOKUP_OBJECT (window5, hbox35, "hbox35");
  GLADE_HOOKUP_OBJECT (window5, image4, "image4");
  GLADE_HOOKUP_OBJECT (window5, label130, "label130");
  GLADE_HOOKUP_OBJECT (window5, button33, "button33");
  GLADE_HOOKUP_OBJECT (window5, alignment17, "alignment17");
  GLADE_HOOKUP_OBJECT (window5, hbox34, "hbox34");
  GLADE_HOOKUP_OBJECT (window5, image3, "image3");
  GLADE_HOOKUP_OBJECT (window5, label129, "label129");
  GLADE_HOOKUP_OBJECT (window5, button34, "button34");
  GLADE_HOOKUP_OBJECT (window5, alignment16, "alignment16");
  GLADE_HOOKUP_OBJECT (window5, hbox33, "hbox33");
  GLADE_HOOKUP_OBJECT (window5, image2, "image2");
  GLADE_HOOKUP_OBJECT (window5, label128, "label128");
  GLADE_HOOKUP_OBJECT (window5, button22, "button22");
  GLADE_HOOKUP_OBJECT (window5, alignment15, "alignment15");
  GLADE_HOOKUP_OBJECT (window5, hbox32, "hbox32");
  GLADE_HOOKUP_OBJECT (window5, image1, "image1");
  GLADE_HOOKUP_OBJECT (window5, label127, "label127");

  return window5;
}

GtkWidget*
create_window6 (void)
{
  GtkWidget *window6;
  GtkWidget *vbox33;
  GtkWidget *scrolledwindow5;
  GtkWidget *viewport3;
  GtkWidget *vbox28;
  GtkWidget *hbox21;
  GtkWidget *radiobutton12;
  GSList *radiobutton12_group = NULL;
  GtkWidget *radiobutton11;
  GtkWidget *hbox20;
  GtkWidget *label108;
  GtkWidget *entry14;
  GtkWidget *label109;
  GtkWidget *entry15;
  GtkWidget *button28;
  GtkWidget *label107;
  GtkWidget *combobox2;
  GtkWidget *combobox3;
  GtkWidget *label105;
  GtkWidget *entry13;
  GtkWidget *label106;
  GtkWidget *scrolledwindow3;
  GtkWidget *textview1;
  GtkWidget *hbox19;
  GtkWidget *radiobutton8;
  GSList *radiobutton8_group = NULL;
  GtkWidget *radiobutton9;
  GtkWidget *radiobutton10;
  GtkWidget *checkbutton10;
  GtkWidget *toolbar2;
  GtkIconSize tmp_toolbar_icon_size;
  GtkWidget *toolitem8;
  GtkWidget *toolitem7;
  GtkWidget *label118;
  GtkWidget *toolitem9;
  GtkWidget *button25;
  GtkWidget *toolitem10;
  GtkWidget *button24;

  window6 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window6), _("Add POI"));
  gtk_window_set_default_size (GTK_WINDOW (window6), 470, 470);

  vbox33 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox33);
  gtk_container_add (GTK_CONTAINER (window6), vbox33);

  scrolledwindow5 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow5);
  gtk_box_pack_start (GTK_BOX (vbox33), scrolledwindow5, TRUE, TRUE, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow5), GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);

  viewport3 = gtk_viewport_new (NULL, NULL);
  gtk_widget_show (viewport3);
  gtk_container_add (GTK_CONTAINER (scrolledwindow5), viewport3);
  gtk_container_set_border_width (GTK_CONTAINER (viewport3), 5);
  gtk_viewport_set_shadow_type (GTK_VIEWPORT (viewport3), GTK_SHADOW_NONE);

  vbox28 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox28);
  gtk_container_add (GTK_CONTAINER (viewport3), vbox28);

  hbox21 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox21);
  gtk_box_pack_start (GTK_BOX (vbox28), hbox21, TRUE, TRUE, 0);

  radiobutton12 = gtk_radio_button_new_with_mnemonic (NULL, _("personal"));
  gtk_widget_show (radiobutton12);
  gtk_box_pack_start (GTK_BOX (hbox21), radiobutton12, FALSE, FALSE, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton12), radiobutton12_group);
  radiobutton12_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton12));

  radiobutton11 = gtk_radio_button_new_with_mnemonic (NULL, _("public"));
  gtk_widget_show (radiobutton11);
  gtk_box_pack_start (GTK_BOX (hbox21), radiobutton11, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (radiobutton11), 2);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton11), radiobutton12_group);
  radiobutton12_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton11));
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (radiobutton11), TRUE);

  hbox20 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox20);
  gtk_box_pack_start (GTK_BOX (vbox28), hbox20, TRUE, TRUE, 0);

  label108 = gtk_label_new (_("Lat: "));
  gtk_widget_show (label108);
  gtk_box_pack_start (GTK_BOX (hbox20), label108, FALSE, FALSE, 0);
  gtk_misc_set_padding (GTK_MISC (label108), 1, 0);

  entry14 = gtk_entry_new ();
  gtk_widget_show (entry14);
  gtk_box_pack_start (GTK_BOX (hbox20), entry14, TRUE, TRUE, 0);
  gtk_entry_set_width_chars (GTK_ENTRY (entry14), 5);

  label109 = gtk_label_new (_(" Lon: "));
  gtk_widget_show (label109);
  gtk_box_pack_start (GTK_BOX (hbox20), label109, FALSE, FALSE, 0);
  gtk_misc_set_padding (GTK_MISC (label109), 1, 0);

  entry15 = gtk_entry_new ();
  gtk_widget_show (entry15);
  gtk_box_pack_start (GTK_BOX (hbox20), entry15, TRUE, TRUE, 0);
  gtk_entry_set_width_chars (GTK_ENTRY (entry15), 5);

  button28 = gtk_button_new_with_mnemonic (_("GPS"));
  gtk_widget_show (button28);
  gtk_box_pack_start (GTK_BOX (hbox20), button28, FALSE, FALSE, 0);

  label107 = gtk_label_new (_("Category:"));
  gtk_widget_show (label107);
  gtk_box_pack_start (GTK_BOX (vbox28), label107, FALSE, FALSE, 7);
  gtk_misc_set_alignment (GTK_MISC (label107), 0, 0.5);

  combobox2 = gtk_combo_box_new_text ();
  gtk_widget_show (combobox2);
  gtk_box_pack_start (GTK_BOX (vbox28), combobox2, FALSE, TRUE, 1);
  GTK_WIDGET_SET_FLAGS (combobox2, GTK_CAN_FOCUS);
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("- please choose -"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("Accomodation"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("Businesses"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("Car"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("Cultural"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("Medical"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("Cafe / Pub / Nightlife"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("Place of Worship"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("Public Transportation"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("Restaurant & Food"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("Services"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("Sights & Leisure"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("Shopping"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("Sport"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox2), _("My Personal Places"));
  gtk_combo_box_set_add_tearoffs (GTK_COMBO_BOX (combobox2), TRUE);

  combobox3 = gtk_combo_box_new_text ();
  gtk_box_pack_start (GTK_BOX (vbox28), combobox3, FALSE, TRUE, 0);

  label105 = gtk_label_new (_("Name - Keywords / Tags:"));
  gtk_widget_show (label105);
  gtk_box_pack_start (GTK_BOX (vbox28), label105, FALSE, FALSE, 7);
  gtk_misc_set_alignment (GTK_MISC (label105), 0, 0.5);

  entry13 = gtk_entry_new ();
  gtk_widget_show (entry13);
  gtk_box_pack_start (GTK_BOX (vbox28), entry13, FALSE, FALSE, 0);

  label106 = gtk_label_new (_("Description:"));
  gtk_widget_show (label106);
  gtk_box_pack_start (GTK_BOX (vbox28), label106, FALSE, FALSE, 7);
  gtk_misc_set_alignment (GTK_MISC (label106), 0, 0.5);

  scrolledwindow3 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow3);
  gtk_box_pack_start (GTK_BOX (vbox28), scrolledwindow3, TRUE, TRUE, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow3), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow3), GTK_SHADOW_IN);

  textview1 = gtk_text_view_new ();
  gtk_widget_show (textview1);
  gtk_container_add (GTK_CONTAINER (scrolledwindow3), textview1);
  gtk_widget_set_size_request (textview1, 300, -1);
  gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (textview1), GTK_WRAP_WORD);
  gtk_text_view_set_left_margin (GTK_TEXT_VIEW (textview1), 2);

  hbox19 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox19);
  gtk_box_pack_start (GTK_BOX (vbox28), hbox19, TRUE, TRUE, 0);

  radiobutton8 = gtk_radio_button_new_with_mnemonic (NULL, _("budget"));
  gtk_widget_show (radiobutton8);
  gtk_box_pack_start (GTK_BOX (hbox19), radiobutton8, FALSE, FALSE, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton8), radiobutton8_group);
  radiobutton8_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton8));

  radiobutton9 = gtk_radio_button_new_with_mnemonic (NULL, _("medium"));
  gtk_widget_show (radiobutton9);
  gtk_box_pack_start (GTK_BOX (hbox19), radiobutton9, FALSE, FALSE, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton9), radiobutton8_group);
  radiobutton8_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton9));
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (radiobutton9), TRUE);

  radiobutton10 = gtk_radio_button_new_with_mnemonic (NULL, _("exclusive"));
  gtk_widget_show (radiobutton10);
  gtk_box_pack_start (GTK_BOX (hbox19), radiobutton10, FALSE, FALSE, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton10), radiobutton8_group);
  radiobutton8_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton10));

  checkbutton10 = gtk_check_button_new_with_mnemonic (_("extended opening hours"));
  gtk_widget_show (checkbutton10);
  gtk_box_pack_start (GTK_BOX (vbox28), checkbutton10, FALSE, FALSE, 0);

  toolbar2 = gtk_toolbar_new ();
  gtk_widget_show (toolbar2);
  gtk_box_pack_start (GTK_BOX (vbox33), toolbar2, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (toolbar2), 6);
  gtk_toolbar_set_style (GTK_TOOLBAR (toolbar2), GTK_TOOLBAR_ICONS);
  tmp_toolbar_icon_size = gtk_toolbar_get_icon_size (GTK_TOOLBAR (toolbar2));

  toolitem8 = (GtkWidget*) gtk_tool_item_new ();
  gtk_widget_show (toolitem8);
  gtk_container_add (GTK_CONTAINER (toolbar2), toolitem8);

  toolitem7 = (GtkWidget*) gtk_tool_item_new ();
  gtk_widget_show (toolitem7);
  gtk_container_add (GTK_CONTAINER (toolbar2), toolitem7);

  label118 = gtk_label_new (_("       "));
  gtk_widget_show (label118);
  gtk_container_add (GTK_CONTAINER (toolitem7), label118);

  toolitem9 = (GtkWidget*) gtk_tool_item_new ();
  gtk_widget_show (toolitem9);
  gtk_container_add (GTK_CONTAINER (toolbar2), toolitem9);

  button25 = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_show (button25);
  gtk_container_add (GTK_CONTAINER (toolitem9), button25);
  gtk_container_set_border_width (GTK_CONTAINER (button25), 7);

  toolitem10 = (GtkWidget*) gtk_tool_item_new ();
  gtk_widget_show (toolitem10);
  gtk_container_add (GTK_CONTAINER (toolbar2), toolitem10);

  button24 = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_show (button24);
  gtk_container_add (GTK_CONTAINER (toolitem10), button24);
  gtk_container_set_border_width (GTK_CONTAINER (button24), 7);

  g_signal_connect ((gpointer) button28, "clicked",
                    G_CALLBACK (on_button28_clicked),
                    NULL);
  g_signal_connect ((gpointer) combobox2, "changed",
                    G_CALLBACK (on_combobox2_changed),
                    NULL);
  g_signal_connect ((gpointer) button25, "clicked",
                    G_CALLBACK (on_cancelbutton4_clicked),
                    NULL);
  g_signal_connect ((gpointer) button24, "clicked",
                    G_CALLBACK (on_okbutton4_clicked),
                    NULL);

  
  GLADE_HOOKUP_OBJECT_NO_REF (window6, window6, "window6");
  GLADE_HOOKUP_OBJECT (window6, vbox33, "vbox33");
  GLADE_HOOKUP_OBJECT (window6, scrolledwindow5, "scrolledwindow5");
  GLADE_HOOKUP_OBJECT (window6, viewport3, "viewport3");
  GLADE_HOOKUP_OBJECT (window6, vbox28, "vbox28");
  GLADE_HOOKUP_OBJECT (window6, hbox21, "hbox21");
  GLADE_HOOKUP_OBJECT (window6, radiobutton12, "radiobutton12");
  GLADE_HOOKUP_OBJECT (window6, radiobutton11, "radiobutton11");
  GLADE_HOOKUP_OBJECT (window6, hbox20, "hbox20");
  GLADE_HOOKUP_OBJECT (window6, label108, "label108");
  GLADE_HOOKUP_OBJECT (window6, entry14, "entry14");
  GLADE_HOOKUP_OBJECT (window6, label109, "label109");
  GLADE_HOOKUP_OBJECT (window6, entry15, "entry15");
  GLADE_HOOKUP_OBJECT (window6, button28, "button28");
  GLADE_HOOKUP_OBJECT (window6, label107, "label107");
  GLADE_HOOKUP_OBJECT (window6, combobox2, "combobox2");
  GLADE_HOOKUP_OBJECT (window6, combobox3, "combobox3");
  GLADE_HOOKUP_OBJECT (window6, label105, "label105");
  GLADE_HOOKUP_OBJECT (window6, entry13, "entry13");
  GLADE_HOOKUP_OBJECT (window6, label106, "label106");
  GLADE_HOOKUP_OBJECT (window6, scrolledwindow3, "scrolledwindow3");
  GLADE_HOOKUP_OBJECT (window6, textview1, "textview1");
  GLADE_HOOKUP_OBJECT (window6, hbox19, "hbox19");
  GLADE_HOOKUP_OBJECT (window6, radiobutton8, "radiobutton8");
  GLADE_HOOKUP_OBJECT (window6, radiobutton9, "radiobutton9");
  GLADE_HOOKUP_OBJECT (window6, radiobutton10, "radiobutton10");
  GLADE_HOOKUP_OBJECT (window6, checkbutton10, "checkbutton10");
  GLADE_HOOKUP_OBJECT (window6, toolbar2, "toolbar2");
  GLADE_HOOKUP_OBJECT (window6, toolitem8, "toolitem8");
  GLADE_HOOKUP_OBJECT (window6, toolitem7, "toolitem7");
  GLADE_HOOKUP_OBJECT (window6, label118, "label118");
  GLADE_HOOKUP_OBJECT (window6, toolitem9, "toolitem9");
  GLADE_HOOKUP_OBJECT (window6, button25, "button25");
  GLADE_HOOKUP_OBJECT (window6, toolitem10, "toolitem10");
  GLADE_HOOKUP_OBJECT (window6, button24, "button24");

  gtk_widget_grab_focus (radiobutton11);
  return window6;
}

GtkWidget*
create_window7 (void)
{
  GtkWidget *window7;

  window7 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window7), _("window7"));

  
  GLADE_HOOKUP_OBJECT_NO_REF (window7, window7, "window7");

  return window7;
}

GtkWidget*
create_window8 (void)
{
  GtkWidget *window8;
  GtkWidget *vbox34;
  GtkWidget *vbox35;
  GtkWidget *label119;
  GtkWidget *button26;

  window8 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window8), _("Friend Info"));
  gtk_window_set_position (GTK_WINDOW (window8), GTK_WIN_POS_MOUSE);
  gtk_window_set_destroy_with_parent (GTK_WINDOW (window8), TRUE);
  gtk_window_set_skip_taskbar_hint (GTK_WINDOW (window8), TRUE);
  gtk_window_set_skip_pager_hint (GTK_WINDOW (window8), TRUE);
  gtk_window_set_type_hint (GTK_WINDOW (window8), GDK_WINDOW_TYPE_HINT_DIALOG);

  vbox34 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox34);
  gtk_container_add (GTK_CONTAINER (window8), vbox34);

  vbox35 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox35);
  gtk_box_pack_start (GTK_BOX (vbox34), vbox35, TRUE, TRUE, 9);

  label119 = gtk_label_new (_("--"));
  gtk_widget_show (label119);
  gtk_box_pack_start (GTK_BOX (vbox35), label119, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label119), TRUE);
  gtk_label_set_line_wrap (GTK_LABEL (label119), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label119), 0, 0);
  gtk_misc_set_padding (GTK_MISC (label119), 4, 2);

  button26 = gtk_button_new_with_mnemonic (_("Close"));
  gtk_widget_show (button26);
  gtk_box_pack_start (GTK_BOX (vbox34), button26, FALSE, FALSE, 0);

  g_signal_connect ((gpointer) button26, "clicked",
                    G_CALLBACK (on_button26_clicked),
                    NULL);

  
  GLADE_HOOKUP_OBJECT_NO_REF (window8, window8, "window8");
  GLADE_HOOKUP_OBJECT (window8, vbox34, "vbox34");
  GLADE_HOOKUP_OBJECT (window8, vbox35, "vbox35");
  GLADE_HOOKUP_OBJECT (window8, label119, "label119");
  GLADE_HOOKUP_OBJECT (window8, button26, "button26");

  return window8;
}

GtkWidget*
create_window9 (void)
{
  GtkWidget *window9;

  window9 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window9), _("window9"));

  
  GLADE_HOOKUP_OBJECT_NO_REF (window9, window9, "window9");

  return window9;
}

GtkWidget*
create_window10 (void)
{
  GtkWidget *window10;
  GtkWidget *vbox36;
  GtkWidget *scrolledwindow7;
  GtkWidget *viewport5;
  GtkWidget *vbox37;
  GtkWidget *hbox28;
  GtkWidget *button30;
  GtkWidget *label120;
  GtkWidget *entry17;
  GtkWidget *label121;
  GtkWidget *entry18;
  GtkWidget *label123;
  GtkWidget *entry19;
  GtkWidget *hbox27;
  GtkWidget *radiobutton22;
  GSList *radiobutton22_group = NULL;
  GtkWidget *radiobutton23;
  GtkWidget *label122;
  GtkWidget *combobox5;
  GtkWidget *combobox6;
  GtkWidget *label124;
  GtkWidget *scrolledwindow8;
  GtkWidget *textview2;
  GtkWidget *hbox29;
  GtkWidget *radiobutton24;
  GSList *radiobutton24_group = NULL;
  GtkWidget *radiobutton25;
  GtkWidget *radiobutton26;
  GtkWidget *checkbutton11;
  GtkWidget *label126;
  GtkWidget *toolbar3;
  GtkIconSize tmp_toolbar_icon_size;
  GtkWidget *toolitem11;
  GtkWidget *toolitem12;
  GtkWidget *label125;
  GtkWidget *toolitem13;
  GtkWidget *button31;
  GtkWidget *toolitem14;
  GtkWidget *button32;

  window10 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window10), _("Edit POI"));
  gtk_window_set_modal (GTK_WINDOW (window10), TRUE);
  gtk_window_set_default_size (GTK_WINDOW (window10), 470, 470);

  vbox36 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox36);
  gtk_container_add (GTK_CONTAINER (window10), vbox36);

  scrolledwindow7 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow7);
  gtk_box_pack_start (GTK_BOX (vbox36), scrolledwindow7, TRUE, TRUE, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow7), GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);

  viewport5 = gtk_viewport_new (NULL, NULL);
  gtk_widget_show (viewport5);
  gtk_container_add (GTK_CONTAINER (scrolledwindow7), viewport5);
  gtk_container_set_border_width (GTK_CONTAINER (viewport5), 5);
  gtk_viewport_set_shadow_type (GTK_VIEWPORT (viewport5), GTK_SHADOW_NONE);

  vbox37 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox37);
  gtk_container_add (GTK_CONTAINER (viewport5), vbox37);

  hbox28 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox28);
  gtk_box_pack_start (GTK_BOX (vbox37), hbox28, FALSE, TRUE, 0);
  gtk_widget_set_size_request (hbox28, -1, 40);

  button30 = gtk_button_new_with_mnemonic (_("GPS"));
  gtk_widget_show (button30);
  gtk_box_pack_start (GTK_BOX (hbox28), button30, FALSE, FALSE, 1);
  gtk_widget_set_size_request (button30, -1, 40);

  label120 = gtk_label_new (_("Lat: "));
  gtk_widget_show (label120);
  gtk_box_pack_start (GTK_BOX (hbox28), label120, FALSE, FALSE, 0);
  gtk_misc_set_padding (GTK_MISC (label120), 1, 0);

  entry17 = gtk_entry_new ();
  gtk_widget_show (entry17);
  gtk_box_pack_start (GTK_BOX (hbox28), entry17, TRUE, TRUE, 0);
  gtk_entry_set_width_chars (GTK_ENTRY (entry17), 5);

  label121 = gtk_label_new (_(" Lon: "));
  gtk_widget_show (label121);
  gtk_box_pack_start (GTK_BOX (hbox28), label121, FALSE, FALSE, 0);
  gtk_misc_set_padding (GTK_MISC (label121), 1, 0);

  entry18 = gtk_entry_new ();
  gtk_widget_show (entry18);
  gtk_box_pack_start (GTK_BOX (hbox28), entry18, TRUE, TRUE, 0);
  gtk_entry_set_width_chars (GTK_ENTRY (entry18), 5);

  label123 = gtk_label_new (_("Name - Keywords / Tags:"));
  gtk_widget_show (label123);
  gtk_box_pack_start (GTK_BOX (vbox37), label123, FALSE, FALSE, 7);
  gtk_misc_set_alignment (GTK_MISC (label123), 0, 0.5);

  entry19 = gtk_entry_new ();
  gtk_widget_show (entry19);
  gtk_box_pack_start (GTK_BOX (vbox37), entry19, FALSE, FALSE, 0);

  hbox27 = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_end (GTK_BOX (vbox37), hbox27, FALSE, FALSE, 0);

  radiobutton22 = gtk_radio_button_new_with_mnemonic (NULL, _("personal"));
  gtk_widget_show (radiobutton22);
  gtk_box_pack_start (GTK_BOX (hbox27), radiobutton22, FALSE, FALSE, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton22), radiobutton22_group);
  radiobutton22_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton22));

  radiobutton23 = gtk_radio_button_new_with_mnemonic (NULL, _("public"));
  gtk_widget_show (radiobutton23);
  gtk_box_pack_start (GTK_BOX (hbox27), radiobutton23, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (radiobutton23), 2);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton23), radiobutton22_group);
  radiobutton22_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton23));
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (radiobutton23), TRUE);

  label122 = gtk_label_new (_("Category:"));
  gtk_box_pack_end (GTK_BOX (vbox37), label122, FALSE, FALSE, 7);
  gtk_misc_set_alignment (GTK_MISC (label122), 0, 0.5);

  combobox5 = gtk_combo_box_new_text ();
  gtk_box_pack_end (GTK_BOX (vbox37), combobox5, FALSE, FALSE, 1);
  GTK_WIDGET_SET_FLAGS (combobox5, GTK_CAN_FOCUS);
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox5), _("- please choose -"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox5), _("Accomodation"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox5), _("Businesses"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox5), _("Car"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox5), _("Cultural"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox5), _("Medical"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox5), _("Nightlife"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox5), _("Place of Worship"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox5), _("Public Transportation"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox5), _("Restaurant & Food"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox5), _("Services"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox5), _("Sights & Leisure"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox5), _("Shopping"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox5), _("Sport"));
  gtk_combo_box_set_add_tearoffs (GTK_COMBO_BOX (combobox5), TRUE);

  combobox6 = gtk_combo_box_new_text ();
  gtk_box_pack_end (GTK_BOX (vbox37), combobox6, FALSE, FALSE, 0);

  label124 = gtk_label_new (_("Description:"));
  gtk_widget_show (label124);
  gtk_box_pack_start (GTK_BOX (vbox37), label124, FALSE, FALSE, 7);
  gtk_misc_set_alignment (GTK_MISC (label124), 0, 0.5);

  scrolledwindow8 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow8);
  gtk_box_pack_start (GTK_BOX (vbox37), scrolledwindow8, TRUE, TRUE, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow8), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow8), GTK_SHADOW_IN);

  textview2 = gtk_text_view_new ();
  gtk_widget_show (textview2);
  gtk_container_add (GTK_CONTAINER (scrolledwindow8), textview2);
  gtk_widget_set_size_request (textview2, 300, -1);
  gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (textview2), GTK_WRAP_WORD);
  gtk_text_view_set_left_margin (GTK_TEXT_VIEW (textview2), 2);

  hbox29 = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox37), hbox29, TRUE, TRUE, 0);

  radiobutton24 = gtk_radio_button_new_with_mnemonic (NULL, _("budget"));
  gtk_widget_show (radiobutton24);
  gtk_box_pack_start (GTK_BOX (hbox29), radiobutton24, FALSE, FALSE, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton24), radiobutton24_group);
  radiobutton24_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton24));

  radiobutton25 = gtk_radio_button_new_with_mnemonic (NULL, _("medium"));
  gtk_widget_show (radiobutton25);
  gtk_box_pack_start (GTK_BOX (hbox29), radiobutton25, FALSE, FALSE, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton25), radiobutton24_group);
  radiobutton24_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton25));
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (radiobutton25), TRUE);

  radiobutton26 = gtk_radio_button_new_with_mnemonic (NULL, _("exclusive"));
  gtk_widget_show (radiobutton26);
  gtk_box_pack_start (GTK_BOX (hbox29), radiobutton26, FALSE, FALSE, 0);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (radiobutton26), radiobutton24_group);
  radiobutton24_group = gtk_radio_button_get_group (GTK_RADIO_BUTTON (radiobutton26));

  checkbutton11 = gtk_check_button_new_with_mnemonic (_("extended opening hours"));
  gtk_box_pack_start (GTK_BOX (vbox37), checkbutton11, FALSE, FALSE, 0);

  label126 = gtk_label_new (_("<b>-</b>"));
  gtk_widget_show (label126);
  gtk_box_pack_start (GTK_BOX (vbox37), label126, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label126), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label126), 0, 0);
  gtk_misc_set_padding (GTK_MISC (label126), 2, 2);

  toolbar3 = gtk_toolbar_new ();
  gtk_widget_show (toolbar3);
  gtk_box_pack_start (GTK_BOX (vbox36), toolbar3, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (toolbar3), 6);
  gtk_toolbar_set_style (GTK_TOOLBAR (toolbar3), GTK_TOOLBAR_ICONS);
  tmp_toolbar_icon_size = gtk_toolbar_get_icon_size (GTK_TOOLBAR (toolbar3));

  toolitem11 = (GtkWidget*) gtk_tool_item_new ();
  gtk_widget_show (toolitem11);
  gtk_container_add (GTK_CONTAINER (toolbar3), toolitem11);

  toolitem12 = (GtkWidget*) gtk_tool_item_new ();
  gtk_widget_show (toolitem12);
  gtk_container_add (GTK_CONTAINER (toolbar3), toolitem12);

  label125 = gtk_label_new (_("       "));
  gtk_widget_show (label125);
  gtk_container_add (GTK_CONTAINER (toolitem12), label125);

  toolitem13 = (GtkWidget*) gtk_tool_item_new ();
  gtk_widget_show (toolitem13);
  gtk_container_add (GTK_CONTAINER (toolbar3), toolitem13);

  button31 = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_show (button31);
  gtk_container_add (GTK_CONTAINER (toolitem13), button31);
  gtk_container_set_border_width (GTK_CONTAINER (button31), 7);

  toolitem14 = (GtkWidget*) gtk_tool_item_new ();
  gtk_widget_show (toolitem14);
  gtk_container_add (GTK_CONTAINER (toolbar3), toolitem14);

  button32 = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_show (button32);
  gtk_container_add (GTK_CONTAINER (toolitem14), button32);
  gtk_container_set_border_width (GTK_CONTAINER (button32), 7);

  g_signal_connect ((gpointer) button30, "clicked",
                    G_CALLBACK (on_button30_clicked),
                    NULL);
  g_signal_connect ((gpointer) combobox5, "changed",
                    G_CALLBACK (on_combobox2_changed),
                    NULL);
  g_signal_connect ((gpointer) button31, "clicked",
                    G_CALLBACK (on_cancelbutton5a_clicked),
                    NULL);
  g_signal_connect ((gpointer) button32, "clicked",
                    G_CALLBACK (on_okbutton5a_clicked),
                    NULL);

  
  GLADE_HOOKUP_OBJECT_NO_REF (window10, window10, "window10");
  GLADE_HOOKUP_OBJECT (window10, vbox36, "vbox36");
  GLADE_HOOKUP_OBJECT (window10, scrolledwindow7, "scrolledwindow7");
  GLADE_HOOKUP_OBJECT (window10, viewport5, "viewport5");
  GLADE_HOOKUP_OBJECT (window10, vbox37, "vbox37");
  GLADE_HOOKUP_OBJECT (window10, hbox28, "hbox28");
  GLADE_HOOKUP_OBJECT (window10, button30, "button30");
  GLADE_HOOKUP_OBJECT (window10, label120, "label120");
  GLADE_HOOKUP_OBJECT (window10, entry17, "entry17");
  GLADE_HOOKUP_OBJECT (window10, label121, "label121");
  GLADE_HOOKUP_OBJECT (window10, entry18, "entry18");
  GLADE_HOOKUP_OBJECT (window10, label123, "label123");
  GLADE_HOOKUP_OBJECT (window10, entry19, "entry19");
  GLADE_HOOKUP_OBJECT (window10, hbox27, "hbox27");
  GLADE_HOOKUP_OBJECT (window10, radiobutton22, "radiobutton22");
  GLADE_HOOKUP_OBJECT (window10, radiobutton23, "radiobutton23");
  GLADE_HOOKUP_OBJECT (window10, label122, "label122");
  GLADE_HOOKUP_OBJECT (window10, combobox5, "combobox5");
  GLADE_HOOKUP_OBJECT (window10, combobox6, "combobox6");
  GLADE_HOOKUP_OBJECT (window10, label124, "label124");
  GLADE_HOOKUP_OBJECT (window10, scrolledwindow8, "scrolledwindow8");
  GLADE_HOOKUP_OBJECT (window10, textview2, "textview2");
  GLADE_HOOKUP_OBJECT (window10, hbox29, "hbox29");
  GLADE_HOOKUP_OBJECT (window10, radiobutton24, "radiobutton24");
  GLADE_HOOKUP_OBJECT (window10, radiobutton25, "radiobutton25");
  GLADE_HOOKUP_OBJECT (window10, radiobutton26, "radiobutton26");
  GLADE_HOOKUP_OBJECT (window10, checkbutton11, "checkbutton11");
  GLADE_HOOKUP_OBJECT (window10, label126, "label126");
  GLADE_HOOKUP_OBJECT (window10, toolbar3, "toolbar3");
  GLADE_HOOKUP_OBJECT (window10, toolitem11, "toolitem11");
  GLADE_HOOKUP_OBJECT (window10, toolitem12, "toolitem12");
  GLADE_HOOKUP_OBJECT (window10, label125, "label125");
  GLADE_HOOKUP_OBJECT (window10, toolitem13, "toolitem13");
  GLADE_HOOKUP_OBJECT (window10, button31, "button31");
  GLADE_HOOKUP_OBJECT (window10, toolitem14, "toolitem14");
  GLADE_HOOKUP_OBJECT (window10, button32, "button32");

  gtk_widget_grab_focus (radiobutton23);
  return window10;
}

GtkWidget*
create_window11 (void)
{
  GtkWidget *window11;

  window11 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window11), _("window11"));

  
  GLADE_HOOKUP_OBJECT_NO_REF (window11, window11, "window11");

  return window11;
}

GtkWidget*
create_dialog7 (void)
{
  GtkWidget *dialog7;
  GtkWidget *dialog_vbox7;
  GtkWidget *label131;
  GtkWidget *dialog_action_area7;
  GtkWidget *cancelbutton6;
  GtkWidget *okbutton6;

  dialog7 = gtk_dialog_new ();
  gtk_window_set_title (GTK_WINDOW (dialog7), _("Delete POI?"));
  gtk_window_set_type_hint (GTK_WINDOW (dialog7), GDK_WINDOW_TYPE_HINT_DIALOG);

  dialog_vbox7 = GTK_DIALOG (dialog7)->vbox;
  gtk_widget_show (dialog_vbox7);

  label131 = gtk_label_new (_("Do you really want to \ndelete this Point of Interest?"));
  gtk_widget_show (label131);
  gtk_box_pack_start (GTK_BOX (dialog_vbox7), label131, TRUE, TRUE, 0);
  gtk_label_set_line_wrap (GTK_LABEL (label131), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label131), 0, 0);
  gtk_misc_set_padding (GTK_MISC (label131), 8, 8);

  dialog_action_area7 = GTK_DIALOG (dialog7)->action_area;
  gtk_widget_show (dialog_action_area7);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area7), GTK_BUTTONBOX_END);

  cancelbutton6 = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_show (cancelbutton6);
  gtk_dialog_add_action_widget (GTK_DIALOG (dialog7), cancelbutton6, GTK_RESPONSE_CANCEL);
  GTK_WIDGET_SET_FLAGS (cancelbutton6, GTK_CAN_DEFAULT);

  okbutton6 = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_show (okbutton6);
  gtk_dialog_add_action_widget (GTK_DIALOG (dialog7), okbutton6, GTK_RESPONSE_OK);
  GTK_WIDGET_SET_FLAGS (okbutton6, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) dialog7, "delete_event",
                    G_CALLBACK (on_dialog7_delete_event),
                    NULL);
  g_signal_connect ((gpointer) cancelbutton6, "clicked",
                    G_CALLBACK (on_cancelbutton6_clicked),
                    NULL);

  
  GLADE_HOOKUP_OBJECT_NO_REF (dialog7, dialog7, "dialog7");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog7, dialog_vbox7, "dialog_vbox7");
  GLADE_HOOKUP_OBJECT (dialog7, label131, "label131");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog7, dialog_action_area7, "dialog_action_area7");
  GLADE_HOOKUP_OBJECT (dialog7, cancelbutton6, "cancelbutton6");
  GLADE_HOOKUP_OBJECT (dialog7, okbutton6, "okbutton6");

  return dialog7;
}

GtkWidget*
create_dialog8 (void)
{
  GtkWidget *dialog8;
  GtkWidget *dialog_vbox8;
  GtkWidget *vbox41;
  GtkWidget *textview4;
  GtkWidget *label144;
  GtkWidget *entry24;
  GtkWidget *label145;
  GtkWidget *label146;
  GtkWidget *entry25;
  GtkWidget *label147;
  GtkWidget *entry26;
  GtkWidget *checkbutton13;
  GtkWidget *dialog_action_area9;
  GtkWidget *cancelbutton7;
  GtkWidget *okbutton7;

  dialog8 = gtk_dialog_new ();
  gtk_widget_set_size_request (dialog8, 360, -1);
  GTK_WIDGET_SET_FLAGS (dialog8, GTK_CAN_FOCUS);
  gtk_window_set_title (GTK_WINDOW (dialog8), _("Edit Repository"));
  gtk_window_set_type_hint (GTK_WINDOW (dialog8), GDK_WINDOW_TYPE_HINT_DIALOG);

  dialog_vbox8 = GTK_DIALOG (dialog8)->vbox;
  gtk_widget_show (dialog_vbox8);

  vbox41 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox41);
  gtk_box_pack_start (GTK_BOX (dialog_vbox8), vbox41, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (vbox41), 8);

  textview4 = gtk_text_view_new ();
  gtk_widget_show (textview4);
  gtk_box_pack_start (GTK_BOX (vbox41), textview4, TRUE, TRUE, 5);
  gtk_text_view_set_editable (GTK_TEXT_VIEW (textview4), FALSE);
  gtk_text_view_set_accepts_tab (GTK_TEXT_VIEW (textview4), FALSE);
  gtk_text_view_set_justification (GTK_TEXT_VIEW (textview4), GTK_JUSTIFY_CENTER);
  gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (textview4), GTK_WRAP_WORD);
  gtk_text_view_set_cursor_visible (GTK_TEXT_VIEW (textview4), FALSE);
  gtk_text_buffer_set_text (gtk_text_view_get_buffer (GTK_TEXT_VIEW (textview4)), _("You can find more information about repositories on\n\nhttp://www.tangogps.org/\n"), -1);

  label144 = gtk_label_new (_("<b>Repository Name</b>"));
  gtk_widget_show (label144);
  gtk_box_pack_start (GTK_BOX (vbox41), label144, FALSE, FALSE, 5);
  gtk_label_set_use_markup (GTK_LABEL (label144), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label144), 0, 0.5);

  entry24 = gtk_entry_new ();
  gtk_widget_show (entry24);
  gtk_box_pack_start (GTK_BOX (vbox41), entry24, FALSE, FALSE, 0);

  label145 = gtk_label_new (_(" "));
  gtk_widget_show (label145);
  gtk_box_pack_start (GTK_BOX (vbox41), label145, FALSE, FALSE, 0);

  label146 = gtk_label_new (_("<b>URI</b>"));
  gtk_widget_show (label146);
  gtk_box_pack_start (GTK_BOX (vbox41), label146, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label146), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label146), 0, 0.5);

  entry25 = gtk_entry_new ();
  gtk_widget_show (entry25);
  gtk_box_pack_start (GTK_BOX (vbox41), entry25, FALSE, FALSE, 0);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry25), 9679);

  label147 = gtk_label_new (_("<b>Cache Dir</b>"));
  gtk_widget_show (label147);
  gtk_box_pack_start (GTK_BOX (vbox41), label147, FALSE, FALSE, 3);
  gtk_label_set_use_markup (GTK_LABEL (label147), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label147), 0, 0.5);

  entry26 = gtk_entry_new ();
  gtk_widget_show (entry26);
  gtk_box_pack_start (GTK_BOX (vbox41), entry26, FALSE, FALSE, 0);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry26), 9679);

  checkbutton13 = gtk_check_button_new_with_mnemonic (_("xyz instead of zxy"));
  gtk_widget_show (checkbutton13);
  gtk_box_pack_start (GTK_BOX (vbox41), checkbutton13, FALSE, FALSE, 8);

  dialog_action_area9 = GTK_DIALOG (dialog8)->action_area;
  gtk_widget_show (dialog_action_area9);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area9), GTK_BUTTONBOX_END);

  cancelbutton7 = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_show (cancelbutton7);
  gtk_dialog_add_action_widget (GTK_DIALOG (dialog8), cancelbutton7, GTK_RESPONSE_CANCEL);
  GTK_WIDGET_SET_FLAGS (cancelbutton7, GTK_CAN_DEFAULT);

  okbutton7 = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_show (okbutton7);
  gtk_dialog_add_action_widget (GTK_DIALOG (dialog8), okbutton7, GTK_RESPONSE_OK);
  gtk_widget_set_sensitive (okbutton7, FALSE);
  GTK_WIDGET_SET_FLAGS (okbutton7, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) entry24, "changed",
                    G_CALLBACK (on_entry24_changed),
                    NULL);
  g_signal_connect ((gpointer) entry25, "changed",
                    G_CALLBACK (on_entry25_changed),
                    NULL);
  g_signal_connect ((gpointer) entry26, "changed",
                    G_CALLBACK (on_entry26_changed),
                    NULL);
  g_signal_connect ((gpointer) checkbutton13, "toggled",
                    G_CALLBACK (on_checkbutton13_toggled),
                    NULL);
  g_signal_connect ((gpointer) cancelbutton7, "clicked",
                    G_CALLBACK (on_cancelbutton7_clicked),
                    NULL);
  g_signal_connect ((gpointer) okbutton7, "clicked",
                    G_CALLBACK (on_okbutton7_clicked),
                    NULL);

  
  GLADE_HOOKUP_OBJECT_NO_REF (dialog8, dialog8, "dialog8");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog8, dialog_vbox8, "dialog_vbox8");
  GLADE_HOOKUP_OBJECT (dialog8, vbox41, "vbox41");
  GLADE_HOOKUP_OBJECT (dialog8, textview4, "textview4");
  GLADE_HOOKUP_OBJECT (dialog8, label144, "label144");
  GLADE_HOOKUP_OBJECT (dialog8, entry24, "entry24");
  GLADE_HOOKUP_OBJECT (dialog8, label145, "label145");
  GLADE_HOOKUP_OBJECT (dialog8, label146, "label146");
  GLADE_HOOKUP_OBJECT (dialog8, entry25, "entry25");
  GLADE_HOOKUP_OBJECT (dialog8, label147, "label147");
  GLADE_HOOKUP_OBJECT (dialog8, entry26, "entry26");
  GLADE_HOOKUP_OBJECT (dialog8, checkbutton13, "checkbutton13");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog8, dialog_action_area9, "dialog_action_area9");
  GLADE_HOOKUP_OBJECT (dialog8, cancelbutton7, "cancelbutton7");
  GLADE_HOOKUP_OBJECT (dialog8, okbutton7, "okbutton7");

  return dialog8;
}

GtkWidget*
create_win13_biggeo (void)
{
  GtkWidget *win13_biggeo;
  GtkWidget *eventbox2;
  GtkWidget *drawingarea3;

  win13_biggeo = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (win13_biggeo), _("GeoPhoto"));
  gtk_window_set_position (GTK_WINDOW (win13_biggeo), GTK_WIN_POS_MOUSE);
  gtk_window_set_type_hint (GTK_WINDOW (win13_biggeo), GDK_WINDOW_TYPE_HINT_MENU);

  eventbox2 = gtk_event_box_new ();
  gtk_widget_show (eventbox2);
  gtk_container_add (GTK_CONTAINER (win13_biggeo), eventbox2);

  drawingarea3 = gtk_drawing_area_new ();
  gtk_widget_show (drawingarea3);
  gtk_container_add (GTK_CONTAINER (eventbox2), drawingarea3);
  gtk_widget_set_size_request (drawingarea3, 640, 480);

  g_signal_connect ((gpointer) eventbox2, "button_release_event",
                    G_CALLBACK (on_eventbox2_button_release_event),
                    NULL);
  g_signal_connect ((gpointer) drawingarea3, "configure_event",
                    G_CALLBACK (on_drawingarea3_configure_event),
                    NULL);
  g_signal_connect ((gpointer) drawingarea3, "expose_event",
                    G_CALLBACK (on_drawingarea3_expose_event),
                    NULL);

  
  GLADE_HOOKUP_OBJECT_NO_REF (win13_biggeo, win13_biggeo, "win13_biggeo");
  GLADE_HOOKUP_OBJECT (win13_biggeo, eventbox2, "eventbox2");
  GLADE_HOOKUP_OBJECT (win13_biggeo, drawingarea3, "drawingarea3");

  return win13_biggeo;
}

GtkWidget*
create_dialog_geocode (void)
{
  GtkWidget *dialog_geocode;
  GtkWidget *dialog_vbox9;
  GtkWidget *vbox42;
  GtkWidget *label148;
  GtkWidget *scrolledwindow12;
  GtkWidget *textview5;
  GtkWidget *table7;
  GtkWidget *label149;
  GtkWidget *label150;
  GtkWidget *button39;
  GtkWidget *button40;
  GtkWidget *label154;
  GtkWidget *label155;
  GtkWidget *label156;
  GtkWidget *label157;
  GtkWidget *button44;
  GtkWidget *label172;
  GtkWidget *label174;
  GtkWidget *label173;
  GtkWidget *label158;
  GtkWidget *hbox38;
  GtkWidget *label160;
  GtkWidget *checkbutton14;
  GtkWidget *label161;
  GtkWidget *dialog_action_area10;
  GtkWidget *cancelbutton8;
  GtkWidget *okbutton8;

  dialog_geocode = gtk_dialog_new ();
  gtk_widget_set_size_request (dialog_geocode, 380, -1);
  gtk_window_set_title (GTK_WINDOW (dialog_geocode), _("Photo Correlate"));

  dialog_vbox9 = GTK_DIALOG (dialog_geocode)->vbox;
  gtk_widget_show (dialog_vbox9);

  vbox42 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox42);
  gtk_box_pack_start (GTK_BOX (dialog_vbox9), vbox42, TRUE, TRUE, 0);

  label148 = gtk_label_new (_("<b>Geocoding your photos</b>"));
  gtk_widget_show (label148);
  gtk_box_pack_start (GTK_BOX (vbox42), label148, FALSE, FALSE, 8);
  gtk_label_set_use_markup (GTK_LABEL (label148), TRUE);

  scrolledwindow12 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow12);
  gtk_box_pack_start (GTK_BOX (vbox42), scrolledwindow12, FALSE, FALSE, 7);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow12), GTK_POLICY_NEVER, GTK_POLICY_NEVER);

  textview5 = gtk_text_view_new ();
  gtk_widget_show (textview5);
  gtk_container_add (GTK_CONTAINER (scrolledwindow12), textview5);
  gtk_text_view_set_editable (GTK_TEXT_VIEW (textview5), FALSE);
  gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (textview5), GTK_WRAP_WORD);
  gtk_text_view_set_cursor_visible (GTK_TEXT_VIEW (textview5), FALSE);
  gtk_text_view_set_pixels_above_lines (GTK_TEXT_VIEW (textview5), 3);
  gtk_text_view_set_left_margin (GTK_TEXT_VIEW (textview5), 5);
  gtk_text_buffer_set_text (gtk_text_view_get_buffer (GTK_TEXT_VIEW (textview5)), _("Geocode your photos by correlating them with a gps track. For a tutorial see on http://www.tangogps.org\n"), -1);

  table7 = gtk_table_new (5, 3, FALSE);
  gtk_widget_show (table7);
  gtk_box_pack_start (GTK_BOX (vbox42), table7, FALSE, FALSE, 2);

  label149 = gtk_label_new (_("  <b>1. Add Track</b>        "));
  gtk_widget_show (label149);
  gtk_table_attach (GTK_TABLE (table7), label149, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label149), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label149), 0, 0.5);

  label150 = gtk_label_new (_("  <b>2. Add Photos</b> "));
  gtk_widget_show (label150);
  gtk_table_attach (GTK_TABLE (table7), label150, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label150), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label150), 0, 0.5);

  button39 = gtk_button_new_from_stock ("gtk-open");
  gtk_widget_show (button39);
  gtk_table_attach (GTK_TABLE (table7), button39, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 5, 5);

  button40 = gtk_button_new_from_stock ("gtk-open");
  gtk_widget_show (button40);
  gtk_table_attach (GTK_TABLE (table7), button40, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (GTK_EXPAND), 5, 5);

  label154 = gtk_label_new (_("  <span color=\"red\" weight=\"bold\">-</span>"));
  gtk_widget_show (label154);
  gtk_table_attach (GTK_TABLE (table7), label154, 2, 3, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label154), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label154), 0, 0.5);

  label155 = gtk_label_new (_("  <span color=\"red\" weight=\"bold\">-</span>"));
  gtk_widget_show (label155);
  gtk_table_attach (GTK_TABLE (table7), label155, 2, 3, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label155), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label155), 0, 0.5);

  label156 = gtk_label_new (_("       "));
  gtk_widget_show (label156);
  gtk_table_attach (GTK_TABLE (table7), label156, 2, 3, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label156), 0, 0.5);

  label157 = gtk_label_new (_("  <b>3. Adjust Time</b>"));
  gtk_widget_show (label157);
  gtk_table_attach (GTK_TABLE (table7), label157, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label157), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label157), 0, 0.5);

  button44 = gtk_button_new_with_mnemonic (_("View GPS Photo"));
  gtk_widget_show (button44);
  gtk_table_attach (GTK_TABLE (table7), button44, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 5, 5);
  gtk_widget_set_sensitive (button44, FALSE);

  label172 = gtk_label_new (_("  +00:00h"));
  gtk_widget_show (label172);
  gtk_table_attach (GTK_TABLE (table7), label172, 1, 2, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label172), 0, 0.5);

  label174 = gtk_label_new (_("  0 seconds"));
  gtk_widget_show (label174);
  gtk_table_attach (GTK_TABLE (table7), label174, 1, 2, 4, 5,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label174), 0, 0.5);

  label173 = gtk_label_new (_("Correction:"));
  gtk_widget_show (label173);
  gtk_table_attach (GTK_TABLE (table7), label173, 0, 1, 4, 5,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 5, 0);
  gtk_misc_set_alignment (GTK_MISC (label173), 1, 0);

  label158 = gtk_label_new (_("Timezone:"));
  gtk_widget_show (label158);
  gtk_table_attach (GTK_TABLE (table7), label158, 0, 1, 3, 4,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 5, 0);
  gtk_misc_set_alignment (GTK_MISC (label158), 1, 0);

  hbox38 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox38);
  gtk_box_pack_start (GTK_BOX (vbox42), hbox38, FALSE, FALSE, 12);

  label160 = gtk_label_new ("");
  gtk_widget_show (label160);
  gtk_box_pack_start (GTK_BOX (hbox38), label160, FALSE, TRUE, 0);

  checkbutton14 = gtk_check_button_new_with_mnemonic (_("  add photos to the tangoGPS database"));
  gtk_widget_show (checkbutton14);
  gtk_box_pack_start (GTK_BOX (hbox38), checkbutton14, FALSE, FALSE, 0);
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (checkbutton14), TRUE);

  label161 = gtk_label_new ("");
  gtk_widget_show (label161);
  gtk_box_pack_start (GTK_BOX (hbox38), label161, TRUE, TRUE, 0);

  dialog_action_area10 = GTK_DIALOG (dialog_geocode)->action_area;
  gtk_widget_show (dialog_action_area10);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area10), GTK_BUTTONBOX_END);

  cancelbutton8 = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_show (cancelbutton8);
  gtk_dialog_add_action_widget (GTK_DIALOG (dialog_geocode), cancelbutton8, GTK_RESPONSE_CANCEL);
  GTK_WIDGET_SET_FLAGS (cancelbutton8, GTK_CAN_DEFAULT);

  okbutton8 = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_show (okbutton8);
  gtk_dialog_add_action_widget (GTK_DIALOG (dialog_geocode), okbutton8, GTK_RESPONSE_OK);
  gtk_widget_set_sensitive (okbutton8, FALSE);
  GTK_WIDGET_SET_FLAGS (okbutton8, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) dialog_geocode, "delete_event",
                    G_CALLBACK (on_dialog_geocode_delete_event),
                    NULL);
  g_signal_connect ((gpointer) button39, "clicked",
                    G_CALLBACK (on_button39_clicked),
                    NULL);
  g_signal_connect ((gpointer) button40, "clicked",
                    G_CALLBACK (on_button40_clicked),
                    NULL);
  g_signal_connect ((gpointer) button44, "clicked",
                    G_CALLBACK (on_button44_clicked),
                    NULL);
  g_signal_connect ((gpointer) checkbutton14, "toggled",
                    G_CALLBACK (on_checkbutton14_toggled),
                    NULL);
  g_signal_connect ((gpointer) cancelbutton8, "clicked",
                    G_CALLBACK (on_cancelbutton8_clicked),
                    NULL);
  g_signal_connect ((gpointer) okbutton8, "clicked",
                    G_CALLBACK (on_okbutton8_clicked),
                    NULL);

  
  GLADE_HOOKUP_OBJECT_NO_REF (dialog_geocode, dialog_geocode, "dialog_geocode");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog_geocode, dialog_vbox9, "dialog_vbox9");
  GLADE_HOOKUP_OBJECT (dialog_geocode, vbox42, "vbox42");
  GLADE_HOOKUP_OBJECT (dialog_geocode, label148, "label148");
  GLADE_HOOKUP_OBJECT (dialog_geocode, scrolledwindow12, "scrolledwindow12");
  GLADE_HOOKUP_OBJECT (dialog_geocode, textview5, "textview5");
  GLADE_HOOKUP_OBJECT (dialog_geocode, table7, "table7");
  GLADE_HOOKUP_OBJECT (dialog_geocode, label149, "label149");
  GLADE_HOOKUP_OBJECT (dialog_geocode, label150, "label150");
  GLADE_HOOKUP_OBJECT (dialog_geocode, button39, "button39");
  GLADE_HOOKUP_OBJECT (dialog_geocode, button40, "button40");
  GLADE_HOOKUP_OBJECT (dialog_geocode, label154, "label154");
  GLADE_HOOKUP_OBJECT (dialog_geocode, label155, "label155");
  GLADE_HOOKUP_OBJECT (dialog_geocode, label156, "label156");
  GLADE_HOOKUP_OBJECT (dialog_geocode, label157, "label157");
  GLADE_HOOKUP_OBJECT (dialog_geocode, button44, "button44");
  GLADE_HOOKUP_OBJECT (dialog_geocode, label172, "label172");
  GLADE_HOOKUP_OBJECT (dialog_geocode, label174, "label174");
  GLADE_HOOKUP_OBJECT (dialog_geocode, label173, "label173");
  GLADE_HOOKUP_OBJECT (dialog_geocode, label158, "label158");
  GLADE_HOOKUP_OBJECT (dialog_geocode, hbox38, "hbox38");
  GLADE_HOOKUP_OBJECT (dialog_geocode, label160, "label160");
  GLADE_HOOKUP_OBJECT (dialog_geocode, checkbutton14, "checkbutton14");
  GLADE_HOOKUP_OBJECT (dialog_geocode, label161, "label161");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog_geocode, dialog_action_area10, "dialog_action_area10");
  GLADE_HOOKUP_OBJECT (dialog_geocode, cancelbutton8, "cancelbutton8");
  GLADE_HOOKUP_OBJECT (dialog_geocode, okbutton8, "okbutton8");

  gtk_widget_grab_focus (button39);
  return dialog_geocode;
}

GtkWidget*
create_filechooserdialog1 (void)
{
  GtkWidget *filechooserdialog1;
  GtkWidget *dialog_vbox10;
  GtkWidget *filechooser_label;
  GtkWidget *dialog_action_area11;
  GtkWidget *button42;
  GtkWidget *button43;

  filechooserdialog1 = gtk_file_chooser_dialog_new (_("Please choose"), NULL, GTK_FILE_CHOOSER_ACTION_OPEN, NULL);
  gtk_widget_set_size_request (filechooserdialog1, 450, -1);
  gtk_container_set_border_width (GTK_CONTAINER (filechooserdialog1), 5);
  gtk_window_set_type_hint (GTK_WINDOW (filechooserdialog1), GDK_WINDOW_TYPE_HINT_DIALOG);

  dialog_vbox10 = GTK_DIALOG (filechooserdialog1)->vbox;
  gtk_widget_show (dialog_vbox10);

  filechooser_label = gtk_label_new (_("<b>This is important!</b>\n"));
  gtk_widget_show (filechooser_label);
  gtk_box_pack_start (GTK_BOX (dialog_vbox10), filechooser_label, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (filechooser_label), TRUE);
  gtk_misc_set_alignment (GTK_MISC (filechooser_label), 0.02, 0.5);

  dialog_action_area11 = GTK_DIALOG (filechooserdialog1)->action_area;
  gtk_widget_show (dialog_action_area11);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area11), GTK_BUTTONBOX_END);

  button42 = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_show (button42);
  gtk_dialog_add_action_widget (GTK_DIALOG (filechooserdialog1), button42, GTK_RESPONSE_CANCEL);
  GTK_WIDGET_SET_FLAGS (button42, GTK_CAN_DEFAULT);

  button43 = gtk_button_new_from_stock ("gtk-open");
  gtk_widget_show (button43);
  gtk_dialog_add_action_widget (GTK_DIALOG (filechooserdialog1), button43, GTK_RESPONSE_OK);
  GTK_WIDGET_SET_FLAGS (button43, GTK_CAN_DEFAULT);

  
  GLADE_HOOKUP_OBJECT_NO_REF (filechooserdialog1, filechooserdialog1, "filechooserdialog1");
  GLADE_HOOKUP_OBJECT_NO_REF (filechooserdialog1, dialog_vbox10, "dialog_vbox10");
  GLADE_HOOKUP_OBJECT (filechooserdialog1, filechooser_label, "filechooser_label");
  GLADE_HOOKUP_OBJECT_NO_REF (filechooserdialog1, dialog_action_area11, "dialog_action_area11");
  GLADE_HOOKUP_OBJECT (filechooserdialog1, button42, "button42");
  GLADE_HOOKUP_OBJECT (filechooserdialog1, button43, "button43");

  gtk_widget_grab_default (button43);
  return filechooserdialog1;
}

GtkWidget*
create_dialog_image_data (void)
{
  GtkWidget *dialog_image_data;
  GtkWidget *vbox44;
  GtkWidget *vbox43;
  GtkWidget *hbox39;
  GtkWidget *button47;
  GtkWidget *button45;
  GtkWidget *button50;
  GtkWidget *button46;
  GtkWidget *button48;
  GtkWidget *scrolledwindow13;
  GtkWidget *viewport8;
  GtkWidget *eventbox3;
  GtkWidget *image5;
  GtkWidget *hbox43;
  GtkWidget *hbox45;
  GtkWidget *label170;
  GtkWidget *label171;
  GtkWidget *hbox44;
  GtkWidget *label167;
  GtkWidget *label163;
  GtkWidget *hbox42;
  GtkWidget *hbox46;
  GtkWidget *label164;
  GtkWidget *entry28;
  GtkWidget *label168;
  GtkWidget *hbox47;
  GtkWidget *label175;
  GtkWidget *combobox7;
  GtkWidget *hseparator1;
  GtkWidget *hbox41;
  GtkWidget *label165;
  GtkWidget *button49;
  GtkWidget *okbutton9;

  dialog_image_data = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (dialog_image_data, 450, 460);
  gtk_window_set_title (GTK_WINDOW (dialog_image_data), _("Image Data"));
  gtk_window_set_position (GTK_WINDOW (dialog_image_data), GTK_WIN_POS_MOUSE);

  vbox44 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox44);
  gtk_container_add (GTK_CONTAINER (dialog_image_data), vbox44);

  vbox43 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox43);
  gtk_box_pack_start (GTK_BOX (vbox44), vbox43, TRUE, TRUE, 0);

  hbox39 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox39);
  gtk_box_pack_start (GTK_BOX (vbox43), hbox39, FALSE, FALSE, 0);

  button47 = gtk_button_new_from_stock ("gtk-goto-first");
  gtk_widget_show (button47);
  gtk_box_pack_start (GTK_BOX (hbox39), button47, TRUE, TRUE, 0);

  button45 = gtk_button_new_from_stock ("gtk-go-back");
  gtk_widget_show (button45);
  gtk_box_pack_start (GTK_BOX (hbox39), button45, TRUE, TRUE, 0);

  button50 = gtk_button_new_from_stock ("gtk-zoom-in");
  gtk_widget_show (button50);
  gtk_box_pack_start (GTK_BOX (hbox39), button50, TRUE, TRUE, 0);

  button46 = gtk_button_new_from_stock ("gtk-go-forward");
  gtk_widget_show (button46);
  gtk_box_pack_start (GTK_BOX (hbox39), button46, TRUE, TRUE, 0);

  button48 = gtk_button_new_from_stock ("gtk-goto-last");
  gtk_widget_show (button48);
  gtk_box_pack_start (GTK_BOX (hbox39), button48, TRUE, TRUE, 0);

  scrolledwindow13 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow13);
  gtk_box_pack_start (GTK_BOX (vbox43), scrolledwindow13, TRUE, TRUE, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow13), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  viewport8 = gtk_viewport_new (NULL, NULL);
  gtk_widget_show (viewport8);
  gtk_container_add (GTK_CONTAINER (scrolledwindow13), viewport8);
  gtk_viewport_set_shadow_type (GTK_VIEWPORT (viewport8), GTK_SHADOW_NONE);

  eventbox3 = gtk_event_box_new ();
  gtk_widget_show (eventbox3);
  gtk_container_add (GTK_CONTAINER (viewport8), eventbox3);

  image5 = create_pixmap (dialog_image_data, NULL);
  gtk_widget_show (image5);
  gtk_container_add (GTK_CONTAINER (eventbox3), image5);

  hbox43 = gtk_hbox_new (TRUE, 0);
  gtk_widget_show (hbox43);
  gtk_box_pack_start (GTK_BOX (vbox43), hbox43, FALSE, FALSE, 4);

  hbox45 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox45);
  gtk_box_pack_start (GTK_BOX (hbox43), hbox45, TRUE, TRUE, 0);

  label170 = gtk_label_new (_(" <b>GPS:</b> "));
  gtk_widget_show (label170);
  gtk_box_pack_start (GTK_BOX (hbox45), label170, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label170), TRUE);

  label171 = gtk_label_new (_("      "));
  gtk_widget_show (label171);
  gtk_box_pack_start (GTK_BOX (hbox45), label171, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label171), TRUE);

  hbox44 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox44);
  gtk_box_pack_start (GTK_BOX (hbox43), hbox44, TRUE, TRUE, 0);

  label167 = gtk_label_new (_(" <b>Camera:</b> "));
  gtk_widget_show (label167);
  gtk_box_pack_start (GTK_BOX (hbox44), label167, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label167), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label167), 0, 0.5);

  label163 = gtk_label_new (_("      "));
  gtk_widget_show (label163);
  gtk_box_pack_start (GTK_BOX (hbox44), label163, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label163), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label163), 0, 0.5);

  hbox42 = gtk_hbox_new (TRUE, 0);
  gtk_widget_show (hbox42);
  gtk_box_pack_start (GTK_BOX (vbox43), hbox42, FALSE, FALSE, 4);

  hbox46 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox46);
  gtk_box_pack_start (GTK_BOX (hbox42), hbox46, TRUE, TRUE, 0);

  label164 = gtk_label_new (_(" <b>Correction:</b> "));
  gtk_widget_show (label164);
  gtk_box_pack_start (GTK_BOX (hbox46), label164, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label164), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label164), 0.02, 0.5);

  entry28 = gtk_entry_new ();
  gtk_widget_show (entry28);
  gtk_box_pack_start (GTK_BOX (hbox46), entry28, FALSE, FALSE, 0);
  gtk_widget_set_size_request (entry28, 40, -1);
  gtk_entry_set_text (GTK_ENTRY (entry28), _("0"));
  gtk_entry_set_invisible_char (GTK_ENTRY (entry28), 9679);

  label168 = gtk_label_new (_("s   "));
  gtk_widget_show (label168);
  gtk_box_pack_start (GTK_BOX (hbox46), label168, FALSE, FALSE, 0);

  hbox47 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox47);
  gtk_box_pack_start (GTK_BOX (hbox42), hbox47, TRUE, TRUE, 0);

  label175 = gtk_label_new (_(" <b>Timezone:</b>  "));
  gtk_widget_show (label175);
  gtk_box_pack_start (GTK_BOX (hbox47), label175, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label175), TRUE);

  combobox7 = gtk_combo_box_new_text ();
  gtk_widget_show (combobox7);
  gtk_box_pack_start (GTK_BOX (hbox47), combobox7, FALSE, FALSE, 0);
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("-12:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("-11:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("-10:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("-09:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("-08:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("-07:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("-06:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("-05:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("-04:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("-03:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("-02:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("-01:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("+00:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("+01:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("+02:00 "));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("+03:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("+04:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("+05:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("+06:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("+07:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("+08:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("+09:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("+10:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("+11:00"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (combobox7), _("+12:00"));

  hseparator1 = gtk_hseparator_new ();
  gtk_widget_show (hseparator1);
  gtk_box_pack_start (GTK_BOX (vbox44), hseparator1, FALSE, FALSE, 3);

  hbox41 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox41);
  gtk_box_pack_start (GTK_BOX (vbox44), hbox41, FALSE, FALSE, 0);

  label165 = gtk_label_new ("");
  gtk_widget_show (label165);
  gtk_box_pack_start (GTK_BOX (hbox41), label165, TRUE, TRUE, 0);
  gtk_widget_set_size_request (label165, 200, -1);

  button49 = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_show (button49);
  gtk_box_pack_start (GTK_BOX (hbox41), button49, FALSE, TRUE, 5);
  gtk_widget_set_size_request (button49, 100, -1);
  gtk_container_set_border_width (GTK_CONTAINER (button49), 3);

  okbutton9 = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_show (okbutton9);
  gtk_box_pack_start (GTK_BOX (hbox41), okbutton9, FALSE, FALSE, 5);
  gtk_widget_set_size_request (okbutton9, 100, -1);
  gtk_container_set_border_width (GTK_CONTAINER (okbutton9), 3);
  GTK_WIDGET_SET_FLAGS (okbutton9, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) dialog_image_data, "delete_event",
                    G_CALLBACK (on_dialog_image_data_delete_event),
                    NULL);
  g_signal_connect ((gpointer) button47, "clicked",
                    G_CALLBACK (on_button47_clicked),
                    NULL);
  g_signal_connect ((gpointer) button45, "clicked",
                    G_CALLBACK (on_button45_clicked),
                    NULL);
  g_signal_connect ((gpointer) button50, "clicked",
                    G_CALLBACK (on_button50_clicked),
                    NULL);
  g_signal_connect ((gpointer) button46, "clicked",
                    G_CALLBACK (on_button46_clicked),
                    NULL);
  g_signal_connect ((gpointer) button48, "clicked",
                    G_CALLBACK (on_button48_clicked),
                    NULL);
  g_signal_connect ((gpointer) eventbox3, "button_release_event",
                    G_CALLBACK (on_eventbox3_button_release_event),
                    NULL);
  g_signal_connect ((gpointer) entry28, "changed",
                    G_CALLBACK (on_entry28_changed),
                    NULL);
  g_signal_connect ((gpointer) combobox7, "changed",
                    G_CALLBACK (on_combobox7_changed),
                    NULL);
  g_signal_connect ((gpointer) button49, "clicked",
                    G_CALLBACK (on_button49_clicked),
                    NULL);
  g_signal_connect ((gpointer) okbutton9, "clicked",
                    G_CALLBACK (on_okbutton9_clicked),
                    NULL);

  
  GLADE_HOOKUP_OBJECT_NO_REF (dialog_image_data, dialog_image_data, "dialog_image_data");
  GLADE_HOOKUP_OBJECT (dialog_image_data, vbox44, "vbox44");
  GLADE_HOOKUP_OBJECT (dialog_image_data, vbox43, "vbox43");
  GLADE_HOOKUP_OBJECT (dialog_image_data, hbox39, "hbox39");
  GLADE_HOOKUP_OBJECT (dialog_image_data, button47, "button47");
  GLADE_HOOKUP_OBJECT (dialog_image_data, button45, "button45");
  GLADE_HOOKUP_OBJECT (dialog_image_data, button50, "button50");
  GLADE_HOOKUP_OBJECT (dialog_image_data, button46, "button46");
  GLADE_HOOKUP_OBJECT (dialog_image_data, button48, "button48");
  GLADE_HOOKUP_OBJECT (dialog_image_data, scrolledwindow13, "scrolledwindow13");
  GLADE_HOOKUP_OBJECT (dialog_image_data, viewport8, "viewport8");
  GLADE_HOOKUP_OBJECT (dialog_image_data, eventbox3, "eventbox3");
  GLADE_HOOKUP_OBJECT (dialog_image_data, image5, "image5");
  GLADE_HOOKUP_OBJECT (dialog_image_data, hbox43, "hbox43");
  GLADE_HOOKUP_OBJECT (dialog_image_data, hbox45, "hbox45");
  GLADE_HOOKUP_OBJECT (dialog_image_data, label170, "label170");
  GLADE_HOOKUP_OBJECT (dialog_image_data, label171, "label171");
  GLADE_HOOKUP_OBJECT (dialog_image_data, hbox44, "hbox44");
  GLADE_HOOKUP_OBJECT (dialog_image_data, label167, "label167");
  GLADE_HOOKUP_OBJECT (dialog_image_data, label163, "label163");
  GLADE_HOOKUP_OBJECT (dialog_image_data, hbox42, "hbox42");
  GLADE_HOOKUP_OBJECT (dialog_image_data, hbox46, "hbox46");
  GLADE_HOOKUP_OBJECT (dialog_image_data, label164, "label164");
  GLADE_HOOKUP_OBJECT (dialog_image_data, entry28, "entry28");
  GLADE_HOOKUP_OBJECT (dialog_image_data, label168, "label168");
  GLADE_HOOKUP_OBJECT (dialog_image_data, hbox47, "hbox47");
  GLADE_HOOKUP_OBJECT (dialog_image_data, label175, "label175");
  GLADE_HOOKUP_OBJECT (dialog_image_data, combobox7, "combobox7");
  GLADE_HOOKUP_OBJECT (dialog_image_data, hseparator1, "hseparator1");
  GLADE_HOOKUP_OBJECT (dialog_image_data, hbox41, "hbox41");
  GLADE_HOOKUP_OBJECT (dialog_image_data, label165, "label165");
  GLADE_HOOKUP_OBJECT (dialog_image_data, button49, "button49");
  GLADE_HOOKUP_OBJECT (dialog_image_data, okbutton9, "okbutton9");

  gtk_widget_grab_focus (button46);
  return dialog_image_data;
}

GtkWidget*
create_dialog_geocode_result (void)
{
  GtkWidget *dialog_geocode_result;
  GtkWidget *dialog_vbox11;
  GtkWidget *vbox46;
  GtkWidget *label178;
  GtkWidget *label177;
  GtkWidget *dialog_action_area12;
  GtkWidget *closebutton2;

  dialog_geocode_result = gtk_dialog_new ();
  gtk_window_set_title (GTK_WINDOW (dialog_geocode_result), _("Geocode Result"));
  gtk_window_set_type_hint (GTK_WINDOW (dialog_geocode_result), GDK_WINDOW_TYPE_HINT_DIALOG);

  dialog_vbox11 = GTK_DIALOG (dialog_geocode_result)->vbox;
  gtk_widget_show (dialog_vbox11);

  vbox46 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox46);
  gtk_box_pack_start (GTK_BOX (dialog_vbox11), vbox46, FALSE, FALSE, 0);

  label178 = gtk_label_new (_("<b>The output from gpscorrelate:</b>"));
  gtk_widget_show (label178);
  gtk_box_pack_start (GTK_BOX (vbox46), label178, FALSE, FALSE, 7);
  gtk_label_set_use_markup (GTK_LABEL (label178), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label178), 0, 0.5);

  label177 = gtk_label_new (_("Working...."));
  gtk_widget_show (label177);
  gtk_box_pack_start (GTK_BOX (vbox46), label177, FALSE, FALSE, 0);
  gtk_misc_set_alignment (GTK_MISC (label177), 0.02, 0.5);

  dialog_action_area12 = GTK_DIALOG (dialog_geocode_result)->action_area;
  gtk_widget_show (dialog_action_area12);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area12), GTK_BUTTONBOX_END);

  closebutton2 = gtk_button_new_from_stock ("gtk-close");
  gtk_widget_show (closebutton2);
  gtk_dialog_add_action_widget (GTK_DIALOG (dialog_geocode_result), closebutton2, GTK_RESPONSE_CLOSE);
  GTK_WIDGET_SET_FLAGS (closebutton2, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) closebutton2, "clicked",
                    G_CALLBACK (on_closebutton2_clicked),
                    NULL);

  
  GLADE_HOOKUP_OBJECT_NO_REF (dialog_geocode_result, dialog_geocode_result, "dialog_geocode_result");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog_geocode_result, dialog_vbox11, "dialog_vbox11");
  GLADE_HOOKUP_OBJECT (dialog_geocode_result, vbox46, "vbox46");
  GLADE_HOOKUP_OBJECT (dialog_geocode_result, label178, "label178");
  GLADE_HOOKUP_OBJECT (dialog_geocode_result, label177, "label177");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog_geocode_result, dialog_action_area12, "dialog_action_area12");
  GLADE_HOOKUP_OBJECT (dialog_geocode_result, closebutton2, "closebutton2");

  return dialog_geocode_result;
}

