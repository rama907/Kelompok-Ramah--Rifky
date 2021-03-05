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
}

void loop() {
  if (digitalRead(m1)==1){
  digitalWrite(p,HIGH);
    if (digitalRead(m3)==1)
    {
      digitalWrite(led2,HIGH);
      digitalWrite(led1,LOW);
      digitalWrite(led3,LOW);
     }
  }
   if (digitalRead(m1)==0){
  digitalWrite(p,LOW);
  }
  if (digitalRead(m2)==1){
  digitalWrite(p1,HIGH);
     if (digitalRead(m4)==1)
    {
      digitalWrite(led2,LOW);
      digitalWrite(led1,LOW);
      digitalWrite(led3,HIGH);
     }
  }
  if (digitalRead(m2)==0){
  digitalWrite(p1,LOW);
  }
   if (digitalRead(m3)==1){
  digitalWrite(p2,HIGH);
    if (digitalRead(m2)==1)
    {
      digitalWrite(led2,LOW);
      digitalWrite(led1,HIGH);
      digitalWrite(led3,LOW);
     }
  }
  if (digitalRead(m3)==0){
  digitalWrite(p2,LOW);
  }
  if (digitalRead(m4)==1){
  digitalWrite(p3,HIGH);
     if (digitalRead(m1)==1)
    {
      digitalWrite(led2,LOW);
      digitalWrite(led1,HIGH);
      digitalWrite(led3,LOW);
     }
  }
  if (digitalRead(m4)==0){
  digitalWrite(p3,LOW);
  }
}
