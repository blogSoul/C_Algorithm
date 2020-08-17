#include <stdio.h>
#include <stdlib.h>

void swap(int *p, int a, int b) {
	int temp;
	temp = p[a];
	p[a] = p[b];
	p[b] = temp;
} // 두 원소의 교환을 위한 함수

void reverse(int *p, int M, int N) {
	int i, j, k, temp;
	k = M + N;
	j = k / 2.;
	for (i = M; i <= j; i++) {
		temp = p[i];
		p[i] = p[k - i];
		p[k - i] = temp;
	}
} // p[M]부터 p[N]까지의 순서를 반대로 저장합니다.

int count = 0; // 순서를 저장합니다.
void permutation(int *p, int N) {
	int i, sum1, sum2, sum3;
	if (N == 1) {
		sum1 = p[0] + p[1] + p[2] + p[3];
		sum2 = p[1] + p[2] + p[4] + p[5];
		sum3 = p[2] + p[3] + p[5] + p[6];
		if (sum1 == sum2 && sum2 == sum3) {
			printf("선택 : %d %d %d %d %d %d %d\n", p[0], p[1], p[2], p[3], p[4], p[5], p[6]);
			count++;
		}
	}
	for (int i = 0; i < N; i++) { // M과 N이 같으면 방정식 확인
		swap(p, i, N - 1);
		permutation(p, N - 1);
		swap(p, i, N - 1);
	}
} // 원소가 N개인 배열에서 조건에 맞는 순열을 계산합니다.

int main() {
	int i, *p;
	p = (int*)calloc(7, sizeof(int));
	for (i = 0; i < 7; i++) {
		p[i] = i + 1;
	}
	permutation(p, 7);
	printf("조건에 맞는 순서쌍의 수는 %d입니다.\n", count);
	free(p);
	return 0;
}
