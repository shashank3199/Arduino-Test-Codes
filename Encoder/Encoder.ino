// Tested: Works fine, needs compatibility with the PPR
// Source:  https://robu.in/run-rotary-encoder-arduino-code/.

// These pins can not be changed 2/3 are special pins
int encoderPin1 = 2;
int encoderPin2 = 3;

volatile int lastEncoded = 0;
volatile long encoderValue = 0;

int rotations=0;

long lastencoderValue = 0;

void setup()
{
	Serial.begin (9600);
	pinMode(encoderPin1, INPUT);
	pinMode(encoderPin2, INPUT);
	pinMode(9, OUTPUT);
	pinMode(9, OUTPUT);

	digitalWrite(encoderPin1, HIGH); //turn pullup resistor on
	digitalWrite(encoderPin2, HIGH); //turn pullup resistor on
	digitalWrite(8,HIGH);
	analogWrite(9,50);

	//call updateEncoder() when any high/low changed seen
	//on interrupt 0 (pin 2), or interrupt 1 (pin 3)
	attachInterrupt(0, updateEncoder, CHANGE);
	attachInterrupt(1, updateEncoder, CHANGE);

}

void loop()
{
	Serial.println(rotations);
	delay(100);
}

void updateEncoder()
{
	int MSB = digitalRead(encoderPin1);
	int LSB = digitalRead(encoderPin2);

	int encoded = (MSB << 1) | LSB; //converting the 2 pin value to single number
	int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

	if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++;
	if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --;
	rotations=encoderValue/1120;

	lastEncoded = encoded; //store this value for next time
}
