// Ramah Rinaldi Ruslan - 6702190006
// Muhammad Rifki Ferdiansyah - 6702194022

#include <LiquidCrystal_SR_LCD3.h> 
const int PIN_LCD_STROBE = 2; 
const int PIN_LCD_DATA = 3; 
const int PIN_LCD_CLOCK = 4; 
LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA, 
PIN_LCD_CLOCK,
PIN_LCD_STROBE);

int led=7;
int led1=6;
int led2=5;

int i1=10;
int i2=9;
int i3=8;

void setup()
{
pinMode(led,OUTPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);

pinMode(i1,INPUT);
pinMode(i2,INPUT);
pinMode(i3,INPUT);

lcd.begin(16,2);
lcd.print("Selamat Datang DiLCD NO 10");
}
void loop()
{
digitalWrite(led,HIGH);
digitalWrite(led1,HIGH);
digitalWrite(led2,HIGH);

if(digitalRead(i1)==LOW){
 for (int positionCounter = 0; positionCounter < 15; positionCounter++){
   lcd.scrollDisplayLeft();
   delay(150); 
  }
 }

 else if(digitalRead(i2)==LOW){
  for (int positionCounter = 0; positionCounter < 15; positionCounter++){
   lcd.scrollDisplayRight();
   delay(150); 
  }
 }
  else{
  }
}
