#ifndef PIPELINE_H
#define PIPELINE_H

#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <gtk/gtk.h>

void openSenderPipe();
void closeSenderPipe();
void openGtkPipe();
void closeGtkPipe();
void sendToSender(unsigned char cmd, unsigned char data);
void* reader(void* data);

//

#endif // PIPELINE_H