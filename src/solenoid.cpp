#include "main.h"
#include "robot/solenoid.hpp"
#include "Entity/api.hpp"
#include "robot/hardware.hpp"

/*****************************************************
 *                       NOTE:                       *
 * SOLENOIDS CANNOT SEND DATA AND CAN ONLY READ DATA *
 *****************************************************/

void solenoidControl_fn() { // Example piston control
    while (true) {
        int PistonButton  = controller.get_digital_new_press(DIGITAL_L1); // Example solenoid.

        // Check for button press
        if (PistonButton) {
            example_piston.toggle();
        }

        pros::delay(20); // Saving resources
    }
}
