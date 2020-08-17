#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>

int *prefixAverages1(int *p, int N) {
	int i, j;
	double sum;
	int *q;
	q = (int *)calloc(N, sizeof(int));
	for (i = 0; i < N; ++i) {
		sum = 0;
		for (j = 0; j < i + 1; ++j) {
			sum += p[j];
		}
		q[i] = round(sum / (i + 1));
	}
	return q;
}

int *prefixAverages2(int *p, int N) {
	int i, j;
	double sum = 0;
	int *q;
	q = (int *)calloc(N, sizeof(int));
	for (i = 0; i < N; ++i) {
		sum += p[i];
		q[i] = round(sum / (i + 1));
	}
	return q;
}

int main() {
	int N, i, num;
	int *p, *q, *r;
	LARGE_INTEGER tickPerSec, start, end, diff;
	
	printf("난수 크기 : ");
	scanf("%d", &N); // 난수 크기 설정
	p = (int *)calloc(N, sizeof(int)); // 크기에 맞게 동적 할당
	srand(time(NULL)); // seed 설정
	for (i = 0; i < N; ++i) {
		p[i] = ((((long)rand() << 15) | rand()) % 1000000) + 1;
	}// 난수 생성

	printf("prefixAverages1알고리즘 수행시간 : ");
	QueryPerformanceFrequency(&tickPerSec);	
	QueryPerformanceCounter(&start);
	q = prefixAverages1(p, N); 
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("time: %.12f sec\n", (double)diff.QuadPart / (double)tickPerSec.QuadPart);

	printf("prefixAverages2알고리즘 수행시간 : ");
	QueryPerformanceFrequency(&tickPerSec);
	QueryPerformanceCounter(&start);
	r = prefixAverages2(p, N);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("time: %.12f sec\n", (double)diff.QuadPart / (double)tickPerSec.QuadPart);

	return 0;
}
