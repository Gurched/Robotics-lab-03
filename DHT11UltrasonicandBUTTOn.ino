// Initalize all the libraries
#include <LiquidCrystal.h>
#include <dht11.h>
#define DHT11PIN 7

// set the values as intergers:
float duration, distance;


dht11 DHT11;

  // initialize all arduino pins to the library:
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

  // Set intergers for trig and echo
int trigPin = 10;
int echoPin = 13;

// Code when starting 
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // use the internal resistor for the button:
  pinMode(8, INPUT_PULLUP);

  // Set the trigger pin and echo pin in input/output:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  // Read the input of the buttons:
  int button = digitalRead(8);

  // This part gives a pulse to the ultrasonic sensor to read
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
 // Sending the pulse, this checks how long it taskes for the pulse to come:
  duration = pulseIn(echoPin, HIGH);
  
  // using the duration, we use the 343 m/s as speed of sound to calculate distance
  distance = (duration / 2) * 0.0343;
  
  // if the button is not pressed, it will play the ultrasonic
   if (button == 1) {

  lcd.setCursor(0, 0);                      // Set the cursor to  first row first column
  lcd.print("Distance= ");                  // Print "Distance= "
  if (distance >= 400 || distance <= 2) {   // If the distance is far or too close
    lcd.setCursor(0, 1);                    // Set cursor to second row first column
     lcd.print("Out of range");             // Print "Out of range"
  }
  // if the distance is good do:
  else { 
    lcd.setCursor(0, 1);      // Set cursor to second row first column
    lcd.print(distance);      // print the variable
    lcd.print(" cm");         // print "cm"
    delay(500);               // stop program for half a second
  }
  lcd.clear();                // Clear the screen
  delay(500);                 // stop program for half a second
   }
  // if the button is pressed, it will play the DHT11:
     if (button == 0) {

    int chk = DHT11.read(DHT11PIN);            // Checks the 

  lcd.setCursor(0, 0);                         // Set cursor to the first row and first column
    lcd.print("Humidity:");                    // Print "Humidty: "
    lcd.print((float)DHT11.humidity, 2);       // Print the value of the humidty
    lcd.print("%");                            // Print "%"

  lcd.setCursor(0, 1);                         // Set cursor to second row first column
    lcd.print("Temp:");                        // Print "Temp:"
    lcd.print((float)DHT11.temperature, 2);    // Print the value of the temperature
    lcd.print("c");                            // Print "c" 

  delay(2000);      // stop the program for 2 seconds so you're able to read the values
lcd.clear();        // Clear the screen so the next line can be written with no problem.
  }
}
