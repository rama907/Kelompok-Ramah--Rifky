// Ramah Rinaldi Ruslan - 6702190006
// Muhammad Rifki Ferdiansyah - 6702194022

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int i1=9;
int i2=8;
void setup()
{
lcd.begin(16, 2);
pinMode(i1,INPUT);
pinMode(i2,INPUT);
}
void loop()
{
if (digitalRead(i1)==LOW){
 {
  lcd.print("Button 1 Active");
  lcd.setCursor(0, 1);
 }
}
delay(1000);
if (digitalRead(i2)==LOW){
  {
  lcd.print("Button 2 Active"); 
  lcd.setCursor(0,2);
  }
 }
}
