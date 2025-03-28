#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 5   // پین SS
#define RST_PIN 16 // پین ریست

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Scan an RFID card...");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return;  // اگر کارتی نیست، برگرد
  }

  Serial.print("UID tag: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();
  mfrc522.PICC_HaltA();  // کارت را متوقف کن
}
