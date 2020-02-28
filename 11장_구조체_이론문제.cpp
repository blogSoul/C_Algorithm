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

int mainToPoint11to5() {
	struct dinner st1, st2;
	struct dinner *p = &st1;
	struct dinner *q = &st2;
	int i, j, num;

	for (i = 0; i < 2; ++i) {
		for (j = 0; j < 5; ++j) {
			printf("%d번째 런치박스 %d번째 순서입니다. : ", i + 1, j + 1);
			scanf("%d", &num);
			printf("\n");
			if (i == 0) {
				if (j == 0) {
					p->maindish = num;
				}
				else if (j == 1) {
					p->sidedish[0] = num;
				}
				else if (j == 2) {
					p->sidedish[1] = num;
				}
				else if (j == 3) {
					p->sidedish[2] = num;
				}
				else if (j == 4) {
					p->beverage = num;
				}
			}
			else {
				if (j == 0) {
					q->maindish = num;
				}
				else if (j == 1) {
					q->sidedish[0] = num;
				}
				else if (j == 2) {
					q->sidedish[1] = num;
				}
				else if (j == 3) {
					q->sidedish[2] = num;
				}
				else if (j == 4) {
					q->beverage = num;
				}
			}
		}
	}

	for (i = 0; i < 2; ++i) {
		for (j = 0; j < 5; ++j) {
			if (i == 0) {
				if (j == 0) {
					num = p->maindish;
				}
				else if (j == 1) {
					num = p->sidedish[0];
				}
				else if (j == 2) {
					num = p->sidedish[1];
				}
				else if (j == 3) {
					num = p->sidedish[2];
				}
				else if (j == 4) {
					num = p->beverage;
				}
			}
			else {
				if (j == 0) {
					num = q->maindish;
				}
				else if (j == 1) {
					num = q->sidedish[0];
				}
				else if (j == 2) {
					num = q->sidedish[1];
				}
				else if (j == 3) {
					num = q->sidedish[2];
				}
				else if (j == 4) {
					num = q->beverage;
				}
			}
			printf("%d번째 런치박스 %d번째 가격입니다. : %d\n", i + 1, j + 1, num);
		}
	}
	
	return 0;
}

struct complex {
	double real;
	double imag;
};

struct complex add_complex(struct complex a, struct complex b) {
	struct complex c;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return c;
}

int mainToPoint11to6() {
	struct complex a, b, c;
	printf("a값 입력 : \n");
	scanf("%lf", &a.real);
	scanf("%lf", &a.imag);
	printf("\n");

	printf("b값 입력 : \n");
	scanf("%lf", &b.real);
	scanf("%lf", &b.imag);
	printf("\n");
	
	c = add_complex(a, b);
	printf("뎃셈값 : %.2f", c.real);
	printf("뎃셈값 : %.2f", c.imag);
	// double형은 scanf에선 %lf, printf에선 %f이다.
	return 0;
}

struct student *next_addr(struct student *pst) {
	return pst + 1;
} 
// 구조체 주소를 반환하는 함수 : 포인터를 출력해줍니다.
// 일반 변수의 주소 반환과 동일

int mainToPoint11to7() {
	struct student st[2] = { {0, "tom", 0.1},{1, "Her", 1.1}};
	struct student *p, *q = st;
	p = next_addr(st);
	printf("%d %s %.2f\n", p->id, p->name, p->grade);
	p = next_addr((q + 0));
	printf("%d %s %.2f\n", p->id, p->name, p->grade);
	return 0;
}

struct complex *larger_complex(struct complex *a, struct complex *b) {
	double p, q;
	p = (a->real)*(a->real) + (a->imag)*(a->imag);
	q = (b->real)*(b->real) + (b->imag)*(b->imag);

	if (p >= q)
		return a;
	else
		return b;
}

int mainToPoint11to8() {
	struct complex a, b, *c;
	struct complex *p = &a, *q = &b;
	double num;
	printf("a값 입력 : \n");
	scanf("%lf", &num);
	p->real = num;
	scanf("%lf", &num);
	p->imag = num;
	printf("\n");

	printf("b값 입력 : \n");
	scanf("%lf", &num);
	q->real = num;
	scanf("%lf", &num);
	q->imag = num;
	printf("\n");

	c = larger_complex(p, q);

	printf("절대값이 큰 복소수는 %.2f %.2f\n", c->real, c->imag);
	return 0;
}

struct address {
	int zipcode;
	char city;
};

struct student4 {
	int id;
	char name[8];
	double grade;
	char *dept; // 포인터도 구조체에서 만들 수 있다.
	struct address addr; // 구조체 변수도 넣을 수 있다. 
	// 대신 사용하는 구조체는 상단에 존재해야 한다.
	struct student4 *roommate; //자신과 동일한 구조체의 "포인터"는 사용할 수 있다.
};


int mainToPoint11to9() {
	struct student4 st;
	//struct student4 st = { 10, "Tom", 3.2 , "math" }; 
	// 직접 문자열을 char포인터에 넣을 수 없다.
	char arr[10] = "software";

	st.id = 20;
	st.grade = 3.5;
	strcpy(st.name, "Alice");
	st.dept = arr;
	st.addr.city = 77;
	st.addr.zipcode = 'a';
	st.roommate->grade = 4.5;
	return 0;
}

struct student7 {
	int id;
	char name[8];
	double grade;
	struct student7 *roommate;
	struct student7 *friends[10];
};

int main() {
	struct student7 st1 = { 1, "A", 1 };
	struct student7 st2 = { 2, "B", 2 };
	struct student7 st3 = { 3, "C", 3 };

	st1.friends[0] = &st2;
	st1.friends[1] = &st3;

	printf("1번 학생 정보 입력 : \n");
	scanf("%d", st1.id);
	return 0;
}
