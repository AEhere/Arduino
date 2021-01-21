  #include <Wire.h>
  #include <Adafruit_PWMServoDriver.h>

  Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

  #define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
  #define USMAX  2200 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
  #define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

  #define FwdRA 1
  #define FwdRB 2
  #define FwdRC 3

  #define AftRA 5
  #define AftRB 6
  #define AftRC 7

  #define FwdLA 9
  #define FwdLB 10
  #define FwdLC 11

  #define AftLA 13
  #define AftLB 14
  #define AftLC 15


void setup() {
  //Initialize the servo driver logic
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  delay(100);

  //write home positions to the servos
  // homeLeg('True','True');
  // homeLeg('True','False');
  // homeLeg('False','True');
  // homeLeg('False','False');


  pwm.writeMicroseconds(FwdRA,mapServo(60));
  pwm.writeMicroseconds(FwdLA,mapServo(120));
  pwm.writeMicroseconds(AftRA,mapServo(120));
  pwm.writeMicroseconds(AftLA,mapServo(60));
  delay(1000);
  
  plantLeg(1,1);
    delay(50);
  plantLeg(1,0);
    delay(50);
  plantLeg(0,1);
    delay(50);
  plantLeg(0,0);
  delay(1000);
    
}
//*************************************
//*************************************
//************LOOP START***************
//*************************************
//*************************************



void loop() {

  // retractLeg(1,1);
  // retractLeg(0,0);
  //
  // FwdRA.write(120);
  // FwdLA.write(90);
  // AftRA.write(90);
  // AftLA.write(120);

  retractLeg(1,1);
  delay(100);
  retractLeg(0,0);
  delay(100);
  
  pwm.writeMicroseconds(FwdRA,mapServo(70));
    delay(100);
  pwm.writeMicroseconds(FwdLA,mapServo(120));
    delay(100);
  pwm.writeMicroseconds(AftRA,mapServo(120));
    delay(100);
  pwm.writeMicroseconds(AftLA,mapServo(50));
  delay(100);
  
  plantLeg(1,1);
  delay(100);
  plantLeg(0,0);
  delay(100);
  
  retractLeg(0,1);
  delay(100);
  retractLeg(1,0);
  delay(100);

  pwm.writeMicroseconds(FwdRA,mapServo(50));
    delay(100);
  pwm.writeMicroseconds(FwdLA,mapServo(110));
    delay(100);
  pwm.writeMicroseconds(AftRA,mapServo(130));
    delay(100);
  pwm.writeMicroseconds(AftLA,mapServo(70));  
  delay(100);

  plantLeg(0,1);
  delay(100);
  plantLeg(1,0);
  delay(100);

  pwm.writeMicroseconds(FwdRA,mapServo(60));
    delay(100);
  pwm.writeMicroseconds(FwdLA,mapServo(120));
    delay(100);
  pwm.writeMicroseconds(AftRA,mapServo(120));
    delay(100);
  pwm.writeMicroseconds(AftLA,mapServo(60));
  delay(100);
}
//*************************************
//*************************************
//***********LOOP END******************
//*************************************
//*************************************


int mapServo(int _deg){
  int result;
  result = map(_deg,0,180,USMIN,USMAX);
  return result;
}
//
// void extendLeg(bool _fwd, bool _right){
//   //take 2 bools to know which leg,
//   //then write extension commands to
//   //servos B and C in the correct leg
//
//   int _posFwdRBExtend = mapServo(90);
//   int _posFwdRCExtend = mapServo(180);
//
//   // Fwd Right leg is the reference one
//   // all other legs derive their positions
//   // by transforming those of FwdR
//
//   int _posFwdLBExtend = _posFwdRBExtend;
//   int _posFwdLCExtend = _posFwdRCExtend;
//
//   int _posAftRBExtend = mapServo(180) - _posFwdRBExtend;
//   int _posAftRCExtend = mapServo(180) - _posFwdRCExtend;
//
//   int _posAftLBExtend = mapServo(180) - _posFwdRBExtend;
//   int _posAftLCExtend = mapServo(180) - _posFwdRCExtend;
//
//   if (_fwd){
//     if (_right){
//       //FwdRA.write(0);
//       FwdRB.write(_posFwdRBExtend);
//       FwdRC.write(_posFwdRCExtend);
//       delay(250);
//       }
//     else if(!_right){
//       //FwdLA.write(6);
//       FwdLB.write(_posFwdLBExtend);
//       FwdLC.write(_posFwdLCExtend);
//       delay(250);
//       }
//     }
//    else if (!_fwd){
//     if (_right){
//       //FwdRA.write(0);
//       AftRB.write(_posAftRBExtend);
//       AftRC.write(_posAftRCExtend);
//       delay(250);
//       }
//     else if(!_right){
//       //FwdLA.write(6);
//       AftLB.write(_posAftLBExtend);
//       AftLC.write(_posAftLCExtend);
//       delay(250);
//       }
//     }
// }
//
void plantLeg(bool _fwd, bool _right){
  //take 2 bools to know which leg,
  //then write extension commands to
  //servos B and C in the correct leg

  int _posFwdRBPlant = mapServo(20);
  int _posFwdRCPlant = mapServo(10);

  // Fwd Right leg is the reference one
  // all other legs derive their positions
  // by transforming those of FwdR

  int _posFwdLBPlant = _posFwdRBPlant;
  int _posFwdLCPlant = _posFwdRCPlant;

  int _posAftRBPlant = mapServo(160);
  int _posAftRCPlant = mapServo(170);

  int _posAftLBPlant = mapServo(160);
  int _posAftLCPlant = mapServo(170);

  if (_fwd){
    if (_right){
      pwm.writeMicroseconds(FwdRB,_posFwdRBPlant);
      pwm.writeMicroseconds(FwdRC,_posFwdRCPlant);
      delay(100);
      }
    else if(!_right){
      pwm.writeMicroseconds(FwdLB,_posFwdLBPlant);
      pwm.writeMicroseconds(FwdLC,_posFwdLCPlant);
      delay(100);
      }
    }
   else if (!_fwd){
    if (_right){
      pwm.writeMicroseconds(AftRB,_posAftRBPlant);
      pwm.writeMicroseconds(AftRC,_posAftRCPlant);
      delay(100);
      }
    else if(!_right){
      pwm.writeMicroseconds(AftLB,_posAftLBPlant);
      pwm.writeMicroseconds(AftLC,_posAftLCPlant);
      delay(100);
      }
    }
}

