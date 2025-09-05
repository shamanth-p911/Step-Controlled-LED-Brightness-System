int light=9;
int readred=3;
int HIG=0;
int state;
int readyellow=2;
int state2;
int beep=4;
void setup() {
  // put your setup code here, to run once:
pinMode(light,OUTPUT);
pinMode(readred,INPUT);
pinMode(beep,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
state=digitalRead(readred);
if(state==0){
  if(HIG<200){
  analogWrite(light,HIG);
  HIG=HIG+15;
  digitalWrite(beep,0);
  delay(100);
  }
  else{
    digitalWrite(light,1);
    digitalWrite(beep,1);
    Serial.println("System has reached maximum potential. Initiate reduction by pressing the yellow button.");
    delay(100);
  }
}

state2=digitalRead(readyellow);
if(state2==0){
  if(10<HIG){
  analogWrite(light,HIG);
  HIG=HIG-15;
  digitalWrite(beep,0);
  delay(100);
  }
  else{
    digitalWrite(light,0);
    digitalWrite(beep,1);
    Serial.println("Minimum potential reached. Please increase it by pressing the red button.");
    delay(100);
  }
}

}
