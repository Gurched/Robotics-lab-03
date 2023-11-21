// initialize the library for the LCD:
#include <LiquidCrystal.h>

// Associate each arduino pin with their function with the library:
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Create the ohm symbol:
  byte customeChar[8] = {
    B00000,
    B00000,
    B01110,
    B10001,
    B10001,
    B10001,
    B01010,
    B11011
  };

  // making an interger  for the known resistance:
  int knownR1 = 10000; 

// Program when starting:
void setup() {

  // Setting up each column and rows:
  lcd.begin(16, 2);

  // Create the for the ohm:
  lcd.createChar(0, customeChar); 
}

void loop() {
  // Setting the cursor to the first row first square:
  lcd.setCursor(0, 0);

  // Printing "Resistance:  " in the first row:
  lcd.print("Resistance: ");

  // Transform from bit value to measuring the resistance:
  float pinValue = analogRead(A0);          // Reading bit value
  float volt = (5.00/1023.00) * pinValue;   // Turn the bit value to voltage
  float current = (5.00 - volt) / knownR1;  // Using the known resistance to figure out the current
  float ohms = (volt/current);              // Using the current and voltage to calculate the unkown resistance

  lcd.setCursor(0, 1);      // Set the cursor to the second row and write the value of the resistance
  lcd.print(ohms);          // Print the value of the resistance
  lcd.write(byte(0));       // Print the value 

  // Stop the program for 100 millis seconds
  delay(20);

  // Clear the display so that bigger values won't mess the screen.
  lcd.clear();
}
