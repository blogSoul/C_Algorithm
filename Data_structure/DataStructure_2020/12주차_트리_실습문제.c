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

treeNode *makeStaticTree(treeNode **arr){
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

int main() {
	int N;
	treeNode **p = (treeNode**)malloc(8 * sizeof(treeNode*));
	makeStaticTree(p);
	/*
	for (int i = 0; i < 8; i++) {
		printf("%d\n", p[i]->data);
	} NodeCheck
	*/
	scanf("%d", &N);
	printNode(p, N);
	free(p);
	return 0;
}
