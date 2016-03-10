
#ifndef UIFUNCTIONALITY_H
#define UIFUNCTIONALITY_H

#include <gtk/gtk.h>

#include "functions.h"




void toggleCarSettings(GtkWidget *widget, gpointer data);
void toggleBatterySettings(GtkWidget *widget, gpointer data);
void toggleComfortSettings(GtkWidget *widget, gpointer data);

void loadMainUi(const char *path);
void loadCarSettingsUi(const char *path);
void loadInteriorBuilder(const char *path);
void loadBatteryManagerBuilder(const char *path);

/*
GtkWidget *getCarSettingsUiWidget();
GtkWidget *getInteriorSettingsWidget();
GtkWidget *getBatteryManagementWIdget();
*/

/*GtkBuilder *
GtkBuilder *
GtkBuilder *
GtkBuilder *

GObject *

GtkContainer *
*/


#endif // UIFUNCTIONALITY_H