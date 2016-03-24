#include "cmdparser.h"
#include "uifunctionality.h"

void parseCmd(unsigned char cmd, unsigned char data) {
    DoorCombinationParameters p;
    switch (cmd) {
        case BATTERY_VOLTAGE:
            batStateData d;
            d.value = data;
            gdk_threads_add_idle(changeBatteryState, &d);
        break;
        case FAN_SPEED:
            gdk_threads_add_idle(setFanSpeed, &data);
        break;
        case SUSPENSION_MODE:
            gdk_threads_add_idle(setSuspensionMode, &data);
        break;
        case INTERIOR_LIGTH:
            gdk_threads_add_idle(setInteriorLigth, &data);
        break;
        case SPOILER_MODE:
            gdk_threads_add_idle(setSpoilerMode, &data);
        break;
        case SPORT_MODE:
            gdk_threads_add_idle(setSportMode, &data);
        break;
        case REGENERATION:
            gdk_threads_add_idle(setRegeneration, &data);
        break;
        case DOOR_DRIVER:
            doorDriverState = data;
            gdk_threads_add_idle(setDoor, &p);
        break;
        case DOOR_PASSENGER:
            doorPassengerState = data;
            gdk_threads_add_idle(setDoor, &p);        
        break;
        case DOOR_HOOD:
            doorHoodState = data;
            gdk_threads_add_idle(setDoor, &p);       
        break;
        case DOOR_TRUNK:
            doorTrunkState = data;
            gdk_threads_add_idle(setDoor, &p);       
        break;
        default:
        
        break; 
    }
}