#include <LiquidCrystal_SR_LCD3.h>
const int PIN_LCD_STROBE = 2;
const int PIN_LCD_DATA = 3;
const int PIN_LCD_CLOCK = 4;

int sw_kiri=7;
int sw_tengah=6;
int sw_kanan=5;
int led1=10;
int led2=9;
int led3=8;
int i;

LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA, PIN_LCD_CLOCK,
PIN_LCD_STROBE);

void setup(){
pinMode(sw_kiri,INPUT);
pinMode(sw_tengah,INPUT);
pinMode(sw_kanan,INPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
lcd.begin(16,2);
lcd.setCursor (0, 0);
lcd.print("SELAMAT DATANG");
delay(3000);
lcd.clear();
}

void loop()
{ 
  if(digitalRead(sw_kiri)==LOW){
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print("1. Blink LED");
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  delay(50);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
} 
else if (digitalRead(sw_tengah)==LOW){
  lcd.clear();
  lcd.setCursor (0, 1);
  lcd.print("2. Running LED");
digitalWrite(led1, HIGH);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
delay(1000);
digitalWrite(led1, LOW);
digitalWrite(led2, HIGH);
digitalWrite(led3, LOW);
delay(1000);
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, HIGH);
delay(1000);
} 
else if (digitalRead(sw_kanan)==LOW){
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print("3. Fading LED");
for (i=0; i<=255; i+=5){ analogWrite(led1,i); delay(100);
}
for (i=0; i<=255; i+=5){ analogWrite(led2,i); delay(100);
}
for (i=0; i<=255; i+=5){ analogWrite(led3,i); delay(100);
}
for (i=255; i>=0; i-=5){ analogWrite(led1,i); delay(100);
}
for (i=255; i>=0; i-=5){ analogWrite(led2,i); delay(100);
}
for (i=255; i>=0; i-=5){ analogWrite(led3,i); delay(100);
}
}
else{
   lcd.setCursor (0, 0);
  lcd.print("1. Blink LED");
  lcd.setCursor (0, 1);
  lcd.print("2. Running LED");
  delay(1000);
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print("3. Fading LED");
  delay(1000);
  
digitalWrite(led1,LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
}

}
