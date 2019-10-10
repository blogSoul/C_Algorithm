#include <stdlib.h> 
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <math.h>

typedef struct NodeStruct {
	int value;
	struct NodeStruct* leftChild;
	struct NodeStruct* rightChild;
}Node;

Node* root = NULL;

Node* insertNode(Node* root, int value) {
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->leftChild = root->rightChild = NULL;
		root->value = value;
		return root;
	}
	else {
		if (root->value > value) {
			root->leftChild = insertNode(root->rightChild, value);
		}
	}
	return root;
}

Node* findNode(Node* root) {
	Node* tmp = root;
	while (tmp->leftChild != NULL) {
		tmp = tmp->leftChild;
	}
	return tmp;
}

Node* deleteNode(Node* root, int value) {

}

/*
메모장입니다.
   root->leftChild = BST_insert(root->leftChild, value);
		else
			root->rightChild = BST_insert(root->rightChild, value);
	}
*/
int main() {
	int N; // 동적할당 사이즈
	int K;

	scanf_s("%d", &N);
	scanf_s("%d", &K);
	int* arr = malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		arr[i] = 0;
	}
	//초기화 
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	
	free(arr);
	return 0;
}
