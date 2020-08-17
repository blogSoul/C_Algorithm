#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element value;
	struct ListNode *next;
} ListNode;

ListNode *getNode(int value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->value = value;
	p->next = NULL;
	return p;
}

ListNode * addNode(ListNode* header, int value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->value = value;
	p->next = header->next;
	header->next = p;
	return header;
}

void elements(ListNode *header) {
	ListNode *p = header;
	do {
		p = p->next;
		printf(" %d", p->value);
	} while (p != NULL);
}

int main(void){
	int N, i;
	ListNode *header = getNode(0), *p;
	p = header;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		header = addNode(header, i + 1);
	}
	elements(p);
	return 0;
}
