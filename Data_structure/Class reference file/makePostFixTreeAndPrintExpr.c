#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
	char order[100]; // 스택 원소가 들어가는 배열입니다.
	int orderValue[100]; // 스택 원소의 우선순위가 들어가는 배열입니다.
	int top; // 맨 위에 있는 스택 원소의 위치
}stack; // 스택 구조체 선언

typedef struct treeNode {
	char element; // 노드의 정보를 저장해줍니다.
	struct treeNode* left;
	struct treeNode* right;
}treeNode; // 트리 구조체 선언

typedef struct treeNodeStack {
	treeNode **array; // treeNode 포인터를 받을 배열입니다.
	int top; // 맨 위에 있는 스택 원소의 위치
} treeNodeStack; // 트리 구조체를 가진 스택 선언

/* 1번을 위한 함수들입니다. */

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

char pop(stack *p) {
	char word;
	if (p->top < 0) {
		// printf("emptyError\n");
		return;
	}
	word = p->order[p->top];
	p->order[p->top] = '\0';
	p->orderValue[p->top] = 0;
	p->top--;
	return word;
} // 스택에 맨 위에 있는 원소를 삭제하고 반환합니다.

int turnPostFix(stack *p, char *order, char *result) {
	int j = 0;
	for (int i = 0; i < strlen(order); i++) {
		if (order[i] == '(') {
			push(p, order[i]);
		}
		else if (order[i] == ')') {
			while (p->order[p->top] != '(')
				result[j++] = pop(p);
			p->order[p->top] = '\0';
			p->orderValue[p->top] = 0;
			p->top--;
		}
		else if (order[i] == '*' || order[i] == '/') {
			while (p->orderValue[p->top] >= 2 && p->top > -1 && p->order[p->top] != '(')
				result[j++] = pop(p);
			push(p, order[i]);
		}
		else if (order[i] == '+' || order[i] == '-') {
			while (p->orderValue[p->top] >= 1 && p->top > -1 && p->order[p->top] != '(')
				result[j++] = pop(p);
			push(p, order[i]);
		}
		else {
			result[j++] = order[i];
		}
	}
	return j; // 지금까지 추가한 후위수식 문자열의 배열 길이입니다.
} // 중위수식을 후위수식으로 출력해주고 문자열에 얼마나 문자를 입력했는지 알려주는 함수입니다.

int freeStack(stack *p, char *result, int resultSize) {
	int j = resultSize;
	while (p->top > -1)
		result[j++] = pop(p);
	return j; // 지금까지 추가한 후위수식 문자열의 배열 길이입니다.
} // 스택에 남아있는 원소를 후위수식 문자열에 추가해주는 함수입니다.

void printStack(stack *p) {
	for (int i = p->top; i > -1; i--) {
		printf("%c", p->order[i]);
	}
	printf("\n");
} // 스택에 있는 원소를 출력해줍니다.

/* 2번을 위한 함수들입니다. */

treeNodeStack *getTreeNodeStack() {
	treeNodeStack *p = (treeNodeStack*)malloc(sizeof(treeNodeStack));
	p->array = (treeNode**)malloc(100 * (sizeof(treeNode*)));
	p->top = -1;
	return p;
} // treeNode를 노드로 하는 스택을 초기화하는 함수입니다.

treeNode* getTreeNode(char word) {
	treeNode *p = (treeNode*)malloc(sizeof(treeNode));
	p->element = word;
	p->left = NULL;
	p->right = NULL;
	return p;
} // 트리 노드를 초기화해주는 함수입니다.

void pushTreeNode(treeNodeStack* p, treeNode *node) {
	p->top++;
	p->array[p->top] = node;
} // 스택에 트리 노드를 추가해줍니다.

treeNode *popTreeNode(treeNodeStack* p) {
	treeNode *node = p->array[p->top];
	p->top--;
	return node;
} // 스택에 트리 노드를 삭제하고 삭제한 노드를 반환해줍니다.

void makeExptree(treeNode *node, treeNode *b, treeNode *a) {
	node->left = b;
	node->right = a;
} // 해당 노드를 좌우 자식노드와 연결해줍니다.

treeNode* makeTreeNodeStack(char *order, int n) {
	treeNodeStack *TreeNodeStack = getTreeNodeStack();
	treeNode *node, *a, *b;
	for (int i = 0; i < n; i++) {
		node = getTreeNode(order[i]);
		if (order[i] == '*' || order[i] == '/' || order[i] == '+' || order[i] == '-') {
			a = popTreeNode(TreeNodeStack);
			b = popTreeNode(TreeNodeStack);
			makeExptree(node, b, a);
		}
		pushTreeNode(TreeNodeStack, node);
		// printf("Array: %c\n", TreeNodeStack->array[TreeNodeStack->top]->element); <- push되는 원소 확인
	}
	return popTreeNode(TreeNodeStack);
} // 트리노드가 원소로 들어가 조건에 맞게 연산트리로 만들어줍니다.

void printExpr(treeNode* p, treeNode* root) {
	if (p != NULL && p != root) {
		if (p->left != NULL && p->right != NULL) {
			printf("(");
			printExpr(p->left, root);
		}
		printf("%c", p->element);
		if (p->left != NULL && p->right != NULL) {
			printExpr(p->right, root);
			printf(")");
		}
	}
	else if (p != NULL && p == root) {
		if (p->left != NULL && p->right != NULL) 
			printExpr(p->left, root);
		printf("%c", p->element);
		if (p->left != NULL && p->right != NULL) 
			printExpr(p->right, root);
	} // 가장 바깥에 있는 ()는 필요 없으므로 처음은 p == root인 부분에서 ()를 빼줍니다.
} // 중위 순회로 트리노드들을 출력해주는 함수입니다.

int main() {
	int N, i, resultSize;
	char order[100] = "\0";
	char *result;
	stack *p = getStack();
	treeNode *root;
	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++) {
		gets(order);
		// puts(order);
		result = (char*)malloc(strlen(order) * sizeof(char));
		resultSize = turnPostFix(p, order, result);
		resultSize = freeStack(p, result, resultSize);
		// printf("N: %d\n", resultSize); // 후위수식 확인
		// printStack(p); // 초기화 확인용!
		// printf("CHAR: %s\n", result); // 후위수식 확인
		root = makeTreeNodeStack(result, resultSize);
		printExpr(root, root);
		printf("\n");
	}
	return 0;
}
