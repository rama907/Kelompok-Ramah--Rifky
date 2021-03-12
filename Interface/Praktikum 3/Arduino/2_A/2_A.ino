//Ramah Rinaldi Ruslan (6702190006)
// Muhammad Rifki Ferdiansyah  (6702194022)

int a=10; 
int b=9; 
int c=8; 
int d=7; 
int e=6; 
int f=5; 
int g=4; 
void setup(){ 
for(int i=10; i>=4; i--){
pinMode(i,OUTPUT);
}
} void loop(){ 
for(int i=0; i<=2; i++){
segment(i);
delay(1000);
}
}
void segment(int angka){ 
if (angka==0){ 
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,LOW);
}
if (angka==1){ 
digitalWrite(a,LOW);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,LOW);
digitalWrite(g,LOW);
}
if (angka==2){ 
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,LOW);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,LOW);
digitalWrite(g,HIGH);
}
}
