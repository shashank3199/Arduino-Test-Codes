#include <LiquidCrystal.h>
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)

void setup()
{
	pinMode(8,OUTPUT);
	analogWrite(8,50);
 	// Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display }
	lcd.begin(16,2);
}

void loop()
{
	lcd.setCursor(5,0);
	lcd.print("Hello"); // Prints Statement on the LCD
	lcd.setCursor(5,1); // Sets the location at which subsequent text written to the LCD will be displayed
	lcd.print("World");
	delay(3000);
	lcd.clear(); // Clears the display
	/*************************************************************************************************************
	lcd.blink(); //Displays the blinking LCD cursor
	delay(4000);
	lcd.setCursor(7,1);
	delay(3000);
	lcd.noBlink(); // Turns off the blinking LCD cursor
	lcd.cursor(); // Displays an underscore (line) at the position to which the next character will be written
	delay(4000);
	lcd.noCursor(); // Hides the LCD cursor
	lcd.clear(); // Clears the LCD screen
	*************************************************************************************************************/
}