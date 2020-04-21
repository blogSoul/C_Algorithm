#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct ListNode {
	element elem;
	struct ListNode *prev;
	struct ListNode *next;
} ListNode; // 노드 구조를 설정합니다.

ListNode* getnode() {
	ListNode* phead = (ListNode*)malloc(sizeof(ListNode));
	phead->elem = 0;
	phead->next = phead;
	phead->prev = phead;
	return phead;
} // 이중연결리스트 노드로 할당합니다.

void init(ListNode *header, ListNode *trailer) {
	header->next = trailer;
	trailer->prev = header;
} // 이중연결리스트로 초기화합니다.

void add(ListNode* header, int r, char e) {
	ListNode *p, *newnode;
	newnode = getnode();
	p = header;
	for (int i = 0; i < r; i++) {
		p = p->next;
	}
	newnode->elem = e;
	newnode->next = p;
	newnode->prev = p->prev;
	p->prev->next = newnode;
	p->prev = newnode;
} // 이중연결리스트에서 r번째에 e를 추가합니다.

void delete(ListNode* header, int r) {
	ListNode *p;
	p = header;
	for (int i = 0; i < r; i++) {
		p = p->next;
	}
	if (r < 1 || p->elem == 0) {
		printf("invalid position\n");
		return;
	}
	p->prev->next = p->next;
	p->next->prev = p->prev;
} // 이중연결리스트에서 r번째를 삭제합니다.

element get(ListNode* header, int r) {
	ListNode *p = header->next;
	for (int i = 1; i < r; i++) {
		p = p->next;
	}
	if (r < 1 || p->elem == 0) {
		printf("invalid position\n");
	}
	return p->elem;
} // 이중연결리스트에서 r번째에 원소를 반환합니다.

void print(ListNode* header) {
	ListNode *p;
	if (header->next->elem == 0) {
		printf("invalid position\n");
		return;
	}
	for (p = header->next; p->elem != 0; p = p->next) {
		printf("%c", p->elem);
	}
}// 이중연결리스트의 원소들을 출력합니다.

void freeNode(ListNode* header, ListNode *trailer) {
	ListNode *tmp, *p;
	for (p = header; p->next != trailer;) {
		tmp = p->next;
		free(p);
		p = tmp;
	}
	free(trailer);
} // 이중연결리스트에서 메모리를 해제합니다.

int main() {
	int num, N;
	char order, word, result;
	ListNode *header, *trailer;
	header = getnode();
	trailer = getnode();
	init(header, trailer);
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		order = getchar();
		if (order == 'A') {
			scanf("%d", &num);
			getchar();
			scanf("%c", &word);
			getchar();
			add(header, num, word); // 원소 추가 함수입니다.
		}
		else if (order == 'D') {
			scanf("%d", &num);
			getchar();
			delete(header, num); // 원소 삭제 함수입니다.
		}
		else if (order == 'G') {
			scanf("%d", &num);
			getchar();
			result = get(header, num);// 원소 반환 함수입니다.
			if (result != 0)
				printf("%c\n", result);
		}
		else if (order == 'P') {
			print(header); // 원소 출력 함수입니다.
			printf("\n");
			getchar();
		}
		else {
			printf("invalid command\n");
			break;
		}
	}
	freeNode(header, trailer); // 메모리를 해제합니다.
	return 0;
}
