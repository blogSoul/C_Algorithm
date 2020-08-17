#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *next;
	int data;
}Node;

Node* get_node() {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = 0;
	node->next = NULL;
	return node;
}

void put_node(Node* head, int data) {
	Node* node = get_node();
	node->data = data;
	node->next = head->next;
	head->next = node;
}

void print_node(Node* head) {
	for (Node* p = head->next; p != NULL; p = p->next) {
		printf(" %d", p->data);
	}
}

void free_node(Node* head) {
	if (head != NULL)
		free_node(head->next);
	else
		return;
}

int main() {
	Node *head = NULL;
	head = get_node();
	put_node(head, 10);
	put_node(head, 20);
	put_node(head, 30);
	print_node(head);
	free_node(head);
	return 0;
}