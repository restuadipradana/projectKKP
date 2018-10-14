#define trigPin 33
#define echoPin 32

#define trig2Pin 26
#define echo2Pin 27

long duration, distance, duration2, distance2;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trig2Pin, OUTPUT);
  pinMode(echo2Pin, INPUT);



}

void loop() {
  
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  digitalWrite(trig2Pin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trig2Pin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig2Pin, LOW);
  duration2 = pulseIn(echo2Pin, HIGH);
  distance2 = (duration2/2) / 29.1;

  
  long count;
  if (distance < 10)
  { 
     count = 1;
  }
  else if (distance > 10)
  {
     count = 0;
  }

long count2;
  if (distance2 < 10)
  { 
     count2 = 1;
  }
  else if (distance2 > 10)
  {
     count2 = 0;
  }
  
long counTot = count + count2; 
long tot = 100 - counTot;
Serial.print("Sisa Parkir "); Serial.println(tot); 
Serial.print("  jarak    = ");Serial.println(distance);
Serial.print("  jarak 2  = ");Serial.println(distance2);
Serial.println("     ");
delay(1000);
  
}
