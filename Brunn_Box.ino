#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// TMP36 Pin Variables
int sensorPin = A0; //the analog pin the TMP36's Vout (sense) pin is connected to

// Buzzer Pin
int buzzerPin = 5;

// LED Pin
int ledPin = 3;

// Initialize the LCD
LiquidCrystal_I2C lcd(0x20, 16, 2); // Set the LCD address to 0x20 for a 16x2 display
int backlightLevel = 255; // Set the backlight level (adjust as needed)

void setup() {
  // Initialize the LCD screen
  lcd.init();
  lcd.backlight(); // Set the backlight level

  // Set buzzer, LED, and LED pins as OUTPUT
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Getting the voltage reading from the temperature sensor
  int reading = analogRead(sensorPin);

  // Convert the reading to voltage
  float voltage = reading * 5.0;
  voltage /= 1024.0;

  // Convert to temperature in Celsius
  float temperatureC = (voltage - 0.5) * 100;

  // Display temperature on the LCD
  lcd.setCursor(1, 0);
  lcd.print("Temperature = ");
  lcd.setCursor(1, 1);
  lcd.print(temperatureC);
  lcd.print(" C ");
  lcd.print((temperatureC*9/5)+32);
  lcd.print(" F");

  // Check if temperature is outside the range of 21-24 degrees Celsius 
  // (equivalent to 70-75 degrees Fahrenheit)
  if (temperatureC < 21.0 || temperatureC > 24.0) {
    // If temperature is outside the range, pulse the buzzer and blink the LED
    for (int i = 0; i < 3; i++) {
      tone(buzzerPin, 1000); // Sound the buzzer at 1kHz
      digitalWrite(ledPin, HIGH); // Turn on the LED
      delay(500); // Pulse duration
      noTone(buzzerPin); // Silence the buzzer
      digitalWrite(ledPin, LOW); // Turn off the LED
      delay(500); // Silence duration
    }
  } else {
    // Otherwise, turn off the buzzer and LED
    noTone(buzzerPin); // Stop the buzzer sound
    digitalWrite(ledPin, LOW);
  }

  // Output temperature data to the serial monitor
  Serial.print("Temperature C: ");
  Serial.print(temperatureC);
  Serial.print(" | Temperature F: ");
  Serial.println((temperatureC * 9.0 / 5.0) + 32.0);

  delay(1000); // Wait for a second
}
