#include <stdio.h>
#include <string.h>

void input(int *a, int *b, int *c) {
	scanf("%d %d %d", a, b, c);
}

void output(int *a, int *b, int *c) {
	printf("%d %d %d", *a, *b, *c);
}

int mainToPoint9To7() {
	int x, y, z;
	input(&x, &y, &z);
	output(&x, &y, &z);
	return 0;
}

void swap_1(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int mainToPoint9To8() {
	int ar[50];
	int N, temp;
	int *p = ar;
	int a, b;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", (p + i));
	}

	scanf("%d %d", &a, &b);

	swap_1((p + a), (p + b));

	for (int i = 0; i < N; i++) {
		printf(" %d", *(p + i));
	}
	return 0;
}

void sum_1(int *a, int *b) {
	int add, temp;
	add = *a + *b;
	temp = *a - *b;
	*a = add;
	*b = temp;
}

int mainToPoint9To9() {
	int a, b;
	scanf("%d %d", &a, &b);
	sum_1(&a, &b);
	printf("%d %d", a, b);
	return 0;
}

int gcd(int a, int b) {
	int temp;
	while (true) {
		if (a < b) {
			temp = a;
			a = b;
			b = temp;
		}

		if (a % b == 0) {
			temp = b;
			return temp;
		}
		a = a % b;
	}
}

void gcdlcm(int a, int b, int *p, int *q) {
	*p = gcd(a, b);
	*q = (a*b) / gcd(a, b);
}

int mainToPoint9To10() {
	int a, b;
	int *p = &a, *q = &b;
	scanf("%d %d", &a, &b);
	gcdlcm(a, b, p, q);
	printf("%d %d", *p, *q);
	return 0;
}

int findeven(int *p,int N) {
	int num = 0;
	for (int i = 0; i < N; i++) {
		if (*(p + i) % 2 == 0) {
			num += 1;
		}
	}
	return num;
}

int mainToPoint9To11(){
	int N;
	int arr[100];
	int *p = arr;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", (p + i));
	}
	printf("%d", findeven(p, N));
	return 0;
}

void strcopy(char *p, char *q) {
	for (int i = 0; i < 6; i++) {
		*(p + i) = *(q + i);
	}
}

int mainToPoint9To12() {
	char a[10], b[10];
	char *p= a, *q = b;
	for (int i = 0; i < 6; i++) {
		scanf("%c", (q + i));
	}

	strcopy(p, q);

	for (int i = 0; i < 6; i++) {
		printf("%c", *(p + i));
	}
	return 0;
}

void addArray(int *a, int *b, int *c, int N) {
	for (int i = 0; i < N; i++) {
		*(c + i) = *(a + i) + *(b + N - 1 - i);
	}
}

int mainToPoint9To13() {
	int N;
	int a[10], b[10], c[10];
	int *p = a, *q = b, *r = c;
	scanf("%d", &N);
	for (int i = 0;i<N; i++) {
		scanf("%d", (p + i));
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", (q + i));
	}
	addArray(p, q, r, N);
	for (int i = 0; i < N; i++) {
		printf(" %d", *(r + i));
	}
	return 0;
}

void ABC(int *p ,int k) {
	int max = *p, num, temp;
	for (int i = 0; i < k; i++) {
		if (max <= *(p + i)) {
			max = *(p + i);
			num = i;
		}
	}
	temp = *p;
	*p = *(p + num);
	*(p + num) = temp;
}

int mainToPoint9To14() {
	int arr[10];
	int *p = arr;
	for (int i = 0; i < 10; i++) {
		scanf("%d", (p + i));
	}
	for (int i = 0; i < 9; i++) {
		ABC((p + i), 10 - i);
	}
	for (int i = 0; i < 10; i++) {
		printf(" %d", *(p + i));
	}
	return 0;
}

int arrsum(int *start, int *end) {
	int sum = 0;
	int *p;
	for (p = start; p <= end; p++) {
		sum += *p;
	}
	// 포인터 위치로 반복문에서 배열을 사용하는 예시이다.
	return sum;
}

int mainToPoint9To15() {
	int N, S, E;
	int arr[100];
	int *p = arr;

	scanf("%d %d %d", &N, &S, &E);
	for (int i = 0; i < N; i++) {
		scanf("%d", (p + i));
	}
	printf("%d", arrsum((p + S), (p + E)));
	return 0;
}
