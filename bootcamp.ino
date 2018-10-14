

#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <SimpleTimer.h>
SimpleTimer timer;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "bec70c97995e4f0ba03faca2ef6ed8b5";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "wifi";
char pass[] = "87654321";

void potensio()
{
  int pot = analogRead(32);
  Blynk.virtualWrite(V1, pot);
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, potensio);
}

void loop()
{
  Blynk.run();
  timer.run();
}

