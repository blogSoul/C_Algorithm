#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
	char arr[100];
	int top;
}stack; // 구조체 선언

stack *getStack() {
	stack* p = (stack*)malloc(sizeof(stack));
	p->top = -1;
	return p;
} // 스택 할당

void push(stack *p, char num) {
	if (p->top == 99) {
		//printf("fullError");
		return;
	}// fullError 확인
	p->top++;
	p->arr[p->top] = num;
} // 스택 push

char pop(stack *p) {
	char num;
	if (p->top == -1) {
		//printf("emptyError");
		return NULL;
	}// emptyError 확인
	num = p->arr[p->top];
	p->top--;
	return num;
} // 스택 pop

void inputTree(char *p, char *Tree) {
	strcpy(Tree, p);
}// 문자열을 배열로 구성된 트리에 복사합니다.

void findNode(char *tree, char node) {
	stack *p = getStack();
	int i, nodeNumber;
	for (i = 1; i < strlen(tree); i++) {
		if (node == tree[i]) {
			nodeNumber = i;
			break;
		}
	}
	while (nodeNumber != 1) {
		push(p, tree[nodeNumber]);
		nodeNumber /= 2;
	}
	push(p, tree[nodeNumber]);
	while (p->top != -1) {
		printf("%c", pop(p));
	}
}// 해당 노드에 맞게 root로 가는 경로를 찾아줍니다.

int main() {
	char tree[100], input[100], node;
	scanf("%s", &input);
	getchar();
	scanf("%c", &node);
	inputTree(input, tree);
	findNode(tree, node);
	return 0;
}