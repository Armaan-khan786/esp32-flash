#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

// ================== STEPPER DEFINITIONS ==================
#define STEP_PIN    18
#define DIR_PIN     19
#define ENABLE_PIN  21

const int stepsPerRevolution = 200;     // 200 steps = 360°
const unsigned long STEP_DELAY_US = 12500; // 5 sec per revolution

bool directionCW = true;
bool abortMotor = false;
bool continuousRun = false;

// ================== KEYPAD SETUP ==================
#define ROW_NUM     4
#define COLUMN_NUM  4

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pin_rows[ROW_NUM] = {13, 12, 14, 27};
byte pin_cols[COLUMN_NUM] = {26, 25, 33, 32};

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_cols, ROW_NUM, COLUMN_NUM);

// ================== LCD ==================
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ================== SETUP ==================
void setup() {
  Serial.begin(115200);

  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);

  digitalWrite(ENABLE_PIN, LOW); // enable driver

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Stepper Ready");
  lcd.setCursor(0, 1);
  lcd.print("Press Key");
}

// ================== LOOP ==================
void loop() {
  char key = keypad.getKey();

  // -------- ABORT (GLOBAL) --------
  if (key == 'A') {
    abortMotor = true;
    continuousRun = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ABORTED");
    delay(500);
    lcd.clear();
    return;
  }

  // -------- SET DIRECTION --------
  if (key == '#') {                 // CLOCKWISE
    directionCW = true;
    digitalWrite(DIR_PIN, LOW);     // <-- swapped for your driver
    lcd.clear();
    lcd.print("Direction: CW");
  }

  else if (key == '*') {            // ANTICLOCKWISE
    directionCW = false;
    digitalWrite(DIR_PIN, HIGH);    // <-- swapped for your driver
    lcd.clear();
    lcd.print("Direction: CCW");
  }

  // -------- CONTINUOUS CW --------
  else if (key == 'B') {
    directionCW = true;
    digitalWrite(DIR_PIN, LOW);
    continuousRun = true;
    abortMotor = false;
    lcd.clear();
    lcd.print("Run CW (Cont)");
  }

  // -------- CONTINUOUS CCW --------
  else if (key == 'C') {
    directionCW = false;
    digitalWrite(DIR_PIN, HIGH);
    continuousRun = true;
    abortMotor = false;
    lcd.clear();
    lcd.print("Run CCW (Cont)");
  }

  // -------- NUMBER KEYS (1–9) --------
  else if (key >= '1' && key <= '9') {
    abortMotor = false;
    continuousRun = false;

    int rotations = key - '0';
    int totalSteps = rotations * stepsPerRevolution;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Rotate ");
    lcd.print(rotations);
    lcd.print(" Rev");

    stepMotor(totalSteps);
  }

  // -------- CONTINUOUS MOTOR LOOP --------
  if (continuousRun && !abortMotor) {
    stepOnce();
  }
}

// ================== STEP FUNCTIONS ==================
void stepOnce() {
  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(STEP_DELAY_US);
  digitalWrite(STEP_PIN, LOW);
  delayMicroseconds(STEP_DELAY_US);
}

void stepMotor(int steps) {
  for (int i = 0; i < steps; i++) {
    if (abortMotor) break;

    char key = keypad.getKey();
    if (key == 'A') {
      abortMotor = true;
      break;
    }

    stepOnce();
  }
}