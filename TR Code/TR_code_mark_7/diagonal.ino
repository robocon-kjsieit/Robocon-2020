/**********************FORWARD RIGHT******************************************/
void Fright()
{
  analogWrite(pm1, 0);
  digitalWrite(dm2, HIGH);
  analogWrite(pm2, 255);
  analogWrite(pm3, 0);
  digitalWrite(dm4, HIGH);
  analogWrite(pm4, 255);
}
/**********************FORWARD LEFT******************************************/
void Fleft()
{
  analogWrite(pm1, 255);
  digitalWrite(dm1, HIGH);
  analogWrite(pm2, 0);
  digitalWrite(dm3, HIGH);
  analogWrite(pm3, 255);
  analogWrite(pm4, 0);
}
/********************BACKWARD RIGHT********************************************/
void Rright()
{
  analogWrite(pm1, 0);
  digitalWrite(dm2, LOW);
  analogWrite(pm2, 255);
  analogWrite(pm3, 0);
  digitalWrite(dm4, LOW);
  analogWrite(pm4, 255);
}
/*********************BACKWARD LEFT*******************************************/
void Rleft()
{
  digitalWrite(dm1, LOW);
  analogWrite(pm1, 255);
  analogWrite(pm2, 0);
  digitalWrite(dm3, LOW);
  analogWrite(pm3, 255);
  analogWrite(pm4, 0);
}
