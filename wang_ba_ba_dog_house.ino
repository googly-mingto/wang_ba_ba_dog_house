// initialize the pin 
int ENA = 5;
int ENB = 6;
int IN1 = 10;
int IN2 = 9;
int IN3 = 8;
int IN4 = 7;


bool MotorWriting( int vL, int vR, int delayTime ) // enter the left speed, right speed, and delay time
{
  bool dirL = 0;   // the left tire direction, 1 for forward, 0 for backward
  bool dirR = 0;   // the right tire direction, 1 for forward, 0 for backward
  unsigned int vLAbs = 0;   // the left tire speed magnitude
  unsigned int vRAbs = 0;   // the right tire speed magnitude
  if(vL >= 0 )      // if vL is positive, dirL = 1, otherwise, dirL = 0
  {
    dirL = 1;
    vLAbs = vL;     // assure that vLAbs is positive
  }  
  else
  {
    dirL = 0;
    vLAbs = -vL;  
  }

  if(vR >= 0 )      // if vR is positive, dirR = 1, otherwise, dirR = 0
  {
    dirR = 1;
    vRAbs = vL;     // assure that vRAbs is positive
  }  
  else
  {
    dirR = 0;
    vRAbs = -vL;  
  }

  if( dirL == 1 )  // left tire move forward with the speed vLAbs
  {
    analogWrite(ENA,vLAbs);
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
  }
  else            // left tire move backward with the speed vLAbs
  {
    analogWrite(ENA,vLAbs);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
  }

  if( dirR == 1 )  // right tire move forward with the speed vRAbs
  {
     analogWrite(ENB,vLAbs);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
  }
  else             // right tire move backward with the speed vRAbs
  {
    analogWrite(ENB,vRAbs);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
  }

  delay(delayTime * 1000);   // delayTime s change to ms

  
  
  
}

void setup() { //define the pin as output
  
  
  pinMode(ENA,OUTPUT);  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENB,OUTPUT);
  
}

void loop() {
    if( MotorWriting( 100, 100, 2 ) )  //if the function work, print success, otherwise, print fail
    {
      Serial.println("success moving!");  
    } 
    else
    {
      Serial.println("fail to move!");  
    }
    analogWrite( ENA, 0 );  // stop the left tire
    analogWrite( ENB, 0 );  // stop the right tire
}

/*
#include  <SoftwareSerial.h>
SoftwareSerial BT(10, 11); // RX | TX
String message;
  
void setup()
{
  
  Serial.begin(9600);
  Serial.println("BT is ready!");
  BT.begin(9600);
}
  
void loop()
{
    while(Serial.available())
  {
    //while there is data available on the serial monitor
    message+=char(Serial.read());//store string from serial command
  }
  if(!Serial.available())
  {
    if(message!="")
    {
      //if data is available
      BT.println(message); //show the data
      message=""; //clear the data
    }
  }
    while(BT.available())
  {
    //while there is data available on the serial monitor
    message+=char(BT.read());//store string from serial command
  }
  if(!BT.available())
  {
    if(message!="")
    {
      //if data is available
      Serial.println(message); //show the data
      message=""; //clear the data
    }
  }
    
}
*/
