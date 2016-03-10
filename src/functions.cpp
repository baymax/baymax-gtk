#include "functions.h"

void sportMode(GtkWidget *widget, gpointer data) {
    sendSender(SPORT_MODE, 1);
}

void normalMode(GtkWidget *widget, gpointer data) {
    sendSender(SPORT_MODE, 0);
}

void setSuspensionHigh(GtkWidget *widget, gpointer data) {
    sendSender(SUSPENSION_MODE, 2);
}

void setSuspensionNormal(GtkWidget *widget, gpointer data) {
    sendSender(SUSPENSION_MODE, 1);
}

void setSuspensionLow(GtkWidget *widget, gpointer data) {
    sendSender(SUSPENSION_MODE, 0);
}

void setDownForceOff(GtkWidget *widget, gpointer data) {
    sendSender(SPOILER_MODE, 0);
}

void setDownForceOn(GtkWidget *widget, gpointer data) {
    sendSender(SPOILER_MODE, 1);
}

void setRegenerationOn(GtkWidget *widget, gpointer data) {
    sendSender(REGENERATION, 1);
}

void setRegenerationOff(GtkWidget *widget, gpointer data) {
    sendSender(REGENERATION, 0);
}



// Battery functions



// Interior settings

void setFanSpeed1(GtkWidget *widget, gpointer data) {
    sendSender(FAN_SPEED, 1);
}

void setFanSpeed2(GtkWidget *widget, gpointer data) {
    sendSender(FAN_SPEED, 2);
}

void setFanSpeed3(GtkWidget *widget, gpointer data) {
    sendSender(FAN_SPEED, 3);
}

void setFanSpeed4(GtkWidget *widget, gpointer data) {
    sendSender(FAN_SPEED, 4);
}