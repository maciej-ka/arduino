int ledPin = 13;
int pirPin = 7;

int pirValue;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  digitalWrite(ledPin, HIGH);
  Serial.begin(9600);
  delay(60000);
}

void loop() {
  pirValue = digitalRead(pirPin);
  digitalWrite(ledPin, pirValue);
  Serial.println(pirValue);
}
