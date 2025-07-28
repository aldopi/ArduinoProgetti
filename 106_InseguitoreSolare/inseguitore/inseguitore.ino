
//      progetto:  106 Inseguitore
//          file:  106-1_Inseguitore
//   descrizione:  inseguitore luminoso pannello solare
//       shields:  2x fotoresistenze, servomotore
//      librerie:  Servo
// versione-data:  v1.0 - 130-10-2016
//        autore:  www.aldopi.it

#include <Servo.h>
Servo servoMotor;

#define SERIAL_DEBUG 1
#define PHOTO_1 A1
#define PHOTO_2 A0
#define SOGLIA 20
#define SENSIBILITA 1
#define SERVOPIN 8

int posizione = 90;
    
int i=0;
long media=0;
int val=0;
int differenza=0;

void setup() {
     if (SERIAL_DEBUG) Serial.begin(9600);
     servoMotor.attach(SERVOPIN);
     servoMotor.write(5);
     delay(750);
     servoMotor.write(175);
     delay(750);
     servoMotor.write(90);
     delay(2000);
}

int sonde() {
     int dif = analogRead(PHOTO_1)/SENSIBILITA - analogRead(PHOTO_2)/SENSIBILITA;
     if (dif<SOGLIA*SENSIBILITA and dif>-SOGLIA*SENSIBILITA) dif=0;
     if (SERIAL_DEBUG) Serial.print(dif);
     return dif;
}
    
void loop(){
     differenza = sonde();
     if (differenza > 200)        posizione = posizione + 5;
     else if (differenza > 0)     posizione = posizione + 1;
     else if (differenza < -200)  posizione = posizione - 5;
     else if (differenza < 0)     posizione = posizione - 1;
     
     if (posizione<5) posizione=5;
     else if (posizione >175) posizione = 175;
     if (SERIAL_DEBUG) { 
          Serial.print("\t");
          Serial.println(posizione);
     }
     servoMotor.write(posizione);
     delay(100);
}
//  EOF
