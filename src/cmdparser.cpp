#include "cmdparser.h"
#include "uifunctionality.h"
#include "convert.h"

#include <stdlib.h>

void parseCmd(const char *buf) {
	unsigned char cmd;
	cmd = buf[0];
	if (cmd == TEMPERATURE) {			
		unsigned char tempId;
		tempId = buf[1];
		outTemp = strtof(buf+2, NULL);
		gdk_threads_add_idle(setOutTemp, NULL);
	} else if (cmd == BATTERY_VOLTAGE) {
		int voltageVal = strtof(buf+2, NULL);
		baytteryVoltagePrecent = convertVoltageValToPrecent(voltageVal);
		batteryVoltage = convertVoltageValToVoltage(voltageVal);
		gdk_threads_add_idle(changeBatteryState, NULL);
	} else if (cmd == BATTERY_CURRENT) {
		int currentVal = strtof(buf+2, NULL);
		batteryCurrent = convertCurrentValToCurrent(currentVal);
		batteryCurrentPrecent = convertCurrentValToPrecent(currentVal);
		gdk_threads_add_idle(changeBatteryCurrent, NULL);
	} else {
		switch(cmd) {
			case DOOR_DRIVER:
				doorDriverState = buf[1];
				gdk_threads_add_idle(setDoor, NULL);
			break;
			case DOOR_PASSENGER:
				doorPassengerState = buf[1];
				gdk_threads_add_idle(setDoor, NULL);        
			break;
			case DOOR_HOOD:
				doorHoodState = buf[1];
				gdk_threads_add_idle(setDoor, NULL);       
			break;
			case DOOR_TRUNK:
				doorTrunkState = buf[1];
				gdk_threads_add_idle(setDoor, NULL);       
			break;
			default:
		
			break; 
		}
		
	}
	
	/*DoorCombinationParameters p;
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
	}*/
}