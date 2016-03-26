#include "convert.h"

int voltageRes = 1023;
int currentRes = 1023;

float convertVoltageValToVoltage(int voltageVal) {
    return 0;
}

int convertVoltageValToPrecent(int voltageVal) {
    return voltageVal / voltageRes * 100;
}

int convertCurrentValToCurrent(int currentVal) {
    return 0;
}

int convertCurrentValToPrecent(int currentVal) {
    return currentVal / currentRes * 100;
}