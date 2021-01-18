void allstop() {
  digitalWrite(pakkad1, LOW);
  digitalWrite(phek, LOW);
  analogWrite(mp1, 0);
  analogWrite(mp2, 0);
  analogWrite(mp3, 0);
  analogWrite(mp4, 0);
  motor.setSpeed(0);
  digitalWrite(led,LOW);
  digitalWrite(pitmp,0);
  a = 0;
  b = 0;
  c = 0;
  d = 0;
  e = 0;
  x=0;
  Serial.println("everything is stop");
  analogWrite(mpp, 0);
}
