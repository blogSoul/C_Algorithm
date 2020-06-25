#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue {
	char id[100]; // ID �������
	int piority[100]; // �켱���� �������
	int front;
	int rear;
} queue; // ����ü ����

queue *getQueue(){
	queue* p = (queue*)malloc(sizeof(queue));
	p->front = 0;
	p->rear = 0;
	return p;
} // ť �Ҵ�

void enqueue(queue *p, char word, int num) {
	if (p->front == (p->rear + 1) % 100) {
		// printf("fullError");
		return;
	}// fullError Ȯ��
	p->rear = (p->rear + 1) % 100;
	p->id[p->rear] = word;
	p->piority[p->rear] = num;
} // ť enqueue �Լ�

void dequeue(queue *p) {
	if (p->front == p->rear) {
		// printf("emptyError");
		return;
	}// emptyError Ȯ��
	p->front = (p->front + 1) % 100;
	if (p->piority[p->front] != 0) {
		enqueue(p, p->id[p->front], p->piority[p->front] - 1);
	} else {
		printf("%c ", p->id[p->front]);
		p->piority[p->front] = 0;
	}
	p->id[p->front] = '\0';
}// ť dequeue �Լ�

void printQueue(queue *p) {
	if (p->front == p->rear) {
		// printf("emptyError");
		return;
	}// emptyError Ȯ��
	while (p->front != p->rear) {
		dequeue(p);
	}
	return;
}// ť ����Լ�

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
���� : 
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
