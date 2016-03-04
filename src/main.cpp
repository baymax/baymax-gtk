#include "main.h"
#include <stdio.h>

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}



int
main (int   argc,
      char *argv[])
{
    initPipeLine();
    //printf("ulilli");
    initWindow(argc, argv);
    
    
   
  return 0;
}
