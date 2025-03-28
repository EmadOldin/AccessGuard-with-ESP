// ----# Library #----
#include "Keypad.h"
#include <SPI.h>
#include <MFRC522.h>

// ----# Module Pin #----
#define SS_PIN 5
#define RST_PIN 16
#define RELAY_PIN 4
#define BUZZER_PIN 17

// ----# Setup RC522 #----
MFRC522 mfrc522(SS_PIN, RST_PIN);

// ----# Setup Keypad #----
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte rowPins[ROWS] = { 13, 12, 14, 27 };
byte colPins[COLS] = { 26, 25, 33, 32 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
String password = "123456";  // رمز عبور
String input_password = "";

String user_ID = "72 71 88 51"; // شماره RFID مجاز
String user;

void setup() {
  Serial.begin(115200);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println(F("\n😎System Ready... Enter Password:"));
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  ///------------------------------# Keypad Part #------------------------------
  char key = keypad.getKey();
  if (key) {
    if (key == '*') {
      input_password = "";  
      Serial.println(F("\nPassword Reset. Enter again: "));
    } else if (key == '#') {
      Serial.println();
      if (password == input_password) {
        // clearSerialMonitor();
        Serial.println(F("✅ Correct Password! Please scan your RFID card..."));
        soundSuccess();
        delay(500);
        
        ///------------------------------# RC522 RFID Part #------------------------------
        while (true) {
          if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
            // clearSerialMonitor();
            Serial.print(F("🔹 Card UID: "));
            String content = "";
            for (byte i = 0; i < mfrc522.uid.size; i++) {
              Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
              Serial.print(mfrc522.uid.uidByte[i], HEX);
              content += String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
              content += String(mfrc522.uid.uidByte[i], HEX);
            }
            Serial.println();
            content.toUpperCase();
            user = content.substring(1);
            
            if (user == user_ID) {
              // clearSerialMonitor();
              Serial.println(F("✅ Access Granted! Welcome!"));
              soundSuccess();
              digitalWrite(RELAY_PIN, HIGH);
              delay(7000);
              digitalWrite(RELAY_PIN, LOW);
            } else {
              // clearSerialMonitor();
              Serial.println(F("❌ Access Denied! Unauthorized Card."));
              soundAccessDenied();
            }
            
            mfrc522.PICC_HaltA();
            mfrc522.PCD_StopCrypto1();
            Serial.println(F("\n🔄 System Ready... Enter Password:"));
            break;
          }
          delay(100);
        }
      } else {
        // clearSerialMonitor();
        Serial.println(F("❌ Incorrect Password! Try Again."));
        soundAccessDenied();
      }
      input_password = "";  
    } else {
      input_password += key;
      Serial.print(key); // نمایش رمز کنار هم
    }
  }
}

// ------# For ESP32 #
void soundSuccess() {
  for (int i = 0; i < 3; i++) {   
    tone(BUZZER_PIN, 1000, 100);
    delay(150);
    noTone(BUZZER_PIN);
    delay(200);
  }
}

void soundAccessDenied() {
  for (int i = 0; i < 2; i++) {
    tone(BUZZER_PIN, 2000, 500);
    delay(600);
    noTone(BUZZER_PIN);
    delay(200);
  }
}

// ----# پاک کردن خروجی سریال مانیتور #----
void clearSerialMonitor() {
  Serial.write(27); // ESCAPE character
  Serial.print("[2J"); // پاک کردن صفحه
  Serial.write(27);
  Serial.print("[H"); // انتقال مکان‌نما به بالا
}
