//Ramah Rinaldi Ruslan - 6702190006
#include <LiquidCrystal_SR_LCD3.h> 
const int PIN_LCD_STROBE = 2; 
const int PIN_LCD_DATA = 3; 
const int PIN_LCD_CLOCK = 4;
LiquidCrystal_SR_LCD3 lcd (PIN_LCD_DATA,PIN_LCD_CLOCK, PIN_LCD_STROBE);
int i1=7;
int i2=6;
int i3=5; 

void setup(){
lcd.begin(16,2);
pinMode(i1,INPUT);
pinMode(i2,INPUT);
pinMode(i3,INPUT); 
}

void loop(){
if (digitalRead(i1)==LOW){{
lcd.setCursor(0, 0);
lcd.print("Ramah Rinaldi Ruslan");
    }
 }
 
delay(1000);
if (digitalRead(i2)==LOW){{
lcd.setCursor(0, 1);
lcd.print("6702190006");
    }
  }
}
