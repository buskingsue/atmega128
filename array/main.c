#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR     DDRB   // LED 제어를 위한 포트의 데이터 방향 레지스터
#define LED_PORT    PORTB  // LED를 켜고 끄기 위한 포트

int main(void)
{
	LED_DDR = 0xff;       // LED 제어를 위해 포트 B를 출력으로 설정

	while (1)
	{
		uint8_t led_pattern = 0x01;    // 초기 패턴 값 (0000 0001)

		for (uint8_t i = 0; i < 8; i++)
		{
			LED_PORT = led_pattern;    // 현재 패턴을 LED 포트에 출력
			_delay_ms(200);            // 0.2초 지연
			led_pattern = (led_pattern << 1) | 0x01;  // 패턴을 왼쪽으로 이동하고 1을 추가
		}
	}
}
