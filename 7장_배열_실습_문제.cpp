#include <stdio.h>
#include <string.h>

//7장 3절 문제 1
int mainToProblem1(){
	
	int a[5];
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sum = sum / 5;
	
	for (int i = 0; i < 5; i++) {
		if (a[i] > sum) {
			printf("%d\n", a[i]);
		}
	}

	return 0;
}

//7장 3절 문제 2
int mainToProblem2() {
	
	int a[5];
	int b;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < 4; i++) {
		if (a[i] > a[i + 1]) {
			b = a[i];
			a[i] = a[i + 1];
			a[i + 1] = b;
		}
	}

	for (int i = 0; i < 5; i++) {
		printf("%d\n", a[i]);
	}

	return 0;
}

//7장 3절 문제 3
void drawStar(int num) {
	for (int i = 0; i < num; i++) {
		printf("*");
	}
	printf("\n");
}

int mainToProblem3() {
	
	int a[10];
	int countA = 0;
	int countB = 0;
	int countC = 0;

	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 1) {
			countA += 1;
		}
		else if (a[i] == 2) {
			countB += 1;
		}
		else if (a[i] == 3) {
			countC += 1;
		}
	}

	printf("1:");
	drawStar(countA);
	printf("2:");
	drawStar(countB);
	printf("3:");
	drawStar(countC);

	return 0;
}

//7장 3절 문제 4
int mainToProblem4() {

	int a[5];
	int max;
	int maxNext;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &a[i]);
	}

	max = a[0];
	maxNext = a[1];
	for (int i = 0; i < 5; i++) {
		if (a[i] >= max) {
			maxNext == max;
			max == a[i];
		}
	}

	printf("%d\n", max);
	printf("%d\n", maxNext);

	return 0;
}

//7장 4절 문제 5
int mainToProblem5() {

	char a[7];
	int count = 0;
	for (int i = 0; i < 7; i++) {
		scanf("%c", &a[i]);
	}

	for (int i = 0; i < 5; i++) {
		if (a[i] == 'c' && a[i + 1] == 'a' && a[i + 2] == 't') {
			count += 1;
		}
	}

	printf("%d", count);

	return 0;
}

//7장 5절 문제 6 여기서부터 풀기
int mainToProblem6() {

	char a[5];
	int num = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%c", &a[i]);
	}

	for (int i = 5; i > 0; i--) {
		for (int j = 0; j < 5; j++) {
			num = ((i % 5) + j) % 5;
			printf("%c", a[num]);
		}
		printf("\n");
	}

	return 0;
}

//7장 5절 문제 7 여기서부터 풀기
int mainToProblem7() {

	int a[3][3];
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		for (int j= 0; j < 3; j++) {
			scanf("%d",&a[i][j]);
		}
	}

	for (int i = 0; i < 3; i++) {
		sum += a[i][i];
	}

	printf("%d", sum);

	return 0;
}

//7장 5절 문제 8 여기서부터 풀기
int mainToProblem8() {

	int a[3];
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < 3; i++) {
		if (a[i] == 0) {
			printf("ZERO-\n");
		}
		else if (a[i] == 1) {
			printf("ONE--\n");
		}
		else if (a[i] == 2) {
			printf("TWO--\n");
		}
		else if (a[i] == 3) {
			printf("THREE\n");
		}
		else if (a[i] == 4) {
			printf("FOUR-\n");
		}
		else if (a[i] == 5) {
			printf("FIVE-\n");
		}
	}

	return 0;
}

//7장 4절 문제 9 여기서부터 풀기
int mainToProblem9() {

	int a[3][2];
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < 3; i++) {
		sum = a[i][0] + a[i][1];
		printf("%d\n", sum);
	}

	return 0;
}

//7장 3절 문제 10 여기서부터 풀기
int mainToProblem10() {

	int a[20];
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < num; i++) {
		printf(" %d", a[i]);
	}

	return 0;
}

//7장 4절 문제 11 여기서부터 풀기
int mainToProblem11() {

	char a[3];
	char b;
	int c[3] = { 0,0,0 };

	for (int i = 0; i < 3; i++) {
		scanf("%c", &a[i]);
	}
	getchar();

	for (int i = 0; i < 5; i++) {
		scanf("%c", &b);
		getchar();

		for (int i = 0; i < 3; i++) {
			if (a[i] == b) {
				c[i] = 1;
			}
		}

		for (int i = 0; i < 3; i++) {
			if (c[i] == 0) {
				printf(" _");
			}
			else if (c[i] == 1) {
				printf(" %c", a[i]);
			}
		}
		printf("\n");

		if (c[0] == 1 && c[1] == 1 && c[2] == 1) {
			break;
		}
	}

	return 0;
}

//7장 5절 문제 12 여기서부터 풀기
int mainToProblem12() {

	int a[3][3];
	int b[2][2];
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &b[i][j]);
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf(" %d", a[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			printf(" %d", b[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (a[i][j] == b[0][0] && a[i][j + 1] == b[0][1] && a[i + 1][j] == b[1][0] && a[i + 1][j + 1] == b[1][1]) {
				printf("%d %d", i, j);
				break;
			}
			else {
				if (i == 1 && j == 1) {
					printf("none");
					break;
				}
			}
		}
	}

	return 0;
}
