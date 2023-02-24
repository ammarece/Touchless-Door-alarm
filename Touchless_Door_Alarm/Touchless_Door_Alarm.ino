/*
Code Name:Touchless door alarm
Author: ammarece
Description: This program is used touchless door alarm based on IR sensor
License: Remixing or Changing this Thing is allowed. Commercial use is not allowed.
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define IR_PIN 2
#define BUZZER_PIN 3
#define I2C_ADDR 0x27
#define LCD_COLS 16
#define LCD_ROWS 2

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLS, LCD_ROWS);

void setup() {
  pinMode(IR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.print("Touchless Door ");
  lcd.setCursor(0, 1);
  lcd.print("     System");
}

void loop() {
  int irValue = digitalRead(IR_PIN);
  if (irValue == LOW) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("OPEN THE DOOR");
    digitalWrite(BUZZER_PIN, LOW);
    delay(500); //beep for 0.5 second
    digitalWrite(BUZZER_PIN, LOW);
    delay(1000); //wait for 1 second
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NO ONE IS THERE");
    digitalWrite(BUZZER_PIN, HIGH);
    delay(500); //wait for 0.5 second
  }
}
