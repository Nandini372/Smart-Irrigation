#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// DHT
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define WATER_PIN 3
#define MOTOR 5

void setup() {
  pinMode(WATER_PIN, INPUT);
  pinMode(MOTOR, OUTPUT);

  lcd.init();
  lcd.backlight();
  dht.begin();

  lcd.setCursor(0, 0);
  lcd.print("SMART IRRIGATION");
  lcd.setCursor(2, 1);
  lcd.print("INITIALIZING");

  delay(3000);
  lcd.clear();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  int waterState = digitalRead(WATER_PIN);

  String SoilStatus = (waterState == LOW) ? "WET" : "DRY";
  bool waterDetected = (waterState == HIGH);

  // Control motor
  digitalWrite(MOTOR, waterDetected);

  // Display soil status and humidity
  lcd.setCursor(0, 0);
  lcd.print("SOIL:");
  lcd.print(SoilStatus);
  lcd.print(" Hum:");
  lcd.print((int)hum);
  lcd.print("% ");

  // Display temperature
  lcd.setCursor(0, 1);
  lcd.print("Temp:");
  lcd.print((int)temp);
  lcd.write(0xDF); // Degree symbol
  lcd.print("C ");

  delay(1000);
}
