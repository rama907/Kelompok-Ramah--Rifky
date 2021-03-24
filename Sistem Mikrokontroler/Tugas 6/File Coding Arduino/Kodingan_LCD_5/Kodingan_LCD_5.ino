// Ramah Rinaldi Ruslan - 6702190006
// Muhammad Rifki Ferdiansyah - 6702194022

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int tombol=10;
int tombol1=9;
void setup(){
pinMode(tombol,INPUT);
pinMode(tombol1,INPUT);
lcd.begin(16, 2);
lcd.print("Running Text!!!");
}
void loop(){
if(digitalRead(tombol)==LOW){
for (int positionCounter = 0; positionCounter < 15; positionCounter++){
lcd.scrollDisplayLeft();
delay(150);
}
}
else if(digitalRead(tombol1)==LOW){
for (int positionCounter = 0; positionCounter < 15; positionCounter++){
lcd.scrollDisplayRight();
delay(150);
}
}
else{
}
}
