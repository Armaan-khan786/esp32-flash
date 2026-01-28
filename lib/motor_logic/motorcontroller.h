#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include "MotorInterface.h"

class MotorController {
private:
    MotorInterface& motor;

public:
    // Constructor injection
    MotorController(MotorInterface& m) : motor(m) {}

    void start() {
        motor.on();
    }

    void stop() {
        motor.off();
    }
};

#endif
