#include <gtk/gtk.h>

void
print_track();

gboolean
on_drawingarea1_button_press_event     (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea1_motion_notify_event    (GtkWidget       *widget,
                                        GdkEventMotion  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea1_configure_event        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea1_expose_event           (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_drawingarea1_button_release_event   (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_vscale1_value_changed               (GtkRange        *range,
                                        gpointer         user_data);

void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_window1_delete_event                (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

gboolean
on_window1_destroy_event               (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button5_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_item1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_item2_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

gboolean
on_vscale1_change_value                (GtkRange        *range,
                                        GtkScrollType    scroll,
                                        gdouble          value,
                                        gpointer         user_data);

gboolean
on_vscale1_button_press_event          (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_vscale1_button_release_event        (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_comboboxtext1_changed                   (GtkComboBox     *combobox,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_dialog1_close                       (GtkDialog       *dialog,
                                        gpointer         user_data);

void
on_dialog1_response                    (GtkDialog       *dialog,
                                        gint             response_id,
                                        gpointer         user_data);

void
on_cancelbutton1_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbutton1_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_entry1_changed                      (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_entry2_changed                      (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_entry1_changed                      (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_entry2_changed                      (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
//-----------Traffic auto & show---------------
void
on_checkbutton_trf_auto_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
void
on_togglebutton_trf_show_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
void
on_comboboxtext_trf_changed        (GtkComboBox     *combobox,
                                        gpointer         user_data);
//-----------Traffic auto & show---------------
void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_togglebutton1_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_item3_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_item4_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);


void
on_button14_clicked                    (GtkButton       *button,
                                        gpointer         user_data);


gboolean
on_drawingarea1_scroll_event            (GtkWidget       *widget,
                                        GdkEventScroll   *event,
                                        gpointer         user_data);

void
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_entry7_changed                      (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_entry8_changed                      (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_button13_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button16_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button17_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button18_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button19_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button20_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_cancelbutton2_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbutton2_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton9_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_item6_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);


void
on_item8_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_cancelbutton3_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbutton3_clicked                   (GtkButton       *button,
                                        gpointer         user_data);


gboolean
on_drawingarea2_configure_event        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea2_expose_event           (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_closebutton2_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_item10_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_item11_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_button21_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_item9_button_release_event          (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);





void
on_dialog5_close                       (GtkDialog       *dialog,
                                        gpointer         user_data);

void
on_cancelbutton4_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbutton4_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_dialog6_close                       (GtkDialog       *dialog,
                                        gpointer         user_data);

void
on_cancelbutton5_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbutton5_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_dialog6_delete_event                (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

gboolean
on_dialog5_delete_event                (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_combobox2_changed                   (GtkComboBox     *combobox,
                                        gpointer         user_data);

void
on_item15_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_button22_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_item5_activate                      (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_item7_activate                      (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_item12_activate                     (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_item14_activate                     (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton13_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_entry16_changed                     (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_radiobutton14_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton15_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton16_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton17_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton18_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton19_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton20_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton21_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton8_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

gboolean
on_button11_expose_event               (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_button23_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_item17_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_item18_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_togglebutton2_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_cancelbutton4_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbutton4_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button26_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_window2_delete_event                (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_button27_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button28_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_window3_delete_event                (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_item19_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_item20_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_null_activate                       (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_item9_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
repaint_all();

void
on_button29_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button33_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_cancelbutton5_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbutton5_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_cancelbutton5a_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbutton5a_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button30_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_drawingarea1_key_press_event        (GtkWidget       *widget,
                                        GdkEventKey     *event,
                                        gpointer         user_data);

void
on_button34_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_dialog7_delete_event                (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_cancelbutton6_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbutton6_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button35_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_entry3_changed                      (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_entry4_changed                      (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_button36_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_window12_delete_event               (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_button37_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button38_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_cancelbutton7_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbutton7_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_entry5_changed                      (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_entry20_changed                     (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_entry21_changed                     (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_checkbutton12_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_entry24_changed                     (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_entry25_changed                     (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_entry26_changed                     (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_checkbutton13_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_entry21_activate                    (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_eventbox1_button_release_event      (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_eventbox1_button_release_event      (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_eventbox1_button_release_event      (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_eventbox2_button_release_event      (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea3_configure_event        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea3_expose_event           (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_itemgeocode1_activate               (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_itemimport1_activate                (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_itemselect1_activate                (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_button39_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button40_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button41_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_cancelbutton8_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbutton8_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button44_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button45_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button46_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button47_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button48_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_okbutton9_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button49_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_eventbox3_button_release_event      (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_checkbutton14_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_combobox7_changed                   (GtkComboBox     *combobox,
                                        gpointer         user_data);

gboolean
on_dialog_geocode_delete_event         (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

gboolean
on_dialog_image_data_delete_event      (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

gboolean
on_eventbox4_button_release_event      (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_entry28_changed                     (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_button50_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_closebutton2_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void grid_show(GtkWidget* widget);

