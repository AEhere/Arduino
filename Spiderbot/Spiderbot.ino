
  #include <Servo.h>

  Servo FwdRA;  //Forward Right leg, servo A (body to coxa)
  Servo FwdRB;  //Forward Right leg, servo B (coxa to femur)
  Servo FwdRC;  //Forward Right leg, servo C (femur to tibia)

  Servo AftRA;  //Aft Right leg, servo A
  Servo AftRB;
  Servo AftRC;

  Servo FwdLA;  //Forward Left leg, servo A
  Servo FwdLB;
  Servo FwdLC;

  Servo AftLA;  //Aft Left leg, servo A
  Servo AftLB;
  Servo AftLC;


void setup() {

  //attach the servos to their pins

  FwdRA.attach(3);
  FwdRB.attach(4);
  FwdRC.attach(5);
//
//  AftRA.attach(3);
//  AftRB.attach(4);
//  AftRC.attach(5);
//
//  FwdLA.attach(6);
//  FwdLB.attach(7);
//  FwdLC.attach(8);
//
//  AftLA.attach(9);
//  AftLB.attach(10);
//  AftLC.attach(11);

  // //write home positions to the servos
  //
  // FwdRA.write(posAHome);
  // FwdRB.write(posBHome);
  // FwdRC.write(posCHome);
  //
  // AftRA.write(posAHome);
  // AftRB.write(posBHome);
  // AftRC.write(posCHome);
  //
  // FwdLA.write(posAHome);
  // FwdLB.write(posBHome);
  // FwdLC.write(posCHome);
  //
  // AftLA.write(posAHome);
  // AftLB.write(posBHome);
  // AftLC.write(posCHome);

  homeLeg('True','True');
  homeLeg('True','False');
  homeLeg('False','True');
  homeLeg('False','False');

  delay(1000); //wait one second

}

void loop() {
  // put your main code here, to run repeatedly:

    FwdRA.write(60); //prep leg for advance
    // FwdRB.write(0);
    // FwdRC.write(0);
  delay(500);
  plantLeg('True','True');
  delay(500);
    FwdRA.write(30); //prep leg for advance
    // FwdRB.write(0);
    // FwdRC.write(0);
  delay(500);
  retractLeg('True','True');
  delay(500);
  // extendLeg('True','True');
  // delay(500);
  // retractLeg('True','True');
  // delay(500);
  // plantLeg('True','True');
  // delay(500);




}

void extendLeg(bool _fwd, bool _right){
  //take 2 bools to know which leg,
  //then write extension commands to
  //servos B and C in the correct leg

  int _posFwdRBExtend = 90;
  int _posFwdRCExtend = 180;

  // Fwd Right leg is the reference one
  // all other legs derive their positions
  // by transforming those of FwdR

  int _posFwdLBExtend = _posFwdRBExtend;
  int _posFwdLCExtend = _posFwdRCExtend;

  int _posAftRBExtend = 180 - _posFwdRBExtend;
  int _posAftRCExtend = 180 - _posFwdRCExtend;

  int _posAftLBExtend = 180 - _posFwdRBExtend;
  int _posAftLCExtend = 180 - _posFwdRCExtend;

  if (_fwd){
    if (_right){
      //FwdRA.write(0);
      FwdRB.write(_posFwdRBExtend);
      FwdRC.write(_posFwdRCExtend);
      delay(250);
      }
    else if(!_right){
      //FwdLA.write(6);
      FwdLB.write(_posFwdLBExtend);
      FwdLC.write(_posFwdLCExtend);
      delay(250);
      }
    }
   else if (!_fwd){
    if (_right){
      //FwdRA.write(0);
      AftRB.write(_posAftRBExtend);
      AftRC.write(_posAftRCExtend);
      delay(250);
      }
    else if(!_right){
      //FwdLA.write(6);
      AftLB.write(_posAftLBExtend);
      AftLC.write(_posAftLCExtend);
      delay(250);
      }
    }
}

