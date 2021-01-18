void mainControl(){
  lx = PS3.getAnalogHat(LeftHatX);
  ly = PS3.getAnalogHat(LeftHatY);
  rx = PS3.getAnalogHat(RightHatX);
  ry = PS3.getAnalogHat(RightHatY);
  l2 = PS3.getAnalogButton(L2);
  r2 = PS3.getAnalogButton(R2);
//  Serial.println(count1);
  if (PS3.PS3Connected || PS3.PS3NavigationConnected) {      
    Serial.print(count1);
  Serial.print("  ");
  Serial.println(v);
    //this functoin contains motion of robot
    if(!PS3.getButtonClick(CROSS)){
      if ((PS3.PS3Connected)) {
        chalechalo();
      }
      if (PS3.getAnalogButton(L2) || PS3.getAnalogButton(R2)) {             //clk or aclk
        ghumo();
      }
      else {
        if (PS3.getButtonClick(TRIANGLE)) {                           //left and right pneuma
          Serial.print(F("\r\nTriangle"));
          vm = 70;
          count1=0;
          digitalWrite(pakkad1, LOW);
          v=0;
          y=0;
          d = 0;
          pitchingMotors();
          //PS3.setRumbleOn(RumbleLow);
        }
        if (PS3.getButtonClick(CIRCLE)) {                           //phekulal on-off
          Serial.print(F("\r\nCircle"));
          //PS3.setRumbleOn(RumbleHigh);
          vm = 100;
          pitchingMotors();
        }
        if (PS3.getButtonClick(CROSS)) {                         //all stop
          Serial.print(F("\r\nCross"));
          allstop();
        }
        if (PS3.getButtonClick(SQUARE)) {
          Serial.print(F("\r\nSquare"));
          count1=0;
          digitalWrite(pakkad1, LOW);
          v=0;
          y=0;
          d = 0;
          vm = 60;
          pitchingMotors();
    Serial.println("Bademotors on");
    digitalWrite(led,HIGH);
          d=1;
          a=0;
        }
        if (PS3.getButtonClick(UP)) {                        //throwing
          Serial.print(F("\r\nUp"));
         throwing();
        }
        if (PS3.getButtonClick(LEFT)) {            
          Serial.print(F("\r\nLeft"));
          x=0;
          motorL();
        }
        else if (PS3.getButtonClick(RIGHT)) {         
          Serial.print(F("\r\nRight"));
          d = 0;
          vm = 255;
          pitchingMotors();
        }
        else {
          analogWrite(mpp, 0);
        }
        if (PS3.getButtonPress(L1)) {            //Gripper angle -10
          Serial.print(F("\r\nL1"));
          moorL();
        }
        else if (PS3.getButtonPress(R1)) {                 //Gripper angle +10
          Serial.print(F("\r\nR1"));
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
