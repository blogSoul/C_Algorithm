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

ListNode* init() {
	ListNode* header;
	header = getNode(NULL);
	return header;
} // 리스트를 초기화해줍니다.

void addLastNode(ListNode* header, int data) {
	ListNode *p, *q;
	q = getNode(data);
	p = header;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = q;
} // 마지막에 노드를 추가해줍니다.

void printNode(ListNode* header) {
	ListNode *p;
	p = header;
	if (header->next == NULL) {
		printf(" 0\n");
		return; // 빈 리스트면 0을 반환
	}
	while (p->next != NULL) {
		p = p->next;
		printf(" %d", p->data);
	}
	printf("\n");
} // 노드들을 출력해줍니다.

void removeFirstNode(ListNode* header) {
	ListNode *p, *temp;
	if (header->next == NULL)
		return; // 빈 리스트면 바로 반환
	p = header->next;
	header->next = p->next;
	free(p);
} // 첫번째 원소를 없에줍니다.

ListNode* unionNode(ListNode* A, ListNode* B) {
	ListNode* C = init();
	int a, b;
	while (A->next != NULL && B->next != NULL) {
		a = A->next->data;
		b = B->next->data;
		if (a < b) {
			addLastNode(C, a);
			removeFirstNode(A);
		}
		else if (a > b){
			addLastNode(C, b);
			removeFirstNode(B);
		}
		else {
			addLastNode(C, a);
			removeFirstNode(A);
			removeFirstNode(B);
		}
	}
	while (A->next != NULL) {
		a = A->next->data;
		addLastNode(C, a);
		removeFirstNode(A);
	}
	while (B->next != NULL) {
		b = B->next->data;
		addLastNode(C, b);
		removeFirstNode(B);
	}
	return C;
} // 두 연결리스트를 삭제하면서 두 연결리스트의 합집합을 반환합니다.

ListNode* intersectNode(ListNode* A, ListNode* B) {
	ListNode* C = init();
	int a, b;
	while (A->next != NULL && B->next != NULL) {
		a = A->next->data;
		b = B->next->data;
		if (a < b) {
			removeFirstNode(A);
		}
		else if (a > b) {
			removeFirstNode(B);
		}
		else {
			addLastNode(C, a);
			removeFirstNode(A);
			removeFirstNode(B);
		}
	}
	while (A->next != NULL) {
		removeFirstNode(A);
	}
	while (B->next != NULL) {
		removeFirstNode(B);
	}
	return C;
} // 두 연결리스트를 삭제하면서 두 연결리스트의 합집합을 반환합니다.


int main() {
	int i, N, M, num;
	ListNode *p1, *p2, *p1_1, *p2_1, *UnionTwoList, *IntersectTwoList;
	p1 = init();
	p1_1 = init();
	p2 = init();
	p2_1 = init();
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &num);
		addLastNode(p1, num);
		addLastNode(p1_1, num);
	}
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%d", &num);
		addLastNode(p2, num);
		addLastNode(p2_1, num);
	}
	UnionTwoList = unionNode(p1, p2);
	IntersectTwoList = intersectNode(p1_1, p2_1);
	printNode(UnionTwoList);
	printNode(IntersectTwoList);
	// 노드들을 삭제하면서 합집합과 교집합을 구하는 방법을 사용했으므로 각 리스트는 헤더만 남았습니다.
	free(p1);
	free(p1_1);
	free(p2);
	free(p2_1);
	return 0;
}
