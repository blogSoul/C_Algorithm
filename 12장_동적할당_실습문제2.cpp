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

int maintoPoint12to10() {
	int N, i, min, minCheck;
	char **p = NULL, *q = NULL;
	char str[100];
	scanf("%d", &N);
	getchar();
	p = (char**)calloc(N, sizeof(char*));
	for (i = 0; i < N; ++i) {
		p[i] = (char*)calloc(100, sizeof(char));
	}
	for (i = 0; i < N; ++i) {
		gets_s(str);
		strcpy(p[i], str);
	}

	min = strlen(p[0]);
	for (i = 0; i < N; ++i) {
		if (min >= strlen(p[i])) {
			minCheck = i;
		}
	}
	puts(p[minCheck]);

	for (i = 0; i < N; ++i) {
		free(p[i]);
	}
	free(p);
	return 0;
}

int maintoPoint12to11() {
	int N, i, j, max, maxCheck;
	char **p = NULL, *q = NULL;
	char str[100];
	scanf("%d", &N);
	getchar();
	p = (char**)calloc(N + 1, sizeof(char*));
	for (i = 0; i < N + 1; ++i) {
		p[i] = (char*)calloc(100, sizeof(char));
	}
	for (i = 0; i < N; ++i) {
		gets_s(str);
		strcpy(p[i], str);
	}

	
	for (i = N - 1; i >= 0; --i) {
		max = strlen(p[i]);
		for (j = i; j < N; ++j) {
			if (strlen(p[j]) <= strlen(p[j + 1])) {
				p[N] = p[j];
				p[j] = p[j + 1];
				p[j + 1] = p[N];
			}
		}
	}

	for (i = 0; i < N; ++i) {
		puts(p[i]);
	}

	for (i = 0; i < N; ++i) {
		free(p[i]);
	}
	free(p);
	return 0;
}

int maintoPoint12to12() {
	int *p, i = 0, size = 5;
	p = (int *)malloc(size * sizeof(int));
	// sizeof(int)는 4이다.
	while (size <= 20) {
		if (i + 1 > size) {
			size += 3;
			p = (int *)realloc(p, size * sizeof(int));
			scanf("%d", &p[i]);
		}
		else {
			scanf("%d", &p[i]);
		}
		if (p[i] == -1) {
			size = i;
			for (i = 0; i <= size; ++i) {
				printf(" %d", p[i]);
			}
			break;
		}
		i += 1;
	}
	free(p);
	return 0;
}

int maintoPoint12to13() {
	char **p, str[100];
	int i, j, N, maxCheck = 0;
	scanf("%d", &N);
	getchar();
	p = (char **)calloc(N + 1, sizeof(char*));
	for (i = 0; i < N; ++i) {
		gets_s(str);
		p[i] = (char *)calloc(strlen(str) + 1, sizeof(char));
		strcpy(p[i], str);
	}

	maxCheck = strlen(p[0]);
	for (i = N - 1; i >= 0; --i) {
		for (j = i - 1; j < N; ++j) {
			if (maxCheck <= strlen(p[i])) {
				maxCheck = strlen(p[i]);
			}
		}
	}

	for (i = 0; i <= N; ++i) {
		p[i] = (char *)realloc(p[i], (maxCheck + 1) * sizeof(char));
	}

	for (i = N - 1; i >= 0; --i) {
		for (j = i; j < N - 1; ++j) {
			if (strcmp(p[j], p[j + 1]) == 1) {
				p[N] = p[j];
				p[j] = p[j + 1];
				p[j + 1] = p[N];
			}
		}
	}

	for (i = 0; i < N; ++i) {
		puts(p[i]);
	}

	for (i = 0; i < N; ++i) {
		free(p[i]);
	}
	free(p);
	/*
	_CrtIsValidHeapPointer(block) 오류는 잘못된 포인터를 참조할 때 발생합니다. 
	IsValidHeapPointer라는 어썰트는 말 그대로 해당 포인터가 valid(유효)한지 체크하는 겁니다.
	여기서 말 하는 힙(Heap)은 현재 실행 중인 프로그램의 로컬 힙 메모리를 가리키는 것으로, 
	즉, 해당 포인터가 참조하는 메모리 주소가 프로그램 상에서 new 등으로 할당한 공간의 주소인지를 
	체크하는 것입니다.
	*/
	return 0;
}
