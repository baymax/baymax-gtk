#include <gtk/gtk.h>
#include 

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

static void toggleCarSettings(GtkWidget *widget, gpointer data);
static void toggleBatterySettings()

int
main (int   argc,
      char *argv[])
{
  GtkBuilder *builder;
  GObject *window;
  GObject *button;
  GObject *batteryManagerButton;
  GObject *carSettingsButton;
  GObject *comfortSettingsButton;

  gtk_init (&argc, &argv);

  /* Construct a GtkBuilder instance and load our UI description */
  //builder = gtk_builder_new ();
  builder = gtk_builder_new_from_file ("/home/jaska/Dropbox/baymax-gtk/ui/main.ui");
  //gtk_builder_add_from_file (builder, "~/Dropbox/baymax-gtk/ui/builder.ui", NULL);

  /* Connect signal handlers to the constructed widgets. */
  window = gtk_builder_get_object (builder, "window");
  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  button = gtk_builder_get_object (builder, "batteryManagerButton");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

  button = gtk_builder_get_object (builder, "carSettingsButton");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

  button = gtk_builder_get_object (builder, "comfortSettingsButton");
  g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);

  gtk_main ();

  return 0;
}