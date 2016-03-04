#include "init.h"


void initWindow(int argc, char *argv[]) {
  gtk_init (&argc, &argv);
    
  loadMainUi("/home/jaska/Dropbox/baymax-gtk/ui/main.ui");
  loadCarSettingsUi("/home/jaska/Dropbox/baymax-gtk/ui/carsettings.ui");
  loadInteriorBuilder("/home/jaska/Dropbox/baymax-gtk/ui/comfort.ui");
  loadBatteryManagerBuilder("/home/jaska/Dropbox/baymax-gtk/ui/batterymanager.ui");

  gtk_main ();
}

void initPipeLine() {

}