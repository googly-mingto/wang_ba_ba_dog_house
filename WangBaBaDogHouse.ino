

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
SoftwareSerial BT(3, 5); // RX | TX
char val;  // 儲存接收資料的變數
  
void setup()
{
  
  Serial.begin(9600);
  BT.begin(9600);
}
  
void loop()
{
  if(BT.available())
  {
    val = BT.read();
    Serial.print(val);
    }
  if(Serial.available())
  {
    val = Serial.read();
    BT.print(val);
    
  }
    
}
