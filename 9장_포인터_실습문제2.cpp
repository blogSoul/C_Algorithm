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

int findeven(int arr[]) {

}

int main(){

	return 0;
}
