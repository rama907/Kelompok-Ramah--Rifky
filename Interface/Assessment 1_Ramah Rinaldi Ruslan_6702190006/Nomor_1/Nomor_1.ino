//Ramah Rinaldi Ruslan - 6702190006
int button   = 7;
int led1 = 12;
int led2 = 11;
int led3 = 10;
int blin;

void setup(){
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  blin = 0;
  leedd();
}
void loop(){
    if(blin == 1){
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      delay(300);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      delay(300);
    }
}
void leedd(){
  set:
  if(digitalRead(button)==LOW){
    blin=blin+1;
  }else{
    goto set;
  }
}
