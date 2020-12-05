void clockwise() {
  digitalWrite(md1, HIGH);
  digitalWrite(md2, HIGH);
  digitalWrite(md3, HIGH);
  digitalWrite(md4, HIGH);
  analogWrite(mp1, spd);
  analogWrite(mp2, spd);
  analogWrite(mp3, spd);
  analogWrite(mp4, spd);
}
void aclockwise() {
  digitalWrite(md1, LOW);
  digitalWrite(md2, LOW);
  digitalWrite(md3, LOW);
  digitalWrite(md4, LOW);
  analogWrite(mp1, spd);
  analogWrite(mp2, spd);
  analogWrite(mp3, spd);
  analogWrite(mp4, spd);
}
