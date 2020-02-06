int PWM_pins[] = {7, 8, 9, 10};    // List of PWM pins
int DIR_pins[] = {49, 47, 51, 53}; // List of DIR pins

void setup()
{
  // put your setup code here, to run once:
  for (int i = 0; i < 4; i++)
  {
    pinMode(PWM_pins[i], OUTPUT);
    pinMode(DIR_pins[i], OUTPUT);
    digitalWrite(DIR_pins[i], LOW);
  }
  digitalWrite(DIR_pins[2],HIGH);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 4; i++)
  {
    analogWrite(PWM_pins[i], 80);
  }
}
