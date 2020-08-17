#include <stdio.h>
#include <math.h>
/*
소수를 판별하는 방법 중에 "에라토스테네스의 체"라는 유명한 방법이 있다.
그 중에서 하나의 성질을 사용하면 쉽게 소수 판별법을 구현할 수 있습니다.

* 에라토스테네스의 체에 대한 접근
주어진 자연수 N이 소수이기 위한 필요충분 조건은 N이 
N의 제곱근보다 크지 않은 어떤 소수로도 나눠지지 않는다. 

이 성질을 이용하게 되면 N이라는 수를 소수인지 판별하고 싶은 경우에 
is_prime의 시간 복잡도를 보게되면 for반복문에서 최악실행시간이 얼마나 되는지 확인해보면 O(제곱근(N))인 것을 확인할 수 있습니다.
따라서 is_prime의 시간 복잡도인 O(제곱근(N))만큼 실행하면 N이 소수인지 판별할 수 있습니다.
*/
void is_prime(int num) {
	if (num <= 1) {
		printf("다시 입력해주세요."); // 소수와 합성수는 2이상일 때부터 판별이 가능합니다.
		// 산술의 기본 정리 중 하나는 '1보다 큰 모든 자연수는 그 자체가 소수이거나, 순서를 무시하고 유일한 소인수의 조합을 갖는다' 라는 것입니다.
		return;
	}
	int sqrtOfNum = sqrt(num);
	sqrtOfNum = (double)sqrtOfNum + 0.5; // 제곱근(N)의 값을 구해줍니다.
	for (int i = 2; i <= sqrtOfNum; ++i) {
		if (num % i == 0) {
			printf("composite\n"); // i에 의해 나눠지면 합성수가 됩니다.
			return;
		}
	}
	printf("prime\n"); // 2부터 sqrtOfNum까지 나눠지지 않았다면 이 수는 소수로 판별이 됩니다.
	return;
}

int main() {
	int num, i;
	scanf("%d", &num);
	is_prime(num); // 소수 판별하는 함수를 실행합니다.
	return 0;
}
