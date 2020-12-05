void leftpl() {
//  int m = (x/255)*spd;
//  m = map(x,127,255,0,220);
  digitalWrite(md2, LOW);
  digitalWrite(md4, LOW);
  analogWrite(mp1, 0);
  analogWrite(mp2, m);
  analogWrite(mp3, 0);
  analogWrite(mp4, m);
  Serial.println("rightpl");
}
void rightpl() {
//  int m = ((x+127)/127)*spd;
//  m = map(x,127,0,0,220);
  digitalWrite(md2, HIGH);
  digitalWrite(md4, HIGH);
  analogWrite(mp1, 0);
  analogWrite(mp2, m);
  analogWrite(mp3, 0);
  analogWrite(mp4, m);
  Serial.println("leftpl");
}
void forwardpl() {
//  int m = (x/255)*spd;
//  m = map(x,127,255,0,220);
  digitalWrite(md1, LOW);
  digitalWrite(md3, HIGH);
  analogWrite(mp1, m);
  analogWrite(mp2, 0);
  analogWrite(mp3, m);
  analogWrite(mp4, 0);
  Serial.println("forwardpl");
}
void backpl() {
//  int m = ((x+127)/255)*spd;
//  m = map(x,127,0,0,220);
  digitalWrite(md1, HIGH);
  digitalWrite(md3, LOW);
  analogWrite(mp1, m);
  analogWrite(mp2, 0);
  analogWrite(mp3, m);
  analogWrite(mp4, 0);
  Serial.println("backpl");
}
