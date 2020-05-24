#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int N; // 스택의 크기
	int top; // 현재 마지막 원소의 위치
	char word[100]; // 원소가 담길 연결리스트
} stack; // 구조체 선언

stack* init(int N) {
	stack* p = (stack*)malloc(sizeof(stack));
	p->N = N;
	p->top = -1;
	return p;
} // stack을 초기화해주는 함수입니다.

void push(stack* p, char word) {
	if (p->top == p->N - 1) {
		printf("Stack FULL\n");
		return;
	}
	p->top++;
	p->word[p->top] = word;
} // stack에서 push를 해주는 함수입니다.

void pop(stack* p) {
	if (p->top == -1) {
		printf("Stack Empty\n");
		return;
	}
	p->word[p->top] = "\0";
	p->top--;
} // stack에서 pop를 해주는 함수입니다.

void print(stack* p) {
	if (p->top == -1) {
		printf("Stack Empty\n");
		return;
	}
	for (int i = p->top; i > -1; i--) {
		printf("%c", p->word[i]);
	}
}

void freeStack(stack* p) {
	free(p->word);
	free(p);
	return;
} // stack을 초기화해주는 함수입니다.

void printPostfixformula(char* word) {
	int i, N = strlen(word);
	stack* p;
	p = init(N);
	for (i = 0; i < N; i++) {
		if (word[i] == "*" || word[i] == "/") {

		}
		else if (word[i] == "+" || word[i] == "-") {

		}
		else {
			printf("%c", )
		}
	}
} // 중위수식을 후위수식으로 출력해주는 함수입니다.

int main() {
	int N, i;
	char word[100] = "\0";
	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++) {
		scanf("%s", word);
		getchar();
		printf("* %d , %s\n", strlen(word), word);
	}
	return 0;
}
