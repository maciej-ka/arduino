const int inputPin = 9;
const int outputPin = 8;

void setup() {
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);
}

unsigned long ping() {
  digitalWrite(outputPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(outputPin, LOW);
  return pulseIn(inputPin, HIGH);
}

void loop() {
  Serial.println(ping() / 74 / 2);
  delay(50);
}
