#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;

void inset_node(ListNode **phead, ListNode *p, ListNode *new_node) {
	// phead : 리스트의 헤드 포인터의 포인터 
	// p : 선행 노드
	// new_node : 삽입될 노드
	if (*phead == NULL) {// 공백 리스트
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) {// p가 NULL이면 첫번째 노드로 삽입
		new_node->link = *phead;
		*phead = new_node;
	}
	else {// p 다음에 삽입
		new_node->link = p->link;
		p->link = new_node;
	}
}

void remove_node(ListNode **phead, ListNode *p, ListNode *removed) {
	// phead : 리스트의 헤드 포인터의 포인터 
	// p : 선행 노드
	// new_node : 삽입될 노드
	if (p == NULL) {
		*phead = (*phead)->link;
	}
	else {
		p->link = removed->link;
	}
	free(removed);
}

int main() {
	// 데이터 구조의 기본재료 : 배열, 연결리스트

	// 배열 : 
	// 배열첨자(array index) : 시작: 0 또는 LB(lower bound)
	//                       : 끝: N-1 또는 UB(upper bound)
	// 배열표시(array denotation) : V[LB..UB]
	// V[LB..UB]의 base로부터 V[k]의 offset = k -LB
	// 다차원 배열 :
	// 배열표시 : LB = 0이면, V[N1xN2...xNn]
	//            일반적으로, V[LB1..UB1, LB2..UB2, ... , LBn..UBn]

	// 메모리 할당 : 행우선 순서(또는 저차원우선 순서)

	// 연결 리스트 : 순차 표현 : 배열을 이용한 리스트 표현
	//               연결된 표현 : 연결 리스트를 사용한 리스트 표현, 
	//                            하나의 노드가 데이터와 링크로 구성되어 있고 링크가 노드들을 연결한다.
	// 노드 = 데이터 필드 + 링크 필드
	// 헤드 포인터 : 리스트의 첫번째 노드를 가리키는 변수
	// 노드(node) : 한개의 데이터 원소를 저장하기 위해 동적 메모리에 할당된 메모리
	// 노드 저장 내용 : 1. 원소(element): 데이터원소
	//                  2. 링크(link): 다음 노드의 주소 - 다음 노드가 없는 경우 NULL을 저장
	
	ListNode *p1;
	p1 = (ListNode *)malloc(sizeof(ListNode));
	p1->data = 10;
	p1->link = NULL;

	ListNode *p2;
	p2 = (ListNode*)malloc(sizeof(ListNode));
	p2->data = 20;
	p2->link = NULL;
	p1->link = p2;

	// 이중연결리스트 : 추가링크를 사용하여 역방향 순회도 가능
	// 해더(header)노드와 트레일러(trailer)노드를 사용하는 이유는 구현의 편의성이다.
	// 해더(header)노드와 트레일러(trailer)노드는 dummy element이다.
	return 0;
}
