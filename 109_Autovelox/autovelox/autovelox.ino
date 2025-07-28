/*******************************************
      progetto: corso BASE Arduino
   descrizione: contatore da 0 a 10000
        autore: www.AldoPi.it
          data: 2 ototbre 2019
      versione: 1.0
       shields: max7219 + 8 x display 7 segmenti
 *******************************************
*/

#include "LedControl.h"
#define lc_datain 12
#define lc_cs     11
#define lc_clock  10

LedControl lc = LedControl(lc_datain, lc_clock, lc_cs, 1);
/*  pin 12 is connected to the DataIn
    pin 11 is connected to the CLK
    pin 10 is connected to LOAD
    We have only a single MAX72XX.
    LedControl lc=LedControl(datain,clk,cs,nr);     */

int y = 0;
unsigned long tempo;
float velocita;


void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 5);
  lc.clearDisplay(0);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  numero(99);
}

void loop() {
  while (digitalRead(2) > 0)  {};
  tempo = millis();
  digitalWrite(13, 1);
  while (digitalRead(3) > 0) {};
  velocita  = 105.0 / (millis() - tempo) * 10.0;
  digitalWrite(13, 0);
  // velocità = d/t     mm/msec=m/sec
  // m/s *3,6 = km/h
  numero(velocita);
}


void numero(int y) {
  lc.clearDisplay(0);
  if (y > 99) lc.setDigit(0, 2, (y / 100) % 10, false);
  else lc.setRow(0, 2, 0);
  if (y > 9) lc.setDigit(0, 1, (y / 10) % 10, true);
  else lc.setRow(0, 1, 1);
  lc.setDigit(0, 0, y % 10, false);

  y =  36 * y / 10;
  if (y > 999) lc.setDigit(0, 7, (y / 1000) % 10, false);
  else lc.setRow(0, 7, 0);
  if (y > 99) lc.setDigit(0, 6, (y / 100) % 10, false);
  else lc.setRow(0, 6, 0);
  if (y > 9) lc.setDigit(0, 5, (y / 10) % 10, true);
  else lc.setRow(0, 5, 1);
  lc.setDigit(0, 4, y % 10, false);
  delay(100);
}

