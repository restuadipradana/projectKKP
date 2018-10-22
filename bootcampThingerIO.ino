#include <Wire.h>
#include "RTClib.h"

#include <WiFiClientSecure.h>
#include <ThingerESP32.h>

#define USERNAME "rstx"
#define DEVICE_ID "rst"
#define DEVICE_CREDENTIAL "rstx28"

#define SSID "DILO3"
#define SSID_PASSWORD "DiloBSD123"

ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int xxx;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  
  DateTime now = rtc.now();
  xxx = (now.second());

  thing.add_wifi(SSID, SSID_PASSWORD);

  thing["lampu"] << digitalPin(13);

  thing["pot"] >> outputValue(analogRead(32));

  thing["det"] >> outputValue(xxx);


  
}

void loop() {
  thing.handle();
}
