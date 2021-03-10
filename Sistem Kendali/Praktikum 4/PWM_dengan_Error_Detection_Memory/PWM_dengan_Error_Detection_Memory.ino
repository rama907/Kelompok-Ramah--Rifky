// Ramah Rinaldi Ruslan
// Muhammad Rifki Ferdiansyah

int p=10;
int p1=9;
int p2=6;
int p3=5;

int led2=8;
int led3=7;
int led1=13;

int adc_sensor[6],x,sensorbit,t,a_size;
char sendat[6];

void setup() {
  Serial.begin(9600);
pinMode (p,OUTPUT);
pinMode (p1,OUTPUT);
pinMode (p2,OUTPUT);
pinMode (p3,OUTPUT);

pinMode (led2,OUTPUT);
pinMode (led3,OUTPUT);
pinMode (led1,OUTPUT);

pinMode (A0,INPUT);
pinMode (A1,INPUT);
pinMode (A2,INPUT);
pinMode (A3,INPUT);
pinMode (A4,INPUT);
pinMode (A5,INPUT);
}

void loop() {

  String relay1 = String(digitalRead(A0));
  String relay2 = String(digitalRead(A1));
  String relay3 = String(digitalRead(A2));
  String relay4 = String(digitalRead(A3));
  String relay5 = String(digitalRead(A4));
  String relay6 = String(digitalRead(A5));
  
  String  simpan= relay1+relay2+relay3+relay4+relay5+relay6;
 
  
  if (simpan == "100000"){
      analogWrite(p,123); // belok kiri
      Serial.println("-3,motor kiri 50% motor kanan 0%.");
  }
  else if (simpan=="001100"){
      analogWrite(p,123); // belok kiri
      analogWrite(p3,62); //25%
      Serial.println("-2,motor kiri 50% motor kanan 25%.");
  }
   else if (simpan=="000100"){
      analogWrite(p,123); // belok kiri
      analogWrite(p3,100); //30%
      Serial.println("-1,motor kiri 50% motor kanan 30%.");
  }
  else if (simpan=="001100"){
      analogWrite(p,150); //60%
      analogWrite(p3,150); // 60%
      Serial.println("0,motor kiri 50% motor kanan 50%.");
  }
  else if (simpan=="000010"){
      analogWrite(p,100); // belok kiri
      analogWrite(p3,123); // kanan
      Serial.println("1,motor kiri 30% motor kanan 50%.");
  }
  else if (simpan=="000011"){
      analogWrite(p,62); // belok kiri
      analogWrite(p3,123); // kanan
      Serial.println("2,motor kiri 25% motor kanan 50%.");
  }
  else if (simpan=="000001"){
      analogWrite(p3,255); // kanan
       Serial.println("3,motor kiri 0% motor kanan 50%.");
  }
  else{
  digitalWrite(p,LOW);
  digitalWrite(p1,LOW);
  digitalWrite(p2,LOW);
  digitalWrite(p3,LOW);
  }
}
