#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4,
3, 2);
int i1=8;
int i2=9;
int i3=10;
void setup()
{
lcd.begin(16, 2);
pinMode(i1,INPUT);
pinMode(i2,INPUT);
pinMode(i3,INPUT);
}
void loop()
{
 if (digitalRead(i1)==LOW){
{lcd.print("tombol 1 ditekan");
lcd.setCursor(0, 1);
}
}
delay(1000);
 if (digitalRead(i2)==LOW){
{lcd.print("tombol 2 ditekan"); lcd.setCursor(0,2);
}
}
 if (digitalRead(i3)==LOW) {
  {lcd.clear(); lcd.setCursor(0,3);
}
}
}
