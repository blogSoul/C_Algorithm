#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int mainToPoint14to1() {
	// stream : 프로그램과 파일 사이에 교환되는 연속적인 바이트 흐름(데이터의 논리적 흐름)
	FILE *fp, *fq;
	int i, N , num = 10;

	fq = fopen("test.txt", "w");
	if (fq == NULL) {
		printf("Couldn't open file!\n");
		return -1;
		// EOF(End Of File) : 파일의 끝을 표현하기 위해 정의해 놓은 상수(즉, -1)
	}
	for (i = 0; i < 3; ++i) {
		fprintf(fq, "%d\n", i);
	}
	fprintf(fq, "First file test!\n");
	fclose(fq);

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

	return 0;
}

int mainToPoint14to2() {
	FILE *fp1, *fp2;
	char ch;
	char str[100];

	fp1 = fopen("input.txt", "r");
	if (fp1 == NULL) {
		printf("Couldn't open file!");
		return -1;
	}
	fp2 = fopen("output.txt", "w");
	if (fp2 == NULL) {
		printf("Couldn't open file!");
		return -1;
	}
	while ((ch = fgetc(fp1)) != EOF) {
		printf("%c", ch);
		fputc(ch, fp2);
	}
	printf("\n");
	fclose(fp1);
	fclose(fp2);

	fp1 = fopen("input.txt", "r");
	if (fp1 == NULL) {
		printf("Couldn't open file!");
		return -1;
	}
	fp2 = fopen("output.txt", "w");
	if (fp2 == NULL) {
		printf("Couldn't open file!");
		return -1;
	}
	while (fgets(str, sizeof(str), fp1) != NULL) {
		printf("%s\n", str);
		fputs(str, fp2);
	}
	fclose(fp1);
	fclose(fp2);

	// 반환값 참조:
	// fgetc() : 파일 끝에서 EOF(-1) 반환
	// fgets() : 파일 끝에서 NULL(0) 반환
	// fscanf() : 파일 끝에서 EOF(-1) 반환
	
	return 0;
}

int mainToPoint14to3() {
	FILE *fp;
	char str[100];

	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("Couldnt open file!");
		return -1;
	}
	fgets(str, sizeof(str), fp);
	while (!feof(fp)) {
		printf("%s", str);
		fgets(str, sizeof(str), fp);
	}
	// ^Z를 지나가야 feof(fp) 함수는 0이 아닌 값(참)을 반환합니다.
	fclose(fp);
	// feof() 함수는 EOF를 만났을 떄 0을 반환한다.
	return 0;
}

struct person {
	char name[8];
	int age;
};

int main() {
	FILE *fp;
	char mybuf[30];
	struct person buf[10];
	struct person data[10] = { {"Tom", 46}, {"James", 33}, {"Jane", 21} };
	int i, size;

	fp = fopen("data.txt", "wb");
	if (fp == NULL) {
		printf("Couldn't open file!");
		return -1;
	}
	fwrite(data, sizeof(struct person), 3, fp);
	fclose(fp);

	fp = fopen("data.txt", "rb");
	if (fp == NULL) {
		printf("Couldn't open file!");
		return -1;
	}
	fread(buf, sizeof(struct person), 3, fp);
	for (i = 0; i <= 2; ++i) {
		printf("i = %d %s %d\n", i, buf[i].name, buf[i].age);
	}
	fclose(fp);

	fp = fopen("data.txt", "rb");
	if (fp == NULL) {
		printf("Couldn't open file!");
		return -1;
	}
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fclose(fp);
	printf("Size fo the file: %d bytes. \n", size);

	// buffer flush : 필요에 의해 버퍼의 내용을 강제로 파일에 출력하고, 버퍼를 비우는 일
	fp = fopen("data.txt", "w+");
	if (fp == NULL) {
		printf("Couldn't open file!");
		return -1;
	}
	fputs("Remove data (fflush) ", fp);
	fflush(fp);
	// buffer flush : 필요에 의해 버퍼의 내용을 강제로 파일에 출력하고, 버퍼를 비우는 일
	rewind(fp);
	fgets(mybuf, 10, fp);
	puts(mybuf);
	fclose(fp);
	return 0;
}
