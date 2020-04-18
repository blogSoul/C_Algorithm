#include <stdio.h>
#include <stdlib.h>

int sumNumber(int num) {
	if (num > 9) {
		return sumNumber(num / 10) + (num % 10);
	}
	else {
		return num;
	}
}

int main2TO1() {
	int num;
	scanf("%d", &num);
	printf("%d\n", sumNumber(num));
	return 0;
}

int Fibonacci(int num) {
	if (num > 2) {
		return Fibonacci(num - 1) + Fibonacci(num - 2);
	}
	if (num == 1 || num == 2) {
		return 1;
	}
}

int main2TO2() {
	int num;
	scanf("%d", &num);
	printf("%d\n", Fibonacci(num));
	return 0;
}

int isPalindrome(char *str) {
	int i, num = strlen(str);
	char arr[100] = "\0";
	char *q = arr;
	if (num == 1)
		return -1; // 회문입니다.
	if (str[0] == str[num - 1]) {
		for (i = 1; i < num - 1; ++i) {
			q[i - 1] = str[i];
		}
		return isPalindrome(q);
	}
	else {
		return 0; // 회문이 아닙니다.
	}
}

int main2TO3() {
	char arr[100] = "\0";
	char *p = arr;
	gets(p);
	printf("%d\n", strlen(p));
	if (isPalindrome(p) == -1) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}
