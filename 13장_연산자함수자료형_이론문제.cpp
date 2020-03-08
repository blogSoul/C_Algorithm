#include <stdio.h>
#include <string.h>
#include <stdlib.h> // rand 함수 사용을 위해
#include <time.h> // time 함수 사용을 위해

int mainToPoint13to1() {
	// 비트 단위 논리 연산자 : x & y
	int x = 0X2A;
	int y = 0XAD;
	int z = x & y;
	int a = x << 4;
	// 비트 단위 이동 연산 : x를 비트 단위로 왼쪽으로 4만큼 이동
	// 오른쪽 빈 자리는 k개의 0으로 채움

	printf("%#X\n", z);
	printf("%#X\n", a);
	return 0;
}

int mainToPoint13to2() {
	unsigned char a = 01101100;
	unsigned char b = 01001010;
	unsigned char c;
	int x, zs, zu;

	printf("%#X %#X %#X\n", a & b, a | b, a ^ b);
	printf("%#X %#X %#X\n", ~a, a << 2, a >> 2);

	x = 0XA1234567; // x = 1010 0001 ...
	zs = (signed)x >> 4; // 결과: 1111 1010 0001 ....
	zu = (unsigned)x >> 4; // 결과: 0000 1010 0001 .....
	printf("signed = %#X, unsigned = %#X\n", zs, zu);

	x = 0X71234567; // x = 1010 0001 ...
	zs = (signed)x >> 4; // 결과: 0000 0111 0001 ....
	zu = (unsigned)x >> 4; // 결과: 0000 0111 0001 .....
	printf("signed = %#X, unsigned = %#X\n", zs, zu);
	return 0;
}

int mainToPoint13to3() {
	int x = 0X71234567;
	x = x >> 10;
	// 오른쪽에서 10번째 비트를 가장 오른쪽에 위치시킴
	x = x & 1;
	// x와 ... 0001 의 AND
	// 두 문장을 하나로 합하면 (x >> 10) & 1

	printf("%d\n", x);
	return 0;
}

void dec1(int x) {
	printf("x: %d\n", x);
	if (x > 1)
		dec1(x - 1);
}

void dec2(int x) {
	printf("+start: x=%d\n", x);
	if (x > 1) dec2(x - 1);
	printf("-end: x=%d\n", x);
}

int sum(int n) {
	if (n == 1) return 1;
	return sum(n - 1) + n;
}

int factorial(int n) {
	if (n == 1) return 1;
	return factorial(n - 1) * n;
}

int mainToPoint13to4() {
	dec1(3);
	printf("\n");
	dec2(3);
	printf("\n");
	printf("%d\n", sum(10));
	printf("%d\n", factorial(10));
	printf("%d\n", rand()); // 난수 생성
	srand(10); // 시드를 10으로 지정
	printf("%d\n", rand()); // 난수 생성
	srand(time(NULL)); // 시드를 현재시간으로 지정
	printf("%d\n", rand()); // 난수 생성
	return 0;
}

int randomnumber1() {
	int n;
	n = rand() % 100;
	return n;
}

int mainToPoint13to5() {
	int i;
	for (i = 0; i < 5; i++) {
		printf("%d\n", randomnumber1());
	}

	clock_t start, finish;
	double duration;

	start = clock(); // 시작 시각
	// 수행시간을 측정하고 하는 코드..!
	finish = clock(); // 종료 시각

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	// CLOCKS_PER_SEC (time.h에 정의된 상수)단위로 반환
	printf("실행 시간: %lf 초 \n", duration);
	return 0;
}

void swap2(int* p1, int* p2) {
	int* tmp;
	tmp = p1;
	p1 = p2;
	p2 = tmp;
}

void swap3(int** pp1, int** pp2) {
	int* ptmp;
	ptmp = *pp1;
	*pp1 = *pp2;
	*pp2 = ptmp;
}

int mainToPoint13to6() {
	/*
	int num = 3, *pnum, **ppnum;
	pnum = &num; // 변수 num의 주소가 pnum에 저장됨
	ppnum = &pnum; // 변수 pnum의 주소가 ppnum에 저장됨

	printf("%d %p %p\n", num, pnum, ppnum);
	*/
	int num = 3;
	int* pnum = &num; // 참조연산자를 한 개 사용하면 간접 참조를 한번(*)
	int** ppnum = &pnum; // 참조연산자를 두 개 사용하면 간접 참조를 두번(**)

	printf("%p %p %d\n", ppnum, *ppnum, **ppnum);
	printf("\n");

	printf("%p %d\n", &num, num);
	printf("%p %p %d\n", &pnum, pnum, *pnum);
	printf("%p %p %p %d\n", &ppnum, ppnum, *ppnum, **ppnum);
	printf("\n");

	int x = 10, y = 20;
	int* p1 = &x, *p2 = &y, *ptmp;


	ptmp = p1;
	p1 = p2;
	p2 = ptmp;
	// p1 <-> p2 교환
	printf("%d %d\n", *p1, *p2);
	printf("\n");

	swap2(p1, p2);
	// 함수 안에 설정된 포인터는 함수가 마치고 메모리가 해제된다.
	printf("%d %d\n", *p1, *p2);
	printf("\n");

	swap3(&p1, &p2); // p1 <-> p2 교환
	printf("%d %d\n", *p1, *p2); // p1, p2의 주소는 (int **)형이다.
	printf("\n");
	return 0;
}

