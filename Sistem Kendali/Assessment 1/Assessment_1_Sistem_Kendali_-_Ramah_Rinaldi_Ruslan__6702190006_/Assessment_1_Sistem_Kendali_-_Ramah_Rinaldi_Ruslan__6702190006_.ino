//Ramah Rinaldi Ruslan
//D3TK-43-02
//6702190006

int sensor[6] = {A0, A1, A2, A3, A4, A5};

int enMotorKiri = 4; 
int enMotorKanan = 2; 
int motorKiri1 = 5; 
int motorKiri2 = 6; 
int motorKanan1 = 3; 
int motorKanan2 = 11; 

int ledA = 7;
int ledB = 8;

int valMotorKiri;
int valMotorKanan;

int valSensor[6];

int valError = 0;
int i;

void setup()
{
  
  for(i=0;i<6;i++){
    
    pinMode(sensor[i], INPUT);
  }
  
  pinMode(enMotorKiri, OUTPUT); 
  pinMode(enMotorKanan, OUTPUT); 
  pinMode(motorKiri1, OUTPUT); 
  pinMode(motorKiri2, OUTPUT); 
  pinMode(motorKanan1, OUTPUT); 
  pinMode(motorKanan2, OUTPUT); 
  
  pinMode(ledA, OUTPUT); 
  pinMode(ledB, OUTPUT); 
  
  Serial.begin(9600);
}

void readSensor(){
  for(i=0;i<=5;i++){
    valSensor[i] = analogRead(sensor[i]);
    Serial.print("\nSensor ");
    Serial.print(i+1);
    Serial.print("  : ");
    Serial.print(valSensor[i]);
  }
}

void writeMotor(){
  digitalWrite(enMotorKiri, HIGH);
  digitalWrite(enMotorKanan, HIGH);
  analogWrite(motorKiri1, valMotorKiri);
  analogWrite(motorKiri2, 0);
  analogWrite(motorKanan1, valMotorKanan);
  analogWrite(motorKanan2, 0);
}

void loop()
{  
  readSensor();
  afterError:
  if(valSensor[0]<34&&
     valSensor[1]<34&&
     valSensor[2]>34&&
     valSensor[3]>34&&
     valSensor[4]>34&&
     valSensor[5]>34){
    //konfigurasi duty cycle motor
  valMotorKiri = 255 * 0.06; //duty cycle motor kiri 6%
  valMotorKanan = 255 * 0.67; //duty cycle motor kanan 67%
  writeMotor();
  }

  else if(valSensor[0]>34&&
          valSensor[1]<34&&
          valSensor[2]<34&&
          valSensor[3]>34&&
          valSensor[4]>34&&
          valSensor[5]>34){
  valMotorKiri = 255*0.3; 
  valMotorKanan = 255*0.6;
  writeMotor();
  }

  //jika sensor 3 dan 4 mendeteksi gelap, sisanya terang
  else if(valSensor[0]>34&&
          valSensor[1]>34&&
          valSensor[2]<34&&
          valSensor[3]<34&&
          valSensor[4]>34&&
          valSensor[5]>34){
    //konfigurasi duty cycle motor
  valMotorKiri = 255*0.8; //duty cycle motor kiri 80%
  valMotorKanan = 255*0.8; //duty cycle motor kanan 80%
  //memanggil fungsi writeMotor()
  writeMotor();
  }

  //jika sensor 4 dan 5 mendeteksi gelap, sisanya terang
  else if(valSensor[0]>34&&
          valSensor[1]>34&&
          valSensor[2]>34&&
          valSensor[3]<34&&
          valSensor[4]<34&&
          valSensor[5]>34){
    //konfigurasi duty cycle motor
  valMotorKiri = 255*0.6; 
  valMotorKanan = 255*0.3; 
  writeMotor();
  }

  else if(valSensor[0]>34&&
          valSensor[1]>34&&
          valSensor[2]>34&&
          valSensor[3]>34&&
          valSensor[4]<34&&
          valSensor[5]<34){
  valMotorKiri = 255*0.67; //duty cycle motor kiri 67%
  valMotorKanan = 255*0.06; //duty cycle motor kanan 6%
  writeMotor();
  }

  //semua sensor mendeteksi terang
  else if(valSensor[0]>34&&
          valSensor[1]>34&&
          valSensor[2]>34&&
          valSensor[3]>34&&
          valSensor[4]>34&&
          valSensor[5]>34){
  valMotorKiri = 255*0.06; //duty cycle motor kiri 6%
  valMotorKanan = 255*0.06; //duty cycle motor kanan 6%
    Serial.print("\nRobot Keluar Lintasan");
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    delay(1000);
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    delay(1000);
  writeMotor();
  }

  else if(valSensor[0]<34&&
          valSensor[1]>34&&
          valSensor[2]>34&&
          valSensor[3]>34&&
          valSensor[4]>34&&
          valSensor[5]>34){
  
    valSensor[1] = valSensor[0];
    valError = -2;
    showError();
    goto afterError;
  }

  else if(valSensor[0]>34&&
          valSensor[1]<34&&
          valSensor[2]>34&&
          valSensor[3]>34&&
          valSensor[4]>34&&
          valSensor[5]>34){
  
    valSensor[2] = valSensor[1];
    valError = -1;
    showError();
    goto afterError;
  }

  else if(valSensor[0]>34&&
          valSensor[1]>34&&
          valSensor[2]<34&&
          valSensor[3]>34&&
          valSensor[4]>34&&
          valSensor[5]>34){
    
    valSensor[3] = valSensor[2];
    valError = 0;
    showError();
    goto afterError;
  }

  
  else if(valSensor[0]>34&&
          valSensor[1]>34&&
          valSensor[2]>34&&
          valSensor[3]<34&&
          valSensor[4]>34&&
          valSensor[5]>34){
    
    valSensor[2] = valSensor[3];
    valError = 0;
    showError();
    goto afterError;
  }


  else if(valSensor[0]>34&&
          valSensor[1]>34&&
          valSensor[2]>34&&
          valSensor[3]>34&&
          valSensor[4]<34&&
          valSensor[5]>34){
    
    valSensor[3] = valSensor[4];
    valError = 1;
    showError();
    goto afterError;
  }

  else if(valSensor[0]>34&&
          valSensor[1]>34&&
          valSensor[2]>34&&
          valSensor[3]>34&&
          valSensor[4]>34&&
          valSensor[5]<34){

    valSensor[4] = valSensor[5];
    valError = 2;
    showError();
    goto afterError;
  }
  Serial.print("\n---------------------");
}

void showError(){
  
  Serial.print("\nError   : ");
  Serial.print(valError);
  valError = 0;
}
