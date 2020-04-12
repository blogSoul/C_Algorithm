#include <stdio.h>
#include <math.h>

void JudgeTotalNumber(unsigned int num) {
	unsigned int sqrtNumber, sum = 0;
	int i;
	sqrtNumber = (int)sqrt(num) + 0.5;
	sum += 1; // 약수가 1과 나 자신인 경우
	for (i = 2; i <= sqrtNumber; ++i) {
		if (num % i == 0) {
			sum += i + (num / i);
		}
		if (sum > num) {
			break;
		}
	}
	if (sum > num) {
		printf("초과수입니다.\n");
		return;
	}
	if (sum == num) {
		printf("완전수입니다.\n");
		return;
	}
    if (sum < num) {
		printf("부족수입니다.\n");
		return;
	}
}

int main() {
	unsigned int arr[9] = { 7, 24, 28, 1024, 8128, 33550336, 4000000000, 4294967291, 4294967295 };
	int i;
	for (i = 0; i < 9; ++i) {
		printf("%u는 ", arr[i]);
		JudgeTotalNumber(arr[i]);
	}
	return 0;
}
