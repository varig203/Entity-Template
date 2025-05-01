#include "Entity/api.hpp"
#include "main.h"
#include "robot/autonomous.hpp"
#include "robot/hardware.hpp"

// To add an auton file use the example below for reference
ASSET(example_txt);

void example_auton() {
    // set chassis pose
    chassis.setPose(0, 0, 0);
    // lookahead distance: 15 inches
    // timeout: 2000 ms
    chassis.follow(example_txt, 15, 2000);
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task||I
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

// Basic Auton.
// This is looking from the front of the field.
// functions starting with r are for red side. And b is for blue side.
void rNear_side_awp() {}

void rFar_side_awp() {}

void bNear_side_awp() {}

void bFar_side_awp() {}

void skills() {}
