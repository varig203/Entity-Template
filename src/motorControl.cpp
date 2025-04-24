#include "main.h"
#include "pros/misc.h"
#include "robot/hardware.hpp"

void motorControl_fn() {
    // Insert potential variable initalizing here

    while (true) {
        // Insert your motor control code here
        // Including buttons
        // Example motor control
        bool exampleMotor = controller.get_digital(DIGITAL_B);
        
        if (exampleMotor) {
            example_motor.move_velocity(600); // Assuming blue motor
        } else {
            example_motor.move_velocity(0); // Stops
        }
        pros::delay(20);
    }
}

// Basic dual stick arcade style chassis control
// Docs: https://lemlib.readthedocs.io/en/stable/tutorials/3_driver_control.html
void chassis_fn() {
    while (true) {
        int leftY  = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);  // Up and down on the left stick
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X); // Left and right on the right stick

        // Drivetrain control
        chassis.arcade(leftY, rightX);
        pros::delay(20);
    }
}
