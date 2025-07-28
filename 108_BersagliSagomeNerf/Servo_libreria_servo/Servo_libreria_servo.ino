/*******************************************
      progetto: Arduino Motori
   descrizione: controllo con tre servo motori i bersagli mobili
        autore: www.AldoPi.it
          data: 10-10-2015
      versione:
 *******************************************
*/


// -------------------------------  dichiarazioni globali
// ATTENZIONE non trascrivere quello che viene dopo // sono solo delle note

#define attesa 2500
#define alto     90
#define basso   170
#define motore1 5
#define motore2 6
#define motore3 10


#include <Servo.h>           // importo la libreria per la gestione dei motori
Servo mot1;                  // inizializzo variabile per il motore 1
Servo mot2;                  // inizializzo variabile per il motore 2
Servo mot3;                  // inizializzo variabile per il motore 3
int motore;

void setup() {
  mot1.attach(motore1);         // attivo motore 2 sul pin 10
  mot1.write(alto);          // sagoma bassa
  mot1.attach(motore2);         // attivo motore 2 sul pin 10
  mot1.write(alto);          // sagoma bassa
  mot1.attach(motore3);         // attivo motore 2 sul pin 10
  mot1.write(alto);          // sagoma bassa
  delay(2000);
  mot1.attach(motore1);          // attivo motore 1 sul pin 9
  mot1.write(basso);          // sagoma bassa
  mot1.attach(motore2);         // attivo motore 2 sul pin 10
  mot1.write(basso);          // sagoma bassa
  mot1.attach(motore3);         // attivo motore 2 sul pin 10
  mot1.write(basso);          // sagoma bassa
}


void loop() {
  delay(1000 * random(4, 11));  // tempo di attesa casuale da 4 a 10 secondi
  motore = random(1, 4);        // numero casuale da 1 a 3 (4 escluso)
  switch (motore) {
    case 1:
      mot1.attach(motore1);         // attivo motore 2 sul pin 10
      mot1.write(alto);           // sagoma alta
      delay(attesa);
      mot1.write(basso);          // sagoma bassa
      break;
    case 2:
      mot1.attach(motore2);         // attivo motore 2 sul pin 10
      mot1.write(alto);
      delay(attesa);
      mot1.write(basso);
      break;
    case 3:
      mot1.attach(motore3);         // attivo motore 2 sul pin 10
      mot1.write(alto);
      delay(attesa);
      mot1.write(basso);
  }
}
