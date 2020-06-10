#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
	int data; // 노드에 저장되는 값
	int NodeNumber; // 노드번호
	struct treeNode *left; // child left노드를 가리키는 링크
	struct treeNode *right; // child right노드를 가리키는 링크
}treeNode; // 구조체 선언

treeNode *getNode(int num, int data) {
	treeNode *p = (treeNode *)malloc(sizeof(treeNode));
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	p->NodeNumber = num;
	return p;
} // 노드 초기화

treeNode *makeStaticTree(treeNode **arr) {
	arr[0] = getNode(1, 20);
	arr[1] = getNode(2, 30);
	arr[2] = getNode(3, 50);
	arr[3] = getNode(4, 70);
	arr[4] = getNode(5, 90);
	arr[5] = getNode(6, 120);
	arr[6] = getNode(7, 130);
	arr[7] = getNode(8, 80);
	arr[0]->left = arr[1];
	arr[0]->right = arr[2];
	arr[1]->left = arr[3];
	arr[1]->right = arr[4];
	arr[2]->right = arr[5];
	arr[5]->left = arr[6];
	arr[5]->right = arr[7];
} // static tree를 만들어줍니다.

void printNode(treeNode **arr, int num) {
	if (num > 8) {
		printf("-1\n");
	}
	else if (arr[num - 1]->left != NULL && arr[num - 1]->right != NULL) {
		printf("%d %d %d\n", arr[num - 1]->data, arr[num - 1]->left->data, arr[num - 1]->right->data);
	}
	else if (arr[num - 1]->left == NULL && arr[num - 1]->right != NULL) {
		printf("%d %d\n", arr[num - 1]->data, arr[num - 1]->right->data);
	}
	else if (arr[num - 1]->left != NULL && arr[num - 1]->right == NULL) {
		printf("%d %d\n", arr[num - 1]->data, arr[num - 1]->left->data);
	}
	else if (arr[num - 1]->left == NULL && arr[num - 1]->right == NULL) {
		printf("%d\n", arr[num - 1]->data);
	}
} // 노드 정보를 출력해주는 함수입니다.

void preOrder(treeNode *p) {
	if (p == NULL)
		return;
	printf(" %d", p->data);
	preOrder(p->left);
	preOrder(p->right);
} // 선위순회 알고리즘입니다.

void inOrder(treeNode *p) {
	if (p == NULL)
		return;
	inOrder(p->left);
	printf(" %d", p->data);
	inOrder(p->right);
} // 중위순회 알고리즘입니다.

void postOrder(treeNode *p) {
	if (p == NULL)
		return;
	postOrder(p->left);
	postOrder(p->right);
	printf(" %d", p->data);
} // 후위순회 알고리즘입니다.

void printNodeByOrder(treeNode **arr, int order, int num) {
	treeNode *p;
	if (num > 8 || order > 3 || num < 0 || order < 0) {
		printf("-1\n");
	} // 존재하지 않는 노드 번호거나 맞는 주문이 아닐 경우
	else if (order == 1) {
		preOrder(arr[num - 1]);
	} // 선위 순회일 경우
	else if (order == 2) {
		inOrder(arr[num - 1]);
	} // 중위 순회일 경우
	else if (order == 3) {
		postOrder(arr[num - 1]);
	} // 후위 순회일 경우
} // 순회 종류에 맞게 출력해주는 함수입니다.

int sumNodeData(treeNode *p) {
	if (p == NULL) {
		return 0;
	}
	return p->data + sumNodeData(p->left) + sumNodeData(p->right);
} // 부트리의 크기 총합을 구하는 함수입니다.

void checkSumNodeData(treeNode **arr, int num) {
	treeNode *p;
	if (num > 8 || num < 0) {
		printf("-1\n");
		return;
	} // 존재하지 않는 노드 번호거나 맞는 주문이 아닐 경우
	p = arr[num - 1];
	printf("%d\n", sumNodeData(p));
	return;
}

int main() {
	int N, order;
	treeNode **p = (treeNode**)malloc(8 * sizeof(treeNode*));
	makeStaticTree(p);
	/*
	for (int i = 0; i < 8; i++) {
		printf("%d\n", p[i]->data);
	} NodeCheck
	*/
	scanf("%d", &N);
	checkSumNodeData(p, N);
	free(p);
	return 0;
}
