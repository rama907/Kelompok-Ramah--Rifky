int buzzer=A5;
int i;
int b=A0;
void setup(){
pinMode(buzzer,OUTPUT);
pinMode(b,INPUT);
}
void
loop(){
if (digitalRead(b)==LOW){
for (i=0; i<=255; i+=5){
analogWrite(buzzer,i);
delay(100);
}
}
else
digitalWrite(buzzer,LOW);
}
