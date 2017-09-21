int transistorBasePin = 13;

void setup()
{
  pinMode(transistorBasePin, OUTPUT);
}

void loop()
{
  digitalWrite(transistorBasePin, LOW);
  delay(5000);
  digitalWrite(transistorBasePin, HIGH);
  delay(5000);
}
