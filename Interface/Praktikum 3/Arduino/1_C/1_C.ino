// Ramah Rinaldi Ruslan (6702190006)
// Muhammad Rifki Ferdiansyah (6702194022)

#include <Keypad.h>
#include <LiquidCrystal_SR_LCD3.h>
const int PIN_LCD_STROBE = 2;
const int PIN_LCD_DATA = 3;
const int PIN_LCD_CLOCK = 1;
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
int cursorColumn = 0;
void setup(){
lcd.begin(16,2);
lcd.setCursor (0, 0);
lcd.print("SELAMAT DATANG");
delay(3000);
lcd.clear();
}
void loop(){
char key = keypad.getKey();
if (key) {
lcd.setCursor(cursorColumn, 0); 
lcd.print(key); 
cursorColumn++; 
if(cursorColumn == 16) {

lcd.clear();
cursorColumn = 0;
}
}
}
