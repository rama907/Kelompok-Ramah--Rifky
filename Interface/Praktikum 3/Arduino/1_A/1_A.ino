//Ramah Rinaldi Ruslan (6702190006)
//Muhammad Rifki Ferdiansyah  (6702194022)

int C[]={13,12,11};
int R[]={A1,A2,A3,A4};
char keymap[4][3]={
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
char key;
void setup(){
for (int i=0; i<3;
i++){
pinMode(C[i],INPUT); }
for (int i=0; i<4; i++){
pinMode(R[i],OUTPUT);
}
Serial.begin(9600);
}
void loop(){
scankeypad();
Serial.println(key);
key=' '; }
void scankeypad(){
for(int i=0; i<4; i++){
digitalWrite(R[i],LOW);
for(int j=0; j<3; j++){
if(digitalRead(C[j])==LOW){
key=keymap[i][j];
delay(500);
}
}
digitalWrite(R[i],HIGH);
}
}
