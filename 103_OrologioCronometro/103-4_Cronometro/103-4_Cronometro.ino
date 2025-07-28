//      progetto:  103 Orologio Data e Cronometro
//          file:  103-4_Cronometro
//   descrizione:  visualizza ora, minuti, secondi
//       shields:  max7219 + 8 x display 7 segmenti + 2 pulsanti
//      librerie:  LedControl
// versione-data:  v1.a - 27-12-2016
//        autore:  www.aldopi.it

#define PIN_START 2  // pulsante di conteggio
#define PIN_CLEAR 3  // pulsante di azzerramento

#define lc_clock 10
#define lc_cs 11
#define lc_datain 12
#include "LedControl.h"
LedControl led = LedControl(lc_datain, lc_clock, lc_cs, 1);

byte ora = 0, minuti = 0, secondi = 0, centesimi = 0, i = 0;

void setup() {
  pinMode(PIN_START, INPUT_PULLUP);
  pinMode(PIN_CLEAR, INPUT_PULLUP);
  led.shutdown(0, false);
  led.setIntensity(0, 5);
  led.clearDisplay(0);
}

void loop() {
  delay(10);
  if (digitalRead(PIN_CLEAR) == 0) {
    centesimi = 0;
    secondi = 0;
    minuti = 0;
    ora = 0;
    display();
  }
  if (digitalRead(PIN_START) == 0)
    incrementa();
  display();
}

void incrementa() {
  centesimi++;
  if (centesimi > 99) {
    centesimi = 0;
    secondi++;
    if (secondi == 60) {
      secondi = 0;
      minuti++;
      if (minuti == 60) {
        minuti = 0;
        ora++;
        if (ora == 100)
          ora = 0;
      }
    }
  }
}

void display() {
  if (((ora / 100) % 10) == 0)
    led.setDigit(0, 7, 0, false);
  else
    led.setDigit(0, 7, (ora / 100) % 10, false);
  led.setDigit(0, 6, ora % 10, true);
  if (((minuti / 10) % 10) == 0)
    led.setDigit(0, 5, 0, false);
  else
    led.setDigit(0, 5, (minuti / 10) % 10, false);
  led.setDigit(0, 4, minuti % 10, true);
  if (((secondi / 10) % 10) == 0)
    led.setDigit(0, 3, 0, false);
  else
    led.setDigit(0, 3, (secondi / 10) % 10, false);
  led.setDigit(0, 2, secondi % 10, true);
  led.setDigit(0, 1, (centesimi / 10) % 10, false);
  led.setDigit(0, 0, centesimi % 10, false);
}

// EOF
