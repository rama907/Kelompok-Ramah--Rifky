buzzer=A0; // untuk buzzer pada pin A0
void setup(){
pinMode(buzzer,OUTPUT); // mengatur mode buzzer untuk output
}
void loop(){
digitalWrite(buzzer,HIGH); // mengaktifkan buzzer
delay(1000);
digitalWrite(buzzer,LOW); // mematikan buzzer
delay(1000);
}
