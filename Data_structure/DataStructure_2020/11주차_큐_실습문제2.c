#include <stdio.h>
#include <stdlib.h>

typedef struct queueNode {
	int element;
	struct queueNode *prev;
	struct queueNode *next;
}queueNode; // 구조체 선언

queueNode* getNode() {
	queueNode* p = (queueNode*)malloc(sizeof(queueNode));
	p->element = 0;
	p->next = NULL;
	p->prev = NULL;
	return p;
} // 큐 노드를 초기화합니다.

void init(queueNode* front, queueNode* rear) {
	front = NULL;
	rear = NULL;
} // 큐 구조를 처음 상태로 초기화해줍니다.

void add_front(queueNode *front, queueNode *rear, int num) {
	queueNode *p, *q;
	p = getNode();
	p->element = num;
	if (front->next == NULL) {
		front->next = p;
		rear->next = p;
		// printf("DONE %d\n", front->element);
	}
	else {
		q = front->next;
		front->next = p;
		p->next = q;
		q->prev = p;
	}
} // 큐 구조에서 add_front하는 함수입니다.

void add_rear(queueNode *front, queueNode *rear, int num) {
	queueNode *p, *q;
	p = getNode();
	p->element = num;
	if (rear->next == NULL) {
		front->next = p;
		rear->next = p;
		// printf("DONE %d\n", front->element);
	}
	else {
		q = rear->next;
		q->next = p;
		p->prev = q;
		rear->next = p;
	}
} // 큐 구조에서 add_rear하는 함수입니다.

void delete_front(queueNode *front, queueNode *rear) {
	queueNode *p;
	if (front->next == NULL) {
		printf("underflow");
		exit(0); // underflow로 인한 정상적인 종료
	}
	p = front->next;
	if (front->next == rear->next) {
		front->next = NULL;
		rear->next = NULL;
		free(p);
	}
	else {
		p->next->prev = NULL;
		front->next = p->next;
		free(p);
	}
} // 큐 구조에서 delete_front하는 함수입니다.

void delete_rear(queueNode *front, queueNode *rear) {
	queueNode *p;
	if (rear->next == NULL) {
		printf("underflow");
		exit(0); // underflow로 인한 정상적인 종료
	}
	p = rear->next;
	if (front->next == rear->next) {
		front->next = NULL;
		rear->next = NULL;
		free(p);
	}
	else {
		p->prev->next = NULL;
		rear->next = p->prev;
		free(p);
	}
} // 큐 구조에서 delete_rear하는 함수입니다.

void print(queueNode *front, queueNode *rear) {
	queueNode *p;
	if (front->next == NULL) {
		printf("empty queue\n");
		return;
	}
	for (p = front->next; p != NULL; p = p->next) {
		printf(" %d", p->element);
	}
	printf("\n");
} // 큐 구조 안에 있는 노드들을 출력해줍니다.

int main() {
	int N, i, num;
	char order[3];
	queueNode *front, *rear;
	front = getNode();
	rear = getNode();
	init(front, rear);
	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++) {
		scanf("%s", order);
		getchar();
		if (strcmp(order, "AF") == 0) {
			scanf("%d", &num);
			// printf("%d %s %d\n", N, order, num);
			add_front(front, rear, num);
		}
		else if (strcmp(order, "AR") == 0) {
			scanf("%d", &num);
			// printf("%d %s %d\n", N, order, num);
			add_rear(front, rear, num);
		}
		else if (strcmp(order, "DF") == 0) {
			// printf("%d %s\n", N, order);
			delete_front(front, rear);
		}
		else if (strcmp(order, "DR") == 0) {
			// printf("%d %s\n", N, order);
			delete_rear(front, rear);
		}
		if (strcmp(order, "P") == 0) {
			// printf("%d %s\n", N, order);
			print(front, rear);
		}
	}
	return 0;
}
