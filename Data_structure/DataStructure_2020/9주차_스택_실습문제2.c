#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element; // 원소 정의
typedef struct stack {
	element* array; // 배열 포인터
	int N; // 배열의 크기
	int top; // top의 위치
}stack; // 구조체 선언

stack* initStack(int N) {
	stack* p = (stack*)malloc(sizeof(stack));
	p->array = (element*)calloc(N, sizeof(element));// 동적할당
	p->top = -1;
	p->N = N;
	return p;
} // 초기화

void push(stack* p, element word) {
	if (p->top == p->N - 1) {
		printf("Stack FULL\n");
		return;
	}
	p->top++;
	p->array[p->top] = word;
	return;
} // stack push 함수입니다.

void pop(stack* p) {
	if (p->top == -1) {
		printf("Stack Empty\n");
		return;
	}
	p->array[p->top] = "\0";
	p->top--;
} // stack pop 함수입니다.

void print(stack* p) {
	if (p->top == -1) {
		printf("Stack Empty\n");
		return;
	}
	for (int i = p->top; i >= 0; i--) {
		printf("%c", p->array[i]);
	}
	printf("\n");
	return;
} // stack print 함수입니다.

void freeStack(stack* p) {
	if (p->top == -1 || p->N == 0)
		return;
	free(p->array);
	p->top = -1;
	p->N = 0;
	free(p);
	return;
} // 메모리 해제 함수입니다.

void checkBracket(char* order) {
	int i, count = 0, check = 1;
	stack* p;
	p = initStack(1000); // 수식문장은 1000개 이하이므로
	for (i = 0; i < strlen(order); i++) {
		if (order[i] == '{') {
			push(p, order[i]);
			count++;
		}
		else if (order[i] == '[') {
			push(p, order[i]);
			count++;
		}
		else if (order[i] == '(') {
			push(p, order[i]);
			count++;
		}
		else if (order[i] == ')') {
			if (p->array[p->top] == '(')
				pop(p);
			else
				check = 0;
			count++;
		}
		else if (order[i] == ']') {
			if (p->array[p->top] == '[')
				pop(p);
			else
				check = 0;
			count++;
		}
		else if (order[i] == '}') {
			if (p->array[p->top] == '{')
				pop(p);
			else
				check = 0;
			count++;
		}
	}
	if (p->top != -1)
		check = 0;
	if (check == 1)
		printf("OK_");
	else if(check == 0)
		printf("Wrong_");
	printf("%d\n", count);
	freeStack(p); // 메모리 해제
} // 괄호여부를 판별하는 함수입니다.

int main() {
	int N, i, top;
	char order[1000], word;
	stack* p;
	scanf("%[^\n]", order); // 문자열 입력
	getchar();
	checkBracket(order);
	return 0;
}
