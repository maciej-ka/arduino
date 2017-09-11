int leds[] = {8, 9, 10, 11, 12};
int count = 0;
int timer = 1000;

void setup() {
  for (count = 0; count < 5; count++) {
    pinMode(leds[count], OUTPUT);
  }
}

void loop() {
  for (count = 0; count < 5; count++) {
    digitalWrite(leds[count], HIGH);
    delay(timer);
    digitalWrite(leds[count], LOW);
    delay(timer);
  }
}
