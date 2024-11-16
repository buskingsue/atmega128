/*
 * led.c
 *
 * Created: 2024-11-08 오후 12:17:39
 *  Author: user
 */ 
#include "led.h"


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