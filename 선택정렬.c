#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int* arr; //포인터 변수 선언
	int i, a, b;
	int N;
	int max, num;

	scanf("%d", &N);

	arr = (int*)malloc(sizeof(int) * N); // 메모리 할당 배열의 크기만큼 할당하기 위해 N를 곱함

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (a = N - 1; a >= 0; a = a - 1) {

		for (b = 0; b < a; b++) {
			if (b == 0) {
				max = arr[b];
			}
			else {
				if (max <= arr[b]) {
					max = arr[b];
					num = b;
				}
			}
		}

		if (arr[a] < max) {
			i = arr[a];
			arr[a] = max;
			arr[num] = i;
		}
		num = 0;
	}

	for (i = 0; i < N; i++) {
		printf(" %d", arr[i]);
	}
	
	free(arr);

	return 0;
}
