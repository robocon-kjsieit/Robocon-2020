/*****************************LIBRARY***********************************/
#include <PS3BT.h>
#include <usbhub.h>
#include "CytronMotorDriver.h"
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>
USB Usb;
BTD Btd(&Usb);
PS3BT PS3(&Btd);
bool printTemperature, printAngle;
/**************************VARIABLES**************************************/
#define pm1 4
#define dm1 14        //On HIGH forward
#define pm2 6
#define dm2 44        //On HIGH forward
#define pm3 7
#define dm3 46        //On HIGH forward
#define pm4 5
#define dm4 15        //On HIGH forward
#define p1 33
#define p2 35
#define p3 27
#define p4 37
#define p5 23
#define px1 28
#define px2 A4
int lx, ly, rx, ry, l2, r2;
int up, fron, place, both, Pwm, upp=-1;
int xx = 0;
int yy = 0;
int m, n, f;
CytronMD motor(PWM_DIR, 11, 8);
/****************************************************************/
void setup() {
  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial);
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));
  /****************************************************************/
  pinMode(pm1, OUTPUT);
  pinMode(dm1, OUTPUT);
  pinMode(pm2, OUTPUT);
  pinMode(dm2, OUTPUT);
  pinMode(pm3, OUTPUT);
  pinMode(dm3, OUTPUT);
  pinMode(pm4, OUTPUT);
  pinMode(dm4, OUTPUT);
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
  pinMode(p5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(px1, INPUT);
  pinMode(px2, INPUT);
  analogWrite(pm1, 0);
  analogWrite(pm2, 0);
  analogWrite(pm3, 0);
  analogWrite(pm4, 0);
  up = -1;
  fron = -1;
  place = -1;
  both = -1;
}
/****************************************************************/
void loop()
{
  Usb.Task();         //checks which button press?
  while (1)
  {
    Usb.Task();      //checks which button press?
    lx = PS3.getAnalogHat(LeftHatX);
    ly = PS3.getAnalogHat(LeftHatY);
    rx = PS3.getAnalogHat(RightHatX);
    ry = PS3.getAnalogHat(RightHatY);
    if (PS3.PS3Connected || PS3.PS3NavigationConnected)
    {
      if (PS3.getButtonClick(START))          // if start button press then kill all motion
      {
        allkill();
        break;
      }
      /*********************************PNEUMATICS***************************************/
      else if (PS3.getButtonClick(UP))        //net pneumatics activate
      {
        uppne();
      }
      else if (PS3.getButtonClick(LEFT))      //Push pneumatics activate
      {
        fronpne();
      }
      else if (PS3.getButtonClick(RIGHT))     //placing pneumatics activate
      {
        bothp();
      }
      else if (PS3.getButtonClick(DOWN))      //placing pneumatics activate
      {
        placepne();
      }
      else if (PS3.getButtonClick(CIRCLE))
      {
        digitalWrite(p4, HIGH);
        delay(100);
        motor.setSpeed(-60);
        delay(410);
        motor.setSpeed(0);
        //delay(50);
        //digitalWrite(p5, HIGH);
      }
      else if(PS3.getButtonClick(TRIANGLE))
      {
        while(1)
        {
          m=digitalRead(px1);
          n=digitalRead(px2);
          f++;
          Serial.println(f);
          motor.setSpeed(60);
          if(n==LOW || m==LOW)
          {
            digitalWrite(p4, LOW);
            Serial.println("Yes Baby");
            motor.setSpeed(0);
            f=0;
            break;
          }
        }
      }
      /*********************************NAVIGATION***************************************/
      else if (lx > 127 && rx < 127)          // if left or right joystick push inward then rotate anti clockwise
      {
        unrotatefast();
      }
      else if (lx < 127 && rx > 127)        // if left or right joystick push outward then rotate clockwise
      {
        crotatefast();
      }
      else if (ly > 127 && ry < 127)          //Rotate about axis of 1st motor
      {
        Rdrift();
      }
      else if (ly < 127 && ry > 127 )         //Rotate about axis of 2nd motor
      {
        Ldrift();
      }
      else if (lx > 127 || rx > 127)          //if left or right joystick push right
      {
        right();
      }
      else if (lx < 127 || rx < 127)          // if left or right joystick push left
      {
        left();
      }
      else if (ly < 127 || ry < 127)          //if left or right joystick push up
      {
        
        forward();
      }
      else if (ly > 127 || ry > 127 )         // if left or right joystick push down
      {
        backward();
      }
      /****************************************************************/
      else if (ly < 127 && lx < 127 || ly < 127 && lx > 127 || ly > 127  && lx > 127 || ly > 127  && lx < 127 || ry > 127 && rx > 127 || ry > 127  && rx < 127 || ry < 127  && rx > 127 || ry < 127 && rx < 127)
      {
        stopm();                              // if joystics both satisfy X and Y axis at same time then motion stop
      }
      /****************************************************************/
      else if (PS3.getButtonPress(R1) && PS3.getButtonPress(L1) )       //Diagonal right reverse
      {
        Rright();
      }
      else if (PS3.getButtonPress(L2) &&  PS3.getButtonPress(R2))       //Diagonal left Reverse
      {
        Rleft();
      }
      else if (PS3.getButtonPress(L2))                                  //clock wise rotate
      {
        unrotate();
      }
      else if (PS3.getButtonPress(R2))                                  //anticlock wise rotate
      {
        crotate();
      }
      else if (PS3.getButtonPress(L1))                                  //Diagonal left forward
      {
        Fleft();
      }
      else if (PS3.getButtonPress(R1))                                  //Diagonal right forward
      {
        Fright();
      }
      /****************************************************************/
      else                                                              // all motors stop
      {
        stopm();
      }
    }
    /****************************************************************/
    else                      // PS3 is not connected then all motors off
    {
      stopm();
    }
  }
  /****************************************************************/
  allkill();                //kill all
}
/****************************************************************/
