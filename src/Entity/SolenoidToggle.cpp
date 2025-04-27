#include "Entity/SolenoidToggle.hpp"
#include "main.h"

/*****************************************************
 *                       NOTE:                       *
 * SOLENOIDS CANNOT SEND DATA AND CAN ONLY READ DATA *
 *****************************************************/

// Reusable function as this is used everytime to switch the state of a piston.
namespace entity {

Piston::Piston(uint8_t port) : pros::adi::DigitalOut(port) {
    set_value(state ? 1 : 0);
}

void Piston::toggle() {
    state = !state;
    set_value(state ? 1 : 0);
}

} // namespace entity