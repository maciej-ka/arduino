#include <Servo.h>

Servo myservo;
int pos = 90;

void setup() {
  myservo.attach(9);

  // set range
  myservo.write(180);
  delay(2000);
  myservo.write(90);
  delay(8000);
}

void loop() {
  for(pos = 90; pos < 180; pos += 1) {
    myservo.write(pos);
    delay(15);
  }
  for(pos = 180; pos >= 90; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
}
