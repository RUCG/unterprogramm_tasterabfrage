#include <stdlib.h>
#include <avr/io.h>

#define TASTER1 !(PINB & (1<<PB1))// Wenn TASTER1 auf 0
#define LED_ON (PORTD |= (1<<PD0))// Befehl um die LED zum leuchten bringen
#define LED_OFF (PORTD &= ~(1<<PD0))// Befehl um LED aus zu schalten


short taster(char nr)
{
	if(nr == 1)
	{
		if(TASTER1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 0;	
}

	
	

int main(void)
{
	
	
	DDRD = 0xFF; // PORT D wird als Ausgang definiert
	PORTD = 0x00; //LED grundsäzlich dunkel
	
	DDRB = 0x00; // PORTB als Eingang definiert
	PORTB = 0xFF; // Interner Pull-up gesetzt

	while(1)
	{
		if(taster(1)==1)
		{
			LED_ON;
		}
		else
		{
			LED_OFF;
		}
	
	}
	
return 0;
}