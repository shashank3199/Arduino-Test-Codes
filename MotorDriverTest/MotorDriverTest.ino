#define PWMPin 12
#define DIRPin 11

void setup()
{
	pinMode(PWMPin, OUTPUT);
	pinMode(DIRPin, OUTPUT);
}

void loop()
{
	analogWrite(PWMPin, 200);
	digitalWrite(DIRPin, HIGH);
	delay(3000);
	digitalWrite(DIRPin, LOW);
	delay(3000);
}