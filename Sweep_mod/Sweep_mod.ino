/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo SERVA;  // create servo object to control a servo
Servo SERVB;
Servo SERVC;
// twelve servo objects can be created on most boards

int pos = 30;    // variable to store the servo position
int TXdelay = 500;

void setup() {
  SERVA.attach(9);  // attaches the servo on pin 9 to the servo object
  SERVB.attach(10);
  SERVC.attach(11);

  SERVA.write(30);
  SERVB.write(90);
  SERVC.write(160);
  delay(1000);
}

void loop() {
  
//  for (pos = 30; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    SERVA.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(TXdelay);                       // waits 15ms for the servo to reach the position
//    SERVB.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(TXdelay); 
//    SERVC.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(TXdelay); 
//  }
//  for (pos = 120; pos >= 30; pos -= 1) { // goes from 180 degrees to 0 degrees
//    SERVA.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(TXdelay);                       // waits 15ms for the servo to reach the position
//    SERVB.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(TXdelay); 
//    SERVC.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(TXdelay);                        // waits 15ms for the servo to reach the position
//  }

  SERVB.write(160);
  delay(TXdelay);
  SERVA.write(90);
  delay(TXdelay);
  SERVB.write(90);
  delay(TXdelay);
  SERVA.write(30);
  delay(TXdelay);


}
