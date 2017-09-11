int sensorPin = A0;
int sensorValue = 0;
int threshold = 200;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  if (sensorValue > threshold) {
    Serial.print("Sensor = ");
    Serial.println(sensorValue, DEC);
  }
  delay(10);
}
