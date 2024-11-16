#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "led.h"

int main(void)
{
	GPIO_LedInit(); // DDRB = 0xFF;
	uint8_t ledData = 0x01;	// 0b00000001;
	
	while (1)
	{
		for (int i = 0; i < 7; i++)
		{
			ledLeftShift(&ledData);
			_delay_ms(300);
		}
	}
}

