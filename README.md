# AccessGuard with ESP
---
## Project Introduction

This project is an access control system that uses an ESP32 board, an RC522 RFID module, an OLED display, and a keypad. Users can gain access by presenting a valid RFID card and entering the correct password. If the credentials match, the relay is activated and a confirmation buzzer sounds. Otherwise, the relay remains deactivated and an alarm is activated.

## Required Components

- **ESP32 Board** (for processing and module control)
- **RFID RC522 Module** (for reading RFID cards)
- **OLED Display** (for system status display)
- **Keypad** (for password entry)
- **Relay Module** (to control access mechanisms)
- **Buzzer** (for confirmation or warning alerts)
- **Appropriate Power Supply**

---

## System Operation

1. **RFID Card Reading:** The system reads the card using the RC522 module and verifies its ID.
2. **Password Entry:** If the card is valid, the user is prompted to enter a password via the Keypad.
3. **Credential Validation:**
    - If both the card and password are valid:
        - The relay is activated.
        - A confirmation buzzer sounds.
        - Access is granted.
    - If the card is invalid or the password is incorrect:
        - The relay remains deactivated.
        - A warning buzzer sounds.
        - Access is denied.

---

## Setup and Execution

### Install Required Libraries

- `MFRC522.h` for the RFID module
- `Wire.h` and `Adafruit_SSD1306.h` for OLED display
- `Adafruit_GFX.h` for OLED graphics
- `Keypad.h` for the keypad

---

### Hardware Connections

- Connect the **RC522** module to the ESP32.
- Connect the **OLED display** to the ESP32.
- Connect the **Keypad** to the appropriate ESP32 pins.
- Connect the **Relay Module** to the ESP32.

### Uploading Code to ESP32

- Use **Arduino IDE** or **PlatformIO**
- Configure input and output pins
- Upload the code and test the system

## Usage

1. Place your **RFID card** on the module.
2. If valid, enter your **password** via the Keypad.
3. Check the **OLED display** for the operation result.

---

## Future Enhancements

- Adding memory to store authorized cards and passwords
- Connecting to a server for access logs
- Implementing wireless connectivity via WiFi for remote control

## License

This project is released under the **MIT License**, allowing free use with attribution.

افزودن ارتباط بی‌سیم از طریق WiFi برای کنترل از راه دور

لایسنس

این پروژه تحت لایسنس MIT منتشر شده و استفاده از آن با ذکر منبع آزاد است.

