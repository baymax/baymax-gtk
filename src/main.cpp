#include "main.h"
#include <stdio.h>
#include "pipeline.h"
#include <gtk/gtk.h>

pthread_t readerThreadId;

int
main (int   argc,
      char *argv[])
{
    GError    *error = NULL;
    //openSenderPipe();
    openGtkPipe();
    //int a = 5;
    //g_thread_new("reader", readUi, &a); 
    pthread_create(&readerThreadId, NULL, &reader, NULL);
    initWindow(argc, argv);   
    //closeSenderPipe();
    //closeGtkPipe();
   
  return 0;
}
