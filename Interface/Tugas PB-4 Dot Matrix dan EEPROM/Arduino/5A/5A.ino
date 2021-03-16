#include <FrequencyTimer2.h>
#define SPACE { \
{0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0},\
{0, 0, 0, 0, 0},\
{0, 0, 0, 0, 0},\
{0, 0, 0, 0, 0}\
} 
#define H {\
{1, 0, 0, 0, 1},\
{1, 0, 0, 0, 1},\
{1, 0, 0, 0, 1},\
{1, 1, 1, 1, 1},\
{1, 0, 0, 0, 1},\
{1, 0, 0, 0, 1},\
{1, 0, 0, 0, 1}\
} 
#define E {\
{1, 1, 1, 1, 1},\
{1, 0, 0, 0, 0},\
{1, 0, 0, 0, 0},\
{1, 1, 1, 1, 0},\
{1, 0, 0, 0, 0},\
{1, 0, 0, 0, 0},\
{1, 1, 1, 1, 1}\
}

#define small_E {\
{0, 0, 0, 0, 0},\
{0, 0, 0, 0, 0},\
{0, 1, 1, 1, 0},\
{1, 0, 0, 0, 1},\
{1, 1, 1, 1, 0},\
{1, 0, 0, 0, 0},\
{0, 1, 1, 1, 0}\
}

#define L {\
{1, 0, 0, 0, 0},\
{1, 0, 0, 0, 0},\
{1, 0, 0, 0, 0},\
{1, 0, 0, 0, 0},\
{1, 0, 0, 0, 0},\
{1, 0, 0, 0, 0},\
{1, 1, 1, 1, 1}\
}

#define small_L {\
{0, 1, 1, 0, 0},\
{0, 0, 1, 0, 0},\
{0, 0, 1, 0, 0},\
{0, 0, 1, 0, 0},\
{0, 0, 1, 0, 0},\
{0, 0, 1, 0, 0},\
{0, 1, 1, 1, 0}\
}
#define O {\
{0, 1, 1, 1, 0},\
{1, 0, 0, 0, 1},\
{1, 0, 0, 0, 1},\
{1, 0, 0, 0, 1},\
{1, 0, 0, 0, 1},\
{1, 0, 0, 0, 1},\
{0, 1, 1, 1, 0}\
}

#define small_O {\
{0, 0, 0, 0, 0},\
{0, 0, 0, 0, 0},\
{0, 1, 1, 1, 0},\
{1, 0, 0, 0, 1},\
{1, 0, 0, 0, 1},\
{1, 0, 0, 0, 1},\
{0, 1, 1, 1, 0}\
}

#define small_W {\
{0, 0, 0, 0, 0},\
{0, 0, 0, 0, 0},\
{1, 0, 0, 0, 1},\
{1, 0, 0, 0, 1},\
{1, 0, 1, 0, 1},\
{1, 0, 1, 0, 1},\
{0, 1, 0, 1, 0}\
}

#define small_R {\
{0, 0, 0, 0, 0},\
{0, 0, 0, 0, 0},\
{0, 1, 0, 1, 1},\
{0, 1, 1, 0, 0},\
{0, 1, 0, 0, 0},\
{0, 1, 0, 0, 0},\
{0, 1, 0, 0, 0}\
}

#define small_D {\
{0, 0, 0, 0, 1},\
{0, 0, 0, 0, 1},\
{0, 1, 1, 0, 1},\
{1, 0, 0, 1, 1},\
{1, 0, 0, 0, 1},\
{1, 0, 0, 0, 1},\
{0, 1, 1, 1, 1}\
}
byte col = 0;
byte leds[5][7];
int pins[13]= {-1, 2, 3, 4, 5, 6, 13, 12, 11, 10, 9, 8, 7};
int cols[5] = {pins[1], pins[2], pins[3], pins[4], pins[5]};
int rows[7] = {pins[6], pins[7], pins[8], pins[9],
pins[10], pins[11], pins[12]};

const int numPatterns = 12; byte
patterns[numPatterns][7][5] = {
SPACE, H, small_E, small_L, small_L, small_O,
SPACE, small_W, small_O, small_R, small_L,
small_D
};

int pattern = 0;
void setup()
{ for (int i = 1; i <= 12;
i++) {
pinMode(pins[i], OUTPUT);
 }
 for (int i = 1; i <= 5; i++) {
digitalWrite(cols[i - 1], LOW);
 }
for (int i = 1; i <= 7; i++) {
digitalWrite(rows[i - 1], LOW);
 }
clearLeds();

 FrequencyTimer2::disable();
 FrequencyTimer2::setPeriod(2000);
FrequencyTimer2::setOnOverflow(display);
setPattern(pattern);
}
void loop() {
pattern = ++pattern % numPatterns;
slidePattern(pattern, 100);
} void clearLeds() {
for (int i = 0; i < 5; i++) {
for (int j = 0; j < 7; j++) {
leds[i][j] = 0;
 }
 }
}
void setPattern(int pattern)
{
 for (int i = 0; i < 5; i++) {
  for (int j = 0; j < 7; j++) {
leds[i][j] = patterns[pattern][j][i];
 }
 }
}
void slidePattern(int pattern, int del)
{
 for (int newcol = 0; newcol <= 4; newcol++) {

 // shift the first 4 columns left
for (int row = 0; row <= 6; row++)
for (int col = 0; col <= 3; col++)
leds[col][row] = leds[col+1][row];

 for (int row = 0; row <= 6; row++)
 leds[4][row] = patterns[pattern][row][newcol];

 delay(del);
 }
}
void display(){
 digitalWrite(cols[col], LOW);
col++; if (col == 5) {
col = 0; }
 for (int row = 0; row < 7; row++) {
if (leds[col][row] == 1) {
digitalWrite(rows[row], LOW);
 }
else {
 digitalWrite(rows[row], HIGH);
 }
}
 digitalWrite(cols[col], HIGH);
}
