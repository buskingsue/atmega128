#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR		DDRB
#define LED_PORT	PORTB

void GPIO_LedInit();
void GPIO_Output(uint8_t data);
void ledLeftShift(uint8_t *data);

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

// LED 포트 레지스터에 출력 방향 설정 함수
void GPIO_LedInit()
{
	LED_DDR = 0xff;
}

// LED 포트 레지스터에 데이터를 출력하는 함수
void GPIO_Output(uint8_t data)
{
	LED_PORT = data;	// data 값을 portb 에 출력
}

// LED를 좌측으로 이동하는 함수
void ledLeftShift(uint8_t *data)
{
	*data = (*data >> 7) | (*data << 1);
	GPIO_Output(*data);
}

// LED를 우측으로
void ledRightShift(uint8_t *data)
{
	*data = (*data << 7) | (*data >> 1);
	GPIO_Output(*data);
}
