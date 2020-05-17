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

void peek(stack* p) {
	if (p->top == -1) {
		printf("Stack Empty\n");
		return;
	}
	printf("%c\n", p->array[p->top]);
	return;
} // stack peek 함수입니다.

void duplicate(stack* p) {
	element word;
	if (p->top == -1) {
		printf("Stack Empty\n");
		return;
	}
	if (p->top == p->N - 1) {
		printf("Stack FULL\n");
		return;
	}
	word = p->array[p->top];
	pop(p);
	push(p, word);
	push(p, word);
	return;
} // stack을 한 번 pop하고 push를 두 번하는 함수입니다.

void print(stack* p) {
	for (int i = p->top; i >= 0; i--) {
		printf("%c", p->array[i]);
	}
	printf("\n");
	return;
} // stack print 함수입니다.

void upRotate(stack* p, int N) {
	char topWord;
	int i, num;
	if (p->top == -1) {
		printf("Stack Empty\n");
		return;
	}
	if (p->top < N - 1)
		return;
	topWord = p->array[p->top];
	num = p->top;
	for (i = 0; i < N - 1; i++) {
		p->array[num] = p->array[num - 1];
		num--;
	}
	p->array[p->top - N + 1] = topWord;
} // stack에서 UpRotate을 하는 함수입니다.

void upRotate_2(stack* p, int N) {
	char topWord;
	element *q;
	int i, num;
	q = (element*)calloc(N, sizeof(element));
	if (p->top == -1) {
		printf("Stack Empty\n");
		return;
	}
	if (p->top < N - 1)
		return;
	for (i = 0; i < N; i++) {
		q[i] = p->array[p->top];
		pop(p);
	}
	push(p, q[0]);
	for (i = N - 1; i > 0; i--) {
		push(p, q[i]);
	}
	free(q);
} // stack의 pop과 push를 이용해 UpRotate을 하는 함수입니다.

void downRotate(stack* p, int N) {
	char topWord;
	int i, num;
	if (p->top == -1) {
		printf("Stack Empty\n");
		return;
	}
	if (p->top < N - 1)
		return;
	topWord = p->array[p->top - N + 1];
	num = p->top - N + 1;
	for (i = 0; i < N - 1; i++) {
		p->array[num] = p->array[num + 1];
		num++;
	}
	p->array[p->top] = topWord;
} // stack에서 downRotate을 하는 함수입니다.

void downRotate_2(stack* p, int N) {
	char topWord;
	element *q;
	int i, num;
	q = (element*)calloc(N, sizeof(element));
	if (p->top == -1) {
		printf("Stack Empty\n");
		return;
	}
	if (p->top < N - 1)
		return;
	for (i = 0; i < N; i++) {
		q[i] = p->array[p->top];
		pop(p);
	}
	for (i = N - 2; i >= 0; i--) {
		push(p, q[i]);
	}
	push(p, q[N - 1]);
	free(q);
} // stack의 pop과 push를 이용해 downRotate을 하는 함수입니다.

void freeStack(stack* p) {
	if (p->top == -1 || p->N == 0)
		return;
	free(p->array);
	p->top = -1;
	p->N = 0;
	free(p);
	return;
} // 메모리 해제 함수입니다.

int main() {
	int N, M, J, i, top;
	char order[6], word;
	stack* p;
	scanf("%d", &N); //  stack 크기 설정
	p = initStack(N); // 스택 초기화
	getchar();
	scanf("%d", &M); // 연산의 개수
	getchar();
	for (i = 0; i < M; i++) {
		scanf("%s", order);
		getchar();
		// printf("%s\n", order);
		if (strcmp(order, "POP") == 0) {
			pop(p);
		}
		else if (strcmp(order, "PUSH") == 0) {
			scanf("%c", &word);
			getchar();
			push(p, word);
		}
		else if (strcmp(order, "PEEK") == 0) {
			peek(p);
		}
		else if (strcmp(order, "DUP") == 0) {
			duplicate(p);
		}
		else if (strcmp(order, "UpR") == 0) {
			scanf("%d", &J);
			getchar();
			upRotate_2(p, J);
		}
		else if (strcmp(order, "DownR") == 0) {
			scanf("%d", &J);
			getchar();
			downRotate_2(p, J);
		}
		else if (strcmp(order, "PRINT") == 0) {
			print(p);
		}
	}
	freeStack(p); // 메모리 해제
	return 0;
}
