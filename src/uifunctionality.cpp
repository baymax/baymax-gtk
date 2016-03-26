#include "uifunctionality.h"
#include "uifunctionalityprivate.h"

GtkWidget *carSettingsUiWidget;
GtkWidget *interiorSettingsWidget;
GtkWidget *batteryManagementWidget;

GtkBuilder *mainBuilder;
GtkBuilder *carSettingsBuilder;
GtkBuilder *interiorBuilder;
GtkBuilder *batteryManagerBuilder;

// battery state images

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

float batteryVoltage = 0;
unsigned char baytteryVoltagePrecent = 0;
int batteryCurrent = 0;
unsigned char batteryCurrentPrecent = 0;

// Car door combination images

GtkContainer *carDoorStatesContainer;
GtkImage *currentCarDoorState;
GtkButton *carButton;


GtkImage *doorCombination1Img;
GtkImage *doorCombination2Img;
GtkImage *doorCombination3Img;
GtkImage *doorCombination4Img;
GtkImage *doorCombination5Img;
GtkImage *doorCombination6Img;
GtkImage *doorCombination7Img;
GtkImage *doorCombination8Img;
GtkImage *doorCombination9Img;
GtkImage *doorCombination10Img;
GtkImage *doorCombination11Img;
GtkImage *doorCombination12Img;
GtkImage *doorCombination13Img;
GtkImage *doorCombination14Img;
GtkImage *doorCombination15Img;
GtkImage *doorCombination16Img;

unsigned char doorDriverState = 0; // closed
unsigned char doorPassengerState = 0;
unsigned char doorHoodState = 0;
unsigned char doorTrunkState = 0;


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


unsigned char suspensionState = 0;
unsigned char spoilerMode = 0;
unsigned char regenereationMode = 0;
unsigned char reserveState = 0;
unsigned char sportModeState = 0;

//

// Interior settings

float outTemp = 0;

GtkLabel *tempLabel;

GtkToggleButton *fanSpeed1Button;
GtkToggleButton *fanSpeed2Button;
GtkToggleButton *fanSpeed3Button;
GtkToggleButton *fanSpeed4Button;

GtkToggleButton *interiorLightOnButton;
GtkToggleButton *interiorLightOffButton;

unsigned char interiorLigthState;
unsigned char fanSpeed;

//n


void toggleCarSettings(GtkWidget *widget, gpointer data) {
	gtk_container_remove (mainContainer, interiorSettingsWidget);
	gtk_container_remove (mainContainer, batteryManagementWidget); 
	gtk_container_remove (mainContainer, GTK_WIDGET(carDoorStatesContainer));
	gtk_container_add(mainContainer, carSettingsUiWidget);       
}

void toggleBatterySettings(GtkWidget *widget, gpointer data) {
	gtk_container_remove (mainContainer, interiorSettingsWidget);
	gtk_container_remove (mainContainer, carSettingsUiWidget); 
	gtk_container_remove (mainContainer, GTK_WIDGET(carDoorStatesContainer));
	gtk_container_add(mainContainer, batteryManagementWidget);
}

void toggleComfortSettings(GtkWidget *widget, gpointer data) {
	gtk_container_remove (mainContainer, carSettingsUiWidget);
	gtk_container_remove (mainContainer, batteryManagementWidget); 
	gtk_container_remove (mainContainer, GTK_WIDGET(carDoorStatesContainer));
	gtk_container_add(mainContainer, interiorSettingsWidget);
}

void toggleDoorsStates() {
	gtk_container_remove (mainContainer, carSettingsUiWidget);
	gtk_container_remove (mainContainer, batteryManagementWidget); 
	gtk_container_remove (mainContainer, interiorSettingsWidget);
	gtk_container_add(mainContainer, GTK_WIDGET(carDoorStatesContainer));
}


gboolean changeBatteryState(gpointer data) {
	char labelText[10];
	if (baytteryVoltagePrecent > 100) {
		snprintf(labelText, 10, "%d", 100);
	} else {
		snprintf(labelText, 10, "%d", baytteryVoltagePrecent);
	}
	gtk_label_set_text(batLevelLabel, labelText);
	if (baytteryVoltagePrecent >= 0 && baytteryVoltagePrecent < 10) {
		gtk_container_remove(batBox, GTK_WIDGET(batStateImg));
		gtk_container_add(batBox, GTK_WIDGET(batStateImg5));
		batStateImg = batStateImg5;
	} else if (baytteryVoltagePrecent >= 10 && baytteryVoltagePrecent < 20) {
		gtk_container_remove(batBox, GTK_WIDGET(batStateImg));
		gtk_container_add(batBox, GTK_WIDGET(batStateImg10));
		batStateImg = batStateImg10;
	} else if (baytteryVoltagePrecent >= 20 && baytteryVoltagePrecent < 60) {
		gtk_container_remove(batBox, GTK_WIDGET(batStateImg));
		gtk_container_add(batBox, GTK_WIDGET(batStateImg20));
		batStateImg = batStateImg20;
	} else if (baytteryVoltagePrecent >= 60 && baytteryVoltagePrecent <= 80) {
		gtk_container_remove(batBox, GTK_WIDGET(batStateImg));
		gtk_container_add(batBox, GTK_WIDGET(batStateImg60));
		batStateImg = batStateImg60;
	} else if (baytteryVoltagePrecent >= 80 && baytteryVoltagePrecent < 90) {
		gtk_container_remove(batBox, GTK_WIDGET(batStateImg));
		gtk_container_add(batBox, GTK_WIDGET(batStateImg80));
		batStateImg = batStateImg80;
	} else if (baytteryVoltagePrecent >= 90) {
		gtk_container_remove(batBox, GTK_WIDGET(batStateImg));
		gtk_container_add(batBox, GTK_WIDGET(batStateImg100));
		batStateImg = batStateImg100;
	}
	return G_SOURCE_REMOVE;
}

