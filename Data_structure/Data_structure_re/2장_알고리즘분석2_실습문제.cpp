#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main2to1() {
	int N, max = 0, num = 0, i, j, total = 0, totalCheck = 0;
	int **p;
	scanf("%d", &N);
	p = (int **)malloc(N * sizeof(int*));
	for (i = 0; i < N; ++i) {
		p[i] = (int*)malloc(N * sizeof(int));
	}
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			scanf("%d", &p[i][j]);
		}
	}
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			if (p[i][j] == 1) {
				num += 1;
			}
			else if(j == (N - 1) || p[i][j] == 0) {
				max = num;
				num = 0;
				break;
			}
		}
		if (total < max) {
			total = max;
			max = 0;
			totalCheck = i;
		}
	}
	printf("%d", totalCheck);
	for (i = 0; i < N; ++i) {
		free(p[i]);
	}
	free(p);
	return 0;
}

int main2to1_version2() {
	int N, max = 0, num = 0, i, j, total = 0, totalCheck = 0;
	int **p;
	scanf("%d", &N);
	p = (int **)malloc(N * sizeof(int*));
	for (i = 0; i < N; ++i) {
		p[i] = (int*)malloc(N * sizeof(int));
	}
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			scanf("%d", &p[i][j]);
		}
	}
	for (i = 0; i < N; ++i) {
		j = 0;
		while ((j < N) && (p[i][j] == 1)) {
			j += 1;
			if (j > max) {
				totalCheck = i;
				max = j;
			}
		}
	}
	printf("%d", totalCheck);
	for (i = 0; i < N; ++i) {
		free(p[i]);
	}
	free(p);
	return 0;
}

int main2to2() {
	int N, max = 0, num = 0, i, j, total = 0, totalCheck = 0;
	int **p;
	scanf("%d", &N);
	p = (int **)malloc(N * sizeof(int*));
	for (i = 0; i < N; ++i) {
		p[i] = (int*)malloc(N * sizeof(int));
	}
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			scanf("%d", &p[i][j]);
		}
	}
	i = 0;
	j = 0;
	while(i < N) {
		if (p[i][j] == 1) {
			while (j < N && p[i][j] == 1) {
				j += 1;
				if (j > max) {
					totalCheck = i;
					max = j;
				}
			}
		}
		if (max == N) {
			break;
		}
		if (p[i][j] == 0) {
			i += 1;
		}
	}
	printf("%d", totalCheck);
	for (i = 0; i < N; ++i) {
		free(p[i]);
	}
	free(p);
	return 0;
}
