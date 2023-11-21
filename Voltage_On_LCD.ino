// Library 
#include <LiquidCrystal.h>

// Adruino pin number and what they are linked to in the LCD:
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {    // Code when starting.
  // LCD column and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Voltage: ");
}

void loop() {     // Main program 
  // Setting cursor to the second row:
  lcd.setCursor(0, 1);
  // Read the bit value on the analog pin 0:
  float pinValue = analogRead(A0);
  //converting bit value to voltage:
  float volt = (5.00/1023.00) * pinValue;
  // Print the values on LCD:
  lcd.print(volt);
  lcd.print("V");
  // 100 milliseconds so that the monitor is easy to read:
  delay(100);
}
