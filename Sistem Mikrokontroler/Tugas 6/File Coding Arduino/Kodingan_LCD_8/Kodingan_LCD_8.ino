// Ramah Rinaldi Ruslan - 6702190006
// Muhammad Rifki Ferdiansyah - 6702194022

#include <LiquidCrystal_SR_LCD3.h> 
const int PIN_LCD_STROBE = 2; 
const int PIN_LCD_DATA = 3; 
const int PIN_LCD_CLOCK = 4; 
LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA, PIN_LCD_CLOCK,PIN_LCD_STROBE);
void setup()
{
lcd.begin(16,2);
lcd.home ();
lcd.setCursor (0, 0);
lcd.print("Selamat Datang");
}
void loop()
{
lcd.setCursor(0,1); 
lcd.print(millis()/1000);
}
