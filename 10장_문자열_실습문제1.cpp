#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maintoPoint10to1() {
	char arr[20], str[20];
	int i;
	scanf("%s", arr);
	for (i = 0; arr[i]; i++) {
		if (arr[i] > 'a'&&arr[i] < 'z') {
			printf("%c", arr[i]);
		}
	}
	return 0;
}

int main() {
	char str[9], b;
	int i = 0, num, N;
	int a = 0;
	scanf("%d", &num);
	N = num;

	while (true) {
		N = N / 10;
		a += 1;
		if (N < 1) {
			break;
		}
	}

	for (i = 0; i < a; ++i) {
		str[i] = num % 10 + '0';
		if (str[i] == '0') {
			break;
		}
		printf("%c\n", str[i]);
		num = num / 10;
	}

	printf("%s", str);
	return 0;
}
