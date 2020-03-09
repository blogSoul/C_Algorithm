#include <stdio.h>
#include <string.h>

//8장 3절 문제 1
int add(int a, int b) {
	return a + b;
}

int mainToProblem8to1() {
	int a;
	int sum = 0;
	scanf("%d", &a);

	for (int i = 1; i <= a; i++) {
		sum = add(sum, i);
	}
	printf("%d", sum);
	return 0;
}

//8장 3절 문제 2
int sum(int a, int b) {
	int sum = 0;
	sum = (b*(b + 1) / 2) - (a*(a - 1) / 2);
	return sum;
}

int mainToProblem8to2() {
	int a;
	int b;
	int num = 0;
	scanf("%d %d", &a, &b);
	num = sum(a, b);
	printf("%d", num);
	return 0;
}

//8장 3절 문제 3
int mainToProblem8to3() {
	int a;
	int num = 0;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++) {
		num += sum(1, i);
	}
	printf("%d", num);
	return 0;
}

//8장 3절 문제 4
void print_row1(int x){
	for (int i = 0; i < x; i++) {
		printf("%d", x);
	}
}

void print_row2(int x) {
	printf("%d", x);
	for (int i = 0; i < x-2; i++) {
		printf(" ");
	}
	printf("%d", x);
}

int mainToProblem8to4() {
	int a;
	int num = 0;
	scanf("%d", &a);
	print_row1(a);
	printf("\n");
	for (int i = 0; i < a-2; i++) {
		print_row2(a);
		printf("\n");
	}
	print_row1(a);
	printf("\n");
	return 0;
}

//8장 3절 문제 5
void print_triangle(int x) {
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

int mainToProblem8to5() {
	int a;
	while (true) {
		scanf("%d", &a);
		if (a <= 0) {
			break;
		}
		print_triangle(a);
	}
	return 0;
}

//8장 3절 문제 6
int func1(int x) {
	return 2 * x * x - 5 * x + 1;
}

int mainToProblem8to6() {
	int a;
	scanf("%d", &a);
	printf("%d", func1(a));
	return 0;
}

//8장 3절 문제 7
int func2(int x, int a, int b, int c) {
	int sum = 0;
	sum = a * x * x + b * x + c;
	return sum;
}

int mainToProblem8to7() {
	int num;
	int a, b, c;
	scanf("%d", &num);
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", func2(num, a, b, c));
	return 0;
}

//8장 3절 문제 8
int mainToProblem8to8() {
	int num;
	int a, b, c;
	int d, e, f;
	int sum = 0;
	scanf("%d", &num);
	scanf("%d %d %d", &a, &b, &c);
	scanf("%d %d %d", &d, &e, &f);
	sum = func2(num, a, b, c);
	sum = func2(sum, d, e, f);
	printf("%d", sum);
	return 0;
}

//8장 4절 문제 9
int max1;
int max2;
void update_max(int x) {
	if (max1 <= x) {
		max2 = max1;
		max1 = x;
	}
	if (max2 <= x && x < max1) {
		max2 = x;
	}
}

int mainToProblem8to9() {
	int num;
	while (true) {
		scanf("%d", &num);
		if (num == 0) {
			break;
		}
		update_max(num);
	}
	printf("%d %d", max1, max2);
	return 0;
}

//8장 4절 문제 10
int N;
void die3(int x, int y, int z) {
	int sum = 0;
	sum = x + y + z;
	if (sum == N) {
		printf("%d %d %d", x, y, z);
		printf("\n");
	}
}
void die2(int x, int y) {
	for (int i = 1; i <= 6; i++) {
		die3(x, y, i);
	}
}
void die1(int x) {
	for (int i = 1; i <= 6; i++) {
		die2(x, i);
	}
}
int mainToProblem8to10() {
	int num;
	scanf("%d", &num);
	N = num;
	for (int i = 1; i <= 6; i++) {
		die1(i);
	}
	return 0;
}

//8장 4절 문제 11
int A, B, C;
int count_strike(int a, int b, int c) {
	int count = 0;
	if (A == a) {
		count += 1;
	}
	if (B == b) {
		count += 1;
	}
	if (C == c) {
		count += 1;
	}
	return count;
}
int count_ball(int a, int b, int c) {
	int count = 0;
	if (A == b) {
		count += 1;
	}
	if (A == c) {
		count += 1;
	}
	if (B == a) {
		count += 1;
	}
	if (B == c) {
		count += 1;
	}
	if (C == a) {
		count += 1;
	}
	if (C == b) {
		count += 1;
	}
	return count;
}
int mainToProblem8to11() {
	int a, b, c;
	int d, e, f;
	scanf("%d %d %d", &a, &b, &c);
	A = a;
	B = b;
	C = c;
	while (true) {
		scanf("%d %d %d", &d, &e, &f);
		printf("%dS%dB\n", count_strike(d, e, f), count_ball(d, e, f));
		if (count_strike(d, e, f) == 3) {
			break;
		}
	}
	return 0;
}

//8장 4절 문제 12
void print_line(int x, int y, int z) {
	for (int i = 0; i < x; i++) {
		printf(" ");
	}
	for (int i = 0; i < y; i++) {
		printf("*");
	}
	for (int i = 0; i < z; i++) {
		printf(" ");
	}
}

int mainToProblem8to12() {
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		print_line(num - i, 2 * i + 1, num - i);
		printf("\n");
	}
	return 0;
}

//8장 4절 문제 13
int count_3(int num) {
	int count = 0;
	int j;
	for (int i = 1; i <= num; i++) {
		j = i;
		while (true) {
			if (j % 10 == 3) {
				count += 1;
			}
			j = j / 10;
			if (j < 1) {
				break;
			}			
		}
	}
	return count;
}
int mainToProblem8to13() {
	int a;
	scanf("%d", &a);
	printf("%d", count_3(a));
	return 0;
}

//8장 4절 문제 14
int is_prime(int x) {
	int isPrime = 1;
	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			isPrime = 0;
			break;
		}
	}
	return isPrime;
}
int next_prime(int x) {
	while (true) {
		x += 1;
		if (is_prime(x) == 1) {
			return x;
		}
	}
}

int mainToProblem8to14() {
	int num;
	int a;
	int b;
	scanf("%d %d", &num, &a);

	for (int i = 0; i < a; i++) {
		printf(" %d", next_prime(num));
		num = next_prime(num);
	}
}
