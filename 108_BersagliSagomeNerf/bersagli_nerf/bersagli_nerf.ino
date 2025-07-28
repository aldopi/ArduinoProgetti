/*******************************************
      progetto: corso BASE Arduino
   descrizione:
  versione data:
    componenti:
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

#define p1 2
#define p2 3
#define p3 4
#define p4 5

#define buzer 6

#include "LedControl.h"
// #include "FontLEDClock.h"
#include "Wire.h"

#define lcd8x8_din 12
#define lcd8x8_clk 10
#define lcd8x8_cs 11
LedControl lcd8x8 = LedControl(lcd8x8_din, lcd8x8_clk, lcd8x8_cs, 4);
byte intensity = 7;

void setup() {  // ---------------  setup
  pinMode(p1, INPUT_PULLUP);
  pinMode(p2, INPUT_PULLUP);
  pinMode(p3, INPUT_PULLUP);
  pinMode(p4, INPUT_PULLUP);
  pinMode(buzer, OUTPUT);
  pinMode(s1ve, OUTPUT);
  pinMode(s1ro, OUTPUT);
  pinMode(s2ve, OUTPUT);
  pinMode(s2ro, OUTPUT);
  pinMode(s3ve, OUTPUT);
  pinMode(s3ro, OUTPUT);
  pinMode(s1, INPUT_PULLUP);
  pinMode(s2, INPUT_PULLUP);
  pinMode(s3, INPUT_PULLUP);

  for (int address = 0; address < 4; address++) {
    lcd8x8.shutdown(address, false);
    lcd8x8.setIntensity(address, intensity);
    lcd8x8.clearDisplay(address);
  }

}

void clear_display() {
  for (byte address = 0; address < 4; address++) {
    lcd8x8.clearDisplay(address);
  }
}

void loop() {  // ----------------  loop
//  for (int i = 0; i < 5; i++); {
//    digitalWrite(s1ve, 1); delay(100); digitalWrite(s1ve, 0);
//    digitalWrite(s1ro, 1); delay(100); digitalWrite(s1ro, 0);
//    digitalWrite(s2ve, 1); delay(100); digitalWrite(s2ve, 0);
//    digitalWrite(s2ro, 1); delay(100); digitalWrite(s2ro, 0);
//    digitalWrite(s3ve, 1); delay(100); digitalWrite(s3ve, 0);
//    digitalWrite(s3ro, 1); delay(100); digitalWrite(s3ro, 0);
//  }
  for (int i = 0; i < 100; i++); {
    if (digitalRead(s1)) {
      digitalWrite(s1ve, 1);
      tone(buzer,800);
      delay(400);
      noTone(buzer);      digitalWrite(s1ve, 0);
    }
    if (digitalRead(s2)) {
      digitalWrite(s2ve, 1);
      tone(buzer,800);
      delay(400);
      noTone(buzer);      digitalWrite(s2ve, 0);
    }
    if (digitalRead(s3)) {
      digitalWrite(s3ve, 1);
      tone(buzer,800);
      delay(400);
      noTone(buzer);
      digitalWrite(s3ve, 0);
    }
  }
}


// fine programma
