#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode; // 구조체를 설정합니다.

ListNode* insert_first(ListNode *head, int value) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; // 헤드 포인터의 값을 복사
	head = p; // 헤드 포인터 변경
	return head; // 변경된 헤드 포인터 반환
}

ListNode* insert(ListNode *head, ListNode *pre, element value) {
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode *head) {
	ListNode *removed = NULL;
	if (head == NULL) return NULL;
	removed = head; // 헤드 포인터의 값을 removed에 복사합니다.
	head = removed->link; // 헤드 포인터의 값을 head->link로 변경합니다.
	free(removed); // removed가 가리키는 동적 메모리를 반환합니다.
	return head; // 변경된 헤드 포인터를 반환합니다.
}

ListNode* delete(ListNode *head, ListNode *pre) {
	ListNode *removed;
	if (head == NULL) return NULL;
	removed = pre->link; // pre의 다음 링크를 가리키게 합니다. 
	pre->link = removed->link; // 삭제할 노드의 동적 메모리를 반납합니다. 
	free(removed); // 변경된 헤드 포인터를 반환합니다.
	return head;
}

void print_list(ListNode *head) {
	for (ListNode *p = head; p != NULL; p = p->link) { // p 포인터를 사용해서 출력합니다.
		printf("%d->", p->data);
	}
	printf("NULL\n");
}

int get_length(ListNode *head) {
	int length = 0;
	for (ListNode *p = head; p != NULL; p = p->link) {
		length++;
	}
	return length;
}

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* search_list(ListNode *head, element x) {
	ListNode *p = head;
	while (p != NULL) {
		if (p->data == x)
			return p;
		p = p->link;
	}
	return NULL;
} // 원소를 찾는 함수입니다.

ListNode* concat_list(ListNode *head1, ListNode *head2) {
	if (head1 == NULL) return head2;
	else if(head2 == NULL) return head1;
	else {
		ListNode *p;
		p = head1;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = head2;
		return head1;
	}
} // 리스트를 합치는 함수입니다.

ListNode *reverse(ListNode *head) {
	ListNode *p, *q, *r;
	p = head; // p는 역순으로 만들 리스트
	q = NULL; // q는 역순으로 만들 노드
	while (p != NULL) {
		r = q; // r은 역순으로 된 리스트
		       // r은 q, q는 p를 차례로 따라간다.
		q = p;
		p = p->link;
		q->link = r; // q의 링크 방향을 바꿉니다.
	}
	return q;
} // 노드가 3개 있을 때, 순서를 바꾸는 함수입니다.

int main() {
	ListNode *head1 = NULL;
	ListNode *head2 = NULL;
	ListNode *head3 = NULL;
	int num;
	for (int i = 0; i < 5; i++) {
		head1 = insert_first(head1, i);
		print_list(head1);
		// printf("List 길이 : %d\n", get_length(head1));
	}
	for (int i = 0; i < 5; i++) {
		head2 = insert_first(head2, i);
		print_list(head2);
		// printf("List 길이 : %d\n", get_length(head2));
	}
	if (search_list(head1, 3) != NULL) {
		num = search_list(head1, 3)->data;
		printf("리스트에 %d를 찾았습니다.\n", num);
	}

	head3 = concat_list(head1, head2);
	print_list(head3);

	for (int i = 0; i < 5; i++) {
		head1 = delete_first(head1, i);
		print_list(head1);
		printf("List 길이 : %d\n", get_length(head1));
	}
	return 0;
}
