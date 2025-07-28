//      progetto:  101 Albero di Natale
//          file:  101-3_4x4
//   descrizione:  accendiamo di led a gruppi di 4
//       shields:  basetta con 17 leds
//      librerie:  none
// versione-data:  v1.0 - 01-10-2022
//        autore:  www.aldopi.it
//          note:  pin impiegati dal 2 al 18 compresi

#define pausa 100
int led;
 
void setup() {
  for (int led = 2; led < 19; led++) 
    pinMode(led, OUTPUT);
}

void loop() {
  for (led = 2; led < 16; led = led + 4) {
    if (led==9) led++;         // escludi il bianco
    digitalWrite(led, HIGH);
    digitalWrite(led + 1, HIGH);
    digitalWrite(led + 2, HIGH);
    digitalWrite(led + 3, HIGH);
    delay(pausa);
    digitalWrite(led, LOW);
    digitalWrite(led + 1, LOW);
    digitalWrite(led + 2, LOW);
    digitalWrite(led + 3, LOW);
  }
  digitalWrite(9, HIGH);
  delay(pausa);
  digitalWrite(9, LOW);
}

//  EOF