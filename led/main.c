#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB = 0xff; //0b11111111 -> 출력 설정

    while (1) 
    {
		PORTB = 0xff;
		//0b11111111 -> 각 포트 출력
		_delay_ms(500); //0.5초 딜레이 지연시간
		PORTB =0x00; //500ms
		_delay_ms(500); //0.5초 딜레이 지연시간
    }
}

