#include <gtk/gtk.h>

#define MAIN_SPACING 20

GtkWidget *generate_main_menu(gpointer window_pointer) {
  GtkWidget *window = window_pointer;

  // Header bar
  GtkWidget *header_bar = gtk_window_get_titlebar(GTK_WINDOW(window));
  gtk_header_bar_set_subtitle(GTK_HEADER_BAR(header_bar), "Menú Principal");

  GtkWidget *about_header_btn = gtk_button_new_from_icon_name(
      "help-about-symbolic", GTK_ICON_SIZE_SMALL_TOOLBAR);
  gtk_header_bar_pack_start(GTK_HEADER_BAR(header_bar), about_header_btn);

  // Body
  GtkWidget *main_container =
      gtk_box_new(GTK_ORIENTATION_VERTICAL, MAIN_SPACING);

  // Buttons
  GtkWidget *button_box = gtk_button_box_new(GTK_ORIENTATION_VERTICAL);
  gtk_box_set_spacing(GTK_BOX(button_box), MAIN_SPACING);
  gtk_box_pack_start(GTK_BOX(main_container), button_box, 1, 0, MAIN_SPACING);

  // Search Recipe Button
  GtkWidget *search_recipe_btn = gtk_button_new();
  gtk_button_set_label(GTK_BUTTON(search_recipe_btn), "Buscar Receta");
  gtk_container_add(GTK_CONTAINER(button_box), search_recipe_btn);

  // See Favorites Button
  GtkWidget *see_favorites_btn = gtk_button_new();
  gtk_button_set_label(GTK_BUTTON(see_favorites_btn), "Ver recetas favoritas");
  gtk_container_add(GTK_CONTAINER(button_box), see_favorites_btn);

  // Exit Button
  GtkWidget *exit_btn = gtk_button_new();
  gtk_button_set_label(GTK_BUTTON(exit_btn), "Salir");
  g_signal_connect(exit_btn, "clicked", G_CALLBACK(gtk_window_close),
                   GTK_WINDOW(window));
  gtk_container_add(GTK_CONTAINER(button_box), exit_btn);

  return main_container;
}
