#include "uifunctionality.h"
#include "uifunctionalityprivate.h"

GtkWidget *carSettingsUiWidget;
GtkWidget *interiorSettingsWidget;
GtkWidget *batteryManagementWidget;

GtkBuilder *mainBuilder;
GtkBuilder *carSettingsBuilder;
GtkBuilder *interiorBuilder;
GtkBuilder *batteryManagerBuilder;

GtkImage *batStateImg;
GtkImage *batStateImg5;
GtkImage *batStateImg10;
GtkImage *batStateImg20;
GtkImage *batStateImg60;
GtkImage *batStateImg80;
GtkImage *batStateImg100;

GtkLabel *batLevelLabel;

GtkContainer *batBox;

GObject *window;

GtkContainer *mainContainer;

// Carsettings buttons

GtkToggleButton *suspensionLowButton;
GtkToggleButton *suspensionHighButton;
GtkToggleButton *suspensionNormalButton;

GtkToggleButton *sportModeButton;
GtkToggleButton *normalModeButton;

GtkToggleButton *downForceOnButton;
GtkToggleButton *downForceOffButton;

GtkToggleButton *regenerationOnButton;
GtkToggleButton *regenerationOffButton;

//

// Interior settings

GtkToggleButton *fanSpeed1Button;
GtkToggleButton *fanSpeed2Button;
GtkToggleButton *fanSpeed3Button;
GtkToggleButton *fanSpeed4Button;

GtkToggleButton *interiorLightOnButton;
GtkToggleButton *interiorLightOffButton;

//


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


gboolean changeBatteryState(gpointer data) {
    batStateData *d = (batStateData*)data;
    //d.value = 10;
    printf("%d", d->value);
    //int procent = (int)state;
    char labelText[10];
    if (d->value > 100) {
        snprintf(labelText, 10, "%d", 100);
    } else {
        snprintf(labelText, 10, "%d", d->value);
    }
    gtk_label_set_text(batLevelLabel, labelText);
    if (d->value >= 5 && d->value < 10) {
        gtk_container_remove(batBox, GTK_WIDGET(batStateImg));
        gtk_container_add(batBox, GTK_WIDGET(batStateImg5));
        batStateImg = batStateImg5;
    } else if (d->value >= 10 && d->value < 20) {
        gtk_container_remove(batBox, GTK_WIDGET(batStateImg));
        gtk_container_add(batBox, GTK_WIDGET(batStateImg10));
        batStateImg = batStateImg10;
    } else if (d->value >= 20 && d->value < 60) {
        gtk_container_remove(batBox, GTK_WIDGET(batStateImg));
        gtk_container_add(batBox, GTK_WIDGET(batStateImg20));
        batStateImg = batStateImg20;
    } else if (d->value >= 60 && d->value <= 80) {
        gtk_container_remove(batBox, GTK_WIDGET(batStateImg));
        gtk_container_add(batBox, GTK_WIDGET(batStateImg60));
        batStateImg = batStateImg60;
    } else if (d->value >= 80 && d->value < 90) {
        gtk_container_remove(batBox, GTK_WIDGET(batStateImg));
        gtk_container_add(batBox, GTK_WIDGET(batStateImg80));
        batStateImg = batStateImg80;
    } else if (d->value >= 90) {
        gtk_container_remove(batBox, GTK_WIDGET(batStateImg));
        gtk_container_add(batBox, GTK_WIDGET(batStateImg100));
        batStateImg = batStateImg100;
    }
    return G_SOURCE_REMOVE;
}

gboolean changeBatteryCurrent(gpointer data) {
    return G_SOURCE_REMOVE;
}

gboolean setDoorDriver(gpointer data) {
    return G_SOURCE_REMOVE;
}

gboolean setDoorPassenger(gpointer data) {
    return G_SOURCE_REMOVE;
}

gboolean setDoorHood(gpointer data) {
    return G_SOURCE_REMOVE;
}

gboolean setDoorTrunk(gpointer data) {
    return G_SOURCE_REMOVE;
}

gboolean setReserve(gpointer data) {
    return G_SOURCE_REMOVE;
}

