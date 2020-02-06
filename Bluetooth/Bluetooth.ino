#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

void setup() 
{
	pinMode(LED_BUILTIN,OUTPUT);
	Serial.begin(38400);
	BTSerial.begin(38400);
}

char state,push;

void loop()
{
	if(BTSerial.available())
	{
		state=BTSerial.read();
		if(state=='O'||state=='o')
			digitalWrite(LED_BUILTIN,HIGH);     
		else
			digitalWrite(LED_BUILTIN,LOW);
		if(Serial.available())
		{
			push=Serial.read();
			BTSerial.write(push);  
		} 
	} 
}