void init3(int x[][3]) {// int (*x)[3]과 동일
	x[0][0] = x[1][0] = 0;
}

int(*init4(int(*x)[3]))[3]{
	x[0][0] = x[1][0] = 0;
	return x;
}

int mainToPoint13to7() {
	int a = 1, b = 2, c = 3;
	int* pi[3] = { &a, &b, &c }; // int포인터 배열
	int** ppi;
	int i = 10, *qi, ** qqi, *** qqqi, **** qqqqi;
	int arr[2][3] = { {-2, 4, 0},{1, 2, 3} }; // arr의 자료형은 int(*)[3]
	int j = 0, ar[5] = { 2,3,5,7,-1 };
	int at[3][5];
	int* p, (*px)[5], (*py)[3][5]; // px는 "크기가 5인 int 배열"에 대한 포인터입니다.
	// int *(px[5])와 동일 <- 연산자 []의 우선 순위가 *보다 높음
	// 즉, 포인터들의 배열(포인터 배열)
	int(*r)[3];

	ppi = pi;
	// 배열 이름 pi는 &pi[0]와 동일
	printf("%p %p %d\n", ppi, *ppi, **ppi);
	printf("%d %d %d\n", **ppi, **(ppi + 1), **(ppi + 2));
	// int 배열로 주소지정을 해주면 주소들이 1만큼 차이나게 연속적으로 할당된다.

	qi = &i; // (int)형인 i의 주소는 (int *)형
	qqi = &qi; // (int *)형인 qi의 주소는 (int **)형
	qqqi = &qqi; // (int **)형인 qqi의 주소는 (int ***)형
	qqqqi = &qqqi; // (int ***)형인 qqqi의 주소는 (int ****)형
	printf("%d %d %d %d %d\n", i, *qi, **qqi, ***qqqi, ****qqqqi);

	init3(arr);
	printf("%d %d %d\n", arr[0][0], arr[0][1], arr[0][2]);
	printf("%d %d %d\n", arr[1][0], arr[1][1], arr[1][2]);

	p = &j; // int형에 대한 포인터(int *)
	p = ar; // == &ar[0], 즉 int형에 대한 포인터(int *)
	//p = &ar;
	// "int *"의 간접 참조 수준이 'int(*)[5]'와 다르다
	px = &ar;
	printf("%p %p\n", p, px);
	printf("%p %p %p\n", p, p + 1, p + 2); // 주소값이 4만큼 증가 
	printf("%p %p %p\n", px, px + 1, px + 2); // 주소값이 20만큼 증가

	p = at[1];

	px = &at[1];
	//py = at; py는 자료형을 맞출 수 없다.
	r = init4(arr);
	printf("%d %d %d\n", arr[0][0], arr[0][1], arr[0][2]);
	printf("%d %d %d\n", arr[1][0], arr[1][1], arr[1][2]);
	return 0;
}

void print(int a, int b) {
	printf("%d %d\n", a, b);
}

int add2(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

union student6 {// 공용체
	int id;
	char name[8];
	// 모든 멤버가 메모리를 공유한다.
	// 따라서 데이터를 변경하면 다른 데이터에 영향을 미친다.
};

enum day_type {// 열거형
	sun, mon, tue, wed, thu, fri, sat
	// 이름이 부여된 정수 상수의 집합
	// 코드의 가독성을 높여줌
	// 내부적으로는0부터 차례로 멤버들에세 정수가 부여됨
};

int mainToPoint13to8() {
	int x[2] = { 4, 8 };
	void* p = x;
	void(*fp)(int, int);
	// 반환형 void, 인자가 int형 2개인 함수 포인터 연결
	char op; int a, b;
	int(*fq)(int, int);

	printf("%d\n", *(int*)p);
	p = (int*)p + 1;
	printf("%d\n", *(int*)p);

	fp = print;
	print(2, 3);
	fp(1, 5);

	scanf("%c", &op);
	scanf("%d %d", &a, &b);
	if (op == '+')
		fq = add2;
	else if (op == '-')
		fq = sub;
	else
		return 0;
	printf("=> %d\n", fq(a, b));
	return 0;
}
