void allstop() {
  digitalWrite(pakkad1, LOW);
  digitalWrite(phek, LOW);
  analogWrite(mp1, 0);
  analogWrite(mp2, 0);
  analogWrite(mp3, 0);
  analogWrite(mp4, 0);
  motor.setSpeed(0);
  a = 0;
  b = 0;
  c = 0;
  d = 0;
  e = 0;
  Serial.println("everything is stop");
  if(count1>0){
    while(count1>3 && !PS3.getButtonClick(CROSS)){
      x=1;
      digitalWrite(mpd, LOW);
      analogWrite(mpp, 80);
      Serial.println(count1);
      
    }
  }
  else if(count1<0){
    while(count1<-3 && !PS3.getButtonClick(CROSS)){
      x=0;
      digitalWrite(mpd, HIGH);
      analogWrite(mpp, 80);
      Serial.println(count1);
    }
  }
  else{
    analogWrite(mpp, 0);  
  }
  analogWrite(mpp, 0);
}
