#include "motor_logic.h"

int calculateSteps(int rotations, int stepsPerRevolution) {
    if (rotations <= 0 || stepsPerRevolution <= 0) {
        return 0;
    }
    return rotations * stepsPerRevolution;
}

bool isValidRotationKey(char key) {
    return (key >= '1' && key <= '9');
}
