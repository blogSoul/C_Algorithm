#include <stdio.h> // <- 특정한 헤더 파일을 포함시키기 위하여 사용
#include <string.h>
#include <stdlib.h>
#include <math.h>
// 경로로 지정할 때, \를 하나만 써준다.
// Ex) #include “C:\mywork\project\myheader.h” 

#define EQ ==
#define STRING unsigned int 
#define EMPTY
#define LEVEL 1
// 매크로 상수 : 주로 대문자 사용 , 초기화만 가능 , 데이터 형이 없음

#define SQUARE(x) (x*x)
#define MIN(a,b) (a>b?b:a)
#define ODD(x) (x%2==1?true:false)
// 매크로 함수 : 꼭 ()로 묶어줄 수 있도록 하자! 전처리기에서 번역, 인자를 단순 치환

#undef EMPTY
// 정의된 매크로를 해제하는 지시자

void MyFunc();
void MyFunc() {
	// Nothing
}
// 이런 식으로 함수를 정의할 수 있다.

#if LEVEL == 1
   #define LEVEL 2
#elif LEVEL == 2
#else
#endif
// 조건문도 사용 가능하다. tab은 가시성을 위해서 필요하다.
#ifdef LEVEL 
   #define LEVEL 3
#else
#endif
// 매크로가 정의되있으면 컴파일 할 문장이 실행된다.
#ifndef PI
   #define PI 3.14
#else
#endif
// 매크로가 정의되어 있지 않으면 컴파일 할 문장이 실행된다.

int mainToPoint15to1() {
	// 전처리기(preprocessor) : 컴파일러가 소스 프로그램을 번역하기 이전 과정
	// 예를 들면 #include
	STRING table[30];
	int x, y;

	scanf("%d", &x);
	scanf("%d", &y);
	printf("%d\n", SQUARE(x));
	printf("%d\n", MIN(x,y));
	printf("%d\n", ODD(x));
	printf("%d\n", LEVEL);
	printf("%f\n", PI);
	if (x EQ y) {
		printf("%d\n", SQUARE(y));
	}
	return 0;
}

int mainToPoint15to2() {
	// const : 컴파일러에 의해 처리, 상수의 사용범위가 함수 내부로 제한됨
	// const를 사용하여 변수를 초기화하면, 초기화된 값을 변경시킬 수 없음
	// -> 반드시 변수 값은 선언과 동시에 초기화해야 함!
	int count = 10;
	const int *p = &count;
	//*p = 20; <- 컴파일 오류가 생김  
	// : 이 포인터 변수가 가리키는 변수에 저장된 값을 변경하는 것을 허용하지 않음
	// -> 값을 변경하는 방법에 제한을 두는 것임!
	count = 1;

	int n1 = 10;
	int * const q = &n1;
	*q = 30; // const 상수화 : 한번 주소 값이 저장되면, 그 값이 변경이 불가능하다는 뜻

	return 0;
}

int mainToPoint15to3() {
	// 모듈(module) : 함수 단위로 구분하여 작성하는 것
	// 모듈별로 나누어 개발하고 "빌드"를 통해 해당 작업을 수행
	// 주의사항 : 각 파일 내에서 사용하는 변수나 함수 등은 해당 파일 내에서 선언되어야 함
	// extern 선언 : 다른 소스 파일에 선언 및 정의된 변수 또는 함수를 현재의 소스 파일에 사용하고자 할 때 사용
	// -> Ex)  extern int num; : 외부에 존재한다는 것만 알려주면 됨

	// 변수의 지속기간에 따른 분류:
	// 1. 외부변수(전역변수)
	// 2. 자동변수(지역변수)
	// 3. 정적변수(static변수)

	static int number1; // 정적변수(static변수) 
	// mainToPoint15to3()안에서만 사용이 가능하다.
	return 0;
}
