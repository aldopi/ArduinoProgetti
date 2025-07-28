//      progetto:  101 Albero di Natale
//          file:  101-2_Flash
//   descrizione:  facciamo lampeggiare un led a caso
//       shields:  basetta con 17 leds
//      librerie:  none
// versione-data:  v1.0 - 01-10-2022
//        autore:  www.aldopi.it
//          note:  pin impiegati dal 2 al 18 compresi

#define pausa 100
int led=9;

void setup() {
  for (led = 2; led < 20; led++) 
    pinMode(led, OUTPUT);
}


void loop() {
    digitalWrite(led, HIGH);
    delay(pausa);
    digitalWrite(led, LOW);
    delay(250);
    led=random(2,19);
}

//  EOF