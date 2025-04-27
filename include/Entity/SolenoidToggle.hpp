#pragma once

#include "pros/adi.hpp"

namespace entity {

class Piston : public pros::adi::DigitalOut {
private:
    bool state = false; // Track the state

public:
    // Constructor
    explicit Piston(uint8_t port);

    // Toggle the piston state
    void toggle();
};
} // Namespace apollo