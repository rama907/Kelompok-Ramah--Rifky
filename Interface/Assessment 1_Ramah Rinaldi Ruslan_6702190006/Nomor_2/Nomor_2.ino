//Ramah Rinaldi Ruslan - 6702190006
#include <LiquidCrystal_SR_LCD3.h>
const int PIN_LCD_STROBE  = 2; 
const int PIN_LCD_DATA    = 3; 
const int PIN_LCD_CLOCK   = 4; 
int tombol1 = 7;
int tombol2 = 6;
int led1 = 10;
int led2 = 9;
int led3 = 8;
LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA,
PIN_LCD_CLOCK, PIN_LCD_STROBE);

void setup(){
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  lcd.begin(16,2);
  lcd.home();
  lcd.setCursor(0,0);
  lcd.print("Fadel Januar A");
  pinMode(tombol1,INPUT);
  pinMode(tombol2,INPUT);
}
void loop(){
  lcd.setCursor(0,1);
  if(digitalRead(tombol1)==LOW){
    lcd.print("6702190035");
  } else if(digitalRead(tombol2)==LOW){
    lcd.print("tombol 2 ditekan");
    for (int i=0; i<=4; i++){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    delay(500);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    delay(500);
    }
  }
}
