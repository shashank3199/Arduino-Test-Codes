void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
	digitalWrite(LED_BUILTIN, HIGH);    // turn the LED on by making the voltage HIGH
	delay(250);
	digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
	delay(250);
	digitalWrite(LED_BUILTIN, HIGH);    // turn the LED on by making the voltage HIGH
	delay(250);
	digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
	delay(1000);
}