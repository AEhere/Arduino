#include <Servo.h>

Servo TestServo;

void setup() {
  TestServo.attach(3);
}

void loop() {
  TestServo.write(0);
  delay(1000);
  TestServo.write(90);
  delay(1000);
  TestServo.write(180);
  delay(1000);
}
