#include <unity.h>

#include "MockMotor.h"
#include "../lib/motor_logic/MotorController.h"

void test_motor_start_turns_motor_on() {
    MockMotor motor;
    MotorController controller(motor);

    controller.start();

    TEST_ASSERT_TRUE(motor.isOn);
}

void test_motor_stop_turns_motor_off() {
    MockMotor motor;
    MotorController controller(motor);

    controller.stop();

    TEST_ASSERT_FALSE(motor.isOn);
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(test_motor_start_turns_motor_on);
    RUN_TEST(test_motor_stop_turns_motor_off);

    return UNITY_END();
}
