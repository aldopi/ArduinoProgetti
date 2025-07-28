//      progetto:  101 Albero di Natale
//          file:  101-4_AccesiSpenti
//   descrizione:  accendiamo uno ad uno, poi, li spegnamo uno ad uno
//       shields:  basetta con 17 leds
//      librerie:  none
// versione-data:  v1.0 - 01-10-2022
//        autore:  www.aldopi.it
//          note:  pin impiegati dal 2 al 18 compresi

#define pausa 100
int led;

void setup() {
  for (led = 2; led < 19; led++)
    pinMode(led, OUTPUT);
}

void loop() {
  for (led = 2; led < 19; led++) {
    digitalWrite(led, HIGH);
    delay(pausa);
  }
  for (led = 2; led < 19; led++) {
    digitalWrite(led, LOW);
    delay(pausa);
  }
  delay(pausa);
}

//  EOF