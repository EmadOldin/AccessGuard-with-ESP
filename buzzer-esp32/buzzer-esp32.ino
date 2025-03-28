// /*
//  * This ESP32 code is created by esp32io.com
//  *
//  * This ESP32 code is released in the public domain
//  *
//  * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-piezo-buzzer
//  */

// #include "pitches.h"
// #define BUZZZER_PIN  17 // ESP32 pin GPIO18 connected to piezo buzzer

// int melody[] = {
//   NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
// };

// int noteDurations[] = {
//   4, 8, 8, 4, 4, 4, 4, 4
// };

// void setup() {
//   for (int thisNote = 0; thisNote < 8; thisNote++) {
//     int noteDuration = 1000 / noteDurations[thisNote];
//     tone(BUZZZER_PIN, melody[thisNote], noteDuration);

//     int pauseBetweenNotes = noteDuration * 1.30;
//     delay(pauseBetweenNotes);
//     noTone(BUZZZER_PIN);
//   }
// }

// void loop() {
// }



#define BUZZER_PIN 17  // Change this to the GPIO pin you are using

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Simulate success
  soundSuccess();

  delay(2000);

  // Simulate access denied
  soundAccessDenied();
  delay(2000);  // Wait for 2 seconds
}

void soundSuccess() {
  // صدای ورود موفق
  for (int i = 0; i < 2; i++) {   // 3 بار بوق
    tone(BUZZER_PIN, 1000, 100);  // بوق با فرکانس 1000 هرتز به مدت 200 میلی‌ثانیه
    delay(100);                   // تاخیر بین بوق‌ها
    noTone(BUZZER_PIN);           // خاموش کردن بازر
    delay(200);                   // تاخیر بین بوق‌ها
  }
}
  void soundAccessDenied() {
    // Play an access denied sound (e.g., a longer beep)
    tone(BUZZER_PIN, 2000, 800);  // 500 Hz for 1000 ms
  }
