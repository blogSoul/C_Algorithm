#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int sum2(int num) {
	if (num == 1)
		return 1;
	return num + sum2(num - 1);
}

int main3to1() {
	int num;
	scanf("%d", &num);
	num = sum2(num);
	printf("%d\n", num);
	return 0;
}

int main3to2() {
	int num, N, cnt, i;
	scanf("%d", &num);
	N = num;
	for (cnt = 0;; ++cnt) {
		if (N < pow(10, cnt)) {
			break;
		}
	}
	if (N == 0) {
		printf("%d\n", N);
		return 0;
	}
	for (i = cnt-1;0 <= i; --i) {
		N = num / pow(10, i);
		printf("%d\n", N);
		num -= N * pow(10, i);
	}
	return 0;
}

void digitAndNumber(int n) {
	if (n == 0) {
		return;
	}
	//printf("%d\n", n / 10);
	printf("%d\n", n % 10);
	return digitAndNumber(n / 10);
}

int main3to3() {
	int num, N, cnt, i;
	scanf("%d", &num);
	N = num;
	digitAndNumber(num);
	return 0;
}

int maxArr(int arr[]) {
	int num;
	num = sizeof(arr) / sizeof(int);
}

int main() {
	int N, i;
	int *p;
	scanf("%d", &N);
	p = (int*)calloc(N,sizeof(int));
	for (i = 0; i < N; ++i) {
		scanf("%d", &p[i]);
	}

	return 0;
}
