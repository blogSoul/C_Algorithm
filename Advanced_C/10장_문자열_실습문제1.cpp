#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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

int maintoPoint10to4() {
	char str[100], arr[100];
	int i = 0, num, a = 0;
	scanf("%s", str);
	scanf("%s", arr);

	for (i = 0; str[i]; ++i);
	num = i;

	for (i = 0; i < num; ++i) {
		if (str[i] == arr[i]) {
			a += 1;
		}
	}

	if (a == num) {
		a = 1;
	}
	else {
		a = 0;
	}

	printf("%d %d\n", num, a);
	return 0;
}

int maintoPoint10to5() {
	char str1[20] = "\0";
	char str2[20] = "\0";
	// \0을 적용시켜 이후 가비지 값이 나오는 것을 방지합니다.
	char *p = str1, *q = str2;
	int i, N, j = 0;

	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%d", &N);

	j = strlen(str2);
	for (i = 0; str2[i]; ++i) {
		str1[i + j + N] = str1[i + N];
		str1[i + N] = str2[i];
	}

	printf("%s\n", str1);

	return 0;
}

int maintoPoint10to6() {
	char str1[20] = "\0";
	char str2[20] = "\0";
	// \0을 적용시켜 이후 가비지 값이 나오는 것을 방지합니다.
	char *p = str1, *q = str2;
	int i, N, j = 0, M;

	scanf("%s", str1);
	scanf("%s", str2);
	scanf("%d", &N);
	scanf("%d", &M);

	j = strlen(str2);
	if (M == 0) {
		for (i = 0; str2[i]; ++i) {
			str1[i + j + N] = str1[i + N];
			str1[i + N] = str2[i];
		}
	}
	else {
		for (i = 0; str2[i]; ++i) {
			str1[i + j + N] = str1[i + N];
			str1[i + N] = str2[j - 1 - i];
		}
	}

	printf("%s\n", str1);
	return 0;
}

void member(int a, int b) {
	if (b == 1) {
		printf("one ");
	}
	else if (b == 2) {
		printf("two ");
	}
	else if (b == 3) {
		printf("three ");
	}
	else if (b == 4) {
		printf("four ");
	}
	else if (b == 5) {
		printf("five ");
	}
	else if (b == 6) {
		printf("six ");
	}
	else if (b == 7) {
		printf("seven ");
	}
	else if (b == 8) {
		printf("eight ");
	}
	else if (b == 9) {
		printf("nine ");
	}

	if (a == 3) {
		printf("THO ");
	}
	else if (a == 2) {
		printf("HUN ");
	}
	else if (a == 1) {
		printf("TEN ");
	}
}

int maintoPoint10to7() {
	int N, M, a = 0, b, num, i;
	scanf("%d", &N);
	M = N;

	while (true) {
		N = N / 10;
		if (N < 1)
			break;
		a += 1;
	}

	for (i = a; i >= 0; --i) {
		num = pow(10, i);
		b = M / num;
		member(i, b);
		M -= b * num;
	}

	return 0;
}
