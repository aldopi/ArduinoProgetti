//      progetto:  104 Temperatua ed umidità
//          file:  104-1_TemperaturaUmidita
//   descrizione:  visualizza temperatura ed umidità letta da sensore
//       shields:  max7219 + 8 x display 7 segmenti, DHT22 (dht11)
//      librerie:  LedControl, DHT
// versione-data:  v1.a - 11-11-2018
//        autore:  www.aldopi.it

#include "LedControl.h"
#define datain 12
#define cs     11
#define clk    10
LedControl lc = LedControl(datain, clk, cs, 1);

float temp = 0, umid = 0;

#include "DHT.h"
#define DHTPIN 2   // pinedino connesso DHT
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 2);
  lc.clearDisplay(0);
  delay(1000);
  lc.setRow(0, 4, B01100011);
  lc.setRow(0, 0, B00011100);
  dht.begin();
}

void loop() {
  temp = dht.readTemperature();
  umid = dht.readHumidity();
  float hic = dht.computeHeatIndex(temp, umid, false);
  visualizza_temperatura(temp * 10);
  visualizza_umidita(umid);
  delay(5000);
}

void visualizza_temperatura(int nn) {
  if (nn > 99) lc.setDigit(0, 7, (nn / 100) % 10, false);
  else lc.setRow(0, 7, 0);
  if (nn > 9) lc.setDigit(0, 6, (nn / 10) % 10, true);
  else lc.setRow(0, 6, 0);
  lc.setDigit(0, 5, (nn / 1) % 10, false);
}

void visualizza_umidita(int nn) {
  if (nn > 9) lc.setDigit(0, 2, (nn / 10) % 10, false);
  else lc.setRow(0, 2, 0);
  lc.setDigit(0, 1, (nn / 1) % 10, false);
}

// EOF
