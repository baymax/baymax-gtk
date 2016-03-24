#include "functions.h"
#include "uifunctionality.h"
#include "pipeline.h"

void sportMode(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        char v = 1;
        setSportMode(&v);
        //sendToSender(SPORT_MODE, 1);
    }
}

void normalMode(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        char v = 0;
        setSportMode(&v);
        //sendToSender(SPORT_MODE, 0);
    }
}

void setSuspensionHigh(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        char v = 2;
        setSuspensionMode(&v);
        //sendToSender(SUSPENSION_MODE, 2);
    }
}

void setSuspensionNormal(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        char v = 1;
        setSuspensionMode(&v);
        //sendToSender(SUSPENSION_MODE, 1);
    }
}

void setSuspensionLow(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        char v = 0;
        setSuspensionMode(&v);
        //sendToSender(SUSPENSION_MODE, 0);
    }
}

void setDownForceOff(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        char v = 0;
        setSpoilerMode(&v);
        //sendToSender(SPOILER_MODE, 0);
    }
}

void setDownForceOn(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        char v = 1;
        setSpoilerMode(&v);
        //sendToSender(SPOILER_MODE, 1);
    }
}

void setRegenerationOn(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        char v = 1;
        setRegeneration(&v);
        //sendToSender(REGENERATION, 1);
    }
}

void setRegenerationOff(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        char v = 0;
        setRegeneration(&v);
        //sendToSender(REGENERATION, 0);
    }
}



// Battery functions



// Interior settings

void setFanSpeed1(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        char v = 1;
        setFanSpeed(&v);
        //sendToSender(FAN_SPEED, 1);
    }
}

void setFanSpeed2(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        char v = 2;
        setFanSpeed(&v);
        //sendToSender(FAN_SPEED, 2);
    }
}

void setFanSpeed3(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        char v = 3;
        setFanSpeed(&v);
        //sendToSender(FAN_SPEED, 3);
    }
}

void setFanSpeed4(GtkWidget *widget, gpointer data) {
    gboolean state;
    g_object_get(G_OBJECT(widget), "active", &state);
    if (state) {
        char v = 4;
        setFanSpeed(&v);
        //sendToSender(FAN_SPEED, 4);
    }
}