/*
 * Testing the LEDs and the DIP switches on the AD/DA add-on board
 */

#include<avr/io.h>

void main(void)
{
	// Configure Port A as output high
	PORTA = 0xff;
	DDRA = 0xff;
	// Configure Port D as input with pull-ups
	PORTD = 0xff;
	DDRD = 0;
	// Configure Port C1 as input with pull-up (SW1),
	// C6 as output low (LED9), and C7 as output high (LED10)
	PORTC = 0x82;
	DDRC = 0xc0;

	uint8_t sw1 = PINC & 2;
	while(1)
	{
		// Show state of DIP switches on LEDs 1..8
		PORTA = PIND;

		// If SW1 was pressed, flip LEDs 9/10
		if(sw1 && !(PINC & 2))
			PORTC ^= 0xc0;
		sw1 = PINC & 2;
	}
}

