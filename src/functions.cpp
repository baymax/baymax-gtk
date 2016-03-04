#include "functions.h"

void sportMode(GtkWidget *widget, gpointer data) {
    sendCommandToSender(SPORT_MODE_ON);
}

void normalMode(GtkWidget *widget, gpointer data) {
    sendCommandToSender(SPORT_MODE_OFF);
}

void setSuspensionHigh(GtkWidget *widget, gpointer data) {
    sendCommandToSender(SUSPENSION_MODE_HIGH);
}

void setSuspensionNormal(GtkWidget *widget, gpointer data) {
    sendCommandToSender(SUSPENSION_MODE_NORMAL);
}

void setSuspensionLow(GtkWidget *widget, gpointer data) {
    sendCommandToSender(SUSPENSION_MODE_LOW);
}

void setDownForceOff(GtkWidget *widget, gpointer data) {
    sendCommandToSender(SPOILER_MODE_OFF);
}

void setDownForceOn(GtkWidget *widget, gpointer data) {
    sendCommandToSender(SPOILER_MODE_AUTO);
}



// Battery functions



// Interior settings

void setFanSpeed1(GtkWidget *widget, gpointer data) {
    sendCommandToSender(FAN_SPEED_1);
}

void setFanSpeed2(GtkWidget *widget, gpointer data) {
    sendCommandToSender(FAN_SPEED_2);
}

void setFanSpeed3(GtkWidget *widget, gpointer data) {
    sendCommandToSender(FAN_SPEED_3);
}

void setFanSpeed4(GtkWidget *widget, gpointer data) {
    sendCommandToSender(FAN_SPEED_4);
}