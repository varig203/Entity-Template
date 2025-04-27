#include "robot/hardware.hpp"
#include "Entity/api.hpp"

// Motor groups
pros::MotorGroup left_motors({}, pros::MotorGearset::blue); // lLeft Chassis
pros::MotorGroup right_motors({}, pros::MotorGearset::blue);   // Right Chassis
pros::Motor      example_motor(20, pros::MotorGearset::blue);  // example motor

// Controller and Pistons
pros::Controller      controller(pros::E_CONTROLLER_MASTER); // Initialize controller
entity::Piston        example_piston('A');             // Initialize the solenoid

// Basic sensors. Change to your ports/dimensions.
pros::Imu             imu(0); // IMU
pros::Rotation        vertical_encoder(0);
pros::Rotation        horizontal_encoder(0);
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_2, 3);
lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_2, 0);

// Drivetrain settings (Change to your drivetrain)
lemlib::Drivetrain  drivetrain(&left_motors,               // left motor group
                               &right_motors,              // right motor group
                               16,                         // 10 inch track width
                               lemlib::Omniwheel::NEW_325, // using new 4" omnis
                               600,                        // drivetrain rpm is 360
                               2                           // horizontal drift is 2 (for now)
 );
lemlib::OdomSensors sensors(&vertical_tracking_wheel,   // Vertical tracking wheel
                            nullptr,                    // 2nd Vertical Tracking Wheel
                            &horizontal_tracking_wheel, // Horizontal Tracking wheel
                            nullptr,                    // 2nd Horizontal tracking wheel
                            &imu                        // IMU Sensor
);

// PID controllers
// Default PID
lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// Input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttle_curve(3,    // joystick deadband out of 127
                                      10,   // minimum output where drivetrain will move out of 127
                                      1.019 // expo curve gain
);

// Input curve for steer input during driver control
lemlib::ExpoDriveCurve steer_curve(3,    // joystick deadband out of 127
                                   10,   // minimum output where drivetrain will move out of 127
                                   1.019 // expo curve gain
);

// Create the chassis
lemlib::Chassis chassis(drivetrain,
                        lateral_controller,
                        angular_controller,
                        sensors,
                        &throttle_curve,
                        &steer_curve);
