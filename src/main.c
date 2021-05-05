#include <gtk/gtk.h>
#include <stdio.h>
#include <widgets/main_menu.h>

void activate(GtkApplication *app, gpointer data) {
  GtkWidget *window;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "EcuRecetas");
  gtk_window_set_default_size(GTK_WINDOW(window), 600, 450);

  GtkWidget *header_bar = gtk_header_bar_new();
  gtk_header_bar_set_title(GTK_HEADER_BAR(header_bar), "EcuRecetas");
  gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(header_bar), 1);
  gtk_window_set_titlebar(GTK_WINDOW(window), header_bar);

  GtkWidget *main_menu = generate_main_menu(window);
  gtk_container_add(GTK_CONTAINER(window), main_menu);

  gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
  GtkApplication *app;
  int status;

  app =
      gtk_application_new("org.neolight.ecurecetas", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
