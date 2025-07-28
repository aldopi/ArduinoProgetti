//      progetto:  101 Albero di Natale
//          file:  101-6_Full
//   descrizione:  insieme di giochi di luce
//       shields:  basetta con 17 leds
//      librerie:  none
// versione-data:  v1.0 - 01-10-2022
//        autore:  www.aldopi.it
//          note:  pin impiegati dal 2 al 18 compresi

int led;
 
void setup() {
  for (int led = 2; led < 19; led++) 
    pinMode(led, OUTPUT);
}

#define tempoattesa 50
#define ritardo 6
void loop() {
  destrasinistra(tempoattesa*ritardo, 8000);
  dentrofuori(tempoattesa*ritardo, 5000);
  unoallavolta(tempoattesa*ritardo, 10000);
  bassoalto(tempoattesa*ritardo, 10000);
  acaso(ritardo, 4000);
  unoallavolta(tempoattesa*2, 10000);
  acaso(ritardo, 4000);
  bassoalto(tempoattesa*4, 10000);
  destrasinistra(tempoattesa*ritardo, 8000);
  dentrofuori(tempoattesa*ritardo, 5000);
  acaso(10, 4000);
  //
}

void acaso(int pausa, unsigned int durata) {
  unsigned long tempo = millis();
  while (millis() < tempo + durata) {
    int led = random(2, 19);
    digitalWrite(led, HIGH);
    delay(pausa);
    digitalWrite(led, LOW);
    delay(pausa);
  }
}

void bassoalto(int pausa, unsigned int durata) {
  unsigned long tempo = millis();
  while (millis() < tempo + durata) {
    for (int led = 0; led < 16; led = led + 4) {
      digitalWrite(led + 2, HIGH);
      digitalWrite(led + 3, HIGH);
      digitalWrite(led + 4, HIGH);
      digitalWrite(led + 5, HIGH);
      delay(pausa);
      digitalWrite(led + 2, LOW);
      digitalWrite(led + 3, LOW);
      digitalWrite(led + 4, LOW);
      digitalWrite(led + 5, LOW);
    }
    digitalWrite(18, HIGH);
    delay(pausa);
    digitalWrite(18, LOW);
  }
  off();
}

void unoallavolta(int pausa, unsigned int durata) {
  unsigned long tempo = millis();
  while (millis() < tempo + durata) {
    for (int led = 0; led < 17; led++) {
      digitalWrite(led + 2, HIGH);
      delay(pausa);
      digitalWrite(led + 2, LOW);
    }
  }
}

void destrasinistra(int pausa, unsigned int durata) {
  unsigned long tempo = millis();
  while (millis() < tempo + durata) {
    digitalWrite(2, LOW);  // gialli
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);  // verdi
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH); // rossi
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    digitalWrite(14, HIGH);  // BLU
    digitalWrite(15, HIGH);
    digitalWrite(16, LOW);
    digitalWrite(17, LOW);
    digitalWrite(18, LOW);  // bianco
    delay(pausa);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
    digitalWrite(14, LOW);
    digitalWrite(15, LOW);
    digitalWrite(16, HIGH);
    digitalWrite(17, HIGH);
    digitalWrite(18, LOW);
    delay(pausa);
  }
  off();
}
void dentrofuori(int pausa, unsigned int durata) {
  unsigned long tempo = millis();
  while (millis() < tempo + durata) {
    digitalWrite(2, LOW);  // gialli
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);  // verti
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
  off();
}

void off() {
  for (int i = 2; i < 19; i++) digitalWrite(i, LOW);

}

//  EOF
