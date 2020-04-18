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

int maxArr(int *p, int num) {
	if (num == 1) {
		return p[0];
	}
	else if (p[num - 1] >= maxArr(p, num - 1)) {
		return p[num - 1];
	}
	else if (p[num - 1] < maxArr(p, num - 1)) {
		return maxArr(p, num - 1);
	}
}

int main3to4() {
	int N, i;
	int *p;
	scanf("%d", &N);
	p = (int*)calloc(N, sizeof(int));
	for (i = 0; i < N; ++i) {
		scanf("%d", &p[i]);
	}
	printf("%d\n", maxArr(p, N));
	free(p);
	return 0;
}

void hanoi(int N, char a, char b, char c) {
	if (N == 1) {
		printf("%c %c\n", a, c);
		return;
	}
	else {
		hanoi(N - 1, a, c, b);
		hanoi(1, a, b, c);
		hanoi(N - 1, b, a, c);
		return;
	}
}

int main3to5() {
	int N;
	char A, B, C;
	scanf("%d", &N);
	hanoi(N, 'A', 'B', 'C');
	return 0;
}

int gcd(int a, int b) {
	if (b != 0) {
		return gcd(b, a % b);
	}
	else {
		return a;
	}
}

int main3to6() {
	int A, B;
	scanf("%d %d", &A, &B);
	printf("%d\n", gcd(A, B));
	return 0;
}

int num1 = 0;
int checkWord(char *p, char word) {
	if (p[0] == NULL) {
		return num1;
	}
	else if (p[0] == word) {
		num1 += 1;
		return checkWord(p + 1, word);
	}
	else if(p[0] != word){
		return checkWord(p + 1, word);
	}
}

int main3to7() {
	char a;
	char arr[100];
	scanf("%s", arr);
	getchar();
	scanf("%c", &a);
	printf("%d\n", checkWord(arr, a));
	return 0;
}
