

#include <DFMiniMp3.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int PIR_PIN = 2;
const int LCD_I2C = 0x27;

LiquidCrystal_I2C lcd(LCD_I2C, 16, 2);

SoftwareSerial mySerial(10,11);
DFMiniMp3 mp3;
 
void setup() {
  pinMode(PIR_PIN, INPUT);
  lcd.init()
  lcd.backlight();
  Serial.begin(9600);
  mp3.begin();
  mp3.volume(20);
}

void loop() {
  if (digitalRead(PIR_PIN) == HIGH) {
    lcd.setCursor(0, 1);
    lcd.print("No tocar, gracias");
    mp3.play(1);
    delay(6000);
  } else {
    mp3.stop();
    lcd.clear();
  }
}
