void encoder1() {
  if (digitalRead(mpd)==HIGH) {
    count1++;
  }
  else if (digitalRead(mpd)==LOW) {
    count1--;
  }
  v=count1/10;
}
//void encoder2() {
//  if (digitalRead(md2) == HIGH) {
//    count2++;
//  }
//  else if (digitalRead(md2) == LOW) {
//    count2--;
//  }
//}
//void encoder3() {
//  if (digitalRead(md3) == HIGH) {
//    count3++;
//  }
//  else if (digitalRead(md3) == LOW) {
//    count3--;
//  }
//}
//void encoder4() {
//  if (digitalRead(md4) == HIGH) {
//    count4++;
//  }
//  else if (digitalRead(md4) == LOW) {
//    count4--;
//  }
//}
