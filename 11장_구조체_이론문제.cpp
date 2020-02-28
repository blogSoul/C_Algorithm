#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
	int id;
	char name[8];
	double grade;
}; // 구조체 정의

int mainToPoint11to1() {
	struct student st1 = { 10, "Tom", 3.2 };
	// 구조체 변수 선언
	strcpy(st1.name, "alice"); // st1.name = "alice" (X);

	printf("%d\n", st1.id);
	printf("%s\n", st1.name);
	return 0;
}

struct dinner {
	int maindish;
	int sidedish[3];
	int beverage;
} st; // 전역 변수 st 선언

int mainToPoint11to2() {
	struct dinner dn1;
	struct dinner dn2;
	int num[5], sum = 0, a;

	printf("Main dish: ");
	scanf("%d", &num[0]);
	printf("\n");
	dn1.maindish = num[0];
	
	printf("Side dish 1: ");
	scanf("%d", &num[1]);
	printf("\n");
	dn1.sidedish[0] = num[1];

	printf("Side dish 2: ");
	scanf("%d", &num[2]);
	printf("\n");
	dn1.sidedish[1] = num[2];

	printf("Side dish 3: ");
	scanf("%d", &num[3]);
	printf("\n");
	dn1.sidedish[2] = num[3];

	printf("Beverage: ");
	scanf("%d", &num[4]);
	printf("\n");
	dn1.beverage = num[4];

	dn2 = dn1;

	printf("Main dish(B): ");
	scanf("%d", &a);
	printf("\n");
	dn2.maindish = a;

	for (int i = 0; i < 5; i++) {
		sum += num[i];
	}

	printf("Total: %d\n", sum);
	
	printf("%d\n", sizeof(struct student));
	// 메모리 관리의 효율성을 위해 8의 배수로 할당
	// 할당 단위 크기는 시스템마다 다를 수 있음
    // 자투리 공간은 사용 안 함

	printf("A의 가격표 :\n");
	printf("Main dish: %d\n", dn1.maindish);
	printf("Side dish1: %d\n", dn1.sidedish[0]);
	printf("Side dish2: %d\n", dn1.sidedish[1]);
	printf("Side dish3: %d\n", dn1.sidedish[2]);
	printf("Beverage: %d\n", dn1.beverage);
	printf("\n");

	printf("B의 가격표 :\n");
	printf("Main dish: %d\n", dn2.maindish);
	printf("Side dish1: %d\n", dn2.sidedish[0]);
	printf("Side dish2: %d\n", dn2.sidedish[1]);
	printf("Side dish3: %d\n", dn2.sidedish[2]);
	printf("Beverage: %d\n", dn2.beverage);
	return 0;
}

int mainToPoint11to3(){
	struct dinner st1[2];
	int i, j, num;
	
	for (i = 0; i < 2; ++i) {
		for (j = 0; j < 5; ++j) {
			printf("%d번째 런치박스 %d번째 순서입니다. : ", i + 1, j + 1);
			scanf("%d", &num);
			printf("\n");
			if (j == 0) {
				st1[i].maindish = num;
			}
			else if (j == 1) {
				st1[i].sidedish[0] = num;
			}
			else if (j == 2) {
				st1[i].sidedish[1] = num;
			}
			else if (j == 3) {
				st1[i].sidedish[2] = num;
			}
			else if (j == 4) {
				st1[i].beverage = num;
			}
		}
	}

	for (i = 0; i < 2; ++i) {
		for (j = 0; j < 5; ++j) {
			if (j == 0) {
				num = st1[i].maindish;
			}
			else if (j == 1) {
				num = st1[i].sidedish[0];
			}
			else if (j == 2) {
				num = st1[i].sidedish[1];
			}
			else if (j == 3) {
				num = st1[i].sidedish[2];
			}
			else if (j == 4) {
				num = st1[i].beverage;
			}
			printf("%d번째 런치박스 %d번째 가격입니다. : %d\n", i + 1, j + 1, num);
		}
	}

	return 0;
}

int mainToPoint11to4() {
	struct student st1 = { 10, "Tom", 3.2 }; //변수 선언 및 초기화
	struct student *pst = &st1; // 포인터 선언 및 연결

	pst->id += 20; // 포인터가 가리키는 구조체의 멤버에 접근
	strcpy(pst->name, "alice"); // 주의: pst->name = "alice"(X)
	pst->name[0] = 'A';

	printf("id: %d\n", pst->id);
	printf("name: %s\n", pst->name);
	printf("grade: %.2f\n", pst->grade);
	return 0;
}

int main() {
	struct dinner st1[2];
	struct dinner *p = st1;
	int i, j, num;

	for (i = 0; i < 2; ++i) {
		for (j = 0; j < 5; ++j) {
			printf("%d번째 런치박스 %d번째 순서입니다. : ", i + 1, j + 1);
			scanf("%d", &num);
			printf("\n");
			if (j == 0) {
				st1[i].maindish = num;
			}
			else if (j == 1) {
				st1[i].sidedish[0] = num;
			}
			else if (j == 2) {
				st1[i].sidedish[1] = num;
			}
			else if (j == 3) {
				st1[i].sidedish[2] = num;
			}
			else if (j == 4) {
				st1[i].beverage = num;
			}
		}
	}

	for (i = 0; i < 2; ++i) {
		for (j = 0; j < 5; ++j) {
			if (j == 0) {
				num = st1[i].maindish;
			}
			else if (j == 1) {
				num = st1[i].sidedish[0];
			}
			else if (j == 2) {
				num = st1[i].sidedish[1];
			}
			else if (j == 3) {
				num = st1[i].sidedish[2];
			}
			else if (j == 4) {
				num = st1[i].beverage;
			}
			printf("%d번째 런치박스 %d번째 가격입니다. : %d\n", i + 1, j + 1, num);
		}
	}

	return 0;
}
