#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
	int front; // front 원소 위치 변수
	int rear; // rear 원소 위치 변수
	int *arr; // 배열을 담은 포인터 변수
	int size; // queue의 크기를 나타내주는 변수 (공백 포함)
}queue;

queue* init(int N) {
	queue* p;
	int *q;
	p = (queue*)malloc(sizeof(queue));
	q = (int*)calloc(N, sizeof(int));
	p->arr = q;
	p->front = 0;
	p->rear = 0;
	p->size = N;
	return p;
} // 큐를 초기화해주는 함수입니다.

void print(queue *p) {
	int i, j;
	for (i = 0; i < p->size; i++) {
		printf(" %d", p->arr[i]);
	}
	printf("\n");
} // 큐를 출력해주는 함수입니다.

int add(queue *p, int num) {
	if (p->front == (p->rear + 1) % p->size && p->arr[p->front] == NULL) {
		printf("overflow");
		print(p);
		return 1; // overflow Error 발생
	}
	p->rear = (p->rear + 1) % p->size;
	p->arr[p->rear] = num;
	return 0;
} // 큐에 원소 추가해주는 함수입니다.

int delete(queue *p) {
	if (p->front == p->rear % p->size && p->arr[p->front] == NULL) {
		printf("underflow");
		return 1; // underflow Error 발생
	}
	p->front = (p->front + 1) % p->size;
	p->arr[p->front] = 0;
	return 0;
} // 큐에 원소 삭제해주는 함수입니다.

int main() {
	int q, N, i, num, checkError = 0; // 오류가 없음을 의미합니다.;
	char order;
	queue *p;
	scanf("%d", &q);
	scanf("%d", &N);
	getchar();
	p = init(q); // 초기화
	for (i = 0; i < N; i++) {
		scanf("%c", &order);
		getchar();
		if (order == 'I') {
			scanf("%d", &num);
			getchar();
			// printf("%d %d %c %d\n", q, N, order, num);
			checkError = add(p, num);
		}
		else if (order == 'D') {
			// printf("%d %d %c\n", q, N, order);
			checkError = delete(p);
		}
		else if (order == 'P') {
			// printf("%d %d %c\n", q, N, order);
			print(p);
		}
		else {
			printf("order type Error\n");
		}
		if (checkError == 1)
			break; // 오류 발생으로 종료
	}
	free(p); // 메모리 해제
	return 0;
}
