#include "main.h"
#include "robot/solenoid.hpp"
#include "robot/reuseFunc.hpp"
#include "robot/hardware.hpp"

/*****************************************************
 *                       NOTE:                       *
 * SOLENOIDS CANNOT SEND DATA AND CAN ONLY READ DATA *
 *****************************************************/

void solenoidControl_fn() { // Example piston control
    // Initializing var
    int  lastButtonState  = 0;     // To track the last button state

    while (true) {
        int currentButtonState  = controller.get_digital(DIGITAL_L1); // Example solenoid.

        // Check for button press
        if (currentButtonState && !lastButtonState) {
            example_piston.toggle();
        }
        // Resetting value
        lastButtonState  = currentButtonState;

        pros::delay(20); // Saving resources
    }
}
