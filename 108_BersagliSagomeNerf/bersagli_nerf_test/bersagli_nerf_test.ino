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

#define p1 2
#define p2 3
#define p3 4
#define p4 5

#define buzer 6

int punti = 0;
int i;
int x;

#include "LedControl.h"
// #include "FontLEDClock.h"
#include "Wire.h"

#define lcd8x8_clk 12
#define lcd8x8_cs  11
#define lcd8x8_din 10
LedControl lcd8x8 = LedControl(lcd8x8_din, lcd8x8_clk, lcd8x8_cs, 4);
byte intensity = 7;
byte font[13][7] = {
  B00111000,     //0
  B01000100,
  B01001100,
  B01010100,
  B01100100,
  B01000100,
  B00111000,

  B00010000,   //1
  B00110000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00111000,

  B00111000,   //2
  B01000100,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B01111100,

  B01111100,   //3
  B00001000,
  B00010000,
  B00001000,
  B00000100,
  B01000100,
  B00111000,

  B00010000,   //4
  B00110000,
  B01010000,
  B10010000,
  B11111000,
  B00010000,
  B00010000,

  B01111100,   //5
  B01000000,
  B01111000,
  B00000100,
  B00000100,
  B01000100,
  B00111000,

  B00011000,   //6
  B00100000,
  B01000000,
  B01111000,
  B01000100,
  B01000100,
  B00111000,

  B01111100,   //7
  B01000100,
  B00000100,
  B00001000,
  B00010000,
  B00010000,
  B00010000,

  B00111000,   //8
  B01000100,
  B01000100,
  B00111000,
  B01000100,
  B01000100,
  B00111000,

  B00111000,   //9
  B01000100,
  B01000100,
  B00111100,
  B00000100,
  B00001000,
  B00110000,

  B00111100,   //G
  B01000000,
  B01001110,
  B01000010,
  B00111100,
  B00000000,
  B00000000,

  B00111100,   //o
  B01000010,
  B01000010,
  B01000010,
  B00111100,
  B00000000,
  B00000000,

  B00000000,   //-
  B00000000,
  B00000000,
  B01111110,
  B00000000,
  B00000000,
  B00000000
};

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

void numero(int disp, int val) {
  if (val == 99) {
    lcd8x8.clearDisplay(disp);
  } else {
    lcd8x8.setRow(disp, 0, font[val] [0]);
    lcd8x8.setRow(disp, 1, font[val] [1]);
    lcd8x8.setRow(disp, 2, font[val] [2]);
    lcd8x8.setRow(disp, 3, font[val] [3]);
    lcd8x8.setRow(disp, 4, font[val] [4]);
    lcd8x8.setRow(disp, 5, font[val] [5]);
    lcd8x8.setRow(disp, 6, font[val] [6]);
  }
}


void loop() {  // ----------------  loop
  numero(3, 12);
  numero(2, 99);
  numero(1, 99);
  numero(0, 99);
  if (digitalRead(p1) == 0) game0();
  if (digitalRead(p2) == 0) game1();
  delay(100);
}

void game0() {
  numero(3, 10); numero(2, 11); numero(1, 0); numero(0, 99);
  delay(2000);
  numero(3, 99);  numero(2, 99); numero(1, 99); numero(0, 0);
  punti = 0;
  for (i = 0; i < 500; i++) {
    if (punti > 8) punti = 0;
    if (digitalRead(s1)) {
      digitalWrite(s1ve, 1);
      tone(buzer, 800);
      numero(0, ++punti);
      delay(400);
      noTone(buzer);
      digitalWrite(s1ve, 0);
    }
    if (digitalRead(s2)) {
      digitalWrite(s2ve, 1);
      tone(buzer, 800);
      numero(0, ++punti);
      delay(400);
      noTone(buzer);
      digitalWrite(s2ve, 0);
    }
    if (digitalRead(s3)) {
      digitalWrite(s3ve, 1);
      tone(buzer, 800);
      numero(0, ++punti);
      delay(400);
      noTone(buzer);
      digitalWrite(s3ve, 0);
    }
    delay(200);
    if (digitalRead(p1) == 0) {
      while (digitalRead(p1) == 0) {};
      return;
    };
  }
}

void game1() {
  int tempo = 0;
  int sagoma = 0;
  punti = 0;
  numero(3, 10); numero(2, 11); numero(1, 1); numero(0, 99);
  delay(1000);
  numero(3, 99);  numero(2, 99); numero(1, 99); numero(0, punti);
  for (i = 1; i < 7; i++) {
    numero(3, i);
    tempo = random(2, 8);
    sagoma = random(1, 4);
    delay(2000);
    switch (sagoma) {
      case 1:
        digitalWrite(s1ve, 1);
        digitalWrite(s1ro, 1);
        break;
      case 2:
        digitalWrite(s2ve, 1);
        digitalWrite(s2ro, 1);
        break;
      case 3:
        digitalWrite(s3ve, 1);
        digitalWrite(s3ro, 1);
        break;
    }
    for (x = 0; x < 16; x++) {
      if (digitalRead(s1) and sagoma == 1) {
        tone(buzer, 800);
        numero(0, ++punti);
        delay(400);
        noTone(buzer);
        x = 200;
      }  else if (digitalRead(s2) and sagoma == 2) {
        tone(buzer, 800);
        numero(0, ++punti);
        delay(400);
        noTone(buzer);
        x = 200;
      }  else if (digitalRead(s3) and sagoma == 3) {
        tone(buzer, 800);
        numero(0, ++punti);
        delay(400);
        noTone(buzer);
        x = 200;
      }
      delay(200);
    }
    if (x < 100) {
      tone(buzer, 300);
      delay(400);
      noTone(buzer);
    }
    digitalWrite(s1ve, 0);
    digitalWrite(s1ro, 0);
    digitalWrite(s2ve, 0);
    digitalWrite(s2ro, 0);
    digitalWrite(s3ve, 0);
    digitalWrite(s3ro, 0);
  }
  delay(3000);
}
// fine programma
