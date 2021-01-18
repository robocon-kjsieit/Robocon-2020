/*****************************NET PNEUMATIC***********************************/
void uppne()
{
  up++;
  if (up % 2 == 0)
  {
    digitalWrite(p1, HIGH);   //recieving pneumatic open
  }
  else
  {
    digitalWrite(p1, LOW);    //recieving pneumatic close
  }
}
/*****************************PUSHING PNEUMATIC***********************************/
void fronpne()
{
  fron++;
  if (fron % 2 == 0)
  {
    digitalWrite(p2, HIGH);   //pushing pneumatic open
  }
  else
  {
    digitalWrite(p2, LOW);    //pushing pneumatic close
  }
}
/******************************PLACE PNEUMATIC**********************************/
void placepne()
{
  place++;
  if (place % 2 == 0)
  {
    digitalWrite(p3, HIGH);    //placing pneumatic open
  }
  else
  {
    digitalWrite(p3, LOW);    //placing pneumatic close
  }
}
/******************************PLACE AND PUSH PNEUMATICS**********************************/
void bothp()
{
  both++;
  if (both % 2 == 0)
  {
    digitalWrite(p2, HIGH);    //pushing pneumatic open
    digitalWrite(p3, HIGH);    //placing pneumatic open
  }
  else
  {
    digitalWrite(p2, LOW);    //pushing pneumatic close
    digitalWrite(p3, LOW);    //placing pneumatic close
  }
}
/****************************************************************/
