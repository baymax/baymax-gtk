#ifndef FAN_H
#define FAN_H

#include <gtk/gtk.h>

struct Fan {
    GtkButton *button = NULL;
    GtkImage **images = NULL;
    int currentImage = 0;
    int imageCount = 0;
};

void setFanImages(const char **paths, Fan *f, int count);
void changeState(Fan *f);

#endif // FAN_H