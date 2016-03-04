#include "uifunctionality.h"
#include "uifunctionalityprivate.h"

GtkWidget *carSettingsUiWidget;
GtkWidget *interiorSettingsWidget;
GtkWidget *batteryManagementWidget;

GtkBuilder *mainBuilder;
GtkBuilder *carSettingsBuilder;
GtkBuilder *interiorBuilder;
GtkBuilder *batteryManagerBuilder;

GObject *window;

GtkContainer *mainContainer;

void toggleCarSettings(GtkWidget *widget, gpointer data) {
    gtk_container_remove (mainContainer, interiorSettingsWidget);
    gtk_container_remove (mainContainer, batteryManagementWidget); 
    gtk_container_add(mainContainer, carSettingsUiWidget);       
}

void toggleBatterySettings(GtkWidget *widget, gpointer data) {
    gtk_container_remove (mainContainer, interiorSettingsWidget);
    gtk_container_remove (mainContainer, carSettingsUiWidget); 
    gtk_container_add(mainContainer, batteryManagementWidget);
}

void toggleComfortSettings(GtkWidget *widget, gpointer data) {
    gtk_container_remove (mainContainer, carSettingsUiWidget);
    gtk_container_remove (mainContainer, batteryManagementWidget); 
    gtk_container_add(mainContainer, interiorSettingsWidget);
}


void loadMainUi(const char *path) {
    mainBuilder = gtk_builder_new_from_file (path);
    window = gtk_builder_get_object (mainBuilder, "window");
    gtk_window_maximize (GTK_WINDOW(window));
    mainContainer = GTK_CONTAINER(gtk_builder_get_object (mainBuilder, "functionsContainer"));
    GObject *button;
    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    button = gtk_builder_get_object (mainBuilder, "batteryManagerButton");
    g_signal_connect (button, "clicked", G_CALLBACK (toggleBatterySettings), NULL);
    button = gtk_builder_get_object (mainBuilder, "carSettingsButton");
    g_signal_connect (button, "clicked", G_CALLBACK (toggleCarSettings), NULL);
    button = gtk_builder_get_object (mainBuilder, "comfortSettingsButton");
    g_signal_connect (button, "clicked", G_CALLBACK (toggleComfortSettings), NULL);
}

void loadCarSettingsUi(const char *path) {
    carSettingsBuilder = gtk_builder_new_from_file (path);
    carSettingsUiWidget = GTK_WIDGET(gtk_builder_get_object (carSettingsBuilder, "mainContainer"));
    GObject *button;
    button = gtk_builder_get_object (carSettingsBuilder, "setSuspensionLowButton");
    g_signal_connect (button, "clicked", G_CALLBACK (setSuspensionLow), NULL);
    button = gtk_builder_get_object (carSettingsBuilder, "setSuspensionNormalButton");
    g_signal_connect (button, "clicked", G_CALLBACK (setSuspensionNormal), NULL);
    button = gtk_builder_get_object (carSettingsBuilder, "setSuspensionHighButton");
    g_signal_connect (button, "clicked", G_CALLBACK (setSuspensionHigh), NULL);
    
    button = gtk_builder_get_object (carSettingsBuilder, "setSportModeButton");
    g_signal_connect (button, "clicked", G_CALLBACK (sportMode), NULL);
    button = gtk_builder_get_object (carSettingsBuilder, "setNormalModeButton");
    g_signal_connect (button, "clicked", G_CALLBACK (normalMode), NULL);
    
    button = gtk_builder_get_object (carSettingsBuilder, "setDownForceOnButton");
    g_signal_connect (button, "clicked", G_CALLBACK (setDownForceOn), NULL);
    button = gtk_builder_get_object (carSettingsBuilder, "setDownForceOffButton");
    g_signal_connect (button, "clicked", G_CALLBACK (setDownForceOff), NULL);
}

void loadInteriorBuilder(const char *path) {
    interiorBuilder = gtk_builder_new_from_file(path);
    interiorSettingsWidget = GTK_WIDGET(gtk_builder_get_object(interiorBuilder, "mainContainer"));
    
    GObject *button;
    
    button = gtk_builder_get_object (interiorBuilder, "setFanSpeed1Button");
    g_signal_connect (button, "clicked", G_CALLBACK (setFanSpeed1), NULL);
    button = gtk_builder_get_object (interiorBuilder, "setFanSpeed2Button");
    g_signal_connect (button, "clicked", G_CALLBACK (setFanSpeed2), NULL);
    button = gtk_builder_get_object (interiorBuilder, "setFanSpeed3Button");
    g_signal_connect (button, "clicked", G_CALLBACK (setFanSpeed3), NULL);
    button = gtk_builder_get_object (interiorBuilder, "setFanSpeed4Button");
    g_signal_connect (button, "clicked", G_CALLBACK (setFanSpeed4), NULL);

}

void loadBatteryManagerBuilder(const char *path) {
    batteryManagerBuilder= gtk_builder_new_from_file(path);
    batteryManagementWidget = GTK_WIDGET(gtk_builder_get_object(batteryManagerBuilder, "mainContainer"));
}


