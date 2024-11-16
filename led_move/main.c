#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR		DDRB //led 제어를 위한 포트의 데이터 방향 레지스터
#define LED_PORT	PORTB //LED를 켜고 끄기 위한 포트
//형식 케스팅 (uint16_t)uint8_t bit8 = 0; //8비트를 16비트로 쓸거야
	int main(void)
	{
		LED_DDR = 0xff;
		
		while (1)
		{
			for(uint8_t i=0; i <8;i++)
			{
				LED_PORT = (0x01 << i);
				_delay_ms(200); //0.2초 딜레이 지연시간
			/*
			i=0	0b 0000 0001
			1	0b 0000 0010
			2	0b 0000 0100
			3	0b 0000 1000
			4	0b 0001 0000
			5	0b 0010 0000
			6	0b 010 00000
			7	0b 100 00000

			*/
			}
			
		}
	}