gboolean setFanSpeed(gpointer data) {
    
    char value = *((char*)data);
    switch (value) {
        case 1:
            g_object_set(G_OBJECT(fanSpeed1Button), "active", TRUE);
            g_object_set(G_OBJECT(fanSpeed2Button), "active", FALSE);
            g_object_set(G_OBJECT(fanSpeed3Button), "active", FALSE);
            g_object_set(G_OBJECT(fanSpeed4Button), "active", FALSE);
        break;
        case 2:
            g_object_set(G_OBJECT(fanSpeed2Button), "active", TRUE);
            g_object_set(G_OBJECT(fanSpeed1Button), "active", FALSE);
            g_object_set(G_OBJECT(fanSpeed3Button), "active", FALSE);
            g_object_set(G_OBJECT(fanSpeed4Button), "active", FALSE);
        break;
        case 3:
            g_object_set(G_OBJECT(fanSpeed3Button), "active", TRUE);
            g_object_set(G_OBJECT(fanSpeed1Button), "active", FALSE);
            g_object_set(G_OBJECT(fanSpeed2Button), "active", FALSE);
            g_object_set(G_OBJECT(fanSpeed4Button), "active", FALSE);
        break;
        case 4:
            g_object_set(G_OBJECT(fanSpeed4Button), "active", TRUE);
            g_object_set(G_OBJECT(fanSpeed1Button), "active", FALSE);
            g_object_set(G_OBJECT(fanSpeed2Button), "active", FALSE);
            g_object_set(G_OBJECT(fanSpeed3Button), "active", FALSE);     
        break;
        default:
        
        break;        
    }
    return G_SOURCE_REMOVE;
}

gboolean setSuspensionMode(gpointer data) {
    char value = *((char*)data);
    printf("Setting suspension mode to %d\n", value);
    switch(value) {
        case 0:
            g_object_set(G_OBJECT(suspensionLowButton), "active", TRUE);
            g_object_set(G_OBJECT(suspensionNormalButton), "active", FALSE);
            g_object_set(G_OBJECT(suspensionHighButton), "active", FALSE);   
        break;
        case 1:
            g_object_set(G_OBJECT(suspensionNormalButton), "active", TRUE);
            g_object_set(G_OBJECT(suspensionLowButton), "active", FALSE);
            g_object_set(G_OBJECT(suspensionHighButton), "active", FALSE);        
        break;
        case 2:
            g_object_set(G_OBJECT(suspensionHighButton), "active", TRUE);
            g_object_set(G_OBJECT(suspensionNormalButton), "active", FALSE);
            g_object_set(G_OBJECT(suspensionLowButton), "active", FALSE);        
        break;
        
    }
    return G_SOURCE_REMOVE;
}

gboolean setInteriorLigth(gpointer data) {
    return G_SOURCE_REMOVE;
}

gboolean setSpoilerMode(gpointer data) {
        char value = *((char*)data);
    switch(value) {
        case 0:
            g_object_set(G_OBJECT(downForceOffButton), "active", TRUE);
            g_object_set(G_OBJECT(downForceOnButton), "active", FALSE);
        break;
        case 1:
            g_object_set(G_OBJECT(downForceOnButton), "active", TRUE);
            g_object_set(G_OBJECT(downForceOffButton), "active", FALSE);     
        break;        
    }
    return G_SOURCE_REMOVE;
}

gboolean setSportMode(gpointer data) {
        char value = *((char*)data);
    switch(value) {
        case 0:
            g_object_set(G_OBJECT(normalModeButton), "active", TRUE);
            g_object_set(G_OBJECT(sportModeButton), "active", FALSE);
        break;
        case 1:
            g_object_set(G_OBJECT(sportModeButton), "active", TRUE);
            g_object_set(G_OBJECT(normalModeButton), "active", FALSE);     
        break;        
    }
    return G_SOURCE_REMOVE;
}

gboolean setRegeneration(gpointer data) {
        char value = *((char*)data);
    switch(value) {
        case 0:
            g_object_set(G_OBJECT(regenerationOffButton), "active", TRUE);
            g_object_set(G_OBJECT(regenerationOnButton), "active", FALSE);   
        break;
        case 1:
            g_object_set(G_OBJECT(regenerationOnButton), "active", TRUE);
            g_object_set(G_OBJECT(regenerationOffButton), "active", FALSE);    
        break;        
    }
    return G_SOURCE_REMOVE;
}


// Load uis;


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
    
    batStateImg = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "batStateImg"));    
    batStateImg5 = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "batStateImg5"));
    batStateImg10 = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "batStateImg10"));
    batStateImg20 = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "batStateImg20"));
    batStateImg60 = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "batStateImg60"));
    batStateImg80 = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "batStateImg80"));
    batStateImg100 = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "batStateImg100"));
    
    batLevelLabel = GTK_LABEL(gtk_builder_get_object(mainBuilder, "batLevelLabel"));
    
    batBox = GTK_CONTAINER(gtk_builder_get_object(mainBuilder, "batImgStateBox"));
    //gtk_container_add(batBox, GTK_WIDGET(batStateImg20));
    gtk_container_remove(batBox, GTK_WIDGET(batStateImg));
    gtk_container_add(batBox, GTK_WIDGET(batStateImg5));
    batStateImg = batStateImg5;
    gtk_container_remove(batBox, GTK_WIDGET(batStateImg));
    gtk_container_add(batBox, GTK_WIDGET(batStateImg80));
    batStateImg = batStateImg80;
}

