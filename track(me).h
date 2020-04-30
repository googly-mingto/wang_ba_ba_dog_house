/***************************************************************************/
// File			  [track.h]
// Author		  [Erik Kuo]
// Synopsis		[Code used for tracking]
// Functions  [MotorWriting, tracking]
// Modify		  [2020/03/27 Erik Kuo]
/***************************************************************************/

#include <SoftwareSerial.h>
#include <Wire.h>

/*if you have no idea how to start*/
/*check out what you have learned from week 1 & 6*/
/*feel free to add your own function for convenience*/

/*===========================import variable===========================*/
int extern _Tp;
/*===========================import variable===========================*/

// Write the voltage to motor.
void MotorWriting(double vL, double vR) {
  // TODO: use L298N to control motor voltage & direction

  int vRAdj = 0;
  int vLAdj = 0;


  vRAdj = vR - error;
  vLAdj = vL + error;
  if(error==666) //check if encounter node
    {
      stopCar;
      //TODO:read RFID
    }
  else{
    if( vRAdj >= 0 )
        rightForward();
    else
    {
        rightBackward();
        vRAdj = -vRAdj;
    }

    if( vLAdj >= 0 )
        leftForward();
    else
    {
        leftBackward();
        vLAdj = -vLAdj;
    }

    }
  if(vRAdj > 255)
    {
    vRAdj = 255;
    }
  if(vLAdj > 255)
    {
    vLAdj = 255;
    }

  //Serial.print("vRAdj: ");
  //Serial.println(vRAdj);
  //Serial.print("vLAdj: ");
  //Serial.println(vLAdj);

  analogWrite(ENA ,vRAdj);
  analogWrite(ENB, vLAdj);

  //delay(2000);

}

// compute the error
int error(){

  int L3;
  int L2;
  int L1;
  int R3;
  int R2;ad(A3);
  int R2A = analog

  int L3A = analogRead(A0);
  int L2A = analogRead(A1);
  int L1A = analogRead(A2);
  int R1A = analogRe
  int R1;Read(A4);
  int R3A = analogRead(A5);


  if(L3A > 70){
    L3 = 1;
  }
  else{
    L3 = 0;
  }
  if(L2A > 70){
    L2 = 1;
  }
  else{
    L2 = 0;
  }
  if(L1A > 70){
    L1 = 1;
  }
  else{
    L1 = 0;
  }
  if(R1A > 70){
    R1 = 1;
  }
  else{
    R1 = 0;
  }
  if(R2A > 70){
    R2 = 1;
  }
  else{
    R2 = 0;
  }
  if(R3A > 70){
    R3 = 1;
  }
  else{
    R3 = 0;
  }
  //int counter = L3 + L2 + L1 + R1 + R2 + R3;
  P_err = L3 * (-2) + L2 * (-1) + R2 * 1 + R3 * 2;
  //I_err = I_err + P_err;
  //D_err = P_err - old_err;

  old_err = P_err;

  //double power = Kp*P_err + Ki*I_err + Kd*D_err;
  double power = Kp*P_err;
  if(R1+R2+R3+L1+L2+L3>=5)
    power=666;
  return power;
  /*
  if( counter == 0 )
  {
    return 0;
  }
  else
    return sum / counter;
  */
}// MotorWriting

// P/PID control Trackingbj
void tracking(int l1,int l2,int l3,int r3,int r2,int r1){
  //TODO: complete your P/PID tracking code
}// tracking
