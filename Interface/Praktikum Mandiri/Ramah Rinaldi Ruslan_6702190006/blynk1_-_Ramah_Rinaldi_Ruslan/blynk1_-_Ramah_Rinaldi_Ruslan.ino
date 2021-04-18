/*************************************************************** 
*  Aplikasi kontrol LED via Blynk Server 
* Buka command windows pada direktori berikut  
* C:\Users\Username\Documents\Arduino\libraries\Blynk\scripts 
 *  
* Pada command prompt ketikan: blynk-ser.bat -c COM2 lalu enter  *  COM2 disesuaikan dengan port yang digunakan pada Proteus Anda! 
 
****************************************************************/ 
#include <BlynkSimpleStream.h> 
 
// Pin Assignments 
int bluePin=13,greenPin=12,yellowPin=11,redPin=10; 
 
//Ganti Auth Token sesuai kode yang muncul pada aplikasi Blynk pada 
//smartphone Anda. Auth Token di bawah ini hanyalah contoh. 
char auth[] = "ySI5MM7G_0kik1BkoDcAQU2akKDNfSpR"; 
 
void setup() { 
  //Atur pin sebagai output   
  pinMode(bluePin,OUTPUT);   
  pinMode(greenPin,OUTPUT);   
  pinMode(yellowPin,OUTPUT);   
  pinMode(redPin,OUTPUT); 
 
  // Blynk berkomunikasi melalui komunikasi serial 
  Serial.begin(9600); 
  Blynk.begin(auth, Serial); 
}  
void loop() 
{ 
//mengaktifkan fungsi Blynk 
  Blynk.run(); } 