void loadCarSettingsUi(const char *path) {
    carSettingsBuilder = gtk_builder_new_from_file (path);
    carSettingsUiWidget = GTK_WIDGET(gtk_builder_get_object (carSettingsBuilder, "mainContainer"));
    GObject *button;
    suspensionLowButton = GTK_TOGGLE_BUTTON (gtk_builder_get_object (carSettingsBuilder, "setSuspensionLowButton"));
    g_signal_connect (suspensionLowButton, "clicked", G_CALLBACK (setSuspensionLow), NULL);
    suspensionNormalButton = GTK_TOGGLE_BUTTON (gtk_builder_get_object (carSettingsBuilder, "setSuspensionNormalButton"));
    g_signal_connect (suspensionNormalButton, "clicked", G_CALLBACK (setSuspensionNormal), NULL);
    suspensionHighButton = GTK_TOGGLE_BUTTON (gtk_builder_get_object (carSettingsBuilder, "setSuspensionHighButton"));
    g_signal_connect (suspensionHighButton, "clicked", G_CALLBACK (setSuspensionHigh), NULL);
    
    sportModeButton = GTK_TOGGLE_BUTTON (gtk_builder_get_object (carSettingsBuilder, "setSportModeButton"));
    g_signal_connect (sportModeButton, "clicked", G_CALLBACK (sportMode), NULL);
    normalModeButton = GTK_TOGGLE_BUTTON (gtk_builder_get_object (carSettingsBuilder, "setNormalModeButton"));
    g_signal_connect (normalModeButton, "clicked", G_CALLBACK (normalMode), NULL);
    
    downForceOnButton = GTK_TOGGLE_BUTTON (gtk_builder_get_object (carSettingsBuilder, "setDownForceOnButton"));
    g_signal_connect (downForceOnButton, "clicked", G_CALLBACK (setDownForceOn), NULL);
    downForceOffButton = GTK_TOGGLE_BUTTON (gtk_builder_get_object (carSettingsBuilder, "setDownForceOffButton"));
    g_signal_connect (downForceOffButton, "clicked", G_CALLBACK (setDownForceOff), NULL);
    
    regenerationOnButton = GTK_TOGGLE_BUTTON (gtk_builder_get_object (carSettingsBuilder, "regenerationOnButton"));
    g_signal_connect (regenerationOnButton , "clicked", G_CALLBACK (setRegenerationOn), NULL);
    regenerationOffButton = GTK_TOGGLE_BUTTON (gtk_builder_get_object (carSettingsBuilder, "regenerationOffButton"));
    g_signal_connect (regenerationOffButton, "clicked", G_CALLBACK (setRegenerationOff), NULL);
    
}

void loadInteriorBuilder(const char *path) {
    interiorBuilder = gtk_builder_new_from_file(path);
    interiorSettingsWidget = GTK_WIDGET(gtk_builder_get_object(interiorBuilder, "mainContainer"));
    
    GObject *button;
    
    fanSpeed1Button = GTK_TOGGLE_BUTTON (gtk_builder_get_object (interiorBuilder, "setFanSpeed1Button"));
    g_signal_connect (fanSpeed1Button, "toggled", G_CALLBACK (setFanSpeed1), NULL);
    fanSpeed2Button = GTK_TOGGLE_BUTTON (gtk_builder_get_object (interiorBuilder, "setFanSpeed2Button"));
    g_signal_connect (fanSpeed2Button, "toggled", G_CALLBACK (setFanSpeed2), NULL);
    fanSpeed3Button = GTK_TOGGLE_BUTTON (gtk_builder_get_object (interiorBuilder, "setFanSpeed3Button"));
    g_signal_connect (fanSpeed3Button, "toggled", G_CALLBACK (setFanSpeed3), NULL);
    fanSpeed4Button = GTK_TOGGLE_BUTTON (gtk_builder_get_object (interiorBuilder, "setFanSpeed4Button"));
    g_signal_connect (fanSpeed4Button, "toggled", G_CALLBACK (setFanSpeed4), NULL);

}

void loadBatteryManagerBuilder(const char *path) {
    batteryManagerBuilder= gtk_builder_new_from_file(path);
    batteryManagementWidget = GTK_WIDGET(gtk_builder_get_object(batteryManagerBuilder, "mainContainer"));
}


