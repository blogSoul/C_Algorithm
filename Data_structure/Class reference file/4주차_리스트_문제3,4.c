#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element value;
	struct ListNode *prev;
	struct ListNode *next;
} ListNode;

ListNode* getNode() {
	ListNode* Node = (ListNode*)malloc(sizeof(ListNode));
	Node->value = NULL;
	Node->prev = Node;
	Node->next = Node;
	return Node;
}

void init(ListNode* header, ListNode* trailer) {
	header->next = trailer;
	trailer->prev = header;
}

void addFirst(ListNode* header, element e) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->value = e;
	node->next = header->next;
	node->prev = header;
	header->next->prev = node;
	header->next = node;
}

void addLast(element e, ListNode* trailer) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->value = e;
	node->next = trailer;
	node->prev = trailer->prev;
	trailer->prev->next = node;
	trailer->prev = node;
}

void removeFirst(ListNode* header, ListNode* trailer) {
	ListNode *p = header->next;
	if (p == trailer) return;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
}

void removeLast(ListNode* header, ListNode* trailer) {
	ListNode *p = trailer->prev;
	if (p == header) return;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
}

void removeAll(ListNode* header, ListNode* trailer) {
	ListNode *temp, *p;
	p = header->next; // 첫번째 원소로 이동
	while (p != trailer) {
		temp = p->next;
		free(p);
		p = temp;
	}
	header->next = trailer;
	trailer->prev = header;
}

void printList(ListNode* header, ListNode* trailer) {
	ListNode* p;
	p = header;
	if (p->next == trailer) {
		printf("init status\n");
		return;
	}
	while (p->next != trailer) {
		p = p->next;
		printf(" %d", p->value);
	} 
	printf("\n");
}

int main() {
	int N, i, value;
	ListNode *header, *trailer, *p;
	header = getNode();
	trailer = getNode();
	init(header, trailer);
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &value);
		addFirst(header, value);
		addLast(value, trailer);
	}
	removeFirst(header, trailer);
	removeLast(header, trailer);
	printList(header, trailer);
	removeAll(header, trailer);
	printList(header, trailer);
	return 0;
}
