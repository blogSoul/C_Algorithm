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

int main() {

	return 0;
}
