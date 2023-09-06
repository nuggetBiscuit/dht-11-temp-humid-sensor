#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT;

#define DHT11_PIN 7

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
}



void loop(){
  int chk = DHT.read11(DHT11_PIN);
  int tF = (int)round(1.8*(DHT.temperature)+32);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(tF);
  lcd.print((char)223);
  lcd.print("F");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");

  Serial.print("Temperature = ");
  Serial.print(tF);
  Serial.println(" F");
  Serial.println("Humidity = ");
  Serial.println(DHT.humidity);
 


  delay(2000);
}