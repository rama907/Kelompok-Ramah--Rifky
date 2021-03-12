#include <sevenSegmentDisplay.h>
#include <Keypad.h>
char keys[4][3] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'} };
byte pin_rows[] = {A1, A2, A3, A4}; //connect to the row pinouts of the keypad
byte pin_column[] = {13, 12, 11}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, 4, 3 );
sevenSegmentDisplay ssd(COMMON_CATHODE, 10, 9, 8, 7, 6, 5, 4, A0);
void setup(){
}
void loop(){
char key = keypad.getKey();
int num = key - '0';
if(key){
if (key == '*' || key == '#') {
} else {
ssd.set(num);
}
}
}
