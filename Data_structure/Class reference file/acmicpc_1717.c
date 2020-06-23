#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001
int value[MAX];

int find(int *p, int i) {
	if (p[i] == i)
		return i;
	else
		return find(p, p[i]);
}

void _union(int *p, int a, int b) {
	int N = find(p, a);
	int M = find(p, b);
	if (N != M)
		p[N] = M;
}

int main() {
	int i, j, N, M, a, b, c;
	scanf("%d %d", &N, &M);
	for (i = 0; i <= N; i++) {
		value[i] = i;
	}
	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) {
			_union(value, b, c);
		}
		else if (a == 1) {
			if (find(value, b) == find(value, c)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
		
	}
	return 0;
}
