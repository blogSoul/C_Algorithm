#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 파일 입출력에 필요한 txt, dat 파일은 따로 첨부하지 않았습니다.

int maintoPoint14to1() {
	int N, i, cnt = 0, num, sum = 0;
	FILE *fp;
	double avg = 0;

	fp = fopen("data.txt", "w");
	if (fp == NULL) {
		printf("Couldn't open file!\n");
		return -1;
	}
	while (true) {
		scanf("%d", &num);
		if (num == 0) 
			break;
		fprintf(fp, "%d\n", num);
		cnt += 1;
	}
	fclose(fp);

	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("Couldn't open file!\n");
		return -1;
	}
	for (i = 0; i < cnt; ++i) {
		fscanf(fp, "%d\n", &num);
		printf("%d\n", num);
		sum += num;
	}
	avg = sum / cnt;

	printf("%d\n", cnt);
	printf("%d\n", sum);
	printf("%.2f\n", avg);
	return 0;
}

int maintoPoint14to2() {
	FILE *fp1, *fp2;
	char ch;

	fp1 = fopen("text1.txt", "r");
	if (fp1 == NULL) {
		printf("Couldn't open file!\n");
		return -1;
	}
	fp2 = fopen("text2.txt", "w");
	if (fp2 == NULL) {
		printf("Couldn't open file!\n");
		return -1;
	}
	while ((ch = fgetc(fp1)) != EOF) {
		if (ch >= 65 && ch <= 90) {
			ch += 32;
		}
		else {
			ch -= 32;
		}
		printf("%c", ch);
		fputc(ch, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}

int maintoPoint14to3() {
	FILE *fp1, *fp2;
	char ch;
	int i = 0;

	fp1 = fopen("text1.txt", "r");
	if (fp1 == NULL) {
		printf("Couldn't open file!\n");
		return -1;
	}

	fp2 = fopen("text2.txt", "w");
	if (fp2 == NULL) {
		printf("Couldn't open file!\n");
		return -1;
	}

	while (!feof(fp1)) {
		ch = fgetc(fp1);
		printf("%c", ch);
		fputc(ch, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}

int maintoPoint14to4() {
	FILE *fp1, *fp2;
	char ch;
	int i = 0;

	fp1 = fopen("text1.txt", "a");
	if (fp1 == NULL) {
		printf("Couldn't open file!\n");
		return -1;
	}

	fp2 = fopen("text2.txt", "r");
	if (fp2 == NULL) {
		printf("Couldn't open file!\n");
		return -1;
	}

	while (!feof(fp2)) {
		ch = fgetc(fp2);
		printf("%c", ch);
		fputc(ch, fp1);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}

struct person {
	char name[10];
	int age;
};

int maintoPoint14to5() {
	struct person student[3];
	char str[10];
	int arr, i;
	FILE *fp;

	for (i = 0; i < 3; ++i) {
		scanf("%s %d", &student[i].name, &student[i].age);
	}

	fp = fopen("student.dat", "wb");
	if (fp == NULL) {
		printf("Couldn't open file!\n");
		return -1;
	}
	fwrite(student, sizeof(struct person), 3, fp);
	fclose(fp);
	return 0;
}

int maintoPoint14to6() {
	struct person student[3];
	struct person str[10];
	int i;
	FILE *fp;

	fp = fopen("student.dat", "rb");
	if (fp == NULL) {
		printf("Couldn't open file!\n");
		return -1;
	}
	fread(str, sizeof(struct person), 3, fp);
	for (i = 0; i < 3; ++i) {
		printf("%s %d\n", str[i].name, str[i].age);
	}
	fclose(fp);
	return 0;
}
