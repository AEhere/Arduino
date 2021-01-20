
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

  FwdRA.attach(0);
  FwdRB.attach(1);
  FwdRC.attach(2);

  AftRA.attach(3);
  AftRB.attach(4);
  AftRC.attach(5);

  FwdLA.attach(6);
  FwdLB.attach(7);
  FwdLC.attach(8);

  AftLA.attach(9);
  AftLB.attach(10);
  AftLC.attach(11);

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

  delay(1000); //wait one second

}

void loop() {
  // put your main code here, to run repeatedly:

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

void homeLeg(bool _fwd, bool _right){
  //take 2 bools to know which leg,
  //then write home commands to
  //servos B and C in the correct leg

  int _posFwdRAHome = 45; //This is a guess, could be 135 as well
  int _posFwdRBHome = 0;
  int _posFwdRCHome = 120;

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
      //FwdRA.write(0);
      FwdRB.write(_posFwdRBHome);
      FwdRC.write(_posFwdRCHome);
      delay(250);
      }
    else if(!_right){
      //FwdLA.write(6);
      FwdLB.write(_posFwdLBHome);
      FwdLC.write(_posFwdLCHome);
      delay(250);
      }
    }
   else if (!_fwd){
    if (_right){
      //FwdRA.write(0);
      AftRB.write(_posAftRBHome);
      AftRC.write(_posAftRCHome);
      delay(250);
      }
    else if(!_right){
      //FwdLA.write(6);
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
