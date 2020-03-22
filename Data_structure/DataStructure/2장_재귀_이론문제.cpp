#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int product(int a, int b) {
	if (b == 1)
		return a;
	return a + product(a, b - 1);
}
int modulo(int a, int b) {
	if (a < b)
		return a;
	else
		return modulo(a - b, b);
}
int quotient(int a, int b) {
	if (a < b)
		return a;
	else
		return 1 + quotient(a - b, b);
}

int main() {
	// 알고리즘 자신을 사용하여 정의된 알고리즘을 재귀적이라고 말한다.
	// 재귀적으로 해결되어야 할 경우, 재귀호출은 항상 베이스 케이스를 향하는
	// 방향으로 진행되어야 한다.

	// hanoi탑 n개를 이동시키려면 (2**n)-1번 이동시켜야 합니다.
	return 0;
}
