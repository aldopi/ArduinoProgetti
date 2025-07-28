/*******************************************
      progetto: corso BASE Arduino
   descrizione: bersaglio NERF
  versione data: 5-04-2019
    componenti: arduino e kit per bersagli
        autore: www.AldoPi.it
 *******************************************
*/

#define s1ve 14
#define s1ro 15
#define s2ve 16
#define s2ro 17
#define s3ve 18
#define s3ro 19

#define s1 7
#define s2 8
#define s3 9


void setup() {  // ---------------  setup
  pinMode(s1ve, OUTPUT);
  pinMode(s1ro, OUTPUT);
  pinMode(s2ve, OUTPUT);
  pinMode(s2ro, OUTPUT);
  pinMode(s3ve, OUTPUT);
  pinMode(s3ro, OUTPUT);
  pinMode(s1, INPUT_PULLUP);
  pinMode(s2, INPUT_PULLUP);
  pinMode(s3, INPUT_PULLUP);
}

void loop() {
  digitalWrite(14, 1);
  digitalWrite(15, 1);
  digitalWrite(16, 1);
  digitalWrite(17, 1);
  digitalWrite(18, 1);
  digitalWrite(19, 1);
  delay(2000);
  digitalWrite(14, 0);
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
  
  for (int i = 14; i < 20; i++) {
    digitalWrite(i, 1); delay(200);
    digitalWrite(i, 0); delay(20
    0);
  }
}
