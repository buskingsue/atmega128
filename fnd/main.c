#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

// FND에서 숫자 0부터 9까지를 나타내는 세그먼트 맵핑을 설정합니다.
uint8_t segment_map[10] = {
	0b00111111, // 숫자 0 0x3F
	0b00000110, // 숫자 1 0x06
	0b01011011, // 숫자 2 0x5B
	0b01001111, // 숫자 3 0x4F
	0b01100110, // 숫자 4 0x66
	0b01101101, // 숫자 5 0x6D
	0b01111101, // 숫자 6 0x7D
	0b00000111, // 숫자 7 0x27
	0b01111111, // 숫자 8 0x7F
	0b01101111  // 숫자 9 0x6F
};

// 특정 숫자를 FND에 출력하는 함수입니다.
void display_digit(uint8_t num) {
	PORTA = segment_map[num]; // PORTA에 세그먼트 값을 출력하여 숫자를 표시
}

int main(void) {
	// PORTA를 출력 모드로 설정합니다.
	DDRA = 0xFF;

	// 숫자 0부터 9까지 반복 출력
	while (1) {
		for (uint8_t i = 0; i < 10; i++) {
			display_digit(i); // 숫자를 FND에 출력
			_delay_ms(1000);  // 1초 대기 후 다음 숫자로 이동
		}
	}
	return 0;
}
