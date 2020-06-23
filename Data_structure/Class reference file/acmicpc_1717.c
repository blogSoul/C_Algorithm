#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001
int value[MAX];

int find(int i) {
	if (value[i] == i)
		return i;
	else {
		value[i] = find(value[i]); // 이 부분이 핵심입니다!!!
		return value[i];
	}
}

void _union(int a, int b) {
	value[find(a)] = find(b);
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
			_union(b, c);
		}
		else {
			if (find(b) == find(c)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
		
	}
	return 0;
}
