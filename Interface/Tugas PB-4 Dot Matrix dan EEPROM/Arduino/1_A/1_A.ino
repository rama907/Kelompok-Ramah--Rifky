#include <EEPROM.h>
int addr = 0;
int potensio = A0;
void setup()
{
Serial.begin(9600);
}
void loop() {
int val = analogRead(potensio) / 4; if (addr <= 512) {
  EEPROM.write(addr, val);
Serial.print(val);
Serial.print("\t");
Serial.println(addr);
addr = addr + 1;
} delay(100);
}
  
