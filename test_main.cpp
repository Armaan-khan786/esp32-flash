#include <unity.h>

// This mimics your motor logic
int test_motor_speed(int input) {
    return input * 2; // Simple math to check
}

void test_math(void) {
    TEST_ASSERT_EQUAL(20, test_motor_speed(10));
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_math);
    return UNITY_END();
}
