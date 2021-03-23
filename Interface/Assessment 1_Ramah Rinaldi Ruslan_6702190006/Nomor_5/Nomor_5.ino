//Ramah Rinaldi Ruslan - 6702190006
int ledpins[]={5,6,7,8,9,10};  
int i=0;
int val=0;                 
int state=0;
int val1=0;
int state1=0;
int old_val=0;
int old_val1=0;

void setup()
{                               
  for(int i=0; i<6; i++)        
  pinMode(ledpins[i], OUTPUT);
  pinMode(2, INPUT);            
  pinMode(3,INPUT);            
}

void loop()
{
  val=digitalRead(2);  
  val1=digitalRead(3);
 
  if((val==HIGH) && (old_val==LOW)){      
    state=1-state;                        
  delay(100);                              
  }
  old_val=val;                            
 
  if((val1==HIGH) && (old_val1==LOW)){
    state1=1-state1;
  delay(100);
  }
  old_val1=val1;

  if (state==1)
{
  i++;               
  while(i==6){i=0;} 
  Serial.println(i);
  digitalWrite(ledpins[i],HIGH);
  delay(200);
  digitalWrite(ledpins[i],LOW);
}

if (state1==1)
{
  while(i==0){i=6;}
  Serial.println(i);
  i--;
  digitalWrite(ledpins[i],HIGH);
  delay(200);
  digitalWrite(ledpins[i],LOW);
}
}
