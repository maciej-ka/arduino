int sensorValue = 0;
int threshold = 50;
int toneDuration = 10;
int speakerPin = 8;
int tones[] = {262, 294, 330, 392, 440};

void setup() {
}

void loop() {
  for (int sensorPin = 0; sensorPin < 5; sensorPin++) {
    sensorValue = analogRead(sensorPin);
    if (sensorValue > threshold) {
      tone(speakerPin, tones[sensorPin], toneDuration);
    }
  }
}
