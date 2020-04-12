#include <stdio.h>

int main4TO1() {
	int i, j, N, num, *p, *q;
	scanf("%d", &N);
	p = (int*)malloc((N + 1) * sizeof(int));
	for (i = 0; i < N; ++i) {
		scanf("%d", &p[i]);
	}
	scanf("%d", &num);
	q = (int*)malloc((2*num) * sizeof(int));
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

int main() {
	int i, N, num, * p, * q;
	int start ,next;
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
	for (i = num - 1; i >= 0; --i) {
		start = q[i];
		next = q[i + 1];
		p[start] = p[next];
	}

	for (i = 0; i < N; ++i) {
		printf(" %d", p[i]);
	}
	free(p);
	free(q);
	return 0;
}
