#include <stdio.h>
#include <stdlib.h>
/*
알고리즘 중에서 여러 sort(정렬) 알고리즘이 있는데, 그 중에서 순차 정렬(Sequential Sort) 알고리즘을 구현해보았습니다.
순차 정렬은 맨 앞에서부터 제일 작은 원소를 배치하게 만들어 나가는 알고리즘입니다.. 
이를 위해 배치할 자리에 있는 원소를 뒤쪽에 있는 원소들과 비교하면서 작은 것을 발견하면 배치할 위치의 원소와 교환합니다.

순차 정렬을 수도 코드로 작성하면, 
base:배열의 시작 주소, n: 원소 개수, compare:비교 논리, swap:교환으로 작성한다면,

for(i:=0->n)
	for(j:=i+1->n)
		if(compare(base[i], base[j]) > 0)
			swap(base[i],base[j])

로 볼 수 있습니다.

이 알고리즘을 보게 되면 base[i], base[j]와 같이 어떤 키값을 갖고 있는 정보의 순서로 정렬하는 것을 볼 수 있습니다.
따라서 이 알고리즘의 최악실행시간을 big-Oh 표기법으로 보면 
이중 반복문의 최악 실행 시간을 보면 (n-1) + (n-2) + ... + 1 = (n-1)n/2 = O(n^2)으로 표현할 수 있습니다.
따라서 이 코드 복잡도를 big-Oh 표기법으로 나타내면 O(n^2)(O(n의 제곱))으로 나타낼 수 있습니다.
*/
int main() {
	int i, j, N, temp;
	int *p;
	scanf("%d", &N);
	p = (int*)malloc((N + 1)*sizeof(int)); // N개의 입력값과 swap을 할 수 있는 공간 하나를 동적할당으로 받아줍니다.
	for (i = 0; i < N; ++i) {
		scanf("%d", &p[i]);
	}
	for (i = 0; i < N; ++i) {
		for (j = i + 1; j < N; ++j) {
			if (p[i] > p[j]) {
				p[N] = p[i];
				p[i] = p[j];
				p[j] = p[N]; // p[i]와 p[j]의 값을 교환합니다.
			}
		}
	}
	for (i = 0; i < N; ++i) {
		printf(" %d", p[i]);
	}
	free(p); // 메모리를 해제합니다.
	return 0;
}
