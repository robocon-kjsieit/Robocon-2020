void clockwise(int x) {
//  int m = (x/255)*spd1;
//  m = map(x,0,255,0,120);
  digitalWrite(md1, HIGH);
  digitalWrite(md2, HIGH);
  digitalWrite(md3, HIGH);
  digitalWrite(md4, LOW);
  analogWrite(mp1, m1);
  analogWrite(mp2, m1);
  analogWrite(mp3, m1);
  analogWrite(mp4, m1);
}
void aclockwise(int x) {
//  int m = (x/255)*spd1;
//  m = map(x,0,255,0,120);
  digitalWrite(md1, LOW);
  digitalWrite(md2, LOW);
  digitalWrite(md3, LOW);
  digitalWrite(md4, HIGH);
  analogWrite(mp1, m1);
  analogWrite(mp2, m1);
  analogWrite(mp3, m1);
  analogWrite(mp4, m1);
}
