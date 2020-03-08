#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int EuclidGcd(int a, int b) {
	if (a < b) {
		return EuclidGcd(b, a);
	}
	else if (a == b || (a % b) == 0) {
		return b;
	}
	if (a > b) {
		a = a - b * int(a / b);
		return EuclidGcd(b, a);
	}
}

int maintoPoint13to1() {
	int a, b, gcd;
	scanf("%d", &a);
	scanf("%d", &b);
	gcd = EuclidGcd(a, b);
	printf("%d", gcd);
	return 0;
}

double fatorial(int n) {
	double sum = 1;
	if (n != 0) {
		for (int i = 1; i <= n; ++i) {
			sum *= i;
		}
		return sum;
	}
	else {
		return 1;
	}
};

int maintoPoint13to2() {
	int N, i;
	double e = 0;
	scanf("%d", &N);
	for (i = 0; i <= 30; ++i) {
		e += (1 / fatorial(i));
	}
	printf("%.6f", e);
	return 0;
}

int Fibonacci(int n) {
	if (n > 1)
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	else if (n == 1)
		return 1;
	else if (n == 0)
		return 0;
}

int maintoPoint13to3() {
	int N;
	scanf("%d", &N);
	printf("%d", Fibonacci(N));
	return 0;
}

int maintoPoint13to4() {
	unsigned int result;
	int a, i, j = 0, sum = 0;
	int arr[32];
	
	for (i = 0; i < 4; ++i) {
		scanf("%d", &a);
		arr[j] = int(a / 16);
		arr[j + 1] = int(a % 16);
		j += 2;
	}

	for (i = 0; i < 8; ++i)
		sum += pow(16, 7-i) * arr[i];
	printf("%d\n", sum);
	return 0;
}

void pswap(int **x, int **y) {
	int *temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int maintoPoint13to5() {
	int x, y;
	int *px = &x, *py = &y;

	scanf("%d", &x);
	scanf("%d", &y);

	pswap(&px, &py);

	printf("%d %d\n", *px, *py);
	return 0;
}

void ABC(int (*p)[20], int k1, int k2) {
	(*(p + k1))[k2] = k1 + k2;
}

int maintoPoint13to6() {
	int arr[20][20];
	int N, i, j;
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			ABC(arr, i, j);
		}
	}
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int add4(int a, int b) {
	return a + b;
}

int sub4(int a, int b) {
	return a - b;
}

int multiply4(int a, int b) {
	return a * b;
}

int main() {
	int a, b, i;
	void *p = &a;
	int (*handle[3])(int, int) = {add4, sub4, multiply4};
	int (*fp)(int, int);

	scanf("%d", &a);
	scanf("%d", &b);
	
	for (i = 0; i < 3; ++i) {
		fp = handle[i];
		printf("%d ", fp(a, b));
	}
	printf("\n");
	printf("%d\n", *(int*)(p));
	return 0;
}
