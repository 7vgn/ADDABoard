/*
 * A primitive ADC
 *
 * Connect R-2R to CMP+ and POT to CMP- by placing two jumpers on J7. 
 */

#include<avr/io.h>
#include<util/delay.h>

void main(void)
{
	// Configure Port A as output high
	PORTA = 0xff;
	DDRA = 0xff;
	// Configure Port B as output low
	PORTB = 0;
	DDRB = 0xff;
	// Configure Port C0 as input without pull-up
	PORTC = 0;
	DDRC = 0;

	uint8_t val = 0;
	do
	{
		// Set R-2R output
		PORTB = val;

		// Show current value via LEDs
		PORTA = ~val;

		// Stop when the analogue voltage generated from val is greater than the
		// measured voltage
		if(PINC & 1)
			break;

		val++;
		_delay_ms(100);
	}
	while(val);
	while(1);
}

