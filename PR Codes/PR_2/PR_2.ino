/*--------------------------------------------------Global declarations-----------------------------------------------*/
#include <PS3BT.h>
#include <usbhub.h>
#include<CytronMotorDriver.h>
// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>
int a, b, c, d, pos = 0, e, l2, r2, lx, ly, rx, ry, count1 = 0, count2 = 0, count3 = 0, count4 = 0, x = 0,spd=255,q;
#define md1 26
#define mp1 5
#define md2 48
#define mp2 8
#define md3 50
#define mp3 11
#define md4 28
#define mp4 4
#define mpd 22
#define mpp 7
#define pakkad1 49
#define phek 45
USB Usb;
//USBHub Hub1(&Usb); // Some dongles have a hub inside

BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so
/* You can create the instance of the class in two ways */
PS3BT PS3(&Btd); // This will just create the instance
//PS3BT PS3(&Btd, 0x00, 0x15, 0x83, 0x3D, 0x0A, 0x57); // This will also store the bluetooth address - this can be obtained from the dongle when running the sketch
CytronMD motor(PWM_DIR, 12, 46);  // PWM = Pin 12, DIR = Pin 46.
bool printTemperature, printAngle;
/*------------------------------------------------------------------setup-----------------------------------------------------------*/
void setup() {
  Serial.begin(115200);
  pinMode(md1, OUTPUT);
  pinMode(md2, OUTPUT);
  pinMode(md3, OUTPUT);
  pinMode(md4, OUTPUT);
  pinMode(mp1, OUTPUT);
  pinMode(mp2, OUTPUT);
  pinMode(mp3, OUTPUT);
  pinMode(mp4, OUTPUT);
  pinMode(mpd,OUTPUT);
  pinMode(mpp,OUTPUT);
  pinMode(pakkad1, OUTPUT);
  pinMode(phek, OUTPUT);
  pinMode(2, INPUT);
  pinMode(19, INPUT);
  pinMode(20, INPUT);
  pinMode(21, INPUT);
  digitalWrite(19,HIGH);
  //  attachInterrupt(digitalPinToInterrupt(3),encoder4,RISING);
  //  attachInterrupt(digitalPinToInterrupt(2),encoder2,RISING);
  //  attachInterrupt(digitalPinToInterrupt(20),encoder3,RISING);
    attachInterrupt(digitalPinToInterrupt(19),encoder1,RISING);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));
}
/*-----------------------------------------------------------------------loop---------------------------------------------------------*/
void loop() {
  Usb.Task();
  lx = PS3.getAnalogHat(LeftHatX);
  ly = PS3.getAnalogHat(LeftHatY);
  rx = PS3.getAnalogHat(RightHatX);
  ry = PS3.getAnalogHat(RightHatY);
  l2 = PS3.getAnalogButton(L2);
  r2 = PS3.getAnalogButton(R2);
  Serial.println(count1);
  if (PS3.PS3Connected || PS3.PS3NavigationConnected) {                    //this functoin contains motion of robot
    if(!PS3.getButtonClick(CROSS)){
      if ((PS3.PS3Connected) && !(PS3.getAnalogButton(L2) || PS3.getAnalogButton(R2))) {
        chalechalo();
      }
      if (PS3.getAnalogButton(L2) || PS3.getAnalogButton(R2)) {             //clk or aclk
        ghumo();
      }
      else {
        if (PS3.getButtonClick(TRIANGLE)) {                           //left and right pneuma
          Serial.print(F("\r\nTriangle"));
          //PS3.setRumbleOn(RumbleLow);
        }
        if (PS3.getButtonClick(CIRCLE)) {                           //phekulal on-off
          Serial.print(F("\r\nCircle"));
          //PS3.setRumbleOn(RumbleHigh);
          pitchingMotors();
        }
        if (PS3.getButtonClick(CROSS)) {                         //all stop
          Serial.print(F("\r\nCross"));
          allstop();
        }
        if (PS3.getButtonClick(SQUARE)) {
          Serial.print(F("\r\nSquare"));
  
        }
        if (PS3.getButtonClick(UP)) {                        //servo vale pneuma
          Serial.print(F("\r\nUp"));
         throwing();
        }
        if (PS3.getButtonClick(LEFT)) {            //servo angle -10
          Serial.print(F("\r\nLeft"));
          motorL();
        }
        else if (PS3.getButtonClick(RIGHT)) {                 //servo angle +10
          Serial.print(F("\r\nRight"));
          motorR();
        }
        else {
          analogWrite(mpp, 0);
          x=2;
        }
        if (PS3.getButtonPress(L1)) {            //servo angle -10
          Serial.print(F("\r\nLeft"));
          moorL();
        }
        else if (PS3.getButtonPress(R1)) {                 //servo angle +10
          Serial.print(F("\r\nRight"));
          moorR();
        }
        else {
          analogWrite(mpp, 0);
          x=2;
        }
        if (PS3.getButtonClick(DOWN)) {                   //to take up ball on the rack
          Serial.print(F("\r\nDown"));
          pakkad();
        }
    }
  }
  else{
     allstop();
  }
  }
  else{
  analogWrite(mp1, 0);
  analogWrite(mp2, 0);
  analogWrite(mp3, 0);
  analogWrite(mp4, 0);
  motor.setSpeed(0);
  analogWrite(mpp, 0);
  }
}
