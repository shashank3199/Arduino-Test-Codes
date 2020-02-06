// Driver represents the connections on the L298 Module from the Motors
struct driver                 
{
	int pin_1;
	int pin_2;
} d_left(2,3),d_right(4,5);
// There are two Drivers (one for each Side) on 1 L298 Module

void setup()                  // The pins in the Driver structure represent the two terminals of the motor
{
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	pinMode(4,OUTPUT);
	pinMode(5,OUTPUT);
	Serial.begin(9600);         // Serial Communication to accept the command
}
					  // Two motors which are on the same side are connected in the Parallel connection as shown in the Figure
void main()
{
	char cmd = Serial.read();
	if(cmd=='f'||cmd=='F')
	{
		digitalWrite(d_left.pin_1,HIGH);      // Combination_1 : Rotates in the ClockWise Direction
		digitalWrite(d_left.pin_2,LOW);
																									// Net Motion: Forward
		digitalWrite(d_right.pin_1,LOW);      // Combination_2 : Rotates in the Anti-ClockWise Direction
		digitalWrite(d_right.pin_2,HIGH);
	}

	else if(cmd=='b'||cmd=='B')
	{
		digitalWrite(d_left.pin_1,LOW);       // Combination_1 : Rotates in the Anti-ClockWise Direction
		digitalWrite(d_left.pin_2,HIGH);
																									// Net Motion: Backward
		digitalWrite(d_right.pin_1,HIGH);      // Combination_2 : Rotates in the ClockWise Direction
		digitalWrite(d_right.pin_2,LOW);
	}

	else if(cmd=='r'||cmd=='R')
	{
		digitalWrite(d_left.pin_1,LOW);       // Combination_1 : Rotates in the ClockWise Direction
		digitalWrite(d_left.pin_2,HIGH);
																									// Net Motion: Right
		digitalWrite(d_right.pin_1,LOW);      // Combination_2 : Rotates in the ClockWise Direction
		digitalWrite(d_right.pin_2,HIGH);
	}

	else if(cmd=='L'||cmd=='l')
	{
		digitalWrite(d_left.pin_1,HIGH);     // Combination_1 : Rotates in the Anti-ClockWise Direction
		digitalWrite(d_left.pin_2,LOW);
																									// Net Motion: Left
		digitalWrite(d_right.pin_1,HIGH);      // Combination_2 : Rotates in the Anti-ClockWise Direction
		digitalWrite(d_right.pin_2,LOW);
	}

	else
	{
		digitalWrite(d_left.pin_1,LOW);      // Combination_1 : Does'nt Rotate
		digitalWrite(d_left.pin_2,LOW);
																									// Net Motion: Stops
		digitalWrite(d_right.pin_1,LOW);      // Combination_2 : Does'nt Rotate
		digitalWrite(d_right.pin_2,LOW);
	}
}