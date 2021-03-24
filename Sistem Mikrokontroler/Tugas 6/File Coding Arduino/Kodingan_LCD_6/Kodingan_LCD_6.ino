// Ramah Rinaldi Ruslan - 6702190006
// Muhammad Rifki Ferdiansyah - 6702194022

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup(){ 
  lcd.begin(16, 2); 
  Serial.begin(9600);
}
void loop() {
if (Serial.available()) { 
  delay(100);
  lcd.clear();
  while (Serial.available() > 0) { 
  lcd.write(Serial.read());
    }
  }
}
