/*
 * led.h
 *
 * Created: 2024-11-08 오후 12:18:55
 *  Author: user
 */ 
#include <avr/io.h>

#define LED_DDR		DDRB
#define LED_PORT	PORTB
void GPIO_LedInit(); // 함수 원형
void GPIO_Output(uint8_t data);
void ledLeftShift(uint8_t *data);

#ifndef LED_H_
#define LED_H_





#endif /* LED_H_ */