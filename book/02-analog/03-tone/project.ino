int sensorPin = 0;
int sensorValue = 0;
int threshold = 200;
int toneDuration = 40;
int toneFrequency = 262;
int speakerPin = 8;

void setup() {
}

void loop() {
  sensorValue = analogRead(sensorPin);
  if (sensorValue > threshold) {
    tone(speakerPin, toneFrequency, toneDuration);
    // if there is no duration
    // sound will be until noTone(pin) call
  }
}
