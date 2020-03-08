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

int main() {
	unsigned int result;
	int a, i, j = 0, num = 0;
	int arr[32];
	for (i = 0; i < 32; ++i)
		arr[i] = NULL;
	for (i = 0; i < 4; ++i) {
		scanf("%d", &a);
		arr[j] = int(a / 16);
		arr[j + 1] = int(a % 16);
		j += 2;
	}

	for (i = 0; i< 8; ++i) 
		printf("%d", arr[i]);
	return 0;
}
