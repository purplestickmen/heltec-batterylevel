#include "Arduino.h"
#include "BatteryLevel.h"
#include "heltec.h" // alias for `#include "SSD1306Wire.h"`
#include <ESP8266WiFi.h>

#ifdef DEBUG_ESP_PORT
#define DEBUG_MSG(...) DEBUG_ESP_PORT.printf( __VA_ARGS__ )
#else
#define DEBUG_MSG(...)
#endif

BatteryLevel::BatteryLevel(int x,int y) {
    this->batteryLocationX = x;
    this->batteryLocationY = y;
}

float BatteryLevel::getBatteryVoltage() { 
  float getVcc = (float)ESP.getVcc();
  float measuredBattery = getVcc / 1024;
  
  return measuredBattery; 
}

int BatteryLevel::getBatteryPercentage() { 
  float getVcc = (float)ESP.getVcc();

  int percent = map(getVcc, 2300, 3000, 0, 100); // map the Vcc to a percentage.  NB. Map doesn't work with floats
  return constrain(percent,0,100); //constrain the values so that it is between 0 and 100%
}

//convenience method
void BatteryLevel::showBatteryLevel() {
  showBatteryLevel(getBatteryPercentage());
}

//convenience method
void BatteryLevel::showBatteryVoltage() {
  showBatteryVoltage(getBatteryVoltage());
}

void BatteryLevel::showBatteryLevel(int percentage) {
  int increment = map(percentage,0,100,1,12);
  increment = constrain(increment,1,12);  //the increment should be between 1 & 12

  //clear the previous battery level
  Heltec.display->setColor(BLACK);
  Heltec.display->fillRect(batteryLocationX,batteryLocationY,16,8);

  Heltec.display->setColor(WHITE);
  Heltec.display->drawRect(batteryLocationX,batteryLocationY,16,8);
  Heltec.display->fillRect(batteryLocationX+2,batteryLocationY+2,increment,4);
  Heltec.display->fillRect(batteryLocationX+16,batteryLocationY+2,2,4);
  
}

void BatteryLevel::showBatteryVoltage(float volts) {
  //assume that the volate is displayed 30 pixels to the right of the battery icon
  String voltage = "";
  voltage = (String)volts + "v";

  //clear previous display
  Heltec.display->setColor(BLACK);
  Heltec.display->fillRect(batteryLocationX+30,batteryLocationY,20,10);

  Heltec.display->setColor(WHITE);
  Heltec.display->setFont(ArialMT_Plain_10);
  Heltec.display->drawString(batteryLocationX+30,batteryLocationY,voltage);
}





