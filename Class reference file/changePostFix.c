#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
	char order[100]; // 스택 원소가 들어가는 배열입니다.
	int orderValue[100]; // 스택 원소의 우선순위가 들어가는 배열입니다.
	int top; // 맨 위에 있는 스택 원소의 위치
}stack; // 구조체 선언

stack *getStack() {
	stack *p = (stack*)malloc(sizeof(stack));
	p->top = -1;
	return p;
} // 스택을 초기화하는 함수입니다.

void push(stack *p, char order) {
	if (p->top > 99) {
		// printf("fullError\n");
		return;
	}
	p->top++;
	p->order[p->top] = order;
	if (order == '*')
		p->orderValue[p->top] = 2;
	else if (order == '/')
		p->orderValue[p->top] = 2;
	else if (order == '+')
		p->orderValue[p->top] = 1;
	else if (order == '-')
		p->orderValue[p->top] = 1;
	else if (order == '(')
		p->orderValue[p->top] = 0;
} // 스택에 원소를 추가합니다

void pop(stack *p) {
	if (p->top < 0) {
		// printf("emptyError\n");
		return;
	}
	printf("%c", p->order[p->top]);
	p->order[p->top] = '\0';
	p->orderValue[p->top] = 0;
	p->top--;
} // 스택에 맨 위에 있는 원소를 삭제합니다.

void turnPostFix(stack *p, char *order) {
	for (int i = 0; i < strlen(order); i++) {
		if (order[i] == '(') {
			push(p, order[i]);
		}
		else if (order[i] == ')') {
			while (p->order[p->top] != '(')
				pop(p);
			p->order[p->top] = '\0';
			p->orderValue[p->top] = 0;
			p->top--;
		}
		else if (order[i] == '*' || order[i] == '/') {
			while (p->orderValue[p->top] >= 2 && p->top > -1 && p->order[p->top] != '(')
				pop(p);
			push(p, order[i]);
		}
		else if (order[i] == '+' || order[i] == '-') {
			while (p->orderValue[p->top] >= 1 && p->top > -1 && p->order[p->top] != '(')
				pop(p);
			push(p, order[i]);
		}
		else {
			printf("%c", order[i]);
		}
	}
} // 중위수식을 후위수식으로 출력해주는 함수입니다.

void freeStack(stack *p) {
	while (p->top > -1)
		pop(p);
	printf("\n");
} // 스택에 남아있는 원소를 출력하고 초기화해줍니다.

int main() {
	int N, i;
	char order[100] = "\0";
	stack *p = getStack();
	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++) {
		gets(order);
		// puts(order);
		turnPostFix(p, order);
		freeStack(p);
	}
	return 0;
}
