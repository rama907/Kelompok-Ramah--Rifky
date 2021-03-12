// Ramah Rinaldi Ruslan
// Muhammad Rifki Ferdiansyah

#include <sevenSegmentDisplay.h>
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
byte pin_rows[] = {A1, A2, A3, A4}; //connect to the row pinouts of the keypad
byte pin_column[] = {13, 12, 11}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, 4, 3 );
sevenSegmentDisplay ssd(COMMON_CATHODE, 10, 9, 8, 7, 6, 5, 4, A0);
LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA, PIN_LCD_CLOCK,
PIN_LCD_STROBE);
int cursorColumn = 0;
void setup(){
lcd.begin(16,2);
lcd.setCursor (0, 0);
}
void loop(){
char key = keypad.getKey();
int num = key - '0';
if (key) {
if (key == '*' || key == '#') {
} else {
ssd.set(num);
}
lcd.setCursor(cursorColumn, 0); // move cursor to (cursorColumn, 0)
lcd.print(key); // print key at (cursorColumn, 0)
cursorColumn++; // move cursor to next position
if(cursorColumn == 16) {
// if reaching limit, clear LCD
lcd.clear();
cursorColumn = 0;
}
}
}
