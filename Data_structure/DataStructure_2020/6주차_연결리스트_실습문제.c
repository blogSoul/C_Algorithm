#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element coef; // 항의 계수
	element exp; // 항의 차수
	struct ListNode *next; // 다음 노드를 가리키는 링크
} ListNode; // 노드 구조체를 설정해줍니다.

ListNode *getnode() {
	ListNode* node;
	node = (ListNode*)malloc(sizeof(ListNode));
	node->next = NULL;
	return node;
} // 노드를 생성하는 함수입니다.

ListNode* appendTerm(ListNode * k, element c, element m) {
	ListNode* t;
	t = getnode();
	t->coef = c;
	t->exp = m;
	k->next = t;
	return k;
} // 해당 연결리스트의 바로 다음 노드를 추가시키는 함수입니다.

ListNode* addPoly(ListNode* x, ListNode* y) {
	ListNode * result, *i, *j, *k;
	int sum;
	result = getnode();
	i = x->next;
	j = y->next;
	k = result;
	while (i != NULL && j != NULL) {
		if (i->exp > j->exp) {
			appendTerm(k, i->coef, i->exp);
			i = i->next;
			k = k->next;
		}
		else if (i->exp < j->exp) {
			appendTerm(k, j->coef, j->exp);
			j = j->next;
			k = k->next;
		}
		else {
			sum = i->coef + j->coef;
			if (sum != 0) {
				appendTerm(k, sum, i->exp);
				k = k->next;
			}
			i = i->next;
			j = j->next;
		}
	}
	if (i == NULL && j == NULL) {
		return result; // 동시에 덧셈이 끝나는 경우도 생각합니다.
	}	
	while (i != NULL) {
		appendTerm(k, i->coef, i->exp);
		i = i->next;
		k = k->next;
	}
	while (j != NULL) {
		appendTerm(k, j->coef, j->exp);
		j = j->next;
		k = k->next;
	}
	return result;
} // 해당 두 연결리스트를 계산해서 result 리스트에 결과값을 저장해줍니다.

void printNode(ListNode* header) { 
	if (header->next == NULL) return;
	ListNode* p;
	p = header;
	do {
		p = p->next;
		printf(" %d %d", p->coef, p->exp);
	} while (p->next != NULL);
} // 해당 연결리스트의 노드 갯수에 맞게 출력해줍니다.

void freeNode(ListNode* header) {
	ListNode *p, *temp;
	for (p = header; p != NULL;) {
		temp = p->next;
		free(p);
		p = temp;
	}
} // 해당 연결리스트의 모든 노드들을 메모리 해제시켜줍니다.

int main() {
	ListNode *header1, *header2, *header3, *p1, *p2, *p3;
	int N1, N2, i, coef, exp;
	header1 = getnode();
	header2 = getnode();
	header3 = getnode();
	p1 = header1; // 첫번째 연결리스트에 대한 헤더 설정입니다.
	p2 = header2; // 두번째 연결리스트에 대한 헤더 설정입니다.
	p3 = header3; // 결과값을 저장하는 연결리스트에 대한 헤더 설정입니다
	scanf("%d", &N1);
	for (i = 0; i < N1; i++) {
		scanf("%d", &coef);
		scanf("%d", &exp);
		p1 = appendTerm(p1, coef, exp);
		p1 = p1->next;
	}// 첫번째 연결리스트에 방정식을 입력입니다.
	scanf("%d", &N2);
	for (i = 0; i < N2; i++) {
		scanf("%d", &coef);
		scanf("%d", &exp);
		p2 = appendTerm(p2, coef, exp);
		p2 = p2->next;
	} // 두번째 연결리스트에 방정식을 입력입니다.
	header3 = addPoly(header1, header2); // 함수 계산 후 header3에 넣어줍니다.
	printNode(header3); // 출력함수입니다.

	// 아래 코드는 메모리 해제 함수입니다.
	freeNode(p1);
	freeNode(p2);
	freeNode(p3);
	return 0;
}
