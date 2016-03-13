
#ifndef UIFUNCTIONALITY_H
#define UIFUNCTIONALITY_H

#include <gtk/gtk.h>

#include "functions.h"




void toggleCarSettings(GtkWidget *widget, gpointer data);
void toggleBatterySettings(GtkWidget *widget, gpointer data);
void toggleComfortSettings(GtkWidget *widget, gpointer data);

gboolean changeBatteryState(gpointer data);
gboolean changeBatteryCurrent(gpointer data);

gboolean setDoorDriver(gpointer data);
gboolean setDoorPassenger(gpointer data);
gboolean setDoorHood(gpointer data);
gboolean setDoorTrunk(gpointer data);
gboolean setReserve(gpointer data);
gboolean setFanSpeed(gpointer data);
gboolean setSuspensionMode(gpointer data);
gboolean setInteriorLigth(gpointer data);
gboolean setSpoilerMode(gpointer data);
gboolean setSportMode(gpointer data);
gboolean setRegeneration(gpointer data);




void loadMainUi(const char *path);
void loadCarSettingsUi(const char *path);
void loadInteriorBuilder(const char *path);
void loadBatteryManagerBuilder(const char *path);

struct batStateData {
    int value;
};

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