//Ramah Rinaldi Ruslan - 6702190006
#include <LiquidCrystal_SR_LCD3.h> // library baru
const int PIN_LCD_STROBE  = 2;  //lcd shift-register strobe
const int PIN_LCD_DATA    = 3; //lcd shift-register data
const int PIN_LCD_CLOCK   = 4; //lcd shift-register clock
int tombol1 = 7;
int tombol2 = 6;
LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA,
PIN_LCD_CLOCK, PIN_LCD_STROBE); //definisi pin

void setup(){
  lcd.begin(16,2);
  lcd.home();
  lcd.setCursor(0,0);
  lcd.print("6702190006");
  pinMode(tombol1,INPUT);
  pinMode(tombol2,INPUT);

}

void loop(){
  lcd.setCursor(0,1);
    for (int positionCounter = 0;
       positionCounter < 4;
       positionCounter++){
        lcd.scrollDisplayRight();
        delay(150);
}
}
