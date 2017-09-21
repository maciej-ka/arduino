int enablePin = 11;
int in1 = 4;
int in2 = 7;

void setup() {
  pinMode(enablePin, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  digitalWrite(enablePin, LOW);
}

void loop() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(enablePin, HIGH);
  for(int i = 0; i <= 255; i++) {
    analogWrite(enablePin, i);
    delay(50);
  }

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  for(int i = 0; i <= 255; i++) {
    analogWrite(enablePin, i);
    delay(50);
  }
}
