/*-----------------------------------Grabbing and picking Task using encoders--------------------------*/
void motorL() {
  y=y+1;
  while(v>=-13 && y==2){
    Usb.Task(); 
    digitalWrite(mpd, LOW);
    analogWrite(mpp, 80);
    Serial.println(count1);
//    mainControl();
    if(PS3.getButtonClick(CROSS)){
      y=4;
    }
    else if(PS3.getButtonClick(SQUARE)){
      y=4;
    }
  }
  analogWrite(mpp, 0);
  while(v<=7 && y==1){
    Usb.Task();
    digitalWrite(mpd, HIGH);
    analogWrite(mpp, 80);
    Serial.println(count1);
//    mainControl();
    if(PS3.getButtonClick(CROSS)){
      y=4;
    }
    else if(PS3.getButtonClick(SQUARE)){
      y=4;
    }
  }
  analogWrite(mpp, 0);
  while(v<=0 && y==3){
      x=1;
      Usb.Task();
      digitalWrite(mpd, HIGH);
      analogWrite(mpp, 80);
      Serial.println(count1);
//      mainControl();
      if(PS3.getButtonClick(CROSS)){
        y=4;
    }
    else if(PS3.getButtonClick(SQUARE)){
      y=4;
    }
  }
  analogWrite(mpp, 0);
  if(x==1){
    y=0;
    x=0;
  }
}

void motorR() {
  while(v<=6 && x==0){
    digitalWrite(mpd, HIGH);
    analogWrite(mpp, 80);
    Serial.println(count1);
//    mainControl();
    if(PS3.getButtonClick(CROSS)){
      x=1;
    }
  }
  analogWrite(mpp, 0);
}
/*------------------------------------------Gripper Movement------------------------------------------*/
void moorL() {
  if (PS3.getButtonPress(L1)) {
    digitalWrite(mpd, LOW);
    analogWrite(mpp, 120);
    Serial.print(count1);
  Serial.print("  ");
  Serial.println(v);
  }
}
void moorR() {
  if (PS3.getButtonPress(R1)) { 
    digitalWrite(mpd, HIGH);
    analogWrite(mpp, 120);
    Serial.print(count1);
  Serial.print("  ");
  Serial.println(v);
  }
}
   
