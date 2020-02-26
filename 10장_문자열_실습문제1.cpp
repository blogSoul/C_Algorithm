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

int maintoPoint10to2() {
	char str[9];
	int a = 0,i = 0;
	int num, N;
	
	scanf("%d", &num);
	N = num;

	while (true) {
		N = N / 10;
		a += 1;
		if (N < 1) {
			break;
		}
	}

	N = 0;
	for (i = 0; i < a; ++i) {
		N = (10 * N) + (num % 10);
		num = num / 10;
	}

	sprintf(str, "%d", N);
	//int to str해주는 함수입니다!
	printf("%s\n", str);
	return 0;
}

int maintoPoint10to3(){
	char str[100], c[100];
	int i = 0, j = 0, num = 0, a;

	scanf("%s", str);
	a = strlen(str);

	for (i = 0; i < a; ++i) {
		sprintf(c, "%s", str); // 초기화!
		for (j = 0; j < a; ++j) {
			num = (i + j) % a;
			c[j] = str[num];
		}
		printf("%s\n", c);
	}

	return 0;
}

int main() {

	return 0;
}
