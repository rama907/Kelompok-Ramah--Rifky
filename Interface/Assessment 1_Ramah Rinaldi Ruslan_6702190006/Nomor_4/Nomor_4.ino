//Ramah Rinaldi Ruslan - 6702190006
#include <Keypad.h>
#include <LiquidCrystal_SR_LCD3.h>
const int PIN_LCD_STROBE = 2;
const int PIN_LCD_DATA = 3;
const int PIN_LCD_CLOCK = 1;
int l1=10;
int l2=9;
int l3=8;
int l4=7;
int l5=6;
int l6=5;

char keys[4][3] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte pin_rows[] = {A1, A2, A3, A4};
byte pin_column[] = {13, 12, 11}; 

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, 4, 3 );

LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA, PIN_LCD_CLOCK,
PIN_LCD_STROBE);
void setup() {
   lcd.begin(16,2);
   pinMode(l1,OUTPUT);
   pinMode(l2,OUTPUT);
   pinMode(l3,OUTPUT);
   pinMode(l4,OUTPUT);
   pinMode(l5,OUTPUT);
   pinMode(l6,OUTPUT);
}

void loop() {
  char key = keypad.getKey();
  
 if (key){

  if (key =='1'){
    digitalWrite(l1,HIGH);
    digitalWrite(l2,HIGH);
    digitalWrite(l3,LOW);
    digitalWrite(l4,LOW);
    digitalWrite(l5,LOW);
    digitalWrite(l6,LOW);
  }
  else if (key == '2'){
    digitalWrite(l1,LOW);
    digitalWrite(l2,LOW);
    digitalWrite(l5,LOW);
    digitalWrite(l6,LOW);
    digitalWrite(l3,HIGH);
    digitalWrite(l4,HIGH);
  }
  else if (key == '3'){
    digitalWrite(l5,HIGH);
    digitalWrite(l6,HIGH);
    digitalWrite(l1,LOW);
    digitalWrite(l2,LOW);
    digitalWrite(l3,LOW);
    digitalWrite(l4,LOW);
  }
   else if (key == '#') {
      lcd.setCursor (0,0);
      lcd.print("Running LED");
     digitalWrite(l1,HIGH);
     delay(500);
     digitalWrite(l1,LOW);
     delay(500);
     digitalWrite(l2,HIGH);
     delay(500);
     digitalWrite(l2,LOW);
     delay(500);
     digitalWrite(l3,HIGH);
     delay(500);
     digitalWrite(l3,LOW);
     delay(500);
     digitalWrite(l4,HIGH);
     delay(500);
     digitalWrite(l4,LOW);
     delay(500);
     digitalWrite(l5,HIGH);
     delay(500);
     digitalWrite(l5,LOW);
     delay(500);
     digitalWrite(l6,HIGH);
     delay(500);
     digitalWrite(l6,LOW);
     delay(500);
     lcd.clear();
    }
    else if (key == '*') {
       lcd.setCursor (0,0);
      lcd.print("Blink LED");
     digitalWrite(l1,HIGH);
     digitalWrite(l2,HIGH);
     delay(500);
     digitalWrite(l1,LOW);
     digitalWrite(l2,LOW);
     delay(500);
     digitalWrite(l3,HIGH);
     digitalWrite(l4,HIGH);
     delay(500);
     digitalWrite(l4,LOW);
     digitalWrite(l3,LOW);
     delay(500);
     digitalWrite(l5,HIGH);
     digitalWrite(l6,HIGH);
     delay(500);
     digitalWrite(l6,LOW);
      digitalWrite(l5,LOW);
      lcd.clear();
    }
 }
}