// void homeLeg(bool _fwd, bool _right){
//   //take 2 bools to know which leg,
//   //then write home commands to
//   //servos B and C in the correct leg
//
//   int _posFwdRAHome = mapServo(135);
//   int _posFwdRBHome = mapServo(0);
//   int _posFwdRCHome = mapServo(45);
//
//     // Fwd Right leg is the reference one
//     // all other legs derive their positions
//     // by transforming those of FwdR
//
//   int _posFwdLAHome = mapServo(180) - _posFwdRAHome;
//   int _posFwdLBHome = _posFwdRBHome;
//   int _posFwdLCHome = mapServo(180) - _posFwdRCHome;
//
//   // int _posAftRAHome = 0;
//   // int _posAftRBHome = 0;
//   // int _posAftRCHome = 0;
//   //
//   // int _posAftLAHome = 0;
//   // int _posAftLBHome = 0;
//   // int _posAftLCHome = 0;
//
//   if (_fwd){
//     if (_right){
//       FwdRA.write(_posFwdRAHome);
//       FwdRB.write(_posFwdRBHome);
//       FwdRC.write(_posFwdRCHome);
//       delay(250);
//       }
//     else if(!_right){
//       FwdLA.write(_posFwdLAHome);
//       FwdLB.write(_posFwdLBHome);
//       FwdLC.write(_posFwdLCHome);
//       delay(250);
//       }
//     }
//    else if (!_fwd){
//     if (_right){
//       // FwdRA.write(_posAftRAHome);
//       // AftRB.write(_posAftRBHome);
//       // AftRC.write(_posAftRCHome);
//       delay(250);
//       }
//     else if(!_right){
//       // FwdLA.write(_posAftLAHome);
//       // AftLB.write(_posAftLBHome);
//       // AftLC.write(_posAftLCHome);
//       delay(250);
//       }
//     }
//   }
//
//
  void retractLeg(bool _fwd, bool _right){
    //take 2 bools to know which leg,
    //then write home commands to
    //servos B and C in the correct leg
    // This is basically a simplified homeLeg() routine
    
    int _posFwdRBHome = mapServo(0);
    int _posFwdRCHome = mapServo(20);
    
    int _posFwdLBHome = _posFwdRBHome;
    int _posFwdLCHome =  mapServo(20);
    
    int _posAftRBHome = mapServo(180);
    int _posAftRCHome = mapServo(180-20);
    
    int _posAftLBHome = mapServo(180);
    int _posAftLCHome = mapServo(180-20);

    if (_fwd){
      if (_right){
        pwm.writeMicroseconds(FwdRB,_posFwdRBHome);
        pwm.writeMicroseconds(FwdRC,_posFwdRCHome);
        delay(100);
        }
      else if(!_right){
        pwm.writeMicroseconds(FwdLB,_posFwdLBHome);
        pwm.writeMicroseconds(FwdLC,_posFwdLCHome);
        delay(100);
        }
      }
     else if (!_fwd){
      if (_right){
        pwm.writeMicroseconds(AftRB,_posAftRBHome);
        pwm.writeMicroseconds(AftRC,_posAftRCHome);
        delay(100);
        }
      else if(!_right){
        pwm.writeMicroseconds(AftLB,_posAftLBHome);
        pwm.writeMicroseconds(AftLC,_posAftLCHome);
        delay(100);
        }
      }
  }
// //
// // void advanceLeg(bool _fwd, bool _right, int _deg /*degrees to advance*/) {
// //   /* code */
// // }
