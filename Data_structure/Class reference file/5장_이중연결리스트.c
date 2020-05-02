#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
	char studentName[20]; // 학생 이름
	char className[20];  // 과목명
	int score; // 점수
	struct ListNode *prev;
	struct ListNode *next;
} ListNode; // 문제에 맞는 구조체 할당

ListNode* getNode() {
	ListNode* Node = (ListNode*)malloc(sizeof(ListNode));
	Node->prev = Node;
	Node->next = Node;
	return Node;
} // 노드를 초기화해주는 함수입니다.

void init(ListNode* header, ListNode* trailer) {
	header->next = trailer;
	trailer->prev = header;
} // 초기화 상태를 만들어주는 함수입니다.

void addFirst(ListNode* header,char studentName[20], char className[20], int score) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->score = score;
	strcpy(node->studentName, studentName);
	strcpy(node->className, className);
	node->next = header->next;
	node->prev = header;
	header->next->prev = node;
	header->next = node;
} // 첫번째 순서에 노드를 추가하는 함수입니다.

void addLast(char studentName[20], char className[20], int score, ListNode* trailer) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->score = score;
	strcpy(node->studentName, studentName);
	strcpy(node->className, className);
	node->next = trailer;
	node->prev = trailer->prev;
	trailer->prev->next = node;
	trailer->prev = node;
} // 마지막 순서에 노드를 추가하는 함수입니다.

void updateNode(ListNode* node, int updateScore) {
	ListNode* p = node;
	node->score = updateScore;
} // 해당 노드에 점수를 업데이트해주는 함수입니다.

void printList(ListNode* header, ListNode* trailer) {
	ListNode* p;
	int count = 0;
	p = header;
	if (p->next == trailer) {
		printf("NONE");
		return;
	}
	while (p->next != trailer) {
		p = p->next;
		count++;
		printf("%s %s %d\n", p->studentName, p->className, p->score);
	}
	printf("%d\n", count);
} // 이중연결리스트의 원소 갯수와 노드 정보 출력함수입니다.

int count = 0; // 60점 밑에 있는 학생 수를 저장합니다.
void countNode2(ListNode* header, ListNode* trailer) {
	ListNode* p;
	p = trailer->prev;
	if (p == header) {
		printf("%d\n", count);
		return;
	}
	else {
		if (p->score <= 60) {
			printf("%s %s %d\n", p->studentName, p->className, p->score);
			count++;
		}
		countNode2(header, p);
	}
} // 점수가 60점 밑에 있는 학생수를 찾습니다.

ListNode* get(ListNode* header, ListNode* trailer, char studentName[20], char className[20]) {
	ListNode *p = header;
	do {
		p = p->next;
		if (strcmp(p->className, className) == 0 && strcmp(p->studentName, studentName) == 0) {
			return p;
		}
	} while (p != trailer);
	return p; // 없을 시 trailer를 받는다.
} // 입력 받은 데이터와 같은 데이터를 가진 노드를 찾는 함수입니다. 

void removeNode(ListNode* header, ListNode* removed, ListNode* trailer) {
	ListNode *p = removed;
	if (p == header || p == trailer) return;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
} // 지우고 싶은 노드를 삭제해줍니다.

void swap(ListNode* p, ListNode* q, ListNode* header, ListNode* trailer) {
	if (p == header || p == trailer) return;
	if (q == header || q == trailer) return; // 예외사항 설정
	p->prev->next = p->next;
	p->next->prev = p->prev;
	p->next = q->next;
	p->prev = q;
	q->next->prev = p;
	q->next = p;
} // 이웃해 있는 두 노드의 순서를 바꿔줍니다.

void ListDescending(ListNode* header, ListNode* p ,ListNode* trailer, int length) {
	for (int i = 0; i < length; i++) {
		if (p->score < p->next->score) {
			swap(p, p->next, header, trailer);
		}
	}
} // 이중연결리스트를 내림차순으로 sort해주는 함수입니다.

