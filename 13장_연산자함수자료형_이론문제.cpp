#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mainToPoint13to1() {
	// 비트 단위 논리 연산자 : x & y
	int x = 0X2A;
	int y = 0XAD;
	int z = x & y;
	int a = x << 4; 
	// 비트 단위 이동 연산 : x를 비트 단위로 왼쪽으로 4만큼 이동
	// 오른쪽 빈 자리는 k개의 0으로 채움

	printf("%#X\n", z);
	printf("%#X\n", a);
	return 0;
}

int mainToPoint13to2() {
	unsigned char a = 01101100;
	unsigned char b = 01001010;
	unsigned char c;
	int x, zs, zu;

	printf("%#X %#X %#X\n", a&b, a | b, a^b);
	printf("%#X %#X %#X\n", ~a, a<<2, a>>2);

	x = 0XA1234567; // x = 1010 0001 ...
	zs = (signed)x >> 4; // 결과: 1111 1010 0001 ....
	zu = (unsigned)x >> 4; // 결과: 0000 1010 0001 .....
	printf("signed = %#X, unsigned = %#X\n", zs, zu);

	x = 0X71234567; // x = 1010 0001 ...
	zs = (signed)x >> 4; // 결과: 0000 0111 0001 ....
	zu = (unsigned)x >> 4; // 결과: 0000 0111 0001 .....
	printf("signed = %#X, unsigned = %#X\n", zs, zu);
	return 0;
}

int mainToPoint13to3() {
	int x = 0X71234567;
	x = x >> 10; 
	// 오른쪽에서 10번째 비트를 가장 오른쪽에 위치시킴
	x = x & 1;
	// x와 ... 0001 의 AND
	// 두 문장을 하나로 합하면 (x >> 10) & 1

	printf("%d\n", x);
	return 0;
}

void dec1(int x) {
	printf("x: %d\n", x);
	if (x > 1)
		dec1(x - 1);
}

void dec2(int x) {
	printf("+start: x=%d\n", x);
	if (x > 1) dec2(x - 1);
	printf("-end: x=%d\n", x);
}

int sum(int n) {
	if (n == 1) return 1;
	return sum(n - 1) + n;
}

int factorial(int n) {
	if (n == 1) return 1;
	return factorial(n - 1) * n;
}

int main() {
	dec1(3);
	printf("\n");
	dec2(3);
	printf("\n");
	printf("%d\n", sum(10));
	printf("%d\n", factorial(10));
	printf("%d\n", rand()); // 난수 생성
	return 0;
}
