#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int tombol=10;

void setup(){
pinMode(tombol,INPUT);
lcd.begin(16, 2);
Serial.begin(9600);
lcd.setCursor(0,0);
lcd.print("Hello, GUYSSS!");
delay(1000);
lcd.clear();
}
void loop(){
 if (Serial.available()) {
  
   while(Serial.available()>0){
   char ch=Serial.read();
 
   Serial.write(ch);
   lcd.write(ch);
  }
 }
 if(digitalRead(tombol)==LOW){
  for (int positionCounter = 0; positionCounter < 15; positionCounter++){
   lcd.scrollDisplayLeft();
   delay(150); 
  }
 }
}
