#include "init.h"


void initWindow(int argc, char *argv[]) {
  gtk_init (&argc, &argv);
  loadMainUi("/usr/share/baymax/ui/main.ui");
  loadCarSettingsUi("/usr/share/baymax/ui/carsettings.ui");
  loadInteriorBuilder("/usr/share/baymax/ui/comfort.ui");
  loadBatteryManagerBuilder("/usr/share/baymax/ui/batterymanager.ui");

  gtk_main ();
}

void initPipeLine() {

}