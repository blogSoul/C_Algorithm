#include <stdio.h>
#include <stdlib.h>

int MaxNumber(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {
	int N, i, *p, *sum, sumMax;
	scanf("%d", &N);
	p = (int *)calloc(N, sizeof(int));
	sum = (int *)calloc(N, sizeof(int));
	for (i = 0; i < N; i++) {
		scanf("%d", &p[i]);
	}
	sum[0] = p[0];
	sumMax = sum[0];
	for (i = 1; i < N; i++) {
		sum[i] = MaxNumber(sum[i - 1] + p[i], p[i]);
		sumMax = MaxNumber(sum[i], sumMax);
	}
	printf("%d\n", sumMax);
	free(p);
	return 0;
}