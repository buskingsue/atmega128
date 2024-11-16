#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	
	uint8_t FND_Number[]
	= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};

	int count = 0; // 지역변수 count, 초기값 0
	DDRA = 0xff; // A port 출력 설정

	while (1)
	{
	PORTA = FND_Number[count];
	count = (count + 1) % 10; 
	//나머지 연산자  1 2 3 4 5 6 7 8 9 0 1 ~
	_delay_ms(1000);
	}
}