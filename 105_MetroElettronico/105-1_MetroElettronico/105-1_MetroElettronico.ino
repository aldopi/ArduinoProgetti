//      progetto:  105 Metro Elettronico
//          file:  105-1_Metroelettronico
//   descrizione:  Metro elettronico da 40mm a 2mt
//       shields:  max7219 display 7segmenti8digit, hc-sr04
//      librerie:  LedControl
// versione-data:  v1.a - 27-12-2016
//        autore:  www.aldopi.it

#define lc_datain 12
#define lc_cs     11
#define lc_clock  10
#include "LedControl.h"
LedControl lc = LedControl(lc_datain, lc_clock, lc_cs, 1);
int t;

#define trigPin 8
#define echoPin 9

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 3);
  lc.clearDisplay(0);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  word nn = distanza();
  if (nn > 9999) lc.setDigit(0, 5, (nn / 1000) % 10, false);
  else lc.setRow(0, 5, 0);
  if (nn > 999) lc.setDigit(0, 4, (nn / 1000) % 10, false);
  else lc.setRow(0, 4, 0);
  if (nn > 99) lc.setDigit(0, 3, (nn / 100) % 10, false);
  else lc.setRow(0, 3, 0);
  if (nn > 9) lc.setDigit(0, 2, (nn / 10) % 10, false);
  else lc.setRow(0, 2, 0);
  lc.setDigit(0, 1, (nn / 1) % 10, false);
  t = 600;
  if (nn < 50) t = 200;
  if (nn < 100) t = 400;
  if (nn<300) digitalWrite(13, 1);
  delay(100);
  digitalWrite(13, 0);
  delay(t);
}

word distanza() {
  long duration;
  float distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 2.91;
  if (distance < 40) {
    return 9999;
  } else {
    return distance;
  }
}
//   EOF














