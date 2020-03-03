#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maintoPoint12to1(){
	int N, i, *p, sum =0;
	scanf("%d", &N);
	p = (int *)calloc(N, sizeof(int));
	for (i = 0; i < N; ++i) {
		scanf("%d", &p[i]);
		sum += p[i];
	}
	printf("%d\n", sum);
	free(p);
	return 0;
}

int maintoPoint12to2() {
	int N, i;
	double *p, max;
	scanf("%d", &N);
	p = (double *)calloc(N, sizeof(double));
	for (i = 0; i < N; ++i) {
		scanf("%lf", &p[i]);
	}
	max = p[0];
	for (i = 0; i < N; ++i) {
		if (max <= p[i])
			max = p[i];
	}
	printf("%.2f", max);
	free(p);
	return 0;
}

int maintoPoint12to3() {
	int N, i, aCount = 0, bCount = 0;
	char *p, a, b;
	scanf("%d", &N);
	p = (char *)calloc(N, sizeof(char));
	scanf("%s", p);
	getchar();
	
	scanf("%c %c", &a, &b);

	for (i = 0; i < N; ++i) {
		if (*(p + i) == a)
			aCount += 1;
		if (*(p + i) == b)
			bCount += 1;
	}

	printf("%d %d", aCount, bCount);
	free(p);
	return 0;
}

int maintoPoint12to4() {
	int N, i, *p;
	scanf("%d", &N);
	p = (int *)calloc(N + 1, sizeof(int));
	for (i = 0; i < N; ++i) {
		scanf("%d", (p + i));
	}
	for (i = 0; i < N - 1; ++i) {
		if (p[i] > p[i + 1]) {
			p[N] = p[i];
			p[i] = p[i + 1];
			p[i + 1] = p[N];
		}
	}
	for (i = 0; i < N; ++i) {
		printf("%d\n", *(p + i));
	}
	free(p);
	return 0;
}

int maintoPoint12to5() {
	int N, i, num = 0;
	char *p = NULL;
	scanf("%d", &N);
	p = (char*)calloc(N, sizeof(char));
	scanf("%s", p);
	getchar();
	for (i = 0; i < N - 2; ++i) {
		if (*(p + i) == 'c' && *(p + i + 1) == 'a' && *(p + i + 2) == 't')
			num += 1;
	}
	printf("%d\n", num);
	free(p);
	return 0;
}

int maintoPoint12to6() {
	int N, i, j = 0, *p, *q;
	scanf("%d", &N);
	p = (int *)calloc(N, sizeof(int));
	q = (int *)calloc(N - 1, sizeof(int));
	for (i = 0; i < N; ++i) {
		*(p + i) = i;
	}

	for (i = 0; i < N - 1; ++i) {
		if (i < N / 2)
			*(q + i) = *(p + i);
		else
			*(q + i) = *(p + i + 1);
	}
		
	for (i = 0; i < N -1; ++i) {
		printf(" %d", *(q + i));
	}
	
	free(q);
	free(p);
	return 0;
}
