#include "vex.h"

void intakeCont(){
if (Controller1.ButtonR1.pressing()){
  Intake.spin(forward);
}
else if (Controller1.ButtonR2.pressing()){
  Intake.spin(reverse);
}
else {
  Intake.stop();
}
}
