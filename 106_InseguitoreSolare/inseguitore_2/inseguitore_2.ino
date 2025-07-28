/*******************************************
 *    progetto: corso BASE Arduino
 * descrizione: inseguitore luminoso pannello solare
 *      autore: www.AldoPi.it
 *        data: 30 ottobre 2016
 *    versione: 1.0
 ******************************************* 
*/

#include <Servo.h>
Servo servoMotor;

#define PHOTO_1 A1
#define PHOTO_2 A0
#define SOGLIA 20
#define SENSIBILITA 1
#define SERVOPIN 8

int posizione = 90;
    
//  +++++++++++++++++++++++++++++++++++++++++ SETUP
void setup() {
     servoMotor.attach(SERVOPIN);
     
     servoMotor.write(5);
     delay(750);
     servoMotor.write(175);
     delay(750);
     servoMotor.write(90);
     delay(2000);
}
//   ---------------------------------------- SETUP



//  +++++++++++++++++++++++++++++++++++++++++ SONDE
int sonde() {
     int dif = analogRead(PHOTO_1)/SENSIBILITA - analogRead(PHOTO_2)/SENSIBILITA;
     if (dif<SOGLIA*SENSIBILITA and dif>-SOGLIA*SENSIBILITA) dif=0;
     return dif;
}
//   ---------------------------------------- SONDE
    
int i=0;
long media=0;
int val=0;
int differenza=0;
    
//  +++++++++++++++++++++++++++++++++++++++++ LOOP
void loop(){
     
     differenza = sonde();
     if (differenza > 200)        posizione = posizione + 5;
     else if (differenza > 0)     posizione = posizione + 1;
     else if (differenza < -200)  posizione = posizione - 5;
     else if (differenza < 0)     posizione = posizione - 1;
     
     if (posizione<5) posizione=5;
     else if (posizione >175) posizione = 175;
     servoMotor.write(posizione);
     delay(100);

}
//   ---------------------------------------- LOOP
