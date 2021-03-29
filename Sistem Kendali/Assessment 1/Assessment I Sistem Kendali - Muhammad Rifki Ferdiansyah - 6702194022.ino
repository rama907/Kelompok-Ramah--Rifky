//Assessment 1 Sistem Kendali Praktik 6702194022

//konfigurasi pin sensor
int sensor[6] = {A0, A1, A2, A3, A4, A5};

//konfigurasi pin motor
int enMotorKiri = 4; //pin enable input motorKiri
int enMotorKanan = 2; //pin enable input motorKanan
int motorKiri1 = 5; //pin input 1 L293D
int motorKiri2 = 6; //pin input 2 L293D
int motorKanan1 = 3; //pin input 3 L293D
int motorKanan2 = 11; //pin input 4 L293D

//konfigurasi pin led
int ledA = 7;
int ledB = 8;

//variabel bantuan untuk menampung nilai motor
int valMotorKiri;
int valMotorKanan;

//variabel bantuan untuk menampung nilai sensor
int valSensor[6];

//variabel bantuan untuk menyimpan nilai Error
int valError = 0;
int i;

void setup()
{
  //mengulangi konfigurasi pin
  for(i=0;i<6;i++){
  	//konfigurasi pin A0, A1, A2, A3, A4, A5 sebagai input
  	pinMode(sensor[i], INPUT);
  }
  //konfigurasi pin dirver motor L293D
  pinMode(enMotorKiri, OUTPUT); //pin 4
  pinMode(enMotorKanan, OUTPUT); //pin 2
  pinMode(motorKiri1, OUTPUT); //pin 5
  pinMode(motorKiri2, OUTPUT); //pin 6
  pinMode(motorKanan1, OUTPUT); //pin 3
  pinMode(motorKanan2, OUTPUT); //pin 11
  //konfigurasi pin led sebagai output
  pinMode(ledA, OUTPUT); //pin 7
  pinMode(ledB, OUTPUT); //pin 8
  //konfigurasi serial baud rate 9600
  Serial.begin(9600);
}

//fungsi untuk membaca nilai sensor
void readSensor(){
  //perulangan untuk mengulangi pembacaan sensor
  for(i=0;i<=5;i++){
  	//membaca dan menampung nilai sensor ke dalam variabel valSensor[i]
  	valSensor[i] = analogRead(sensor[i]);
  	//manampilkan nilai sensor pada serial monitor
    Serial.print("\nSensor ");
    Serial.print(i+1);
    Serial.print("	: ");
    Serial.print(valSensor[i]);
  }
}

//fungsi untuk menggerakan motor
void writeMotor(){
  //enable motor kiri dan kanan
  digitalWrite(enMotorKiri, HIGH);
  digitalWrite(enMotorKanan, HIGH);
  //duty cycle motor kiri
  analogWrite(motorKiri1, valMotorKiri);
  analogWrite(motorKiri2, 0);
  //duty cycle motor kanan
  analogWrite(motorKanan1, valMotorKanan);
  analogWrite(motorKanan2, 0);
}

