
/*
int ENA = 11;
int IN1 = 10;
int IN2 = 9;
int IN3 = 8;
int IN4 = 7;
int ENB = 6;


void setup() {
  
  
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENB,OUTPUT);

}

void loop() {
   
  analogWrite(ENA,79);
  analogWrite(ENB,100);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(1000);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN4,LOW);
  digitalWrite(IN3,HIGH);
  delay(1000);
 
  }
*/
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
