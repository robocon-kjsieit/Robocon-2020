void pitchingMotors(){                              //phrkulal on off
  d = d + 1;
  if (d == 1) {
    motor.setSpeed(255);
//    digitalWrite(pitmd1,HIGH);
//    analogWrite(pitmp1,255);
//    digitalWrite(pitmd2,HIGH);
//    analogWrite(pitmp2,255);
    Serial.println("Bademotors on");
  }
  else if (d == 2) {
    motor.setSpeed(0);
//    analogWrite(pitmp1,0);
//    analogWrite(pitmp2,0);
    d = 0;
    Serial.println("Bademotors off");
  }
}
void stopr() {
  analogWrite(mp1, 0);
  analogWrite(mp2, 0);
  analogWrite(mp3, 0);
  analogWrite(mp4, 0);
  //Serial.println("stopped");
}
