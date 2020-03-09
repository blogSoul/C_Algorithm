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

int mainToPoint9To4() {
	char ch[10];
	char *p = ch;
	char word;
	int num = 0, a = 0;

	//scanf("%s", p);
	//이렇게 코드를 작성하면 마지막에 NULL값이 붙어서 크기가 11인 문자열이 생성되어서 
	//ERROR가 발생한다.
	for (int i = 0; i < 10; i++) {
		scanf("%c", p + i);
	}
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (*(p + i) == *(p + j)) {
				a += 1;
			}
		}

		if (a > num) {
			word = *(p + i);
			num = a;
		}
		a = 0;
	}

	printf("%c %d", word, num);
	//printf("%s", ch);
	//NULL값이 붙는 것을 확인하려면 주석을 지워면 됩니다.
	return 0;
}

int mainToPoint9To5() {
	int arr[5];
	int rank[5];
	int *p = arr, *q = rank;
	int num;

	for (int i = 0; i < 5; i++) {
		scanf("%d", arr + i);
	}

	for (int i = 0; i < 5; i++) {
		*(rank + i) = *(arr + i);
		for (int j = i - 1; j >= 0; j--) {
			if (*(rank + j) < *(rank + j + 1)) {
				num = *(rank + j);
				*(rank + j) = *(rank + j + 1);
				*(rank + j + 1) = num;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (*(arr + i) == *(rank + j)) {
				num = j;
				break;
			}
		}
		printf("%d=r%d ", *(arr + i), num + 1);
	}
	return 0;
}

int mainToPoint9To6() {
	int a[50];
	int *p = a;
	int N, num = 0;
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", p + i);
	}
	// 왜 1 2 3 4 처럼 띄어쓰기만 해도 다른 변수처럼 입력이 가능할까?
	// 공백문자가 입력되면 더 이상의 입력은 저장되지 않기 때문입니다.
	// 공백문자를 받고 싶다면 gets나 fgets를 참조하도록 합ㄴ디다!
	for (int i = 0; i < N; i++) {
		if (*(p+i) != 0) {
			num += 1;
		}
		else {
			break;
		}
	}

	printf("%d", num);
	return 0;
}
