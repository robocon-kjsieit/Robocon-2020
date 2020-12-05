/*--------------------------------------------------Global declarations-----------------------------------------------*/
#include <PS3BT.h>
#include <usbhub.h>
#include<CytronMotorDriver.h>
// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>
int a, b, c, d, pos = 0, e, l2, r2, lx, ly, rx, ry, count1 = 0, count2 = 0, count3 = 0, count4 = 0, x = 0,m=220,q,v,y=0,m1=120,vm = 125;
//void forward(int x);
//void back(int x);
//void right(int x);
//void left(int x);
//void backpl(int x);
//void rightpl(int x);
//void leftpl(int x);
//void forwardpl(int x);
//void aclockwise(int x);
//void clockwise(int x);
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
#define pakkad1 45
#define phek 49
#define led 47
#define pitmd 44
#define pitmp 13
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
  pinMode(led,OUTPUT);
  digitalWrite(19,HIGH);
//  pinMode(47,OUTPUT);
//  pinMode(25,OUTPUT);
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
  mainControl();
}
