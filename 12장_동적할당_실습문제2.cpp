#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maintoPoint12to7() {
	int N, D, i, *p;
	scanf("%d", &N);
	p = (int *)calloc(N, sizeof(int));
	for (i = 0; i < N; ++i) {
		scanf("%d", (p + i));
	}
	scanf("%d", &D);
	for (i = 0; i < N - D; ++i) {
		printf("%d\n", *(p + i));
	}
	free(p);
	return 0;
}

int maintoPoint12to8() {
	int a, b, i, j;
	char **p, word = 'a';
	scanf("%d %d", &b, &a);
	p = (char**)calloc(a, sizeof(char*));
	for (i = 0; i < a; ++i) {
		p[i] = (char*)calloc(b, sizeof(char));
	}

	for (i = 0; i < a; ++i) {
		for (j = 0; j < b; ++j) {
			p[i][j] = word;
			word += 1;
			if (word == 'z' + 1)
				word = 'A';
			if (word == 'Z' + 1)
				word = 'a';
		}
	}

	for (i = 0; i < a; ++i) {
		for (j = 0; j < b; ++j) {
			printf("%c ", p[i][j]);
		}
		printf("\n");
	}
	
	for (i = 0; i < a; ++i) {
		free(p[i]);
	}
	free(p);
	return 0;
}

typedef struct student {
	char name[7];
	double KoreaScore;
	double EnglishScore;
	double MathScore;
	double min;
}student;

int maintoPoint12to9() {
	student *p;
	int N, i;
	scanf("%d", &N);
	p = (student*)calloc(N, sizeof(student));
	for (i = 0; i < N; ++i) {
		scanf("%s", &p[i].name);
		scanf("%lf", &p[i].KoreaScore);
		scanf("%lf", &p[i].EnglishScore);
		scanf("%lf", &p[i].MathScore);
		p[i].min = (p[i].KoreaScore + p[i].EnglishScore + p[i].MathScore) / 3;
		getchar();
	}
	for (i = 0; i < N; ++i) {
		printf("%s %.1f", p[i].name, p[i].min);
		if (p[i].KoreaScore >= 90 || p[i].EnglishScore >= 90 || p[i].MathScore >= 90) {
			printf(" GREAT");
		}
		if (p[i].KoreaScore < 70 || p[i].EnglishScore < 70 || p[i].MathScore < 70) {
			printf(" BAD");
		}
		printf("\n");
	}
	free(p);
	return 0;
}

int main() {
	int N, i;
	char *p = NULL;
	scanf("%d", &N);
	
	return 0;
}
