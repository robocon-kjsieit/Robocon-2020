void chalechalo() {
  if (ly < 117 && lx == 127) {        //forward function cross
    Serial.print("lx=");
    Serial.print("  ");
    Serial.print(lx);
    Serial.print("  ");
    Serial.print("ly=");
    Serial.print("  ");
    Serial.print(ly);
    Serial.println("  ");
//    forward(ly);
   back();
  }
  else if (ly > 137 && lx == 127) {  //backward cross
    Serial.print("lx=");
    Serial.print("  ");
    Serial.print(lx);
    Serial.print("  ");
    Serial.print("ly=");
    Serial.print("  ");
    Serial.print(ly);
    Serial.println("  ");
//    back(ly);
   forward();
  }
  else if (lx < 117 && ly == 127) { //left cross
    Serial.print("lx=");
    Serial.print("  ");
    Serial.print(lx);
    Serial.print("  ");
    Serial.print("ly=");
    Serial.print("  ");
    Serial.print(ly);
    Serial.println("  ");
    left();
//    right(lx);
  }
  else if (lx > 137 && ly == 127) {    //right cross
    Serial.print("lx=");
    Serial.print("  ");
    Serial.print(lx);
    Serial.print("  ");
    Serial.print("ly=");
    Serial.print("  ");
    Serial.print(ly);
    Serial.println("  ");
    right();
//left(lx);
  }
  else if (ry < 117 && rx == 127) { //forward plus
    Serial.print("rx=");
    Serial.print("  ");
    Serial.print(rx);
    Serial.print("  ");
    Serial.print("ry=");
    Serial.print("  ");
    Serial.print(ry);
    Serial.println("");
    forwardpl();
//    backpl(ry);
  }
  else if (ry > 137 && rx == 127) { //backward plus
    Serial.print("rx=");
    Serial.print("  ");
    Serial.print(rx);
    Serial.print("  ");
    Serial.print("ry=");
    Serial.print("  ");
    Serial.print(ry);
    Serial.println("");
    backpl();
//forwardpl(ry);
  }
  else if (rx < 117 && ry == 127) {      //left plus
    Serial.print("rx=");
    Serial.print("  ");
    Serial.print(rx);
    Serial.print("  ");
    Serial.print("ry=");
    Serial.print("  ");
    Serial.print(ry);
    Serial.println("");
    leftpl();
//rightpl(rx);
  }
  else if (rx > 137 && ry == 127) {   //right plus
    Serial.print("rx=");
    Serial.print("  ");
    Serial.print(rx);
    Serial.print("  ");
    Serial.print("ry=");
    Serial.print("  ");
    Serial.print(ry);
    Serial.println("");
    rightpl();
//    leftpl(rx);
  }
  else  if (l2 > 0 && r2 == 0) {                     //clk rotation
    Serial.print("L2=");
    Serial.print("  ");
    Serial.print(l2);
    Serial.print("  ");
    Serial.print("R2=");
    Serial.print("  ");
    Serial.print(r2);
    Serial.println("");
    clockwise(l2);
  }
  else if (r2 > 0 && l2 == 0) {             //aclk rotation
    Serial.print("L2=");
    Serial.print("  ");
    Serial.print(l2);
    Serial.print("  ");
    Serial.print("R2=");
    Serial.print("  ");
    Serial.print(r2);
    Serial.println("");
    aclockwise(r2);
  }
  else if (lx == 127 && ly == 127 && rx == 127 && ry == 127 && l2 == 0 && r2 == 0) {   //stop
    stopr();
  }
  else {
    stopr();
  }
}
void ghumo() {

  if (l2 > 0 && r2 == 0) {                     //clk rotation
    Serial.print("L2=");
    Serial.print("  ");
    Serial.print(l2);
    Serial.print("  ");
    Serial.print("R2=");
    Serial.print("  ");
    Serial.print(r2);
    Serial.println("");
    clockwise(l2);
  }
  else if (r2 > 0 && l2 == 0) {             //aclk rotation
    Serial.print("L2=");
    Serial.print("  ");
    Serial.print(l2);
    Serial.print("  ");
    Serial.print("R2=");
    Serial.print("  ");
    Serial.print(r2);
    Serial.println("");
    aclockwise(r2);
  }
  else if (l2 == 0 && r2 == 0) {                                //stop
    stopr();
  }
}
