//      progetto:  103 Orologio Data e Cronometro
//          file:  103-3_ContoRovescia
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

unsigned int conteggio = 1000;
int stato = 0;
unsigned long tempo = 0;

void setup() {
  pinMode(PIN_START, INPUT_PULLUP);
  pinMode(PIN_CLEAR, INPUT_PULLUP);
  led.shutdown(0, false);
  led.setIntensity(0, 5);
  led.clearDisplay(0);
  tempo = millis();
  display();
}

void loop() {
  if (digitalRead(PIN_CLEAR) == 0) {
    conteggio = 1000;
    stato = 0;
    display();
    delay(200);  //antirimbalzo
  }
  if (digitalRead(PIN_START) == 0) {
    if (conteggio > 0) {
      if (stato == 0) {
        stato = 1;  //run
      } else {
        stato = 0;  // stop
      }
    }
    display();
    delay(200);  // antirimbalzo
  }
  if (millis() - tempo > 1000) {  // ogni secondo
    decrementa();
    display();
    tempo = millis();
  }
}

void decrementa() {
  if (stato > 0 and conteggio > 0) {
    conteggio--;
  }
}

void display() {
  if (stato > 0) {
    led.setDigit(0, 7, 1, false);
  } else {
    led.setDigit(0, 7, 0, false);
  }
  led.setDigit(0, 5, (conteggio / 1000) % 10, false);
  led.setDigit(0, 4, (conteggio / 100) % 10, false);
  led.setDigit(0, 3, (conteggio / 10) % 10, false);
  led.setDigit(0, 2, (conteggio) % 10, false);
}

// EOF