ListNode* EXTRACT(ListNode* header, ListNode* trailer, char* subj) {
	ListNode *p, *q, *ExtractNode; // 추출한 리스트를 만들 포인터입니다.
	ListNode* head, *tail;
	int i, count = 0;
	head = getNode();
	tail = getNode();
	init(head, tail); // 새로운 이중연결리스트를 만들어줍니다.
	p = header;
	q = head;
	while (p->next != trailer) {
		p = p->next;
		if (strcmp(p->className, subj) == 0) {
			addFirst(head, p->studentName, p->className, p->score);
			count++;
			ListDescending(head, head->next, tail, count);
		} // 새로운 이중연결리스트에 해당 과목에 맞는 노드를 추가한 후, 내림차순으로 정리해줍니다.
	} 
	p = head->next;
	p->prev = p;
	free(head); // 해더 노드 삭제
	q = tail->prev;
	q->next = q;
	free(tail); // 테일 노드 삭제
	ExtractNode = p;
	return ExtractNode;
} // 과목에 맞는 헤더, 트레일러가 없는 리스트를 만든 후 리스트를 반환해줍니다.

void printEXTRACTList(ListNode* ExtractNode) {
	ListNode *p;
	int Max = 0;
	double sum = 0, count = 0;
	p = ExtractNode;
	if (ExtractNode == NULL) {
		printf("NONE");
		printf("0\n");
		return;
	} // 노드가 없는 경우 예외처리를 해줍니다.
	do {
		printf("%s %s %d\n", p->studentName, p->className, p->score);
		sum += p->score;
		count++;
		p = p->next;
	} while (p->next != p);
	printf("%s %s %d\n", p->studentName, p->className, p->score);
	sum += p->score;
	count++;
	printf("%.f\n", sum / count); // 평균을 구합니다.
} // 트레일러가 없는 리스트를 출력해주는 함수입니다.

void freeNode(ListNode* header, ListNode *trailer) {
	ListNode *tmp, *p;
	for (p = header; p->next != trailer;) {
		tmp = p->next;
		free(p);
		p = tmp;
	}
	free(trailer);
} // 이중연결리스트에서 메모리를 해제합니다.

void freeExtractNode(ListNode* ExtractNode) {
	ListNode *tmp, *p;
	for (p = ExtractNode; p->next != p;) {
		tmp = p->next;
		free(p);
		p = tmp;
	}
	free(p);
} // 헤더노트와 테일 노드가 없는 이중연결리스트에서 메모리를 해제합니다.

int main() {
	int score, i;
	char studentName[20], className[20], findclassName[20];
	ListNode *H, *T, *temp, *ExtractNode;
	H = getNode();
	T = getNode();
	init(H, T);
	while (1) {
		scanf("%s", &studentName);
		getchar();
		if (strcmp(studentName, "XXX") == 0 || strcmp(studentName, "\n") == 0) {
			break; // 학생 이름이 XXX인 경우나 바로 Enter를 해줄 경우 break해줍니다.
		}
		scanf("%s", &className);
		getchar();
		scanf("%d", &score);
		getchar();
		temp = get(H, T, studentName, className); // 중복 노드가 있는지 찾습니다.
		if (score == 0) {
			removeNode(H, temp, T); // 점수가 0이면 해당 노드를 지워줍니다.
		}
		else if (temp != T) {
			updateNode(temp, score); // 만약 같은 이름, 같은 과목인 노드가 존재하면 업데이트를 해줍니다.
		}
		else {
			addLast(studentName, className, score, T); // 없을시 노드를 추가해줍니다.
		}
	}
	scanf("%s", &findclassName);
	ExtractNode = EXTRACT(H, T, findclassName);
	printEXTRACTList(ExtractNode);
	freeNode(H, T);  // 메모리를 해제합니다.
	freeExtractNode(ExtractNode);  // 메모리를 해제합니다.
	return 0;
}
