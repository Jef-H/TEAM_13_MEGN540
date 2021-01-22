/*
 * Lab0.c
 *
 * Created: 1/31/2017 10:48:01 AM
 *  Author: Ozkan Celik
 */ 

#define F_CPU 16000000L //Clock speed of Arduino 16 MHz

#include <avr/io.h>
#include <util/delay.h>

// Define function prototypes
void pin_init(void);
void pin_high(void);
void pin_low(void);

// Write functions
void pin_init(void){
	// Specify the pin5 on portB (1<<DDB5) to out
	DDRB = (1<<DDB5);
	// Set this pin as LOW
	PORTB = (0<<PORTB5);
	}

void pin_high(void){
	// Set pin5 on portB as HIGH
	PORTB = (1<<PORTB5);
}

void pin_low(void){
	// Set pin5 on portB as LOW
	PORTB = (0<<PORTB5);
}

// Main program
int main(void)
{
	pin_init();
	/* Replace with your application code */
	while (1)  // run indefinitely
	{
		pin_low();
		_delay_ms(1000);
		pin_high();
		_delay_ms(1000);
	}
}