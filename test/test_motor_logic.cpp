#include <cassert>
#include "../lib/motor_logic/motor_logic.h"

int main() {

    // ---- calculateSteps tests ----
    assert(calculateSteps(1, 200) == 200);
    assert(calculateSteps(5, 200) == 1000);
    assert(calculateSteps(0, 200) == 0);

    // ---- key validation tests ----
    assert(isValidRotationKey('1') == true);
    assert(isValidRotationKey('9') == true);
    assert(isValidRotationKey('0') == false);
    assert(isValidRotationKey('*') == false);

    return 0;
}
