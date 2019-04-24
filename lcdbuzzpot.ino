#include <WiFi.h>

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <NTPClient.h>
#include <WiFiUdp.h>
const char* ssid     = "RAHARJA";
const char* password = "";

#define NTP_OFFSET  25200 // In seconds 
#define NTP_INTERVAL 60 * 1000    // In miliseconds
#define NTP_ADDRESS  "1.asia.pool.ntp.org"

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_ADDRESS, NTP_OFFSET, NTP_INTERVAL);

#define OLED_MOSI  23
#define OLED_CLK   18
#define OLED_DC    4
#define OLED_CS    5
#define OLED_RESET 2
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#define buz  32
#define but  35

void setup()
{
display.begin();
Serial.begin(9600);

Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected.");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());

timeClient.begin();

display.begin(SSD1306_SWITCHCAPVCC);

display.clearDisplay();
display.setTextColor(WHITE);
//display.startscrollright(0x00, 0x0F);
display.setTextSize(2);
//display.setCursor(0,0);
//display.print("  Internet ");
//display.println("  Clock ");
//display.display();
//delay(3000);

pinMode(but, INPUT);
pinMode(buz, OUTPUT);
}

void loop()
{

timeClient.update();
String formattedTime = timeClient.getFormattedTime();

// Serial.println(formattedTime);
int tbl = digitalRead(but);
 if (tbl == HIGH)
 {
  digitalWrite(buz, HIGH);
 }
 else
 {
  digitalWrite(buz, LOW);
 }

display.clearDisplay();
display.setTextSize(2);
display.setCursor(0, 0);
display.println(formattedTime);

display.display();   // write the buffer to the display
delay(10);
delay(100);

}
