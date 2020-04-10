// initialize the pin 
int ENA = 5;
int ENB = 6;
int IN1 = 10;
int IN2 = 9;
int IN3 = 8;
int IN4 = 7;


void MotorWriting(int vL, int vR){      //speed and dir control

  
  // move forward or backward
  
  //right tire forward
  if(vR>0){
    digitalWrite(IN1,HIGH);   
    digitalWrite(IN2,LOW);
  }
  //right tire backward
  else{
    digitalWrite(IN1,LOW);   
    digitalWrite(IN2,HIGH);
    vR = -vR;
  }
  //left tire forward
  if(vL>0){
    digitalWrite(IN3,HIGH);   
    digitalWrite(IN4,LOW);
  }
  //left tire backward
  else{
    digitalWrite(IN3,LOW);   
    digitalWrite(IN4,HIGH);
    vL = -vL;
  }
  
  analogWrite(ENA, vR); //give speed(right)
  analogWrite(ENB, vL); //give speed(left)

}

// determine the speed (main func)
void ex_method(){

  int vL, vR;

  //stop to turn left
  if(type() == 1){
    vL = -150;
    vR = 150;
  }
  //stop to turn right
  else if(type() == 2){
    vL = 150;
    vR = -150;
  }

  //left tire set to zero to turn left
  else if(type() == 3){
    vL = 0;
    vR = 150;
  }
  //right tire set to zero to turn right
  else if(type() == 4){
    vL = 150;
    vR = 0;
  }
  //slow to turn left
  else if(type() == 5){
    vL = 100;
    vR = 200;
  }
  //slow to turn right
  else if(type() == 6){
    vL = 200;
    vR = 100;
  }
  //stop (outside the road)
  else if(type() == 7){
    vL = 0;
    vR = 0;
  }

  // straight gogo
  else if(type() == 8){
    vL = 200;
    vR = 200;
  }

  //give the motor speed
  MotorWriting(vL, vR);
}
// determine the type
int type(){

  int L3 = digitalRead(A0);
  int L2 = digitalRead(A1);
  int L1 = digitalRead(A2);
  int R1 = digitalRead(A3);
  int R2 = digitalRead(A4);
  int R3 = digitalRead(A5);
  int kind;

  int stop_sum = L3 + L2 + L1 + R1 + R2 + R3;

  
  //type 1: only L3=1
  if(L3 == 1 && L2 != 1){
    kind = 1;
  }
  //type 2: only R3=1
  else if(R3 == 1 && R2 != 1){
    kind = 2;
  }
  //type 3: L3=1 and L2=1
  else if(L3 == 1 && L2 == 1){
    kind = 3;
  }
  //type 4: R3=1 and R2=1
  else if(R3 == 1 && R2 == 1){
    kind = 4;
  }
  //type 5: L2=1
  else if(L2 == 1){
    kind = 5;
  }
  //type 6: R2=1
  else if(R2 == 1){
    kind = 6;
  }  
  //type 7: stop
  else if(stop_sum == 0){
    kind = 7;
  }

  // type 8: straight
  else{
    kind = 8;
  }

  return kind;
}
void setup() {

  //pin setting
  pinMode(ENA,OUTPUT);  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  
}

void loop() {

  //main function
  ex_method();
  
  // 1ms dalay
  delay(1);
  
}
