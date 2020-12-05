void leftpl() {
  digitalWrite(md2, LOW);
  digitalWrite(md4, HIGH);
  analogWrite(mp1, 0);
  analogWrite(mp2, spd);
  analogWrite(mp3, 0);
  analogWrite(mp4, spd);
  Serial.println("rightpl");
}
void rightpl() {
  digitalWrite(md2, HIGH);
  digitalWrite(md4, LOW);
  analogWrite(mp1, 0);
  analogWrite(mp2, spd);
  analogWrite(mp3, 0);
  analogWrite(mp4, spd);
  Serial.println("leftpl");
}
void backpl() {
  digitalWrite(md1, LOW);
  digitalWrite(md3, HIGH);
  analogWrite(mp1, spd);
  analogWrite(mp2, 0);
  analogWrite(mp3, spd);
  analogWrite(mp4, 0);
  Serial.println("forwardpl");
}
void forwardpl() {
  digitalWrite(md1, HIGH);
  digitalWrite(md3, LOW);
  analogWrite(mp1, spd);
  analogWrite(mp2, 0);
  analogWrite(mp3, spd);
  analogWrite(mp4, 0);
  Serial.println("backpl");
}
