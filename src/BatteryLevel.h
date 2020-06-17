
#ifndef BatteryLevel_h
#define BatteryLevel_h

#include "Arduino.h"
#include "heltec.h" // alias for `#include "SSD1306Wire.h"`

class BatteryLevel
{
  public:
    BatteryLevel(int x,int y);

    //draws a specific signal strength indicator
    void drawSignalBar(int barNumber);

    //shows the battery level indicator
    void showBatteryLevel();
   
    //shows the battery volate text
    void showBatteryVoltage();

    //return the battery full percentage
    int getBatteryPercentage();

    //return the battery voltage
    float getBatteryVoltage();


  protected:
    void showBatteryVoltage(float volts);
    void showBatteryLevel(int percentage);
    
    //location for the battery indicator
    unsigned int batteryLocationX;
    unsigned int batteryLocationY;

    //location for the battery voltage text
    unsigned int batteryTextLocationX;
    unsigned int batteryTextLocationY;


};

#endif


