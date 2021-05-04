#include <gtk/gtk.h>

#define MAIN_SPACING 20

GtkWidget *generate_main_menu() {
  GtkWidget *main_container =
      gtk_box_new(GTK_ORIENTATION_VERTICAL, MAIN_SPACING);

  GtkWidget *title = gtk_label_new("EcuRecetas - Main Menu");
  gtk_box_pack_start(GTK_BOX(main_container), title, 1, 1, MAIN_SPACING);

  return main_container;
}
