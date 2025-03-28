#include "Keypad.h"
const byte ROWS = 4;  //four rows
const byte COLS = 4;  //four columns

// char keys[ROWS][COLS] = {
//   {'1','4','7','*'},
//   {'2','5','8','0'},
//   {'3','6','9','#'},
//   {'A','B','C','D'}
// };


char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

// For ESP32 Microcontroller
byte rowPins[ROWS] = { 13, 12, 14, 27 };
byte colPins[COLS] = { 26, 25, 33, 32 };


Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
String password = "123456";
String input_password;


void setup() {
  Serial.begin(9600);
  input_password.reserve(6);  // maximum input characters is 33, change if needed
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);

    if (key == '*') {
      input_password = ""; // clear input password
    } 
    else if (key == '#') {
      if (password == input_password) {
        Serial.println("The password is correct, ACCESS GRANTED!");
        // DO YOUR WORK HERE

      } else {
        Serial.println("The password is incorrect, ACCESS DENIED!");
      }

      input_password = ""; // clear input password
    } 
    else {
      input_password += key; // append new character to input password string
    }
  }
}