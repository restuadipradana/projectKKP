
#define pot  33


void setup()
{
  Serial.begin(9600);
  pinMode(pot, INPUT);
}

void loop()
{

  int value = analogRead(pot);
  Serial.println(value);
  delay(300);
  
}
