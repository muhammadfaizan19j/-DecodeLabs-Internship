#include <LiquidCrystal.h>

// LCD Pins: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensorPin = A0;
int ledPin = 8;
int buzzerPin = 9;

float temperature = 0;

void setup() {

  lcd.begin(16, 2);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);

  lcd.setCursor(0,0);
  lcd.print("IoT Monitoring");
  delay(2000);

  lcd.clear();
}

void loop() {

  // Read LM35 sensor value
  int sensorValue = analogRead(sensorPin);

  // Convert to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // Convert voltage to temperature
  temperature = voltage * 100;

  // Display temperature
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  // Automation logic
  if(temperature > 35) {

    digitalWrite(ledPin, HIGH);

    // Make buzzer beep
    tone(buzzerPin, 1000);

    lcd.setCursor(0,1);
    lcd.print("ALERT! HOT");

    Serial.println("ALERT! Temperature High");

  }
  else {

    digitalWrite(ledPin, LOW);

    // Stop buzzer
    noTone(buzzerPin);

    lcd.setCursor(0,1);
    lcd.print("Status:Normal");

    Serial.println("Temperature Normal");
  }

  delay(1000);
}