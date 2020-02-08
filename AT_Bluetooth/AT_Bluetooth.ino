//#include<SoftwareSerial.h>

//SoftwareSerial BTSerial(11,10);

char serialByte = '0';
const byte  LEDPIN = 13;

#define BTSerial Serial1
#define BT_BAUD 38400

void setup()
{
	pinMode(LEDPIN, OUTPUT);
  	// communication with the host computer
	Serial.begin(9600);
	Serial.println("Do not power the BT module");
	Serial.println("On the BT module, press the button switch (keep pressed, and at the same time power the BT module");
	Serial.println("The LED on the BT module should now flash on/off every 2 seconds");
	Serial.println("Can now release the button switch on the BT module");
	Serial.println("After entering AT mode, type 1 and hit send");
	Serial.println();

  	// wait for the user to type "1" in the serial monitor
	while (serialByte != '1')
	{
		if ( Serial.available() )
			serialByte = Serial.read();
	}

  	// communication with the BT module on BTSerial
	BTSerial.begin(BT_BAUD);
  	// LED to show we have started the serial channels
	digitalWrite(LEDPIN, HIGH);

	Serial.println("AT mode.");
	Serial.println("Remember to to set Both NL & CR in the serial monitor.");
	Serial.println("The HC-05 accepts commands in both upper case and lower case");
}


void loop()
{
  	// Keep reading from HC-05 and send to Arduino Serial Monitor
	if (BTSerial.available())
		Serial.write(BTSerial.read());

  	// Keep reading from Arduino Serial Monitor and send to HC-05
	if (Serial.available())
		BTSerial.write(Serial.read());
}