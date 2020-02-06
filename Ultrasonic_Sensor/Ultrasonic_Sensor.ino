#define trigPin 51
#define echoPin 47

long duration;
int distance;

void setup()
{
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	Serial.begin(9600);
}

void loop()
{
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);

	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	duration = pulseIn(echoPin, HIGH);
	distance = duration * 0.0343 / 2;

	Serial.print("Distance: ");
	Serial.print(distance);
	delay(200);
	Serial.print(" cm\n");
}