#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treeNode {
	struct treeNode *left;
	struct treeNode *right;
	int weight; // 값
	char id; //id
}treeNode; // 구조체 선언

treeNode *getNode(char word) {
	treeNode *p = (treeNode*)malloc(sizeof(treeNode));
	p->id = word;
	p->weight = 0;
	p->left = NULL;
	p->right = NULL;
} // 노드 할당

void maketreeNode(treeNode *root, char a, char b, char c, int num) {
	root->id = a;
	root->weight = num;
	root->left = getNode(b);
	root->right = getNode(c);
} // root 생성

treeNode* findTree(treeNode *p, char word) {
	if (p->id == word)
		return p;
	if (p->left != NULL) {
		treeNode* Left = findTree(p->left, word);
		if (Left != NULL) {
			return Left;
		}
	}
	if (p->right != NULL) {
		return findTree(p->right, word);
	}
	return NULL;
} // 후위순위에 맞게 tree 출력

int weight(treeNode *p) {
	if (p == NULL)
		return 0;
	return p->weight + weight(p->left) + weight(p->right);
}

void findweight(treeNode *root, char word) {
	treeNode *p = findTree(root, word);
	printf("%d", weight(p));
}

void changeTree(treeNode *root, char word) {
	treeNode *p = findTree(root, word);
}

void addTreeNode(treeNode *root, char a, char b, char c, int num) {
	treeNode *p = findTree(root, a);
	//printf("D: %c\n", p->id);
	if (p != NULL) {
		if (b != '0' && b != 'O')
			p->left = getNode(b);
		if (c != '0' && c != 'O')
			p->right = getNode(c);
		p->weight = num;
		// printf("P: %c %c %c %d\n", p->id, p->left->id, p->right->id, p->weight);
	}
	return;
} // 노드를 찾아서 조건에 맞게 트리노드 추가

void printTree(treeNode *p) {
	if (p == NULL)
		return;
	printTree(p->left);
	printTree(p->right);
	printf("%c", p->id);
} // 후위순위에 맞게 tree 출력

int main() {
	int N, i, data;
	char node, left, right, word;
	treeNode *root = getNode('\0');
	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++) {
		scanf("%c %c %c %d", &node, &left, &right, &data);
		getchar();
		// printf("%c %c %c %d\n", node, left, right, data);
		if (i != 0) {
			addTreeNode(root, node, left, right, data);
		}
		else {
			maketreeNode(root, node, left, right, data);
		}
		//printTree(root);
		//printf("\n");
	}
	scanf("%c", &word);
	printTree(root);
	printf("\n");
	findweight(root, word);
	return 0;
}
