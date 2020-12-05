/*-----------------------------------Grabbing and picking Task using encoders--------------------------*/
void motorL() {
   a = a + 1;
  if (a == 1) {
    digitalWrite(pakkad1, HIGH);
    Serial.println("Pakadla");
  }
  delay(300);
  while(v>=-4 && !PS3.getButtonClick(CROSS)){ 
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
  while(v<=21 && !PS3.getButtonClick(CROSS)){
      digitalWrite(mpd, HIGH);
      analogWrite(mpp, 80);
      Serial.println(count1);
    }
    analogWrite(mpp, 0);
   
}
void motorR() {
  while(count1<=22 && !PS3.getButtonClick(CROSS)){
    digitalWrite(mpd, HIGH);
    analogWrite(mpp, 120);
  }
    analogWrite(mpp, 0);
}
/*------------------------------------------Gripper Movement------------------------------------------*/
void moorL() {
  if (PS3.getButtonPress(L1)) {
    digitalWrite(mpd, LOW);
    analogWrite(mpp, 80);
    Serial.print(count1);
    Serial.print("  ");
    Serial.println(v);  }
}
void moorR() {
  if (PS3.getButtonPress(R1)) { 
    digitalWrite(mpd, HIGH);
    analogWrite(mpp, 80);
    Serial.print(count1);
    Serial.print("  ");
    Serial.println(v);
  }
}
   
