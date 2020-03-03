#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct book {
	char name[20]; // 책이름
	int score; // 인증시험 점수
} Books;

typedef struct {
	char name[10]; // 학생 이름
	Books book[5]; // 인증 시험 본 책에 대한 정보
	int cnt = 0, pcnt = 0; // 인증시험 본 책의 권수, 통과한 책의 권수
}St;

int mainToPoint11to13() {
	int N, num = 0;
	int i, j;
	St student[100];
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%s", &student[i].name);
		getchar();
		for (j = 0; j < 5; ++j) {
			scanf("%s", &student[i].book[j].name);
			if (strcmp(student[i].book[j].name, "0") == 0)
				break;
			scanf("%d", &student[i].book[j].score);

			student[i].cnt += 1;
			if (strcmp(student[i].book[j].name, "History") == 0 && student[i].book[j].score >= 50) {
				student[i].pcnt += 1;
			}
			else if (strcmp(student[i].book[j].name, "Politics") == 0 && student[i].book[j].score >= 50) {
				student[i].pcnt += 1;
			}
			else if (strcmp(student[i].book[j].name, "DonQuixote") == 0 && student[i].book[j].score >= 50) {
				student[i].pcnt += 1;
			}
			else if (strcmp(student[i].book[j].name, "LaPeste") == 0 && student[i].book[j].score >= 50) {
				student[i].pcnt += 1;
			}
			else if (strcmp(student[i].book[j].name, "Chaos") == 0 && student[i].book[j].score >= 50) {
				student[i].pcnt += 1;
			}
			getchar();
		}
	}
	for (int i = 0; i < N; ++i) {
		printf("%s %d%%\n", student[i].name, (student[i].pcnt * 20));
	}
	return 0;
}

typedef struct{
	char *name; // 책이름
	int score; // 인증 시험 점수
}Book;

typedef struct st {
	char *name; // 학생 이름
	Book book[5]; // 인증시험 본 책에 대한 정보 
	int cnt = 0, pcnt = 0; // 인증시험 본 책의 권수, 통과한 책의 권수
};

int mainToPoint11to14() {
	st student[100];
	st *p = student;
	char str[5][30];
	char std[5][30];
	int arr[30];
	int N, i, j;
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%s", &str[i]);
		(p + i)->name = str[i];
		getchar();
		
		for (j = 0; j < 5; ++j) {
			scanf("%s", &std[j]);
			if (std[j][0] == '0')
				break;
			(p + i)->book[j].name = std[j];
			scanf("%d", &arr[j]);
			(p + i)->book[j].score = arr[j];
			student[i].cnt += 1;
			if (strcmp((p + i)->book[j].name, "History") == 0 && (p + i)->book[j].score >= 50) {
				student[i].pcnt += 1;
			}
			else if (strcmp((p + i)->book[j].name, "Politics") == 0 && (p + i)->book[j].score >= 50) {
				student[i].pcnt += 1;
			}
			else if (strcmp((p + i)->book[j].name, "DonQuixote") == 0 && (p + i)->book[j].score >= 50) {
				student[i].pcnt += 1;
			}
			else if (strcmp((p + i)->book[j].name, "LaPeste") == 0 && (p + i)->book[j].score >= 50) {
				student[i].pcnt += 1;
			}
			else if (strcmp((p + i)->book[j].name, "Chaos") == 0 && (p + i)->book[j].score >= 50) {
				student[i].pcnt += 1;
			}
			getchar();
		}
		
	}
	for (int i = 0; i < N; ++i) {
		printf("%s %d%%\n", (p + i)->name, ((p + i)->pcnt * 20));
	}
	// 문자열 포인터는 문자열 변수를 참조해야 사용할 수 있습니다! 2015버전 이후로 달라졌습니다!
	return 0;
}