gboolean changeBatteryCurrent(gpointer data) {
	return G_SOURCE_REMOVE;
}

gboolean setDoor(gpointer data) {
	if (doorDriverState && doorPassengerState && doorHoodState && doorTrunkState) {
		gtk_button_set_image (carButton, GTK_WIDGET(doorCombination1Img));
	} else if (doorDriverState && doorPassengerState && doorHoodState && !doorTrunkState) {
		gtk_button_set_image (carButton, GTK_WIDGET(doorCombination2Img));
	} else if (doorDriverState && doorPassengerState && !doorHoodState && doorTrunkState) {
		gtk_button_set_image (carButton, GTK_WIDGET(doorCombination3Img));	
	} else if (doorDriverState && doorPassengerState && !doorHoodState && !doorTrunkState) {
		gtk_button_set_image (carButton, GTK_WIDGET(doorCombination4Img));
	} else if (doorDriverState && !doorPassengerState && doorHoodState && doorTrunkState) {
		gtk_button_set_image (carButton, GTK_WIDGET(doorCombination5Img));		
	} else if (doorDriverState && !doorPassengerState && doorHoodState && !doorTrunkState) {
		gtk_button_set_image (carButton, GTK_WIDGET(doorCombination6Img));		
	} else if (doorDriverState && !doorPassengerState && !doorHoodState && doorTrunkState) {
		gtk_button_set_image (carButton, GTK_WIDGET(doorCombination7Img));		
	} else if (doorDriverState && !doorPassengerState && !doorHoodState && !doorTrunkState) {
		gtk_button_set_image (carButton, GTK_WIDGET(doorCombination8Img));
	} else if (!doorDriverState && doorPassengerState && doorHoodState && doorTrunkState) {
		gtk_button_set_image (carButton, GTK_WIDGET(doorCombination9Img));	
	} else if (!doorDriverState && doorPassengerState && doorHoodState && !doorTrunkState) {
		gtk_button_set_image (carButton, GTK_WIDGET(doorCombination10Img));	
	} else if (!doorDriverState && doorPassengerState && !doorHoodState && doorTrunkState) {
		gtk_button_set_image (carButton, GTK_WIDGET(doorCombination11Img));		
	} else if (!doorDriverState && doorPassengerState && !doorHoodState && !doorTrunkState) {
		gtk_button_set_image (carButton, GTK_WIDGET(doorCombination12Img));		
	} else if (!doorDriverState && !doorPassengerState && doorHoodState && doorTrunkState) {
		gtk_button_set_image (carButton, GTK_WIDGET(doorCombination13Img));		
	} else if (!doorDriverState && !doorPassengerState && doorHoodState && !doorTrunkState) {
		gtk_button_set_image (carButton, GTK_WIDGET(doorCombination14Img));	
	} else if (!doorDriverState && doorPassengerState && doorHoodState && !doorTrunkState) {
		gtk_button_set_image (carButton, GTK_WIDGET(doorCombination15Img));		
	} else if (!doorDriverState && !doorPassengerState && !doorHoodState && !doorTrunkState) {
		gtk_button_set_image (carButton, GTK_WIDGET(doorCombination16Img));	
	}     
	return G_SOURCE_REMOVE;
}    

gboolean setReserve(gpointer data) {
	return G_SOURCE_REMOVE;
}

gboolean setFanSpeed(gpointer data) {
	switch (fanSpeed) {
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
	printf("Setting suspension to %d", suspensionState);
	switch(suspensionState) {
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
	printf("Setting spoiler mode to %d", spoilerMode);
	switch(spoilerMode) {
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
	printf("Setting sportMode to %d", sportModeState);
	switch(sportModeState) {
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
	printf("Setting regenereation to %d", regenereationMode);
	switch(regenereationMode) {
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

gboolean setOutTemp(gpointer data) {
	char labelText[10];
	snprintf(labelText, 10, "%f", outTemp);
	gtk_label_set_text(tempLabel, labelText);	
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
	carButton = GTK_BUTTON(gtk_builder_get_object (mainBuilder, "carSettingsButton"));
	g_signal_connect (G_OBJECT(carButton), "clicked", G_CALLBACK (toggleCarSettings), NULL);
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
	gtk_container_add(batBox, GTK_WIDGET(batStateImg80));
	batStateImg = batStateImg80;
	
	// Loading temperature label
	
	tempLabel = GTK_LABEL(gtk_builder_get_object(mainBuilder, "temperatureLabel"));
	
	
	// Loading doorcombinationimages
	
	carDoorStatesContainer = GTK_CONTAINER(gtk_builder_get_object(mainBuilder, "carDoorStatesContainer"));
	currentCarDoorState = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "currentCarDoorStateImg"));
	
	doorCombination1Img = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "combination1Img"));
	doorCombination2Img = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "combination2Img"));
	doorCombination3Img = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "combination3Img"));
	doorCombination4Img = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "combination4Img"));
	doorCombination5Img = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "combination5Img"));
	doorCombination6Img = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "combination6Img"));
	doorCombination7Img = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "combination7Img"));
	doorCombination8Img = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "combination8Img"));
	doorCombination9Img = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "combination9Img"));
	doorCombination10Img = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "combination10Img"));
	doorCombination11Img = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "combination11Img"));
	doorCombination12Img = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "combination12Img"));
	doorCombination13Img = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "combination13Img"));
	doorCombination14Img = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "combination14Img"));
	doorCombination15Img = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "combination15Img"));
	doorCombination16Img = GTK_IMAGE(gtk_builder_get_object(mainBuilder, "combination16Img"));
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


