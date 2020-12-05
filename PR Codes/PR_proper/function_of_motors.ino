void pitchingMotors(){                              //phrkulal on off
  d = d + 1;
  if (d == 1) {
//    motor.setSpeed(125);
    digitalWrite(pitmd,HIGH);
    analogWrite(pitmp,vm);
//    digitalWrite(pitmd2,HIGH);
//    analogWrite(pitmp2,255);
    Serial.println("Bademotors on");
    digitalWrite(led,HIGH);
//    digitalWrite(47,LOW);
//    digitalWrite(25,LOW);
  }
  else if (d == 2) {
//    motor.setSpeed(0);
    analogWrite(pitmp,0);
//    analogWrite(pitmp,0);
    d = 0;
    Serial.println("Bademotors off");
    digitalWrite(led,LOW);
//    digitalWrite(47,HIGH);
//    digitalWrite(25,HIGH);
  }
}
void stopr() {
  analogWrite(mp1, 0);
  analogWrite(mp2, 0);
  analogWrite(mp3, 0);
  analogWrite(mp4, 0);
  //Serial.println("stopped");
}
