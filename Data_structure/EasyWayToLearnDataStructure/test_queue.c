#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue {
	char id[100]; // ID 저장공간
	int piority[100]; // 우선순위 저장공간
	int front;
	int rear;
} queue; // 구조체 선언

queue *getQueue(){
	queue* p = (queue*)malloc(sizeof(queue));
	p->front = 0;
	p->rear = 0;
	return p;
} // 큐 할당

void enqueue(queue *p, char word, int num) {
	if (p->front == (p->rear + 1) % 100) {
		// printf("fullError");
		return;
	}// fullError 확인
	p->rear = (p->rear + 1) % 100;
	p->id[p->rear] = word;
	p->piority[p->rear] = num;
} // 큐 enqueue 함수

void dequeue(queue *p) {
	if (p->front == p->rear) {
		// printf("emptyError");
		return;
	}// emptyError 확인
	p->front = (p->front + 1) % 100;
	if (p->piority[p->front] != 0) {
		enqueue(p, p->id[p->front], p->piority[p->front] - 1);
	} else {
		printf("%c ", p->id[p->front]);
		p->piority[p->front] = 0;
	}
	p->id[p->front] = '\0';
}// 큐 dequeue 함수

void printQueue(queue *p) {
	if (p->front == p->rear) {
		// printf("emptyError");
		return;
	}// emptyError 확인
	while (p->front != p->rear) {
		dequeue(p);
	}
	return;
}// 큐 출력함수

int main() {
	int N, i, num;
	char word;
	queue *p;
	p = getQueue();
	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++) {
		scanf("%c %d", &word, &num);
		getchar();
		enqueue(p, word, num);
	}
	printQueue(p);
	return 0;
}

/*
예시 : 
8
A 10
B 0
C 4
D 5
E 0
F 0
G 2
H 10
*/
