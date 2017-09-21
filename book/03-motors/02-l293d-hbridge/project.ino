int enablePin = 11;
int in1A = 4;
int in2A = 7;

void setup() {
  pinMode(enablePin, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  digitalWrite(enablePin, LOW);
}

void loop() {
  // drive counterclockwise
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);
  digitalWrite(enablePin, HIGH);
  delay(5000);

  // brake
  digitalWrite(enablePin, LOW);
  delay(2000);

  // drive clockwise
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, HIGH);
  digitalWrite(enablePin, HIGH);
  delay(5000);

  // brake
  digitalWrite(enablePin, LOW);
  delay(2000);
}
