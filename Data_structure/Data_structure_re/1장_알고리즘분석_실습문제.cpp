#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int n) {
	int i, num = 0;
	for (i = 1; i <= n; ++i)
		num += i;
	return num;
}

int main1to1() {
	int i, N, num = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; ++i)
		num += sum(i);
	printf("%d\n", num);
	return 0;
}

void ABC(int arr[10], int k) {
	int max, maxCheck = k, i, temp;
	max = arr[k];
	for (i = k; i < 10; ++i) {
		if (max <= arr[i]) {
			maxCheck = i;
			max = arr[i];
		}	
	}
	temp = arr[maxCheck];
	arr[maxCheck] = arr[k];
	arr[k] = temp;
}

int main1to2() {
	int i;
	int arr[10];
	for (i = 0; i < 10; ++i) {
		scanf("%d", &arr[i]);
	}
	
	for (i = 0; i < 9; ++i) {
		ABC(arr, i);
	}
	
	for (i = 0; i < 10; ++i) {
		printf(" %d", arr[i]);
	}
	return 0;
}

void swap(int *p, int *q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

int main1to3() {
	int N, a, b, i;
	int arr[50];
	int *p = arr;
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%d", &arr[i]);
	}
	scanf("%d %d", &a, &b);
	swap((p + a), (p + b));
	for (i = 0; i < N; ++i) {
		printf(" %d", arr[i]);
	}
	return 0;
}

int main1to4(){
	char str[100] = "\0";
	char arr[100] = "\0";
	char *p = str;
	char *q = arr;
	int i, j, num;
	scanf("%s", str);
	num = strlen(str);

	for (i = 0; i < num; ++i) {
		q = strrchr(str, *(str + i));
		if(i > 0)
			strncat(q, (p + i - 1), 1);
		printf("%s\n", q);
	}
	return 0;
}

int main1to4version2() {
	char str[100] = "\0";
	char arr[200] = "\0";
	char *p = str;
	char *q = arr;
	int i, j, num;
	scanf("%s", str); // 입력은 100까지 받을 수 있습니다.
	num = strlen(str);
	strcat(q, p);
	strcat(q, p);

	for (i = 0; i < num; ++i) {
		printf("%.*s\n", num, q + i);
	}
	return 0;
}

typedef struct clock {
	int time;
	int minute;
	int second;
}clock;

int main1to5() {
	struct clock clock[3];
	int i, num = 0;
	for (i = 0; i < 2; ++i) {
		scanf("%d %d %d", &clock[i].time, &clock[i].minute, &clock[i].second);
	}
	clock[2].time = clock[1].time - clock[0].time;
	clock[2].minute = clock[1].minute - clock[0].minute;
	clock[2].second = clock[1].second - clock[0].second;
	if (clock[2].minute < 0) {
		clock[2].time -= 1;
		clock[2].minute += 60;
	}
	if (clock[2].second < 0) {
		clock[2].minute -= 1;
		clock[2].second += 60;
	}
	printf("%d %d %d\n", clock[2].time, clock[2].minute, clock[2].second);
	return 0;
}

typedef struct student {
	char name[9];
	int score;
}student;

int main1to6(){
	struct student student[5];
	int i;
	double sum = 0;
	for (i = 0; i < 5; ++i) {
		scanf("%s %d", &student[i].name, &student[i].score);
		sum += student[i].score;
	}
	sum = sum / 5;
	for (i = 0; i < 5; ++i) {
		if (student[i].score < sum) {
			printf("%s\n", student[i].name);
		}
	}
	return 0;
}

int main1to7() {
	int N, i;
	int *p, *q;
	scanf("%d", &N);
	p = (int*)calloc(N, sizeof(int));
	q = (int*)calloc(N, sizeof(int));
	for (i = 0; i < N; ++i) {
		scanf("%d", &p[i]);
	}
	for (i = 0; i < N; ++i) {
		scanf("%d", &q[i]);
	}
	for (i = 0; i < N; ++i) {
		printf(" %d", p[i] + q[N - 1 - i]);
	}
	free(p);
	free(q);
	return 0;
}

typedef struct student1 {
	char name[7];
	int KoreanScore;
	int EnglishScore;
	int MathScore;
	double avgScore;
}student1;

int main1to8() {
	int N, i;
	student1 *p;
	scanf("%d", &N);
	p = (student1*)malloc(N * sizeof(student1));
	for (i = 0; i < N; ++i) {
		scanf("%s %d %d %d", &p[i].name, &p[i].KoreanScore, &p[i].EnglishScore, &p[i].MathScore);
		p[i].avgScore = (double)(p[i].KoreanScore + p[i].EnglishScore + p[i].MathScore) / 3;
	}
	for (i = 0; i < N; ++i) {
		printf("%s %.1f ", p[i].name, p[i].avgScore);
		if (p[i].KoreanScore >= 90 || p[i].EnglishScore >= 90 || p[i].MathScore >= 90) {
			printf("GREAT ");
		}
		if (p[i].KoreanScore < 70 || p[i].EnglishScore < 70 || p[i].MathScore < 70) {
			printf("BAD ");
		}
		printf("\n");
	}
	free(p);
	return 0;
}
