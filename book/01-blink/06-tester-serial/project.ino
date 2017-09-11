volatile int state = 0;
int leds[] = {8, 9, 10, 11, 12};
int count = 0;
int timer = 75;
int stopLed = 6;
int goLed = 7;
int randMin = 250;
int randMax = 750;
int startDelay;
volatile float time;
float start_time;

void setup() {
  for (count = 0; count < 5; count++) {
    pinMode(leds[count], OUTPUT);
  }
  attachInterrupt(0, ledOnOff, RISING);
  pinMode(stopLed, OUTPUT);
  pinMode(goLed, OUTPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void loop() {
  // start state
  if (state == 0) {
    digitalWrite(stopLed, HIGH);
    digitalWrite(goLed, LOW);
    for (count = 0; count < 5; count++) {
      digitalWrite(leds[count], LOW);
    }
  }

  // start button pressed
  if (state == 1) {
    // random start
    startDelay = random(randMin, randMax);
    delay(startDelay);
    state = 2;
    start_time = millis();
    digitalWrite(stopLed, LOW);
    digitalWrite(goLed, HIGH);
    delay(timer);
    for (count = 0; count < 5; count++) {
      if (state == 3) {
        time = (time - start_time) / 1000;
        Serial.print("Reaction time: ");
        Serial.print(time);
        Serial.println(" seconds");
        delay(1000);
        break;
      }
      delay(timer);
      digitalWrite(leds[count], HIGH);
    }
    state = 3;
  }
}

void ledOnOff() {
  if (state == 1) return;

  // ignore debounce problems
  static unsigned long lastMillis = 0;
  unsigned long newMillis = millis();
  if (newMillis - lastMillis < 300) return;
  lastMillis = newMillis;

  state = (state + 1) % 4;
  if (state == 3) time = millis();
}
