#include "functions.h"
#include "uifunctionality.h"
#include "pipeline.h"

void sportMode(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        sportModeState = 1;
        setSportMode((void*)NULL);
        sendToSender(SPORT_MODE, 1);
    }
}

void normalMode(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        sportModeState = 0;
        setSportMode(NULL);
        sendToSender(SPORT_MODE, 0);
    }
}

void setSuspensionHigh(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        suspensionState = 2;
        setSuspensionMode(NULL);
        sendToSender(SUSPENSION_MODE, 2);
    }
}

void setSuspensionNormal(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        suspensionState = 1;
        setSuspensionMode(NULL);
        sendToSender(SUSPENSION_MODE, 1);
    }
}

void setSuspensionLow(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        suspensionState = 0;
        setSuspensionMode(NULL);
        sendToSender(SUSPENSION_MODE, 0);
    }
}

void setDownForceOff(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        spoilerMode = 0;
        setSpoilerMode(NULL);
        sendToSender(SPOILER_MODE, 0);
    }
}

void setDownForceOn(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        spoilerMode = 1;
        setSpoilerMode(NULL);
        sendToSender(SPOILER_MODE, 1);
    }
}

void setRegenerationOn(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        regenereationMode = 1;
        setRegeneration(NULL);
        sendToSender(REGENERATION, 1);
    }
}

void setRegenerationOff(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        regenereationMode = 0;
        setRegeneration(NULL);
        sendToSender(REGENERATION, 0);
    }
}



// Battery functions



// Interior settings

void setFanSpeed1(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        fanSpeed = 1;
        setFanSpeed(NULL);
        sendToSender(FAN_SPEED, 1);
    }
}

void setFanSpeed2(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        fanSpeed = 2;
        setFanSpeed(NULL);
        sendToSender(FAN_SPEED, 2);
    }
}

void setFanSpeed3(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        fanSpeed = 3;
        setFanSpeed(NULL);
        sendToSender(FAN_SPEED, 3);
    }
}

void setFanSpeed4(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        fanSpeed = 4;
        setFanSpeed(NULL);
        sendToSender(FAN_SPEED, 4);
    }
}