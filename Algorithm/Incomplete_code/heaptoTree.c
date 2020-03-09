#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_ELEMENT 100

typedef struct Node {
	int data;
	struct Node *Leftchild;
	struct Node *Rightchild;
	struct Node *parent;
}Node;

Node * search(Node * node, int key) {
	if (node == NULL) {
		return NULL;
	}
	if (node) {
		search(node->Leftchild, key);
		if (key == node->data) {
			return node;
		}
		search(node->Rightchild, key);
	}
}

Node * new(int key){
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = key;
	node->Leftchild = NULL;
	node->Rightchild = NULL;
	node->parent = NULL;

	return node;
}

Node * insertItem(Node * node, int key) {
	if (node == NULL) {
		return new(key);
	}
	else if (node->Leftchild == NULL) {
		Node * leftchild = insert(node->Leftchild, key);
		node->Leftchild = leftchild;
		leftchild->parent = node;
	}
	else if (node->Rightchild == NULL) {
		Node *rightchild = insert(node->Rightchild, key);
		node->Rightchild = rightchild;
		rightchild->parent = node;
	}
	return node;
}

Node * upHeap(Node * node) {
	int change;
	if (node->parent = NULL) {
		return;
	}

	if (node->data < node->parent) {
		change = node->data;
		node->data = node->parent;
		node->parent = change;
		change = 0;
	}
	else {
		return;
	}
	upHeap(node->parent);
}


Node * removeMax(Node * root){
	k = root->data;
	//삭제부분이 정확히 잘 안 떨어집니다.
}

Node * downHeap(Node * node) {
	int change, N;
	if (node->Rightchild== NULL && node->Leftchild == NULL) {
		return;
	}
	
	if (node->Rightchild != NULL) {
		if (node->Rightchild < node->Leftchild) {
			N = node->Rightchild;
		}
	}
	if (node->data <= node->Leftchild)
		return;
	change = node->Leftchild;
	node->Leftchild = node->data;
	node->data = change;

	downHeap(node->Leftchild);
}

void printHeap(Node * node) {
	if (node) {
		printHeap(node->Leftchild);
		printf("[%d]", node->data);
		printHeap(node->Rightchild);
	}
}

int main() {

	while (1) {
		i = i + 1;
		scanf("%c %d", &a, &b);
		e[i].key = b;
		if (a == 'i') {
			insert_max_heap(heap, e[i]);
			printf("0\n");
		}
		else if (a == 'd') {
			e[i] = delete_max_heap(heap);
			printf("%d\n", e[i].key);
		}
		else if (a == 'p') {
			Print_heap(heap);
		}
		else if (a == 'q') {
			break;
		}
	}

	free(heap);
	return 0;
}
/*
int main(void) {
	HeapType* heap;
	element e[100];

	char a, c;
	int b;
	int i = 0;

	heap = create();
	init(heap);

	while (1) {
		i = i + 1;
		scanf("%c %d", &a, &b);
		e[i].key = b;
		if (a == 'i') {
			insert_max_heap(heap, e[i]);
			printf("0\n");
		}
		else if (a == 'd') {
			e[i] = delete_max_heap(heap);
			printf("%d\n", e[i].key);
		}
		else if (a == 'p') {
			Print_heap(heap);
		}
		else if (a == 'q') {
			break;
		}

	}

	free(heap);
	return 0;
}
*/
