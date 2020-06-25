#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
	char arr[100];
	int top;
}stack; // ����ü ����

stack *getStack() {
	stack* p = (stack*)malloc(sizeof(stack));
	p->top = -1;
	return p;
} // ���� �Ҵ�

void push(stack *p, char num) {
	if (p->top == 99) {
		//printf("fullError");
		return;
	}// fullError Ȯ��
	p->top++;
	p->arr[p->top] = num;
} // ���� push

char pop(stack *p) {
	char num;
	if (p->top == -1) {
		//printf("emptyError");
		return NULL;
	}// emptyError Ȯ��
	num = p->arr[p->top];
	p->top--;
	return num;
} // ���� pop

void inputTree(char *p, char *Tree) {
	strcpy(Tree, p);
}// ���ڿ��� �迭�� ������ Ʈ���� �����մϴ�.

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
}// �ش� ��忡 �°� root�� ���� ��θ� ã���ݴϴ�.

int main() {
	char tree[100], input[100], node;
	scanf("%s", &input);
	getchar();
	scanf("%c", &node);
	inputTree(input, tree);
	findNode(tree, node);
	return 0;
}