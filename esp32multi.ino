/*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

This example is for a 128x64 size display using I2C to communicate
3 pins are required to interface (2 I2C and one reset)

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <SimpleTimer.h>
SimpleTimer timer;




#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "bec70c97995e4f0ba03faca2ef6ed8b5";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "wifi";
char pass[] = "87654321";



#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

#include "RTClib.h"

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};

void potensio()
{
  int pot = analogRead(34);
  Blynk.virtualWrite(V1, pot);
}

void setup()   {                
  display.begin(9600);
  if (rtc.lostPower()) {
    display.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2018, 10, 7, 13, 12, 0));
  }

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, potensio);
  // draw a single pixel
  display.drawPixel(10, 10, WHITE);
  // Show the display buffer on the hardware.
  // NOTE: You _must_ call display after making any drawing commands
  // to make them visible on the display hardware!
  display.display();
  delay(1000);
  display.clearDisplay();

}


void loop() {

  Blynk.run();
  timer.run();
  
  DateTime now = rtc.now();


  
    // text display tests
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
    display.print(now.hour(), DEC);
    display.print(':');
    display.print(now.minute(), DEC);
    display.print(':');
    display.println(now.second(), DEC);
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.print(' ');
  display.print(daysOfTheWeek[now.dayOfTheWeek()]);
  display.println(' ');
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.print(now.day(), DEC);
    display.print('-');
    display.print(now.month(), DEC);
    display.print('-');
    display.println(now.year(), DEC);
  int pot = analogRead(34);
  display.print("V=");
  display.print(pot);
  int state = digitalRead(13);
  display.print(" ");
  display.print(state);
  display.display();
  delay(10);
  display.clearDisplay();
}

