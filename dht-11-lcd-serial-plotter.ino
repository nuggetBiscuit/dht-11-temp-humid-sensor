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
  int tC = DHT.temperature;
  int tF = (int)round(1.8 * tC + 32);

  // Define the desired y-axis range
  int yMin = -10; // Minimum value
  int yMax = 100; // Maximum value

  // Scale the temperature value to fit the range
  int scaledTemp = map(tF, -40, 125, yMin, yMax); // Assuming a temperature range of -40°C to 125°C

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

  // Send the scaled temperature value to the Serial Plotter
  Serial.print(0);
  Serial.print(",");
  Serial.print(scaledTemp);
  Serial.print("");
  Serial.print(10);

  delay(2000);
}