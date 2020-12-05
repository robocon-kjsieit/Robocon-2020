void forward() {
  // FORWARD IS FROM 1 AND 4 AGAINST MECHANISM
//  int m = ((x+127)/255)*spd;
//  m = map(x,127,0,0,220);
  digitalWrite(md1, HIGH);                   //HIGH  = CLOCK   MOTOR 1
  digitalWrite(md2, HIGH);                  //HIGH = CLOCK   MOTOR 2
  digitalWrite(md3, LOW);                   //LOW  = CLOCK   MOTOR 3
  digitalWrite(md4, HIGH);                  //HIGH = CLOCK   MOTOR 4
  analogWrite(mp1, m);
  analogWrite(mp2, m);
  analogWrite(mp3, m);
  analogWrite(mp4, m);
  Serial.println("forward");
}
void back() {
//  int m = (x/255)*spd;
//  m = map(x,127,255,0,220);
  digitalWrite(md1, LOW);
  digitalWrite(md2, LOW);
  digitalWrite(md3, HIGH);
  digitalWrite(md4, LOW);
  analogWrite(mp1, m);
  analogWrite(mp2, m);
  analogWrite(mp3, m);
  analogWrite(mp4, m);
  Serial.println("Backward");
}
void right() {
//  int m = ((x+127)/255)*spd;
//  m = map(m,127,0,0,220);
  digitalWrite(md1, LOW);
  digitalWrite(md2, HIGH);
  digitalWrite(md3, HIGH);
  digitalWrite(md4, HIGH);
  analogWrite(mp1, m);
  analogWrite(mp2, m);
  analogWrite(mp3, m);
  analogWrite(mp4, m);
  Serial.println("left");
}
void left() {
//  int m = (x/255)*spd;
//  m = map(x,127,255,0,220);
  digitalWrite(md1, HIGH);
  digitalWrite(md2, LOW);
  digitalWrite(md3, LOW);
  digitalWrite(md4, LOW);
  analogWrite(mp1, m);
  analogWrite(mp2, m);
  analogWrite(mp3, m);
  analogWrite(mp4, m);
  Serial.println("right");
}
