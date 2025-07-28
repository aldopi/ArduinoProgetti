#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(4);

  myservo.write(20);
  delay(800);

  myservo.write(140);
  delay(800);

  myservo.write(80);
  delay(2000);
}

void loop() {

  for (int i = 45; i < 120; i += 1) {
    myservo.write(i);
    delay(20);
  };
  delay(1000);

  for ( int i = 120; i > 45 ; i -= 1) {
    myservo.write(i);
    delay(20);
  };
  delay(1000);
}

