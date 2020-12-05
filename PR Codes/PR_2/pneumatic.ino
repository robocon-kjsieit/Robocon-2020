void pakkad() {
  a = a + 1;
  if (a == 1) {
    digitalWrite(pakkad1, HIGH);
    Serial.println("Pakadla");
  }
  else if (a == 2) {
    digitalWrite(pakkad1, LOW);
    Serial.println("Sodla");
    a = 0;
  }
}
void throwing() {
  b = b + 1;
  if (b == 1) {
    Serial.println("Khali ye");
    digitalWrite(phek, HIGH);
  }
  else if (b == 2){
    digitalWrite(phek, LOW);
    Serial.println("Ghal motor madhye");
    b = 0;
  }
}
