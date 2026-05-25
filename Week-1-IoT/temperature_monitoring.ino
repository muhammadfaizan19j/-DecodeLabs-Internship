

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int lm35Pin = A0;

float temperature = 0.0;

void setup() {
  lcd.begin(16, 2);         
  Serial.begin(9600);     

  lcd.setCursor(0, 0);
  lcd.print("IoT Temp Monitor");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

void loop() {
  int rawValue = analogRead(lm35Pin);
  temperature = (rawValue * 5.0 / 1023.0) * 100.0;
  lcd.setCursor(0, 0);
  lcd.print("Temperature:    ");

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print(" C      ");

  Serial.print("Raw ADC: ");
  Serial.print(rawValue);
  Serial.print("  |  Temperature: ");
  Serial.print(temperature, 1);
  Serial.println(" C");

  delay(1000);
}
