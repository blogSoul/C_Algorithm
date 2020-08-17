#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element value;
	struct ListNode *next;
}ListNode;

ListNode* initialize() {
	ListNode* header = (ListNode *)malloc(sizeof(ListNode));
	header->value = 0;
	header->next = header;
	return header;
}

ListNode* getNode(int value) {
	ListNode* node = (ListNode *)malloc(sizeof(ListNode));
	node->value = value;
	node->next = NULL;
	return node;
}

ListNode* addNode_last(ListNode* header, int value) {
	ListNode *last = header, *p;
	p = getNode(value);
	while (last->next != header) {
		last = last->next;
	}
	last->next = p;
	p->next = header;
	return header;
}

void traverse(ListNode * header) {
	ListNode *p = header->next;
	do {
		printf(" %d", p->value);
		p = p->next;
	} while (p->value != 0);
	if (p == header) {
		printf(" DONE\n");
	}
}

int main(){
	int N, i;
	ListNode *p = initialize();
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		p = addNode_last(p, i + 1);
	}
	traverse(p);
	return 0;
}
