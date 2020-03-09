#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *next;
	int data;
} Node;

int main() {
	Node *head;
	Node *node;

	node = (Node *)malloc(sizeof(Node));
	node->data = 10;
	node->next = NULL;

	head = node;

	printf("%d", head->data);
	free(head);

	system("pause");
	return 0;
}
