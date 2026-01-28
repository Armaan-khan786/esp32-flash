#ifndef ESP32_MOTOR_H
#define ESP32_MOTOR_H

#include <Arduino.h>
#include "MotorInterface.h"

class Esp32Motor : public MotorInterface {
private:
    int pin;

public:
    Esp32Motor(int motorPin) : pin(motorPin) {
        pinMode(pin, OUTPUT);
    }

    void on() override {
        digitalWrite(pin, HIGH);
    }

    void off() override {
        digitalWrite(pin, LOW);
    }
};

#endif
