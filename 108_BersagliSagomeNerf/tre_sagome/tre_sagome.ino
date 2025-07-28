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
  delay(5000);
}

void loop2() {
  mot1.write(alto);
  delay(2500);
  mot1.write(basso);
  delay(4500);
}



void loop() {
  delay(1000 * random(4, 11));  // tempo di attesa casuale da 4 a 10 secondi
  motore = random(1, 4);        // numero casuale da 1 a 3 (4 escluso)
  if (motore == 1 ) {
    mot1.attach(motore1);         // attivo motore 2 sul pin 10
    mot1.write(alto);           // sagoma alta
    delay(attesa);
    mot1.write(basso);          // sagoma bassa

  } else if (motore == 2) {
    mot1.attach(motore2);         // attivo motore 2 sul pin 10
    mot1.write(alto);
    delay(attesa);
    mot1.write(basso);

  } else if (motore == 3) {
    mot1.attach(motore3);         // attivo motore 2 sul pin 10
    mot1.write(alto);
    delay(attesa);
    mot1.write(basso);
  }
}
