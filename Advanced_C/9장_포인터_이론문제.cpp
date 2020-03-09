#include <stdio.h>
#include <string.h>

int mainToPoint9to1() {
	int a = 0;
	printf("%d ... %p\n", a, &a);
	
	// EX) int num, *pnum = &num;
	//pnum을 선언하고 num의 주소로 초기화

	printf("대입(연결)\n");

	char ch = 'A'; // 두 줄을 묶어서 
	char *pch;     // char ch = 'A', pch; 로 적어도 됩니다.
	int num = 3, *pnum; // 포인터는 무조건 다른 변수와 연결해야 한다.

	pch = &ch; // 변수 ch의 주소가 pch에 저장됩니다.
	pnum = &num; // 포인터 pnum에 변수 num을 연결시킵니다.

	printf("%c %p\n", ch, pch); // %p: 주소 출력할 때 사용
	printf("%d %p\n", num, pnum);

	printf("%c %p\n", *pch, pch);
	printf("%d %p\n", *pnum, pnum);
	// 참조 연산 : 포인터(변수)가 가리키는 변수에 접근하는 것을 의미합니다.
	// EX) *pch : 포인터 pch가 가리키는 변수, 0x3C(예시입니다.)번지에 저장된 값

	printf("대입(연결)을 이용한 연산\n");

	*pch = 'B'; // ex) ch = 'B'와 *pch = 'B'는 동일한 기능을 한다.
	*pnum += 4;

	++*pnum;
	(*pnum)++;

	printf("%c\n", ch);
	printf("%d", num);

	return 0;
}
int mainToPoint9to2() {
	//주소를 이용한 배열 참조
	// ar: 배열의 시작 주소
	// *ar: 배열의 시작 주소에 저장된 값, 즉, 0번째 원소를 의미
	
	int ar[5] = { 2, 3, 5, 7, 1 };
	int *p = ar; // 배열을 포인터 변수에 연결하여 사용
	int i = 4;
	int *q = &ar[2]; // 2번 원소에 연결합니다.
	int *r = &ar[1]; // 1번 원소에 연결합니다.

	printf("%p %d\n", p, *(p + 1));
	// ar[i], p[i], *(ar + i), *(p + i)은 모두 같은 값을 가집니다.
	printf("%p %d %d\n", ar, ar[0], *ar);
	printf("%p %d %d \n", q, q[0], *q);

	//주소에 정수를 더하거나 빼기 
	printf("%p %d\n", r, *r); // &ar[1], ar[1]
	printf("%p %d\n", --r, *r); // ar[0]
	printf("%p %d\n", r + i, *(r + i)); // ar[4](p의 값) 

	return 0;
}

int mainToPoint9to3() {
	//실습 6 포인터 연산 - 더하기 입니다.
	int num = NULL, *p1;
	char cnum = NULL, *p2;
	p1 = &num; // 변수 num의 주소가 p1에 저장됩니다.
	p2 = &cnum; // 변수 cnum의 주소가 p2에 저장됩니다.

	printf("%d %p\n", num, p1);
	printf("%c %p\n", cnum, p2);

	++*p1;
	++*p2;
	printf("%d %p\n", num, p1);
	printf("%c %p\n", cnum, p2);

    *p1 += 2;
	*p2 += 2;
	printf("%d %p\n", num, p1);
	printf("%c %p\n", cnum, p2);
	
	return 0;
}

int mainToPoint9to4() {
	// 실습 7 포인터 연산을 이용하여 배열 전체 훑어보기
	int ar[10] = { 2, 3, 5, 7, -1 };
	int i, *p = ar;
	//int *p = ar는 
	//p = ar로 써도 된다.
	int *p1, *p2;
	p1 = &ar[1];
	p2 = &ar[4];

	for (i = 0; i < 10; i++) {
		printf(" %d", *(p + i));
	}
	printf("\n");
	//*(p + i) 대신 *(p++)을 사용해도 된다. 

	for (p = ar; p < &ar[10]; p++) {
		printf(" %d", *p);
	}
	printf("\n");
	//다른 반복문 예시입니다.

	for (p = ar; *p; p++) {
		printf(" %d", *p);
	}
	printf("\n");
	// *p가 0이 되면 종료합니다.

	printf("%p %p\n", p1, p2);
	printf("%d %d\n", *p1, *p2);
	printf("%d %d\n", p1 < p2, *p1 < *p2);
	// 크기 비교 코드입니다.
	// 연산은 더하기, 빼기 연산만 가능하고, 연산에 정수만 사용 가능합니다.

	return 0;
}

// 포인터 인자와 주소 반환
void change(int i) {
	//함수 본체 수행 : 지역변수 i에 10 대입
	i = 10;
	//함수 종료 : 함수의 지역변수(인자 포함)가 없어짐(할당된 메모리 공간 반환)
}

int main() {
	int a = 5;

	change(a);
	// 함수 시작(호출): 형식 인자(변수)에 공간이 할당되고, 
	// 각 인자에 전달된 정수 값이 대입됨
	printf("a=%d\n", a);
	
	return 0;
}
