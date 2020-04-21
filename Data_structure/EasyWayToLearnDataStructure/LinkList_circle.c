#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	element data;
	struct ListNode *link;
} ListNode;

ListNode *insert_first(ListNode* head, element data) {
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode *insert_last(ListNode* head, element data) {
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node; // 헤드 포인터로 변경합니다.
	}
	return head;
}

void print_list(ListNode* head) {
	ListNode *p;
	if (head == NULL) {
		return;
	}
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data); // 마지막 노드 출력
}

int get_length(ListNode* head) {
	ListNode *p;
	int num = 0;
	if (head == NULL) {
		return 0;
	}
	p = head->link;
	do {
		num++;
		p = p->link;
	} while (p != head);
	return num++;
}

int main() {
	ListNode *head = NULL;
	head = insert_last(head, 10);
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 0);
	
	printf("길이 : %d\n", get_length(head));
	print_list(head);
	return 0;
}
