#include "main.h"
#include <stdio.h>
#include "pipeline.h"
#include <gtk/gtk.h>


int
main (int   argc,
      char *argv[])
{
    GError    *error = NULL;
    initPipeLine();
    int a = 5;
    g_thread_new("reader", readUi, &a); 
    initWindow(argc, argv);
    
    
   
  return 0;
}
