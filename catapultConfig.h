#include "vex.h"

void catapultPI(){
double kP = 0.00000086;
double kI = 0.0005;
double prevError = 0.0;
double targetPosition = Rotation3.angle() > 51;

double currentPosition = Rotation3.angle();
double error = targetPosition - currentPosition;
double integral = error;
prevError = error;
} 

void runCata() { 
 while (Rotation3.angle() > 0 && Rotation3.angle() < 50) {
  catapultPI();
  
  Cata.spin(forward);

}
  Cata.stop();
  if (Controller1.ButtonL1.pressing()){
    Cata.spin(forward);
    wait(.1, seconds);
    while (Rotation3.angle() > 0 && Rotation3.angle() < 50) {
      catapultPI();
      Cata.spin(forward);
    }
    Cata.stop();
  }
}

void Driver_Auto_Cata(){
  if (Controller1.ButtonL1.pressing()){
    runCata();
  }
}