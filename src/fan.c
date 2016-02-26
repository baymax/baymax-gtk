#include "fan.h"

void setFanImages(const char *path, ... , Fan *f, int count) {
    f->images = new GtkImage*;
    f->imageCount = count;
    va_list args;
    char *p;
    int i = 0;
    va_start (args, p)
     f->images[i] = gtk_image_new_from_file (p);
     i++;
    va_end(args);    
}

void changeState(Fan *f) {
    if (NULL != f->button && NULL != f->images && f->imageCount > 0) {
        gtk_button_set_image(f->button, f->images[f->currentImage])
        f->currentImage++;
        if (f->currentImage >= f->imageCount) f->currentImage = 0;
    }
}