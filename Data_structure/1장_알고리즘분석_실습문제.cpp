#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int n) {
	int i, num = 0;
	for (i = 1; i <= n; ++i)
		num += i;
	return num;
}

int main1to1() {
	int i, N, num = 0;
	scanf("%d", &N);
	for (i = 1; i <= N; ++i)
		num += sum(i);
	printf("%d\n", num);
	return 0;
}

void ABC(int arr[10], int k) {
	int max, maxCheck = k, i, temp;
	max = arr[k];
	for (i = k; i < 10; ++i) {
		if (max <= arr[i]) {
			maxCheck = i;
			max = arr[i];
		}	
	}
	temp = arr[maxCheck];
	arr[maxCheck] = arr[k];
	arr[k] = temp;
}

int main() {
	int i;
	int arr[10];
	for (i = 0; i < 10; ++i) {
		scanf("%d", &arr[i]);
	}
	
	for (i = 0; i < 9; ++i) {
		ABC(arr, i);
	}
	
	for (i = 0; i < 10; ++i) {
		printf(" %d", arr[i]);
	}
	return 0;
}
