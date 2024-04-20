#include "DHT.h"
#define DHTTYPE DHT11
#define DHTPIN 8
DHT dht(DHTPIN, DHTTYPE);
#include <LiquidCrystal.h>  // include the library code
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// float DHTPIN = 8 ;

void setup() {
  pinMode(DHTPIN, INPUT);
  // Serial.begin(9600);  //setup serial
  dht.begin();
  lcd.begin(16, 2);
}

void loop() {
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();
  /// put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  lcd.print("Temp = ");  //show Temp
  lcd.print(temp);       //show Temp

  lcd.setCursor(0, 1);
  lcd.print("humidity = ");  //show humidity
  lcd.print(humidity);       //show humidity


  // lcd.setCursor(0, 0);
  // Serial.print("Temp = ");  //show Temp
  // Serial.println(temp);     //show Temp

  // // lcd.setCursor(0, 1);
  // Serial.print("humidity = ");  //show humidity
  // Serial.println(humidity);     //show humidity
  delay(1000);
  //lcd.clear();
}
