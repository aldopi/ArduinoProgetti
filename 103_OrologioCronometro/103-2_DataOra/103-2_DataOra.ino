//      progetto:  103 Orologio Data e Cronometro
//          file:  103-1_Orologio
//   descrizione:  visualizza ora, minuti, secondi
//       shields:  max7219 + 8 x display 7 segmenti
//      librerie:  LedControl
// versione-data:  v1.a - 27-12-2016
//        autore:  www.aldopi.it

#define clk 10
#define cs 11
#define datain 12
#include "LedControl.h"
LedControl led = LedControl(datain, clk, cs, 1);

byte ora     = 18;  // ora start
byte minuti  = 05;  // minuti start
byte secondi = 00;  // secondi start

unsigned long timer = 0;

void setup() {
  led.shutdown(0, false);
  led.setIntensity(0, 3);
  led.clearDisplay(0);
  timer = millis();
}

void loop() {
  int i = millis() - timer;
  if (i > 999) {
    timer = millis();
    incremento();
    visualizzo_ora();
  }
}

void incremento() {
  secondi ++;
  if (secondi == 60) {
    secondi = 0;
    minuti++;
    if (minuti == 60) {
      minuti = 0;
      ora++;
      if (ora == 24)
        ora = 0;
    }
  }
}

void visualizzo_ora() {
  if (secondi % 2)   {
    led.setRow(0, 5, 1);
    led.setRow(0, 2, 1);
  }  else {
    led.setRow(0, 5, 0);
    led.setRow(0, 2, 0);
  }
  //  ora
  if (((ora / 10) % 10) == 0) led.setRow(0, 7, 0);
  else led.setDigit(0, 7, (ora / 10) % 10, false);
  led.setDigit(0, 6, ora % 10, false);
  //  minuti
  if (((minuti / 10) % 10) == 0) led.setRow(0, 4, 0);
  else led.setDigit(0, 4, (minuti / 10) % 10, false);
  led.setDigit(0, 3, minuti % 10, false);
  //  secondi
  if (((secondi / 10) % 10) == 0) led.setRow(0, 1, 0);
  else  led.setDigit(0, 1, (secondi / 10) % 10, false);
  led.setDigit(0, 0, secondi % 10, false);
}

// EOF
