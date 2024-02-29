/*
 * Testing the R-2R ladder
 */

#include<avr/io.h>

void main(void)
{
	// Configure Port A as output high
	PORTA = 0xff;
	DDRA = 0xff;
	// Configure Port B as output low
	PORTB = 0;
	DDRB = 0xff;
	// Configure Port D as input with pull-ups
	PORTD = 0xff;
	DDRD = 0;

	while(1)
	{
		// Write value from DIP switches to R-2R ladder
		PORTB = ~PIND;
		// Show value from DIP switches on LEDs
		PORTA = PIND;
	}
}

