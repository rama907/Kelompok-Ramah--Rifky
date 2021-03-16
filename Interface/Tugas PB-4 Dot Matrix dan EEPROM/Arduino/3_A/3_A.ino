#include <EEPROM.h>
void setup()
{
for (int i = 0; i < 512; i++) EEPROM.write(i, 0); digitalWrite(13, HIGH);
}
void loop()
{
}
