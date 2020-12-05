void back() {
  // FORWARD IS FROM 1 AND 4 AGAINST MECHANISM
  digitalWrite(md1, HIGH);                   //HIGH  = CLOCK   MOTOR 1
  digitalWrite(md2, HIGH);                  //HIGH = CLOCK   MOTOR 2
  digitalWrite(md3, LOW);                   //LOW  = CLOCK   MOTOR 3
  digitalWrite(md4, LOW);                  //LOW = CLOCK   MOTOR 4
  analogWrite(mp1, spd);
  analogWrite(mp2, spd);
  analogWrite(mp3, spd);
  analogWrite(mp4, spd);
  Serial.println("forward");
}
void forward() {
  digitalWrite(md1, LOW);
  digitalWrite(md2, LOW);
  digitalWrite(md3, HIGH);
  digitalWrite(md4, HIGH);
  analogWrite(mp1, spd);
  analogWrite(mp2, spd);
  analogWrite(mp3, spd);
  analogWrite(mp4, spd);
  Serial.println("Backward");
}
void left() {
  digitalWrite(md1, HIGH);
  digitalWrite(md2, LOW);
  digitalWrite(md3, LOW);
  digitalWrite(md4, HIGH);
  analogWrite(mp1, spd);
  analogWrite(mp2, spd);
  analogWrite(mp3, spd);
  analogWrite(mp4, spd);
  Serial.println("left");
}
void right() {
  digitalWrite(md1, LOW);
  digitalWrite(md2, HIGH);
  digitalWrite(md3, HIGH);
  digitalWrite(md4, LOW);
  analogWrite(mp1, spd);
  analogWrite(mp2, spd);
  analogWrite(mp3, spd);
  analogWrite(mp4, spd);
  Serial.println("right");
}