void loop()
{  
  //memanggil fungsi readSensor()
  readSensor();
  //jika terdeteksi error, program akan lompat ke label afterError
  afterError:
  //kasus 1
  //jika sensor 1 dan 2 mendeteksi gelap, sisanya terang
  if(valSensor[0]<34&&
     valSensor[1]<34&&
     valSensor[2]>34&&
     valSensor[3]>34&&
     valSensor[4]>34&&
     valSensor[5]>34){
  	//konfigurasi duty cycle motor
	valMotorKiri = 255 * 0.22; //duty cycle motor kiri 22%
	valMotorKanan = 255 * 0.67; //duty cycle motor kanan 67%
	//memanggil fungsi writeMotor()
	writeMotor();
  }

  //jika sensor 2 dan 3 mendeteksi gelap, sisanya terang
  else if(valSensor[0]>34&&
          valSensor[1]<34&&
          valSensor[2]<34&&
          valSensor[3]>34&&
          valSensor[4]>34&&
          valSensor[5]>34){
  	//konfigurasi duty cycle motor
	valMotorKiri = 255*0.3; //duty cycle motor kiri 30%
	valMotorKanan = 255*0.6; //duty cycle motor kanan 60%
	//memanggil fungsi writeMotor()
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
	valMotorKiri = 255*0.6; //duty cycle motor kiri 60%
	valMotorKanan = 255*0.3; //duty cycle motor kanan 30%
	//memanggil fungsi writeMotor()
	writeMotor();
  }

  //jika sensor 5 dan 6 mendeteksi gelap, sisanya terang
  else if(valSensor[0]>34&&
          valSensor[1]>34&&
          valSensor[2]>34&&
          valSensor[3]>34&&
          valSensor[4]<34&&
          valSensor[5]<34){
  	//konfigurasi duty cycle motor
	valMotorKiri = 255*0.67; //duty cycle motor kiri 67%
	valMotorKanan = 255*0.22; //duty cycle motor kanan 22%
	//memanggil fungsi writeMotor()
	writeMotor();
  }

  //jika semua sensor mendeteksi terang
  else if(valSensor[0]>34&&
          valSensor[1]>34&&
          valSensor[2]>34&&
          valSensor[3]>34&&
          valSensor[4]>34&&
          valSensor[5]>34){
  	//konfigurasi duty cycle motor
	valMotorKiri = 255*0.22; //duty cycle motor kiri 22%
	valMotorKanan = 255*0.22; //duty cycle motor kanan 22%
    //tampilkan peringatan robot keluar lintasan
    Serial.print("\nROBOT KELUAR LINTASAN!!!");
    //led kedip kedip
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    delay(1000);
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    delay(1000);
	//memanggil fungsi writeMotor()
	writeMotor();
  }

 //kasus 2 
  //jika hanya sensor 1 mendeteksi gelap, sisanya terang
  else if(valSensor[0]<34&&
          valSensor[1]>34&&
          valSensor[2]>34&&
          valSensor[3]>34&&
          valSensor[4]>34&&
          valSensor[5]>34){
  	//sensor terdekat diberikan nilai yang sama dengan sensor yang mendeteksi gelap
    valSensor[1] = valSensor[0];
  	//tandai sebagai error
    valError = -2;
    //tampilkan nilai error
    showError();
    //lompat ke label afterError: (baris 77)
    goto afterError;
  }

  //jika hanya sensor 2 mendeteksi gelap, sisanya terang
  else if(valSensor[0]>34&&
          valSensor[1]<34&&
          valSensor[2]>34&&
          valSensor[3]>34&&
          valSensor[4]>34&&
          valSensor[5]>34){
  	//sensor terdekat diberikan nilai yang sama dengan sensor yang mendeteksi gelap
    valSensor[2] = valSensor[1];
  	//tandai sebagai error
    valError = -1;
    //tampilkan nilai error
    showError();
    //lompat ke label afterError: (baris 77)
    goto afterError;
  }

  //jika hanya sensor 3 mendeteksi gelap, sisanya terang
  else if(valSensor[0]>34&&
          valSensor[1]>34&&
          valSensor[2]<34&&
          valSensor[3]>34&&
          valSensor[4]>34&&
          valSensor[5]>34){
  	//sensor terdekat diberikan nilai yang sama dengan sensor yang mendeteksi gelap
    valSensor[3] = valSensor[2];
  	//tandai sebagai error
    valError = 0;
    //tampilkan nilai error
    showError();
    //lompat ke label afterError: (baris 77)
    goto afterError;
  }

  //jika hanya sensor 4 mendeteksi gelap, sisanya terang
  else if(valSensor[0]>34&&
          valSensor[1]>34&&
          valSensor[2]>34&&
          valSensor[3]<34&&
          valSensor[4]>34&&
          valSensor[5]>34){
  	//sensor terdekat diberikan nilai yang sama dengan sensor yang mendeteksi gelap
    valSensor[2] = valSensor[3];
  	//tandai sebagai error
    valError = 0;
    //tampilkan nilai error
    showError();
    //lompat ke label afterError: (baris 77)
    goto afterError;
  }

  //jika hanya sensor 5 mendeteksi gelap, sisanya terang
  else if(valSensor[0]>34&&
          valSensor[1]>34&&
          valSensor[2]>34&&
          valSensor[3]>34&&
          valSensor[4]<34&&
          valSensor[5]>34){
  	//sensor terdekat diberikan nilai yang sama dengan sensor yang mendeteksi gelap
    valSensor[3] = valSensor[4];
  	//tandai sebagai error
    valError = 1;
    //tampilkan nilai error
    showError();
    //lompat ke label afterError: (baris 77)
    goto afterError;
  }

  //jika hanya sensor 6 mendeteksi gelap, sisanya terang
  else if(valSensor[0]>34&&
          valSensor[1]>34&&
          valSensor[2]>34&&
          valSensor[3]>34&&
          valSensor[4]>34&&
          valSensor[5]<34){
  	//sensor terdekat diberikan nilai yang sama dengan sensor yang mendeteksi gelap
    valSensor[4] = valSensor[5];
  	//tandai sebagai error
    valError = 2;
    //tampilkan nilai error
    showError();
    //lompat ke label afterError: (baris 77)
    goto afterError;
  }
  Serial.print("\n---------------------");
}

void showError(){
  
  //menampilkan nilai valError
  Serial.print("\nError		: ");
  Serial.print(valError);
  //mengosongkan valError
  valError = 0;
}