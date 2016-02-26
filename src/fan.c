#include "fan.h"

void setFanImages(const char **paths, Fan *f, int count) {
    f->images = new *GtkImage[count];
    f->imageCount = count;
    for (int i = 0; i < count; i++) {
        f->images[i] = gtk_image_new_from_file (paths[i]);
    }
}

void changeState(Fan *f) {
    if (NULL != f->button && NULL != f->images && f->imageCount > 0) {
        gtk_button_set_image(f->button, (GtkWidget*)f->images[f->currentImage])
        f->currentImage++;
        if (f->currentImage >= f->imageCount) f->currentImage = 0;
    }
}