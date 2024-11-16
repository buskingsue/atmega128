#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR     DDRB   // LED 제어를 위한 포트의 데이터 방향 레지스터
#define LED_PORT    PORTB  // LED를 켜고 끄기 위한 포트

int main(void)
{
	LED_DDR = 0xff;       // LED 제어를 위해 포트 B를 출력으로 설정

	// LED 패턴 배열 정의
	uint8_t led_patterns[] = { //배열의 개수 선언 안해도 들어감
		0b10000001,  // 1000 0001 //0x81
		0b01000010,  // 0100 0010 //0x42
		0b00100100,  // 0010 0100 //0x24
		0b00011000,  // 0001 1000 //0x14
		0b00100100,  // 0010 0100 //0x24
		0b01000010,  // 0100 0010 //0x42
		0b10000001   // 1000 0001 //0x41
	};

	uint8_t num_patterns = sizeof(led_patterns) / sizeof(led_patterns[0]);  // 패턴 개수
	//배열 개수

	while (1)
	{
		// 각 패턴을 순서대로 출력
		for (uint8_t i = 0; i < num_patterns; i++)
		{
			LED_PORT = led_patterns[i];  // 현재 패턴을 LED 포트에 출력
			_delay_ms(200);              // 0.2초 지연
		}
	}
}
