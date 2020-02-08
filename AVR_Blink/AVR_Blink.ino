#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 4000000UL

int main(void)
{
	DDRB |= (1 << DDB5);
	while(1)
	{
		PORTB |= (1 << PORTB5);
		_delay_ms(1000); 
		PORTB &= ~(1 << PORTB5);
		_delay_ms(1000); 
	}
}