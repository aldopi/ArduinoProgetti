//      progetto:  101 Albero di natale
//          file:  101-1_TestLed
//   descrizione:  test di verifica collegamenti ai leds
//       shields:  basetta con 17 leds
//      librerie:  none
// versione-data:  v1.b - 18-09-2022
//        autore:  www.aldopi.it
//          note:  pin impiegati dal 2 al 18 compresi

int led;

void setup() {
  for (led = 2; led < 20; led++) 
    pinMode(led, OUTPUT);
}

void loop() {
  for (led = 2; led < 20; led++) {
    digitalWrite(led, HIGH);
    delay(250);
    digitalWrite(led, LOW);
    delay(250);
  }
}

//   EOF