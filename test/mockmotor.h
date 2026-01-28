#ifndef MOCK_MOTOR_H
#define MOCK_MOTOR_H

#include "../lib/motor_logic/MotorInterface.h"

class MockMotor : public MotorInterface {
public:
    bool isOn = false;

    void on() override {
        isOn = true;
    }

    void off() override {
        isOn = false;
    }
};

#endif
