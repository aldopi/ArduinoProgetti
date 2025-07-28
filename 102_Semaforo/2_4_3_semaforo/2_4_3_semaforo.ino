//     progetto: corso base - componenti
//  descrizione: realizzare un semaforo
//      shields: arduino uno, tre leds, tre resisstenze 220
//         data: v1.1 02-02-2020

#define ledrosso 12
#define ledgiallo 11
#define ledverde 10
#define pulsante 4

void setup() {
  pinMode(ledrosso, OUTPUT);
  pinMode(ledgiallo, OUTPUT);
  pinMode(ledverde, OUTPUT);
}

void loop() {
  // semaforo ROSSO
  digitalWrite(ledrosso, 1);
  digitalWrite(ledgiallo, 0);
  digitalWrite(ledverde, 0);
  delay(5000);
  // semaforo GIALLO
  digitalWrite(ledrosso, 0);
  digitalWrite(ledgiallo, 1);
  digitalWrite(ledverde, 0);
  delay(2000);
  // semaforo VERDE
  digitalWrite(ledrosso, 0);
  digitalWrite(ledgiallo, 0);
  digitalWrite(ledverde, 1);
  delay(5000);
}
