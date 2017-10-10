/*
  piny od vss (lewy górny)
  1 - ground
  2 - 5v
  3 - pot wiper
  4 - 12 digital
  5 - ground
  6 - 11 digital
  7 - 10 ... empty
  11 - digital 5
  12 - digital 4
  13 - digital 3
  14 - digital 2
  15 - 5v
  16 - ground
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Arduino in");
  lcd.setCursor(0, 1);
  lcd.print("Action Rocks!");
}

void loop() {
}
