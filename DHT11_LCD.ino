// Initialize all the libraries:
#include <LiquidCrystal.h>   // Library Code for the LCD
#include <dht11.h>           // Library Code online for DHT11
#define DHT11PIN 7           // Setting the DHT11 to pin 7


dht11 DHT11;

  // Set all arduino pins with their functions according to the library:
  const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  // Check the values of pin 7
  int chk = DHT11.read(DHT11PIN);
  
  lcd.setCursor(0, 0);                        // Set Cursor to first row first column
    lcd.print("Humidity:");                   // Prints "Humidity: "
    lcd.print((float)DHT11.humidity, 2);      // Print the value of the humidity
    lcd.print("%");                           // Prints "%"
  lcd.setCursor(0, 1);                        // Set Cursor to second row first column
    lcd.print("Temp:");                       // Print "Temp:    
    lcd.print((float)DHT11.temperature, 2);   // Print the value of the humidity
    lcd.print("c");                           // Print "c"

  delay(2000);  // Stop the program for 2 seconds
lcd.clear();    // Clear the display
}
