#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor UpL = motor(PORT5, ratio6_1, true);
motor UpR = motor(PORT2, ratio6_1, false);
motor BackL = motor(PORT10, ratio6_1, false);
motor FrontL = motor(PORT20, ratio6_1, false);
motor FrontR = motor(PORT11, ratio6_1, true);
motor BackR = motor(PORT1, ratio6_1, true);
rotation Rotation3 = rotation(PORT3, false);
motor Cata = motor(PORT21, ratio36_1, false);
motor Intake = motor(PORT4, ratio6_1, false);
controller Controller1 = controller(primary);
digital_out intakePistons = digital_out(Brain.ThreeWirePort.A);
digital_out Wings = digital_out(Brain.ThreeWirePort.B);
inertial Inertial = inertial(PORT9);
digital_out Endgame = digital_out(Brain.ThreeWirePort.C);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1UpDownButtonsControlMotorsStopped = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // check the ButtonUp/ButtonDown status to control Cata
      if (Controller1.ButtonUp.pressing()) {
        Cata.spin(forward);
        Controller1UpDownButtonsControlMotorsStopped = false;
      } else if (Controller1.ButtonDown.pressing()) {
        Cata.spin(reverse);
        Controller1UpDownButtonsControlMotorsStopped = false;
      } else if (!Controller1UpDownButtonsControlMotorsStopped) {
        Cata.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1UpDownButtonsControlMotorsStopped = true;
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}