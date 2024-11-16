#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR     DDRB   // LED 제어를 위한 포트의 데이터 방향 레지스터
#define LED_PORT    PORTB  // LED를 켜고 끄기 위한 포트

int main(void)
{
	LED_DDR = 0xff;     // LED 제어를 위해 포트 B를 출력으로 설정

	while (1)
	{
		// 오른쪽으로 이동하는 루프
		for (uint8_t i = 0; i < 8; i++)
		{
			LED_PORT = (0x01 << i);  // i번째 LED를 ON
			_delay_ms(200);          // 0.2초 지연
		}

		// 왼쪽으로 이동하는 루프
		for (uint8_t i = 7; i > 0; i--)
		{
			LED_PORT = (0x01 << i);  // i번째 LED를 ON
			_delay_ms(200);          // 0.2초 지연
		}
	}
}