void plantLeg(bool _fwd, bool _right){
  //take 2 bools to know which leg,
  //then write extension commands to
  //servos B and C in the correct leg

  int _posFwdRBPlant = 60;
  int _posFwdRCPlant = 60;

  // Fwd Right leg is the reference one
  // all other legs derive their positions
  // by transforming those of FwdR

  int _posFwdLBPlant = _posFwdRBPlant;
  int _posFwdLCPlant = _posFwdRCPlant;

  int _posAftRBPlant = 180 - _posFwdRBPlant;
  int _posAftRCPlant = 180 - _posFwdRCPlant;

  int _posAftLBPlant = 180 - _posFwdRBPlant;
  int _posAftLCPlant = 180 - _posFwdRCPlant;

  if (_fwd){
    if (_right){
      //FwdRA.write(0);
      FwdRB.write(_posFwdRBPlant);
      FwdRC.write(_posFwdRCPlant);
      delay(250);
      }
    else if(!_right){
      //FwdLA.write(6);
      FwdLB.write(_posFwdLBPlant);
      FwdLC.write(_posFwdLCPlant);
      delay(250);
      }
    }
   else if (!_fwd){
    if (_right){
      //FwdRA.write(0);
      AftRB.write(_posAftRBPlant);
      AftRC.write(_posAftRCPlant);
      delay(250);
      }
    else if(!_right){
      //FwdLA.write(6);
      AftLB.write(_posAftLBPlant);
      AftLC.write(_posAftLCPlant);
      delay(250);
      }
    }
}

void homeLeg(bool _fwd, bool _right){
  //take 2 bools to know which leg,
  //then write home commands to
  //servos B and C in the correct leg

  int _posFwdRAHome = 135;
  int _posFwdRBHome = 0;
  int _posFwdRCHome = 45;

    // Fwd Right leg is the reference one
    // all other legs derive their positions
    // by transforming those of FwdR

  int _posFwdLAHome = 180 - _posFwdRAHome;
  int _posFwdLBHome = _posFwdRBHome;
  int _posFwdLCHome = 180 - _posFwdRCHome;

  int _posAftRAHome = 0;
  int _posAftRBHome = 0;
  int _posAftRCHome = 0;

  int _posAftLAHome = 0;
  int _posAftLBHome = 0;
  int _posAftLCHome = 0;

  if (_fwd){
    if (_right){
      FwdRA.write(_posFwdRAHome);
      FwdRB.write(_posFwdRBHome);
      FwdRC.write(_posFwdRCHome);
      delay(250);
      }
    else if(!_right){
      FwdLA.write(_posFwdLAHome);
      FwdLB.write(_posFwdLBHome);
      FwdLC.write(_posFwdLCHome);
      delay(250);
      }
    }
   else if (!_fwd){
    if (_right){
      FwdRA.write(_posAftRAHome);
      AftRB.write(_posAftRBHome);
      AftRC.write(_posAftRCHome);
      delay(250);
      }
    else if(!_right){
      FwdLA.write(_posAftLAHome);
      AftLB.write(_posAftLBHome);
      AftLC.write(_posAftLCHome);
      delay(250);
      }
    }
  }
  void retractLeg(bool _fwd, bool _right){
    //take 2 bools to know which leg,
    //then write home commands to
    //servos B and C in the correct leg
    // This is basically a simplified homeLeg() routine

    int _posFwdRAHome = 135;
    int _posFwdRBHome = 0;
    int _posFwdRCHome = 45;

      // Fwd Right leg is the reference one
      // all other legs derive their positions
      // by transforming those of FwdR

    int _posFwdLAHome = 180 - _posFwdRAHome;
    int _posFwdLBHome = _posFwdRBHome;
    int _posFwdLCHome = 180 - _posFwdRCHome;

    int _posAftRAHome = 0;
    int _posAftRBHome = 0;
    int _posAftRCHome = 0;

    int _posAftLAHome = 0;
    int _posAftLBHome = 0;
    int _posAftLCHome = 0;

    if (_fwd){
      if (_right){
        // FwdRA.write(_posFwdRAHome);
        FwdRB.write(_posFwdRBHome);
        FwdRC.write(_posFwdRCHome);
        delay(250);
        }
      else if(!_right){
        // FwdLA.write(_posFwdLAHome);
        FwdLB.write(_posFwdLBHome);
        FwdLC.write(_posFwdLCHome);
        delay(250);
        }
      }
     else if (!_fwd){
      if (_right){
        // FwdRA.write(_posAftRAHome);
        AftRB.write(_posAftRBHome);
        AftRC.write(_posAftRCHome);
        delay(250);
        }
      else if(!_right){
        // FwdLA.write(_posAftLAHome);
        AftLB.write(_posAftLBHome);
        AftLC.write(_posAftLCHome);
        delay(250);
        }
      }
    }

//
// void advanceLeg(bool _fwd, bool _right, int _deg /*degrees to advance*/) {
//   /* code */
// }
