/***************************FORWARD*************************************/
void forward()
{
  if (ry < 127 && ly == 0 && PS3.getButtonPress(L2))      //if both joystics pushes
  {
    digitalWrite(dm1, HIGH);
    analogWrite(pm1, 170);
    digitalWrite(dm2, LOW);
    analogWrite(pm2, 170);
    digitalWrite(dm3, LOW);
    analogWrite(pm3, 170);
    digitalWrite(dm4, HIGH);
    analogWrite(pm4, 170);
  }
  else if (ry < 127 && ly == 0 && PS3.getButtonPress(R2)) //if both joystics pushes
  {
    digitalWrite(dm1, LOW);
    analogWrite(pm1, 170);
    digitalWrite(dm2, HIGH);
    analogWrite(pm2, 170);
    digitalWrite(dm3, HIGH);
    analogWrite(pm3, 170);
    digitalWrite(dm4, LOW);
    analogWrite(pm4, 170);
  }
  else if (ry < 127 && ly == 0)                         //if both joystics pushes
  {
    Pwm = map(ry, 127, 0, 200, 255);
    digitalWrite(dm1, HIGH);
    analogWrite(pm1, Pwm);
    digitalWrite(dm2, HIGH);
    analogWrite(pm2, Pwm);
    digitalWrite(dm3, HIGH);
    analogWrite(pm3, Pwm);
    digitalWrite(dm4, HIGH);
    analogWrite(pm4, Pwm);
  }
  else if ((ry < 127 || ly < 127 ) && PS3.getButtonPress(L2)) //rotate anti-clockwise in forward motion
  {
    digitalWrite(dm1, HIGH);
    analogWrite(pm1, 100);
    digitalWrite(dm2, LOW);
    analogWrite(pm2, 100);
    digitalWrite(dm3, LOW);
    analogWrite(pm3, 100);
    digitalWrite(dm4, HIGH);
    analogWrite(pm4, 100);
  }
  else if ((ry < 127 || ly < 127 ) && PS3.getButtonPress(R2)) //rotate clockwise in forward motion
  {
    digitalWrite(dm1, LOW);
    analogWrite(pm1, 100);
    digitalWrite(dm2, HIGH);
    analogWrite(pm2, 100);
    digitalWrite(dm3, HIGH);
    analogWrite(pm3, 100);
    digitalWrite(dm4, LOW);
    analogWrite(pm4, 100);
  }
  else if (ly < 127)                                      //if only right joystic push
  {
    Pwm = map(ly, 127, 0, 0, 127);
    digitalWrite(dm1, HIGH);
    analogWrite(pm1, Pwm);
    digitalWrite(dm2, HIGH);
    analogWrite(pm2, Pwm);
    digitalWrite(dm3, HIGH);
    analogWrite(pm3, Pwm);
    digitalWrite(dm4, HIGH);
    analogWrite(pm4, Pwm);
  }
  else                                                    //if only left joystic push
  {
    Pwm = map(ry, 127, 0, 150, 200);
    digitalWrite(dm1, HIGH);
    analogWrite(pm1, Pwm);
    digitalWrite(dm2, HIGH);
    analogWrite(pm2, Pwm);
    digitalWrite(dm3, HIGH);
    analogWrite(pm3, Pwm);
    digitalWrite(dm4, HIGH);
    analogWrite(pm4, Pwm);
  }
}
/******************************BACKWARD**********************************/
void backward()
{
  if (ry > 127 && ly == 255 && PS3.getButtonPress(L2))     //if both joystics pushes & L2 press
  {
    digitalWrite(dm1, HIGH);
    analogWrite(pm1, 170);
    digitalWrite(dm2, LOW);
    analogWrite(pm2, 170);
    digitalWrite(dm3, LOW);
    analogWrite(pm3, 170);
    digitalWrite(dm4, HIGH);
    analogWrite(pm4, 170);
  }
  else if (ry > 127 && ly == 255 && PS3.getButtonPress(R2)) //if both joystics pushes & R2 press
  {
    digitalWrite(dm1, LOW);
    analogWrite(pm1, 170);
    digitalWrite(dm2, HIGH);
    analogWrite(pm2, 170);
    digitalWrite(dm3, HIGH);
    analogWrite(pm3, 170);
    digitalWrite(dm4, LOW);
    analogWrite(pm4, 170);
  }
  else if (ry > 127 && ly == 255)                         //if both joystics pushes
  {
    Pwm = map(ry, 127, 255, 200, 255);
    digitalWrite(dm1, LOW);
    analogWrite(pm1, Pwm);
    digitalWrite(dm2, LOW);
    analogWrite(pm2, Pwm);
    digitalWrite(dm3, LOW);
    analogWrite(pm3, Pwm);
    digitalWrite(dm4, LOW);
    analogWrite(pm4, Pwm);
  }
  else if ((ry > 127 || ly > 127 ) && PS3.getButtonPress(L2)) //rotate anti-clockwise in backward motion
  {
    digitalWrite(dm1, HIGH);
    analogWrite(pm1, 100);
    digitalWrite(dm2, LOW);
    analogWrite(pm2, 100);
    digitalWrite(dm3, LOW);
    analogWrite(pm3, 100);
    digitalWrite(dm4, HIGH);
    analogWrite(pm4, 100);
  }
  else if ((ry > 127 || ly > 127 ) && PS3.getButtonPress(R2)) //rotate clockwise in backward motion
  {
    digitalWrite(dm1, LOW);
    analogWrite(pm1, 100);
    digitalWrite(dm2, HIGH);
    analogWrite(pm2, 100);
    digitalWrite(dm3, HIGH);
    analogWrite(pm3, 100);
    digitalWrite(dm4, LOW);
    analogWrite(pm4, 100);
  }
  else if (ly > 127)                                    //if only right joystic push
  {
    Pwm = map(ly, 127, 255, 0, 127);
    digitalWrite(dm1, LOW);
    analogWrite(pm1, Pwm);
    digitalWrite(dm2, LOW);
    analogWrite(pm2, Pwm);
    digitalWrite(dm3, LOW);
    analogWrite(pm3, Pwm);
    digitalWrite(dm4, LOW);
    analogWrite(pm4, Pwm);
  }
  else                                                //if only right joystic push
  {
    Pwm = map(ry, 127, 255, 150, 200);
    digitalWrite(dm1, LOW);
    analogWrite(pm1, Pwm);
    digitalWrite(dm2, LOW);
    analogWrite(pm2, Pwm);
    digitalWrite(dm3, LOW);
    analogWrite(pm3, Pwm);
    digitalWrite(dm4, LOW);
    analogWrite(pm4, Pwm);
  }
}
/****************************LEFT************************************/
void left()
{
  if (rx < 127 && lx == 0 && PS3.getButtonPress(L2))    //if both joystics pushes & L2 PRESS
  {
    digitalWrite(dm1, HIGH);
    analogWrite(pm1, 170);
    digitalWrite(dm2, LOW);
    analogWrite(pm2, 170);
    digitalWrite(dm3, LOW);
    analogWrite(pm3, 170);
    digitalWrite(dm4, HIGH);
    analogWrite(pm4, 170);
  }
  else if (rx < 127 && lx == 0 && PS3.getButtonPress(R2)) //if both joystics pushes & R2 PRESS
  {
    digitalWrite(dm1, LOW);
    analogWrite(pm1, 170);
    digitalWrite(dm2, HIGH);
    analogWrite(pm2, 170);
    digitalWrite(dm3, HIGH);
    analogWrite(pm3, 170);
    digitalWrite(dm4, LOW);
    analogWrite(pm4, 170);
  }
  else if (rx < 127 && lx == 0)                         //if both joystics pushes
  {
    Pwm = map(rx, 127, 0, 200, 255);
    Serial.println("full left");
    digitalWrite(dm1, HIGH);
    analogWrite(pm1, Pwm);
    digitalWrite(dm2, LOW);
    analogWrite(pm2, Pwm);
    digitalWrite(dm3, HIGH);
    analogWrite(pm3, Pwm);
    digitalWrite(dm4, LOW);
    analogWrite(pm4, Pwm);
  }
  else if ((rx < 127 || lx < 127 ) && PS3.getButtonPress(L2))      //rotate anti-clockwise in left motion
  {
    digitalWrite(dm1, HIGH);
    analogWrite(pm1, 170);
    digitalWrite(dm2, LOW);
    analogWrite(pm2, 170);
    digitalWrite(dm3, LOW);
    analogWrite(pm3, 170);
    digitalWrite(dm4, HIGH);
    analogWrite(pm4, 170);
  }
  else if ((rx < 127 || lx < 127 ) && PS3.getButtonPress(R2))     //rotate clockwise in left motion
  {
    digitalWrite(dm1, LOW);
    analogWrite(pm1, 170);
    digitalWrite(dm2, HIGH);
    analogWrite(pm2, 170);
    digitalWrite(dm3, HIGH);
    analogWrite(pm3, 170);
    digitalWrite(dm4, LOW);
    analogWrite(pm4, 170);
  }
  else if (lx < 127)                                            //if only right joystic push
  {
    Pwm = map(lx, 127, 0, 0, 127);
    digitalWrite(dm1, HIGH);
    analogWrite(pm1, Pwm);
    digitalWrite(dm2, LOW);
    analogWrite(pm2, Pwm);
    digitalWrite(dm3, HIGH);
    analogWrite(pm3, Pwm);
    digitalWrite(dm4, LOW);
    analogWrite(pm4, Pwm);
  }
  else//if only left joystic push
  {
    Pwm = map(rx, 127, 0, 150, 200);
    digitalWrite(dm1, HIGH);
    analogWrite(pm1, Pwm);
    digitalWrite(dm2, LOW);
    analogWrite(pm2, Pwm);
    digitalWrite(dm3, HIGH);
    analogWrite(pm3, Pwm);
    digitalWrite(dm4, LOW);
    analogWrite(pm4, Pwm);
  }
}
/************************RIGHT****************************************/
void right()
{
  if (rx > 127 && lx == 255 && PS3.getButtonPress(L2))
  {
    digitalWrite(dm1, HIGH);
    analogWrite(pm1, 170);
    digitalWrite(dm2, LOW);
    analogWrite(pm2, 170);
    digitalWrite(dm3, LOW);
    analogWrite(pm3, 170);
    digitalWrite(dm4, HIGH);
    analogWrite(pm4, 170);
  }
  else if (rx > 127 && lx == 255 && PS3.getButtonPress(R2))
  {
    digitalWrite(dm1, LOW);
    analogWrite(pm1, 170);
    digitalWrite(dm2, HIGH);
    analogWrite(pm2, 170);
    digitalWrite(dm3, HIGH);
    analogWrite(pm3, 170);
    digitalWrite(dm4, LOW);
    analogWrite(pm4, 170);
  }
  else if (rx > 127 && lx == 255)           //if both joystics pushes
  {
    Serial.println("full right");
    Pwm = map(rx, 127, 255, 200, 255);
    digitalWrite(dm1, LOW);
    analogWrite(pm1, Pwm);
    digitalWrite(dm2, HIGH);
    analogWrite(pm2, Pwm);
    digitalWrite(dm3, LOW);
    analogWrite(pm3, Pwm);
    digitalWrite(dm4, HIGH);
    analogWrite(pm4, Pwm);
  }
  if ((rx > 127 || lx > 127 ) && PS3.getButtonPress(L2))     //rotate anti-clockwise in right motion
  {
    digitalWrite(dm1, HIGH);
    analogWrite(pm1, 170);
    digitalWrite(dm2, LOW);
    analogWrite(pm2, 170);
    digitalWrite(dm3, LOW);
    analogWrite(pm3, 170);
    digitalWrite(dm4, HIGH);
    analogWrite(pm4, 170);
  }
  else if ((rx > 127 || lx > 127 ) && PS3.getButtonPress(R2))   //rotate clockwise in right motion
  {
    digitalWrite(dm1, LOW);
    analogWrite(pm1, 170);
    digitalWrite(dm2, HIGH);
    analogWrite(pm2, 170);
    digitalWrite(dm3, HIGH);
    analogWrite(pm3, 170);
    digitalWrite(dm4, LOW);
    analogWrite(pm4, 170);
  }
  else if (lx > 127)                                            //if only right joystic push
  {
    Pwm = map(lx, 127, 255, 0, 127);
    digitalWrite(dm1, LOW);
    analogWrite(pm1, Pwm);
    digitalWrite(dm2, HIGH);
    analogWrite(pm2, Pwm);
    digitalWrite(dm3, LOW);
    analogWrite(pm3, Pwm);
    digitalWrite(dm4, HIGH);
    analogWrite(pm4, Pwm);
  }
  else                                                        //if only left joystic push
  {
    Pwm = map(rx, 127, 255, 150, 200);
    digitalWrite(dm1, LOW);
    analogWrite(pm1, Pwm);
    digitalWrite(dm2, HIGH);
    analogWrite(pm2, Pwm);
    digitalWrite(dm3, LOW);
    analogWrite(pm3, Pwm);
    digitalWrite(dm4, HIGH);
    analogWrite(pm4, Pwm);
  }
}
/************************ANTI CLOCKWISE ROTATE****************************************/
void unrotate()
{
  digitalWrite(dm1, HIGH);
  analogWrite(pm1, 80);
  digitalWrite(dm2, LOW);
  analogWrite(pm2, 80);
  digitalWrite(dm3, LOW);
  analogWrite(pm3, 80);
  digitalWrite(dm4, HIGH);
  analogWrite(pm4, 80);
}
/**********************CLOCKWISE ROTATE******************************************/
void crotate()
{
  digitalWrite(dm1, LOW);
  analogWrite(pm1, 80);
  digitalWrite(dm2, HIGH);
  analogWrite(pm2, 80);
  digitalWrite(dm3, HIGH);
  analogWrite(pm3, 80);
  digitalWrite(dm4, LOW);
  analogWrite(pm4, 80);
}
void unrotatefast()
{
  digitalWrite(dm1, HIGH);
  analogWrite(pm1, 150);
  digitalWrite(dm2, LOW);
  analogWrite(pm2, 150);
  digitalWrite(dm3, LOW);
  analogWrite(pm3, 150);
  digitalWrite(dm4, HIGH);
  analogWrite(pm4, 150);
}
void crotatefast()
{
  digitalWrite(dm1, LOW);
  analogWrite(pm1, 150);
  digitalWrite(dm2, HIGH);
  analogWrite(pm2, 150);
  digitalWrite(dm3, HIGH);
  analogWrite(pm3, 150);
  digitalWrite(dm4, LOW);
  analogWrite(pm4, 150);
}
/**********************RIGHT DRIFT******************************************/
void Rdrift()
{
  digitalWrite(dm1, LOW);
  analogWrite(pm1, 0);
  digitalWrite(dm2, HIGH);
  analogWrite(pm2, 255);
  digitalWrite(dm3, HIGH);
  analogWrite(pm3, 255);
  digitalWrite(dm4, LOW);
  analogWrite(pm4, 255);
}
/*********************LEFT DRIFT*******************************************/
void Ldrift()
{
  digitalWrite(dm1, HIGH);
  analogWrite(pm1, 255);
  digitalWrite(dm2, HIGH);
  analogWrite(pm2, 0);
  digitalWrite(dm3, LOW);
  analogWrite(pm3, 255);
  digitalWrite(dm4, HIGH);
  analogWrite(pm4, 255);
}
/****************************************************************/
