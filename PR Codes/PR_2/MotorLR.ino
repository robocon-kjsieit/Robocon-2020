/*-----------------------------------Grabbing and picking Task using encoders--------------------------*/
void motorL() {
   a = a + 1;
  if (a == 1) {
    digitalWrite(pakkad1, HIGH);
    Serial.println("Pakadla");
  }
  delay(300);
  while(count1>=-65 && !PS3.getButtonClick(CROSS)){ 
    x=1;
    digitalWrite(mpd, LOW);
    analogWrite(mpp, 80);
    Serial.println(count1);
  }
   a = a + 1;
   analogWrite(mpp, 0);
  if (a == 2) {
    digitalWrite(pakkad1, LOW);
    Serial.println("Sodla");
    a = 0;
  }
  delay(300);
  while(count1<3 && !PS3.getButtonClick(CROSS)){
      x=0;
      digitalWrite(mpd, HIGH);
      analogWrite(mpp, 80);
      Serial.println(count1);
    }
  x=2;
    analogWrite(mpp, 0);
   
}
void motorR() {
  while(count1<=120 && !PS3.getButtonClick(CROSS)){
    x=0; 
    digitalWrite(mpd, HIGH);
    analogWrite(mpp, 120);
  }
    analogWrite(mpp, 0);
   x=2;
}
/*------------------------------------------Gripper Movement------------------------------------------*/
void moorL() {
  if (PS3.getButtonPress(L1)) {
    x=1;
    digitalWrite(mpd, LOW);
    analogWrite(mpp, 80);
    Serial.println(count1);
  }
  x=2;
//    count1=0;
}
void moorR() {
  if (PS3.getButtonPress(R1)) {
    x=0; 
    digitalWrite(mpd, HIGH);
    analogWrite(mpp, 80);
    Serial.println(count1);
  }
  x= 2;
//    count1=0;
}
   
