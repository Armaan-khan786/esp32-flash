# ESP32 Stepper Motor Control with Keypad & LCD

This project controls a **NEMA17 stepper motor** using an **ESP32**, a **4×4 keypad**, and a **16×2 I2C LCD**.
Motor direction, rotation count, and continuous run are controlled via keypad inputs.

A **GitHub Actions CI pipeline** is included to automatically compile and verify the Arduino code on every push.

---

## 🔧 Hardware Used

- ESP32 Dev Module
- A4988 / DRV8825 Stepper Driver
- NEMA17 Stepper Motor
- 4×4 Matrix Keypad
- 16×2 I2C LCD (Address: `0x27`)
- External Motor Power Supply

---

## 🔌 Pin Connections

### Stepper Driver
| ESP32 Pin | Function |
|---------|----------|
| GPIO 18 | STEP |
| GPIO 19 | DIR |
| GPIO 21 | ENABLE |

### Keypad
| Row | GPIO |
|----|------|
| R1 | 13 |
| R2 | 12 |
| R3 | 14 |
| R4 | 27 |

| Column | GPIO |
|-------|------|
| C1 | 26 |
| C2 | 25 |
| C3 | 33 |
| C4 | 32 |

### LCD (I2C)
| Signal | ESP32 |
|------|-------|
| SDA | GPIO 21 |
| SCL | GPIO 22 |

---

## ⌨️ Keypad Controls

| Key | Function |
|----|---------|
| `1–9` | Rotate motor by given revolutions |
| `#` | Set direction Clockwise |
| `*` | Set direction Counter-Clockwise |
| `B` | Continuous CW rotation |
| `C` | Continuous CCW rotation |
| `A` | Abort / Stop motor |

---

## ⚙️ Software Requirements

- Arduino IDE
- ESP32 Board Package
- Libraries:
  - `Keypad`
  - `LiquidCrystal_I2C`

---

## 🤖 GitHub Actions (CI)

This repository uses **GitHub Actions** to automatically:

- Install Arduino CLI
- Install ESP32 core
- Install required libraries
- Compile the sketch

📌 **Note:**  
GitHub Actions verifies **code compilation only**.  
Actual hardware I/O (GPIO, motor, LCD) must be tested on real hardware.

Workflow file:
