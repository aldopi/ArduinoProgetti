//      progetto:  101 Albero di Natale
//          file:  101-5_Alternati
//   descrizione:  accendiamo due gruppi alternati
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
    digitalWrite(2, LOW);  // gialli
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);  // verdi
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH); // rossi
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    digitalWrite(14, HIGH);  // BLU
    digitalWrite(15, HIGH);
    digitalWrite(16, HIGH);
    digitalWrite(17, HIGH);
    digitalWrite(18, HIGH);
    delay(pausa);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(14, LOW);
    digitalWrite(15, LOW);
    digitalWrite(16, LOW);
    digitalWrite(17, LOW);
    digitalWrite(18, LOW);
    delay(pausa);
}

//EOF