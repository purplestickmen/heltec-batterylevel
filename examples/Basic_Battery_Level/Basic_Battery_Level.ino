/*
  Battery Level usage

  Traditional indicator that shows a battery level indicator at a specified
  location.  Optionally displays the current voltage rating.

    Note: You must specify ADC_MODE(ADC_VCC)
    This additionally means that the A0 pin must be clear of connections.  
 
*/

#include <BatteryLevel.h>


ADC_MODE(ADC_VCC);

BatteryLevel batteryLevel(0,0);

void setup() {
  
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Serial Enable*/);
  Heltec.display->init();
  Heltec.display->flipScreenVertically();


}

void loop() {

    batteryLevel.showBatteryLevel();
    batteryLevel.showBatteryVoltage();
    
    Heltec.display->display();
    
    delay(2000);
}
