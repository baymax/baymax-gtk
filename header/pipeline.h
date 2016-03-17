#ifndef PIPELINE_H
#define PIPELINE_H

#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <gtk/gtk.h>


void sendSender(unsigned char cmd, unsigned char data);
gpointer readUi(gpointer user_data);


#endif // PIPELINE_H