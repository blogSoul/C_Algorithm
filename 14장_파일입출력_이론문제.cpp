#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int mainToPoint14to1() {
	// stream : 프로그램과 파일 사이에 교환되는 연속적인 바이트 흐름(데이터의 논리적 흐름)
	FILE *fp;
	int i, N , num = 10;

	fp = fopen("test.txt", "r");
	// 만약 경로로 설정하고 싶으면 "C:\\C_pro\\Project\\test.dat"와 같이 \\로 경로를 설정해줍니다.
	// r: 읽기, w: 쓰기, a: 추가
	if (fp == NULL) {
		printf("Couldn't open file!\n");
		return -1;
		// EOF(End Of File) : 파일의 끝을 표현하기 위해 정의해 놓은 상수(즉, -1)
	}

	for (i = 0; i < 3; ++i) {
		fscanf(fp, "%d", &N); // 스캔을 할 대상을 확인해야 한다.
		printf("%d\n", N);
	}
	fclose(fp);

	fp = fopen("test.txt", "w");
	fprintf(fp, "First file test!\n");
	fprintf(fp, "나이: %d세", num);
	fclose(fp);

	return 0;
}

int main() {
	FILE *fp1
}
