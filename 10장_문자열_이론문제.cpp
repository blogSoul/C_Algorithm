#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mainToPoint10to1() {
	char arr[10] = "Hello";
	char *str = arr;
	//이렇게 지정하게 되면 변수 영역: 변경 가능

	printf("%s\n", str);
	scanf("%s", str);
	printf("%s\n", str);

	for (int i = 0; str[i]; ++i) {
		printf("%c", str[i]);
	}
	//printf("%s\n", str);와 같은 문구이다.

	//str = "World";
	// 이렇게 지정하게 되면 상수 영역 : 변경 불가능
	return 0;
}

int mainToPoint10to2() {
	int str[6];
	scanf("%s", str);
	printf("%s\n", str);
	str[5] = '?';
	printf("%s\n", str);
	//str[5]에 물음표 문자 '?' 대입
	return 0;
}

int mainToPoint10to3() {
	char str[20];
	scanf("%s", str);
	printf("%s..\n", str);
	scanf("%s", str + 5);
	printf("%s..\n", str);
	// 문자배열에 문자열을 대입하는 것은 불가능
	return 0;
}

int mainToPoint10to4() {
	char arr[50] = "To be, or not to be : that is the question";
	char *str = arr;
	int num = 0;

	for (int i = 0; str[i]; i++) {
		if (str[i] == 't') {
			num += 1;
		}
	}
	printf("%d\n", num);
	
	return 0;
}

int mainToPoint10to5() {
	char num[3][5] = { "zero","one","two" };
	for (int i = 0; i < 3; ++i) {
		printf("%s\n", num[i]);
	}
	/*
	++i는 내부적으로 다음과 같이 동작한다.
	1. i의 값을 1 더한다.
	2. i의 값을 반환한다.

    i++는 내부적으로 다음과 같이 동작한다.
    1. i의 현재 값을 보관한다. (현재 실행되는 명령문에서는 이 보관된 값이 사용되어야 하니까)
    2. i의 값을 1 더한다.
    3. 보관했던 값을 반환한다.

	++i가 i++보다 조금 더 빠르다고 볼 수 있습니다!
	*/
	return 0;
}

int mainToPoint10to6() {
	char num[3][20] = { "Time is gold", "No pain no gain", "No sweat no sweet" };
	char *arr;
	int sum = 0, a = 0;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 20; ++j) {
			if (num[i][j] == 'a') {
				sum += 1;
			}
			a += 1;
		}
	}
	printf("%d\n", sum);
	printf("%d\n", a);
	sum = 0;
	a = 0;

	for (int i = 0; i < 3; ++i) {
		arr = *(num + i);
		for (int j = 0; *(arr + j); ++j) {
			if (*(arr + j) == 'a') {
				sum += 1;
			}
			a += 1;
		}
	}
	printf("%d\n", sum);
	printf("%d\n", a);
	return 0;
}

int mainToPoint10to7() {
	char str[20] = "Hello World";
	char str1[6] = "Hello";
	int i;

	for (i = 0; str[i] != '\0'; ++i);
	printf("Length: %d\n", i);
	printf("Length: %d\n", strlen(str));
	// 원형: unsigned int strlen(char *s)
    // 기능: 문자열 s의 길이 반환

	strcpy(str1, "hi");
	// char *strcpy(char *s1, char *s2)
    // 기능: s1의 공간에 s2의 문자열 복사(문자열 대입), s2는 변화 없음
	// 주의 사항 : s2의 문자열 길이+1 이상의 공간이 s1에 할당되어 있어야 함
	printf("str1: %s\n", str1);

	strcat(str1, "hi");
	// char *strcat(char *s1, char *s2)
	// 기능: s1의 문자열 뒤에 s2의 문자열 접합 (문자열 대입), s2는 변화 없음
	// 주의사항 : 접합한 문자열을 저장할 수 있는 충분한 공간이 s1에 할당되어 있어야 함
	printf("str1: %s\n", str1);

	printf("%d\n", strcmp("hi", "hello"));
	// int strcmp(char *s1, char *s2)
	// 기능: 사전 순으로 s1과 s2를 비교하여s1 < s2이면 음수, s1 == s2이면 0, s1 > s2이면 양수 리턴

	return 0;
}

int mainToPoint10to8() {
	char A[20], B[20], C[50];
	scanf("%s", A);
	scanf("%s", B);
	printf("%d %d\n", strlen(A), strlen(B));
	if (strcmp(A, B) == 1) {
		printf("%s\n", B);
	}
	else if (strcmp(A, B) == 0) {
		printf("%s\n", A);
		printf("%s\n", B);
	}
	else {
		printf("%s\n", A);
	}
	strcat(B, A);
	strcat(A, B);
	printf("%s\n", A);

	//int atoi(char *s) : int형으로 계산하여 반환 
	//long atol(char *s) : long형으로 계산하여 반환
	//double atof(char *s) : double형으로 계산하여 반환
	return 0;
}

int mainToPoint10to9() {
	char str[10] = "Hi world";
	char arr[10];
	int ret = 1;
	ret = puts(str);
	puts(str);
	printf("return: %d\n", ret);

	fgets(arr, 10, stdin);
	// gets 함수는 2015버전 이후부터 지원하지 않는다.
	// char* fgets(char* str, int num, FILE* stream);이다!
	printf("arr: %s", arr);

	ret = putchar('a');
	printf("\nreturn: %d\n", ret);

	ret = getchar(); // int ret로 반환되어진다.
	putchar(ret);
	return 0;
}
