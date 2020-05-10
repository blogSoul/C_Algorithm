#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int data;
	struct ListNode *next;
}ListNode; // 구조체 선언

ListNode* getNode(int data) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = data;
	p->next = NULL;
	return p;
} // 노드를 초기화해줍니다.

void addLastNode(ListNode* first, int data) {
	ListNode *p, *q;
	q = getNode(data);
	p = first;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = q;
} // 마지막에 노드를 추가해줍니다.

void printNode(ListNode* first) {
	ListNode *p;
	p = first;
	while (p != NULL) {
		printf(" %d", p->data);
		p = p->next;
	}
	printf("\n");
} // 노드들을 출력해줍니다.

ListNode* removeFirstNode(ListNode* first) {
	ListNode *p, *temp;
	p = first;
	temp = p->next;
	free(p);
	return temp;
} // 첫번째 원소를 없에줍니다.

int member(ListNode *p1, int e) {
	ListNode *p;
	int a;
	if (p1 == NULL)
		return 0; // e가 p1안에 들어 있지 않습니다.
	p = p1;
	while (1) {
		a = p->data;
		if (a < e) {
			if (p->next == NULL)
				return 0;
			else
				p = p->next;
		}
		else if (a > e)
			return 0; // e가 p1안에 들어 있지 않습니다.
		else
			return 1; // e가 p1안에 들어 있습니다.
	}
} // p1안에 e가 속해있는지 확인해줍니다.

int subset(ListNode *p1, ListNode *p2) {
	ListNode *p;
	if (p1 == NULL)
		return 0; // 부분집합에 속합니다.
	p = p1;
	while (1) {
		if (member(p2, p->data) == 1) {
			if (p->next == NULL)
				return 0;// 부분집합에 속합니다.
			else
				p = p->next;
		}
		else 
			return p->data;
	}
} // 부분집합인지 판별합니다.

void freeNode(ListNode *p1) {
	ListNode *p, *temp;
	if (p1 == NULL)
		return;
	p = p1;
	while (p->next != NULL) {
		temp = p->next;
		free(p);
		p = temp;
	}
} // 메모리를 해제합니다.

int main() {
	int i, N, M, num;
	ListNode *p1 = NULL, *p2 = NULL;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &num);
		if (i != 0)
			addLastNode(p1, num);
		else
			p1 = getNode(num);
	}

	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%d", &num);
		if (i != 0)
			addLastNode(p2, num);
		else
			p2 = getNode(num);
	}
	printf("%d\n", subset(p1, p2));
	freeNode(p1);
	freeNode(p2);
	return 0;
}
