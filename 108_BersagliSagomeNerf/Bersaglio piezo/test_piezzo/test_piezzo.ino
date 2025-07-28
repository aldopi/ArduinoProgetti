/*******************************************
      progetto: corso BASE Arduino
   descrizione:
        autore: www.AldoPi.it
          data:
      versione:
 *******************************************
*/


// -------------------------------  dichiarazioni globali


void setup() {  // ---------------  setup
  Serial.begin(115200);

}  // ============================  setup fine


void loop() {  // ----------------  loop
  for (int i = 0; i < 300; i++) {
    Serial.println(analogRead(1));
    delay(10);
  }
  Serial.println("200");
             }  // ============================  loop fine


               // fine programma
