#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define FND_DATA_DDR	DDRC	// 데이터 방향
#define FND_SELECT_DDR	DDRG	// 디지트 방향
#define FND_DATA_PORT	PORTC	// 데이터 출력
#define FND_SELECT_PORT	PORTG	// 디지트 출력

void FND_Display(uint16_t data);	// 출력 함수 선언

int main(void)
{
	FND_DATA_DDR = 0xff;	// 데이터 핀을 출력 모드로 설정
	FND_SELECT_DDR = 0xff;	// 디지트 핀을 출력 모드로 설정
	FND_SELECT_PORT = 0xff;	// 디지트를 HIGH로 설정하여 초기 비활성화

	uint16_t count = 1000;		// 카운트 초기화
	uint32_t timeTick = 0;	// 시간 틱 변수
	uint32_t prevTime = 0;	// 이전 시간 저장 변수
	
	while (1)
	{
		FND_Display(count);	// FND에 count 값을 표시
		if(timeTick - prevTime > 500)	// 100ms마다 카운트를 증가
		{
			prevTime = timeTick;
			count++;
			if(count > 1100) // 100를 초과하면 0으로 초기화
			count = 1000;
		}
		_delay_ms(1);	// 1ms 대기
		timeTick++;		// 시간 틱 증가
	}
}

void FND_Display(uint16_t data)
{
	static uint8_t position = 0;	// 자릿수 선택 변수
	uint8_t fndData[] =
	{
		~0x3F, ~0x06, ~0x5B, ~0x4F, ~0x66, ~0x6D, ~0x7D, ~0x27, ~0x7F, ~0x67
		// 비트 반전으로 켜고 끄는 상태를 반대로 설정
	};
	
	switch (position)
	{
		case 0:
		// 첫 번째 자릿수 활성화: 0번 핀 HIGH, 나머지 LOW
		FND_SELECT_PORT |= (1 << 0); 
		//NOT 연산자 &= ~(1 << 0); 
		FND_SELECT_PORT &= ~((1 << 1) | (1 << 2) | (1 << 3));
		FND_DATA_PORT = fndData[data / 1000];
		break;
		
		case 1:
		// 두 번째 자릿수 활성화: 1번 핀 HIGH, 나머지 LOW
		FND_SELECT_PORT |= (1 << 1);
		//복합 OR 연산자 a|b = a (==>) a|=b //NOT &= ~(1<<1); 
		FND_SELECT_PORT &= ~((1 << 0) | (1 << 2) | (1 << 3)); 
		//NOT |= (1 << 0) | (1 << 2) | (1 << 3);
		FND_DATA_PORT = fndData[(data / 100) % 10];
		break;
		
		case 2:
		// 세 번째 자릿수 활성화: 2번 핀 HIGH, 나머지 LOW
		FND_SELECT_PORT |= (1 << 2);
		FND_SELECT_PORT &= ~((1 << 0) | (1 << 1) | (1 << 3));
		FND_DATA_PORT = fndData[(data / 10) % 10];
		break;
		
		case 3:
		// 네 번째 자릿수 활성화: 3번 핀 HIGH, 나머지 LOW
		FND_SELECT_PORT |= (1 << 3);
		FND_SELECT_PORT &= ~((1 << 0) | (1 << 1) | (1 << 2));
		FND_DATA_PORT = fndData[data % 10];
		break;
	}
	position++;		// 다음 자릿수로 이동
	position = position % 4; // 4개 자릿수 순환
}
