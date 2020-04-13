#include <stdio.h>

int main4TO1() {
	int i, j, N, num, *p, *q;
	scanf("%d", &N);
	p = (int*)malloc((N + 1) * sizeof(int));
	for (i = 0; i < N; ++i) {
		scanf("%d", &p[i]);
	}
	scanf("%d", &num);
	q = (int*)malloc((2 * num) * sizeof(int));
	for (i = 0; i < 2 * num; ++i) {
		scanf("%d", &q[i]);
	}

	for (i = 0; i < 2 * num; i += 2) {
		int start = q[i], end = q[i + 1];
		for (j = start; j <= (start + end) / 2; ++j) {
			p[N] = p[j];
			p[j] = p[start + end - j];
			p[start + end - j] = p[N];
		}
	}

	for (i = 0; i < N; ++i) {
		printf(" %d", p[i]);
	}
	free(p);
	free(q);
	return 0;
}

int main4TO2() {
	int i, N, num, *p, *q;
	int start, next;
	scanf("%d", &N);
	p = (int*)malloc((N + 1) * sizeof(int));
	for (i = 0; i < N; ++i) {
		scanf("%d", &p[i]);
	}
	scanf("%d", &num);
	q = (int*)malloc((num) * sizeof(int));
	for (i = 0; i < num; ++i) {
		scanf("%d", &q[i]);
	}

	start = q[0];
	p[N] = p[start];
	for (i = num - 1; i > 0; --i) {
		start = q[i - 1];
		next = q[i];
		p[next] = p[start];
	}
	start = q[1];
	p[start] = p[N];
	// 교환을 하는 부분입니다.

	for (i = 0; i < N; ++i) {
		printf(" %d", p[i]);
	} // 출력 부분입니다.
	free(p); // 메모리 헤제합니다.
	free(q);
	return 0;
}

int main4TO3() {
	int i, j, N, **p, k = 1;
	scanf("%d", &N);
	p = (int**)malloc(N*(sizeof(int*)));
	for (i = 0; i < N; ++i) {
		p[i] = (int *)malloc(N * sizeof(int));
	}
	for (i = 0; i < N; ++i) {
		if (i % 2 == 0) {
			for (j = 0; j < N; ++j) {
				p[i][j] = k++;
			}
		}
		else {
			for (j = N-1; j >= 0; --j) {
				p[i][j] = k++;
			}
		}
	}

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			printf(" %d", p[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < N; ++i) {
		free(p[i]);
	}
	free(p);
	return 0;
}

int main4TO4() {
	int i, j, N, M, **p, k = 1, a;
	int direction = 1, x_range, y_range;
	scanf("%d %d", &N, &M);
	p = (int**)malloc(N*(sizeof(int*)));
	for (i = 0; i < N; ++i) {
		p[i] = (int *)malloc(M * sizeof(int));
	}

	x_range = N;
	y_range = M;
	i = 0;
	j = -1; 
	while (k <= N * M) {
		for (a = 0; a < y_range; ++a) {
			j = j + direction;
			p[i][j] = k++;
		}
		x_range -= 1; 

		for (a = 0; a < x_range; ++a) {
			i = i + direction;
			p[i][j] = k++;
		}
		y_range -= 1;
		direction *= -1;
	}

	for (i = 0; i < N; ++i) {
		for (j = 0; j < M; ++j) {
			printf(" %d", p[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < N; ++i) {
		free(p[i]);
	}
	free(p);
	return 0;
}

int min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}
int main4TO5() {
	int i, j, N, M, **p, sum = 0, k = 1, MAX;
	scanf("%d %d", &N, &M);
	p = (int**)malloc(N*(sizeof(int*)));
	for (i = 0; i < N; ++i) {
		p[i] = (int *)malloc(M * sizeof(int));
	}

	i = 0;
	j = 0;
	while (k <= N * M) {
		p[i][j] = k++;
		i++;
		j--;
		if (i > sum || i > N - 1) {
			sum++;
			j = min(M - 1, sum);
			i = sum - j;
		}
	}

	for (i = 0; i < N; ++i) {
		for (j = 0; j < M; ++j) {
			printf(" %d", p[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < N; ++i) {
		free(p[i]);
	}
	free(p);
	return 0;
}
