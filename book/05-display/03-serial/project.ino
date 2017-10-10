/*
  pins lcd, od dołu
  1 - i2c scl (ostatni obok usb)
  2 - i2c sda (przedostatni obok usb)
  3 - 5v
  4 - ground

  pins lm35 od lewej, patrząc na stronę płaską
  1 - 5v
  2 - a0
  3 - ground
*/

/* Displays text sent over the serial port (e.g. from the Serial Monitor) on
 * an attached LCD.
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

float temp;
int LM35 = 0;

LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup()
{
  lcd.begin();
  lcd.backlight();
  lcd.print("Temp:");
}

void loop()
{
  temp = analogRead(LM35) * 0.48828125;
  lcd.setCursor(0, 1);
  lcd.print(temp);
  lcd.print("C");
  delay(1000);
}

