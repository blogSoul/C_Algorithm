#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int N; // 스택의 크기
	int top; // 현재 마지막 원소의 위치
	int word[100]; // 정수 원소가 담길 연결리스트
} stack; // 구조체 선언

stack* init(int N) {
	stack* p = (stack*)malloc(sizeof(stack));
	p->N = N;
	p->top = -1;
	return p;
} // stack을 초기화해주는 함수입니다.

void push(stack* p, int word) {
	if (p->top == p->N - 1) {
		printf("Stack FULL\n");
		return;
	}
	p->top++;
	p->word[p->top] = word;
} // stack에서 push를 해주는 함수입니다.

int pop(stack* p) {
	int num;
	if (p->top == -1) {
		// printf("Stack Empty\n");
		return;
	}
	num = p->word[p->top];
	p->word[p->top] = 0;
	p->top--;
	return num;
} // stack에서 pop를 해주고 삭제한 원소를 반환해주는 함수입니다.

void print(stack* p) {
	if (p->top == -1) {
		// printf("Stack Empty\n");
		return;
	}
	for (int i = p->top; i > -1; i--) {
		printf("%d", p->word[i]);
	}
	printf("\n");
	return;
} // stack에서 print를 해주는 함수입니다.

void freeStack(stack* p) {
	free(p->word);
	free(p);
	return;
} // stack을 초기화해주는 함수입니다.

void CalculatePostfixformula(char* word) {
	int i, a, b, N = strlen(word);
	stack* p;
	p = init(N); // 스택 초기화 및 선언
	for (i = 0; i < N; i++) {
		if (word[i] == '*') {
			a = pop(p);
			b = pop(p);
			push(p, a * b);
		}
		else if (word[i] == '/') {
			a = pop(p);
			b = pop(p);
			push(p, b / a);
		}
		else if (word[i] == '+') {
			a = pop(p);
			b = pop(p);
			push(p, a + b);
		}
		else if (word[i] == '-') {
			a = pop(p);
			b = pop(p);
			push(p, b - a);
		}
		else {
			push(p, word[i] - '0');
		}
	}
	a = pop(p);
	printf("%d\n", a); // 결과값 출력
} // 후위수식을 계산해주는 함수입니다.

int main() {
	int N, i;
	char word[100] = "\0";
	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++) {
		scanf("%s", word);
		getchar();
		// printf("*%d번째 문자열 : %d , %s\n", i, strlen(word), word);
		CalculatePostfixformula(word);
	}
	return 0;
}
