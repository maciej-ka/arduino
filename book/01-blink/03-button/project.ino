volatile int state = LOW;
int leds[] = {8, 9, 10, 11, 12};
int count = 0;
int timer = 75;
int pause = 500;

void setup() {
  for (count = 0; count < 5; count++) {
    pinMode(leds[count], OUTPUT);
  }
  pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(0, ledOnOff, RISING);
}

void loop() {
  if (state) {
    for (count = 0; count < 5; count++) {
      digitalWrite(leds[count], HIGH);
      delay(timer);
    }
    delay(pause);

    for (count = 0; count < 5; count++) {
      digitalWrite(leds[count], LOW);
      delay(timer);
    }
    delay(pause);
  }
}

void ledOnOff() {
  // ignore debounce problems
  static unsigned long lastMillis = 0;
  unsigned long newMillis = millis();
  if (newMillis - lastMillis < 300) return;
  lastMillis = newMillis;

  state = !state;

  if (state) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
