#define ENCODERPIN1 2
#define ENCODERPIN2 3
#define RESOLUTION 4920
#define PWMPin 9
#define DIRPin 8
#define DEGtoCOUNT(x) (RESOLUTION/360)*x
#define Delta(x,y,c) (((x-y)<c) || ((x-y)>-c)) ? 1 : 0
#define MtrDir(x) (x>0) ? 1 : 0

volatile int lastEncoded = 0;
volatile int rotations = 0;
volatile long encoderValue = 0;
volatile int position =  0;

int motorSpeed = 0;
boolean motorDir = LOW;

void updateEncoder()
{
	int MSB = digitalRead(ENCODERPIN1);
	int LSB = digitalRead(ENCODERPIN2);
	//converting the 2 pin value to single number
	int encoded = (MSB << 1) | LSB;
	//adding it to the previous encoded value
	int sum  = (lastEncoded << 2) | encoded;
	if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011)
	encoderValue++;

	if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000)
	encoderValue--;

	if (fabs(encoderValue - position) < 10)
	analogWrite(PWMPin, 0);

	//store this value for next time
	lastEncoded = encoded;
}

void MoveTo()
{
	int error = position - encoderValue;
	motorDir = MtrDir(error);
	digitalWrite(DIRPin, motorDir);
	Serial.println(fabs(error));
	if (fabs(error) > 10)
	{
		analogWrite(PWMPin, motorSpeed);
	}
	else if (fabs(error) > 0)
	{
		analogWrite(PWMPin, 50);
	}
	else
	{
		analogWrite(PWMPin, 0);
	}
}

void setup()
{
	//=================================================================//
	Serial.begin (9600);

	//=================================================================//
	pinMode(ENCODERPIN1, INPUT);
	pinMode(ENCODERPIN2, INPUT);
	pinMode(PWMPin, OUTPUT);
	pinMode(DIRPin, OUTPUT);

	//=================================================================//
	digitalWrite(ENCODERPIN1, HIGH); //turn pullup resistor on
	digitalWrite(ENCODERPIN2, HIGH); //turn pullup resistor on

	//=================================================================//
	//call updateEncoder() when any high/low changed seen
	attachInterrupt(0, updateEncoder, CHANGE);
	attachInterrupt(1, updateEncoder, CHANGE);
	//on interrupt 0 (pin 2), or interrupt 1 (pin 3)

	//=================================================================//
	motorSpeed = 200;
}

void loop()
{
	if (Serial.available())
		position = DEGtoCOUNT(Serial.parseInt());
	MoveTo();
	delay(100);
}