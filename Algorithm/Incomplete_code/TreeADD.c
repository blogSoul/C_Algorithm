// 14010384 설민욱 과제1 제출 내용입니다.
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode *left, *right;
}TreeNode;
// 트리 구조를 만들었습니다.

TreeNode * search(TreeNode * node, int key) {
	if (node == NULL) {
		return NULL;
	}

	if (key == node->key) {
		return node;
	}
	else if (key < node->key) {
		return search(node->left, key);
	}
	else {
		return search(node->right, key);
	}
}// 노드를 입력하면 탐색할 수 있는 함수입니다.

void RLsearch(TreeNode * root, char *a) {
    if (root != NULL) {
		printf(" %d", root->key);
		if (a[0] == 'L') {
			a = a - 'L';
			RLsearch(root->left, a);
		}
		if (a[0] == 'R') {
			a = a - 'R';
			RLsearch(root->right, a);
		}
    }
}// RL방향에 따라 노드를 입력하면 탐색할 수 있는 함수입니다.

TreeNode * newnode(int N) {
	TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
	temp->key = N;
	temp->left = temp->right = NULL;
	return temp;
}// 아무것도 없는 노드에 입력 받은 N를 노드에 넣습니다.

TreeNode * insertnode(TreeNode * node, int key) {
	if (node == NULL) {
		return newnode(key);
	}

	if (key < node->key) {
		node->left = insertnode(node->left, key);
	}
	else if(key > node->key){
		node->right = insertnode(node->right, key);
	}
	return node;
}// 노드를 삽입하는 함수입니다.

void preorder(TreeNode * root) {
	if (root != NULL){
		printf("[%d] ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}// 전위함수로 노드가 어떻게 분포 되어 있는지 확인할 수 있는 함수입니다.

int main(void) {
	TreeNode * root = NULL;// 트리로 이루어진 구조 하나를 만들었습니다. 
	TreeNode * tmp = NULL;// 트리로 이루어진 구조 하나를 만들었습니다. 
	char op[100]; // 문자를 입력 받는 함수 입니다.
	int find; // 경로 탐색 횟수입니다.
	int num_op; // 입력받는 노드 문장의 개수입니다.
	int left, data, right; // 각각 노드별로 왼쪽에 있는 자식, 부모, 오른쪽에 있는 자식으로 받습니다.
	
	scanf("%d", &num_op); // 연산 개수를 입력합니다.
	for (int i = 0; i < num_op; ++i) {
		scanf("%d %d %d", &data, &left, &right);
		root = insertnode(root, data);
		root = insertnode(root, left);
		root = insertnode(root, right);
	}

	scanf("%d", &find); // 경로 설정 횟수를 지정합니다.
	for (int i = 0; i < find; ++i) {
		scanf("%s", &op);
		RLsearch(root, op);
	}
    preorder(root);
	return 0;
}
