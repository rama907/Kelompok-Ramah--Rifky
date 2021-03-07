int p=10;
int p1=9;
int p2=6;
int p3=5;

int led2=8;
int led3=7;
int led1=13;

int m1=A0;
int m2=A1;
int m3=A2;
int m4=A3;
int m5=A4;
int m6=A5;
int m7=A6;
int m8=A7;

void setup() {
pinMode (p,OUTPUT);
pinMode (p1,OUTPUT);
pinMode (p2,OUTPUT);
pinMode (p3,OUTPUT);

pinMode (led2,OUTPUT);
pinMode (led3,OUTPUT);
pinMode (led1,OUTPUT);

pinMode (m1,INPUT);
pinMode (m2,INPUT);
pinMode (m3,INPUT);
pinMode (m4,INPUT);
pinMode (m5,INPUT);
pinMode (m6,INPUT);
pinMode (m7,INPUT);
pinMode (m8,INPUT);

}

void loop() {
  if (digitalRead(m1)==1 && digitalRead(m2)==1){
      analogWrite(p,123); // belok kiri
      
  }
  else if (digitalRead(m2)==1 && digitalRead(m3)==1 ){
      analogWrite(p,123); // belok kiri
      analogWrite(p3,62); // kanan
  }
   else if (digitalRead(m3)==1 && digitalRead(m4)==1){
      analogWrite(p,123); // belok kiri
      analogWrite(p3,100); // kanan
  }
  else if (digitalRead(m4)==1 && digitalRead(m5)==1 ){
      analogWrite(p,150); // belok kiri
      analogWrite(p3,150); // kanan
  }
  else if (digitalRead(m5)==1 && digitalRead(m6)==1 ){
      analogWrite(p,100); // belok kiri
      analogWrite(p3,123); // kanan
  }
  else if (digitalRead(m6)==1 && digitalRead(m7)==1 ){
      analogWrite(p,62); // belok kiri
      analogWrite(p3,123); // kanan
  }
  else if (digitalRead(m7)==1 && digitalRead(m8)==1 ){
      analogWrite(p3,123); // kanan
  }
  else{
  digitalWrite(p,LOW);
  digitalWrite(p1,LOW);
  digitalWrite(p2,LOW);
  digitalWrite(p3,LOW);
  }
}
