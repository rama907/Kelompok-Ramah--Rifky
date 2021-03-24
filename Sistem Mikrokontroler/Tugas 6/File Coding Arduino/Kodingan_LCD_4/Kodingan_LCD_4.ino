// Ramah Rinaldi Ruslan - 6702190006
// Muhammad Rifki Ferdiansyah - 6702194022

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
lcd.begin(16, 2);
lcd.print("Selamat Datang");
}
void loop()
{
for (int positionCounter = 0;
positionCounter < 13;
positionCounter++)
{
lcd.scrollDisplayLeft();
delay(150);
}
for (int positionCounter = 0;
positionCounter < 29;
positionCounter++)
{
lcd.scrollDisplayRight();
delay(150);
}
for (int positionCounter = 0;
positionCounter < 16;
positionCounter++)
{
lcd.scrollDisplayLeft();
delay(150);
}
delay(1000);
}
