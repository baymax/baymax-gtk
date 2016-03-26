
#ifndef UIFUNCTIONALITY_H
#define UIFUNCTIONALITY_H

#include <gtk/gtk.h>

#include "functions.h"

// doorstates

extern unsigned char doorDriverState;
extern unsigned char doorPassengerState;
extern unsigned char doorHoodState;
extern unsigned char doorTrunkState;

// temperature

extern float outTemp;

//

extern unsigned char suspensionState;

//

extern unsigned char interiorLigthState;

//

extern unsigned char spoilerMode;

//

extern unsigned char regenereationMode;

//

extern unsigned char baytteryVoltagePrecent;
extern float batteryVoltage; 

//

extern int batteryCurrent;
extern unsigned char batteryCurrentPrecent;

//

extern unsigned char reserveState;

//

extern unsigned char fanSpeed;

//

extern unsigned char sportModeState;

void toggleCarSettings(GtkWidget *widget, gpointer data);
void toggleBatterySettings(GtkWidget *widget, gpointer data);
void toggleComfortSettings(GtkWidget *widget, gpointer data);
void toggleDoorsStates();

gboolean changeBatteryState(gpointer data);
gboolean changeBatteryCurrent(gpointer data);

gboolean setDoor(gpointer data);
/*gboolean setDoorDriver(gpointer data);
gboolean setDoorPassenger(gpointer data);
gboolean setDoorHood(gpointer data);
gboolean setDoorTrunk(gpointer data);*/
gboolean setReserve(gpointer data);
gboolean setFanSpeed(gpointer data);
gboolean setSuspensionMode(gpointer data);
gboolean setInteriorLigth(gpointer data);
gboolean setSpoilerMode(gpointer data);
gboolean setSportMode(gpointer data);
gboolean setRegeneration(gpointer data);
gboolean setOutTemp(gpointer data);

//


void loadMainUi(const char *path);
void loadCarSettingsUi(const char *path);
void loadInteriorBuilder(const char *path);
void loadBatteryManagerBuilder(const char *path);

struct batStateData {
    int value;
};

struct DoorCombinationParameters {
    unsigned char door;
    unsigned char mode;
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