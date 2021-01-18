/************************STOP ALL MOTORS****************************************/
void stopm()
{
  Pwm = 0;
  analogWrite(pm1, 0);
  analogWrite(pm2, 0);
  analogWrite(pm3, 0);
  analogWrite(pm4, 0);
  motor.setSpeed(0);
}
/************************REST ALL VARIABLES ****************************************/
void allkill()
{
  Pwm = 0;
  up = -1;
  fron = -1;
  place = -1;
  both = -1;
  analogWrite(pm1, 0);
  analogWrite(pm2, 0);
  analogWrite(pm3, 0);
  analogWrite(pm4, 0);
  digitalWrite(p1, LOW);
  digitalWrite(p2, LOW);
  digitalWrite(p3, LOW);
  motor.setSpeed(0);
}
/****************************************************************/
