int led=12;
int pot=A1;
int data;
int led1=11;
int led2=10;
int i;
void setup(){
pinMode(led,OUTPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(pot,INPUT);
}
void loop(){
data=analogRead(pot);
data=data/4;
analogWrite(led,data);
analogWrite(led1,data);
analogWrite(led2,data);
if (data > 0) {
digitalWrite(led, HIGH);
} else {
digitalWrite(led, LOW);
}
if (data > 55) {
digitalWrite(led1, HIGH);
} else {
digitalWrite(led1, LOW);
}
if (data > 225) {
digitalWrite(led2, HIGH);
} else {
digitalWrite(led2, LOW);
}
}
