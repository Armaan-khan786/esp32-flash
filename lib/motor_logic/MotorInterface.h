#ifndef MOTOR_INTERFACE_H
#define MOTOR_INTERFACE_H

class MotorInterface {
public:
    virtual void on() = 0;
    virtual void off() = 0;

    virtual ~MotorInterface() {}
};

#endif
