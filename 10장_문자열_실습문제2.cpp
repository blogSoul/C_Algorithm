#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int maintoPoint10to10() {
	char str1[80] = "\0";
	char str2[10] = "\0";
	int num, i, j, check = 0;
	scanf("%s", str1);
	scanf("%s", str2);
	
	for (i = 0; str1[i]; ++i) {
		if (str1[i] == str2[0]) {
			for (j = 0; str2[j]; ++j) {
				if (str1[i + j] != str2[j]) {
					check = 0;
					break;
				}
			}
			if (j == strlen(str2)) {
				check = 1;
				break;
			}
		}
	}
	printf("%d %d", strlen(str1), check);
	return 0;
}

int maintoPoint10to11() {
	char str1[80] = "\0";
	char str2[10] = "\0";
	int num, i, j, check = 0;
	scanf("%[^\n]", str1); // \n(엔터)를 제외한 모든 문자열을 받는다!라는 뜻을 가지고 있습니다!
	scanf("%s", str2);

	num = strlen(str1);
	for (i = 0; i < num; ++i) {
		if (str1[i] == str2[0]) {
			for (j = 0; str2[j]; ++j) {
				if (str1[i + j] != str2[j]) {
					break;
				}
			}
			if (j == strlen(str2)) {
				check += 1;
			}
		}
	}
	printf("%d\n", check);
	return 0;
}

int maintoPoint10to12() {
	char str1[100] = "\0";
	char str2[100] = "\0";
	int N, i, num = -1;

	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		getchar();
		scanf("%[^\n]", str1);
		if (num != -1) {
			if (num > strlen(str1)) {
				strcpy(str2, str1);
				num = strlen(str2);
			}
		}
		else {
			strcpy(str2, str1);
			num = strlen(str1);
		}
	}
	printf("%s\n", str2);

	/*
	getchar란?
	만일 파일 끝에 도달하거나, 읽기 오류가 발생한다면 함수는 EOF 를 리턴하고
	이에 대응하는 오류혹은 EOF 표시자가 설정된다. 
	ferror이나 feof함수를 통해 각각 어떤 오류가 발생했는지, 
	파일 끝에 도달하였는지 알 수 있다.
	*/
	return 0;
}

int maintoPoint10to13() {
	char str1[50];
	char str2[50];

	scanf("%s", str1);
	scanf("%s", str2);

	strcat(str2, str1);
	printf("%s", str2);

	return 0;
}

int check(char *p){
	int num = strlen(p);
	int i;
	for (i = 0; i < (num/ 2); ++i) {
		if (*(p + i) != *(p + num - 1 - i)) {
			return 0;
		}
	}
	return 1;
}

int maintoPoint10to14(){
	char str[30];
	char *p = str;
	scanf("%s", p);
	printf("%d %d\n", strlen(str), check(p));
}
