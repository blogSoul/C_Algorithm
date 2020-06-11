#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
	int data;
	struct treeNode *left;
	struct treeNode *right;
}treeNode; // 구조체 선언

treeNode* getNode(int data) {
	treeNode* p = (treeNode*)malloc(sizeof(treeNode));
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
} // 노드 초기화

int isInternal(treeNode *p) {
	if (p->left != NULL || p->right != NULL)
		return 1; // 존재합니다.
	else
		return 0; // 존재하지 않습니다.
} // 내부 노드인지 확인해주는 함수입니다.

int isExternal(treeNode *p) {
	if (p->left == NULL && p->right == NULL)
		return 1; // 존재합니다.
	else
		return 0; // 존재하지 않습니다.
} // 외부 노드인지 확인해주는 함수입니다.

int sumNodeData(treeNode *p) {
	if (p == NULL) {
		return 0;
	}
	return p->data + sumNodeData(p->left) + sumNodeData(p->right);
} // 부트리의 크기 총합을 구하는 함수입니다.

treeNode *findNode(treeNode* p, int data) {
	if (p->data == data) {
		return p;
	} else {
		if (p->left != NULL) {
			treeNode* Left = findNode(p->left, data);
			if (Left != NULL) {
				return Left;
			}
		}
		if (p->right != NULL)
			return findNode(p->right, data);
	}
	return NULL;
} // data에 해당되는 정보가 들어 있는 노드를 찾는 함수입니다.

void addNode(treeNode* root, int nodeData, int leftData, int rightData) {
	treeNode* p = findNode(root, nodeData);
	// printf("%d\n", p->data);
	if (p->left == NULL && leftData != 0)
		p->left = getNode(leftData);
	if (p->right == NULL && rightData != 0)
		p->right = getNode(rightData);
} // 조건에 맞게 노드를 추가해주는 함수입니다.

void printNode(treeNode* p) {
	if (p != NULL) {
		printf(" %d", p->data);
		printNode(p->left);
		printNode(p->right);
	}
} // 선위 순회로 트리노드들을 출력해주는 함수입니다.

void maketree(treeNode* root, int nodeData, int leftData, int rightData) {
	root->data = nodeData;
	root->left = getNode(leftData);
	root->right = getNode(rightData);
	return;
} // 첫번째 원소를 받아 트리구조를 만들어줍니다.

void makeOrderBy(treeNode* root, char *order) {
	treeNode *p = root;
	printf(" %d", p->data);
	for (int i = 0; i < strlen(order); i++) {
		if (order[i] == 'L') {
			if (p->left != NULL) {
				p = p->left;
				printf(" %d", p->data);
			}
			else break;
		}
		else if (order[i] == 'R') {
			if (p->right != NULL) {
				p = p->right;
				printf(" %d", p->data);
			}
			else break;
		}
	}
} // 주문에 맞게 노드를 출력해주는 함수입니다.

int main() {
	int M, N, i, j, leftData, rightData, nodeData;
	treeNode *root = getNode(0), *p, *q;
	char order[100];
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &nodeData, &leftData, &rightData);
		// printf("%d %d %d\n", nodeData, leftData, rightData);
		if(i != 0)
			addNode(root, nodeData, leftData, rightData);
		else
			maketree(root, nodeData, leftData, rightData);
	}
	// printNode(root);
	// printf("\n");
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%s", &order);
		makeOrderBy(root, order);
	}
	return 0;
}
