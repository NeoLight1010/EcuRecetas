#include <gtk/gtk.h>
#include <stdio.h>
#include <widgets/main_menu.h>

void activate(GtkApplication *app, gpointer data) {
  GtkWidget *window;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "EcuRecetas");
  gtk_window_set_default_size(GTK_WINDOW(window), 600, 450);

  GtkWidget *main_menu = generate_main_menu();
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
