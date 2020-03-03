#include <stdio.h>
#include <string.h>
#include <stdlib.h> // 동적 메모리 할당을 위해서 필요한 패키지이다.

int mainToPoint12to1() {
	// 정적 메모리 할당 :
	// 프로그램 실행 전에 변수의 메모리 할당 크기가 정해짐
	// 변수의 메모리 할당 크기를 정확히 알 수 없는 경우, 충분히 큰 메모리 크기를
	// 가정함으로써 프로그램 실행 전에 메모리 할당 크기를 정할 수 있음

	// 동적 메모리 할당 :
	// 변수 이름이 없음, 컴파일 과정에서는 할당할 메모리 크키를 알 수 없음

	// C프로그래밍에서의 메모리 구성
	// 높은 순에서 낮은 순으로 얘기하면 
	// 1. 스택 영역 : 지역변수와 함수의 인수가 할당되는 영역
	// 2. 힙(Heap) 영역 : 동적 메모리 할당을 위한 영역
	// 3. 데이터 영역 : 전역변수와 static 변수가 할당되는 영역
	// 4. 코드 영역 : 실행할 프로그램 코드가 저장되는 메모리 영역

	int *p = NULL; //동적으로 할당 받은 메모리의 시작 주소를 저장하는데 사용합니다.
	p = (int *)malloc(10 * sizeof(int));
	// malloc(10 * sizeof(int)) : int형의 메모리 크기 * 10만큼 (void*)형으로 반환해줍니다.
	// (int *) : 앞서 선언한 자료형 변수로 활용하기 위해 강제적으로 형을 변환합니다.
	if (p == NULL) {
		printf("Not enough memory!\n");
		return -1;
	} // 공간을 확보하지 못하면 NULL값을 반환합니다.
	else{
		free(p); // 메모리 해제
	}

	char *pch = NULL; // 반드시 NULL로 초기화 -> 댕글링 포인터(danfling pointer) 방지
	pch = (char *)malloc(5 * sizeof(char));
	free(pch); // 메모리 해제

	return 0;
}

int mainToPoint12to2() {
	int *score = NULL;
	int i, n;
	double sum = 0;
	scanf("%d", &n);
	score = (int *)malloc(n * sizeof(int));
	if (score == NULL) {
		printf("Not enough memory!\n");
		return -1;
	}
	
	for (i = 0; i < n; ++i) {
		scanf("%d", &score[i]);
		// &score[i]를 score + i 로 가능합니다.
	}

	for (i = 0; i < n; ++i) {
		sum += score[i];
		// sum += *(score+i); 로 가능합니다.
	}
	sum = sum / n;
	printf("%.2f\n", sum);
	free(score);
	return 0;
}

int mainToPoint12to3() {
	char str[20], *p = NULL;
	int i;
	scanf("%s", str);
	p = (char *)malloc(strlen(str) * sizeof(char));
	if (p == NULL) {
		printf("Not enough memory!\n");
		return -1;
	}
	for (i = 0; i < strlen(str); ++i) {
		*(p + i) = str[i];
	}
	for (i = 0; i < strlen(str); ++i) {
		printf("%c", *(p + i));
	}
	free(p);
	return 0;
}

typedef struct book_title {
	char *title;
} BINFO;

int mainToPoint12to4() {
	BINFO *p = NULL;
	int i, n;
	char str[30] = "\0";
	char *q = str;
	scanf("%d", &n);
	getchar();
	p = (BINFO *)malloc(n * sizeof(BINFO));
	if (p == NULL) {
		printf("Not enough memory!\n");
		return -1;
	}
	for (i = 0; i < n; ++i) {
		scanf("%s", str);
		getchar();
		p[i].title = (char*)malloc((strlen(str) + 1) * sizeof(char));
		// (p + i)-> title는 안됩니다!
		if (p[i].title == NULL) {
			printf("Not enough memory!\n");
			return -1;
		}
		strcpy(p[i].title, str);
	}
	for (i = 0; i < n; ++i) {
		printf("%s\n", p[i].title);
	}
	for (i = 0; i < n; ++i) {
		free(p[i].title);
	} // 메모리 해제
	free(p); // 메모리 해제
	return 0;
}

int mainToPoint12to5() {
	char **pch = NULL;
	char str[4];
	int i;
	pch = (char**)malloc(3 * sizeof(char*));
	for (i = 0; i < 3; ++i) {
		pch[i] = (char*)malloc(4 * sizeof(char));
	}

	for (i = 0; i < 3; ++i) {
		gets_s(str); 
		// scanf함수를 이용해 변수를 통해 문자열을 받는 것은 보안상 좋지 않으므로 
		// gets_s를 사용하자!
		strcpy(pch[i], str); // str에 있는 문자열을 pch[i]에 복사해줍니다.
	}
	
	for (i = 0; i < 3; ++i) {
		puts(pch[i]); 
		// printf함수를 이용해 변수를 통해 문자열을 받는 것은 보안상 좋지 않으므로 
		// puts를 사용하자!
	}

	for (i = 0; i < 3; ++i) {
		free(pch[i]);
	}// 메모리 해제
	free(pch);// 메모리 해제
	return 0;
}

int main() {
	// calloc() : 바이트 수 만큼 할당하고, 0으로 초기화 후 시작 위치 반환
	int *p = NULL;
	int size = 3;
	int num, i, index = 0;
	p = (int*)calloc(size, sizeof(int));
	if (p == NULL) {
		printf("Not enough memory!\n");
		return -1;
	}
	for (i = 0; i < 10; ++i) {
		scanf("%d", &num);
		if (index < size) {
			p[index++] = num;
		}
		else {
			size += 3;
			p = (int *)realloc(p, size * sizeof(int));
			p[index++] = num;
		}
	}
	printf("%d\n", size); // size가 12만큼 나오는 것을 볼 수 있습니다.
	free(p);
	// realloc() : ptr이 가리키는 메모리의 크기를 size바이트 크기로 조정하고 시작 위치 반환
	return 0;
}
