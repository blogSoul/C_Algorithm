#include <stdio.h>
#include <string.h>

int mainToPoint9To1() {
	int x, y, z;
	int *px, *py, *pz, *tmp; // tmp는 포인터입니다.
	int num;

	px = &x;
	py = &y;
	pz = &z;

	/*
	tmp = py;
	py = px;
	px = pz;
	pz = tmp;
	*/
	//이게 왜 안되는지 한번 더 생각해보기

	scanf("%d %d %d", px, py, pz);

	py = &x;
	pz = &y;
	px = &z;

	printf("%d %d %d", *px, *py, *pz);

	return 0;
}

int mainToPoint9To2() {
	char ch[20];
	char *p = ch;

	scanf("%s", p);
	/*
	for (int i = 0; i < 4; i++) {
		scanf("%s", *(p + i));
	}
	*/
	for (int i = 0; i < 20; i++) {
		if (*(p + i) == '#') {
			for (int j = i - 1; j >= 0; j--) {
				printf("%c", *(p + j));
			}
		}
	}

	return 0;
}

int mainToPoint9To3() {
	int x[3];
	int num;
	
	for (int i = 0; i < 3; i++) {
		scanf("%d", &x[i]);
	}

	for (int i = 0; i < 2; i++) {
		if (x[i] >= x[i + 1]) {
			num = x[i];
			x[i] = x[i + 1];
			x[i + 1] = num;
		}
	}

	printf("%d", x[1]);
	return 0;
}

int main() {

	return 0;
}
