#include <DHT.h>
#include <LiquidCrystal.h>

// Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

/*

DHT Connection -

 from front 1 to 4 -

 Pin 1 - 5V
	   - 10k Ohm
 pin 2 - 10k Ohm
	   - pin 8
 pin 3 - blank
 pin 4 - -ve

*/

#define DHTPIN 8
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
	lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display }
	dht.begin();
}

void loop()
{
	float h = dht.readHumidity();
	float t = dht.readTemperature();

	if(isnan(t) || isnan(h))
	{
		lcd.println("Failed to Read from DHT");
	}
	else
	{
		lcd.setCursor(0,0);
		lcd.print("Hum: ");
		lcd.print(h);
		lcd.setCursor(0,1);
		lcd.print("Temp: ");
		lcd.print(t);
		lcd.print(" C");
	}
	delay(1500);
	lcd.clear();
}