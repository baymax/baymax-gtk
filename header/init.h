#ifndef INIT_H
#define INIT_H

#include <gtk/gtk.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#include "uifunctionality.h"
#include "uifunctionalityprivate.h"
#include "pipeline.h"

void initWindow(int argc, char *argv[]);
void initPipeLine();

void closePipeLine();


#endif // INIT_H