#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <math.h>

int H[100]; // 배열 안에서 구현할 예정입니다.
int n; // 힙의 크기

void upHeap(int i) {
	int a, b;
	while (true) {
		a = int(floor(i / 2));
		if (H[i] > H[a]) {
			b = H[a];
			H[a] = H[i];
			H[i] = b;
			i = a;
		}
		else {
			break;
		}
	}
}

void downHeap(int i) {
	int a, b;
	while (true) {
		a = int(floor(i / 2));
		if (H[i] < H[a] && i != 1) {
			b = H[a];
			H[a] = H[i];
			H[i] = b;
			i = a;
		}
		else {
			break;
		}
	}
}

void insertItem(int key) {
	n = n + 1;
	H[n] = key;
	upHeap(n);
}

int removeMax(void) {
	int a;
	a = H[1];
	H[1] = H[n];
	n = n - 1;
	downHeap(1);
	return a;
}


void printHeap(void) {
	int i;
	for (i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}
}

int main(void) {
	char order;
	int num;
	
	while (true) {
		scanf("%c %d", &order, &num);
		if (order == 'i') {
			insertItem(num);
			printf("0\n");
		}
		if (order == 'd') {
			printf("%d\n", removeMax());
		}
		if (order == 'p') {
			printHeap();
			printf("\n");
		}
		if (order == 'q') {
			break;
		}
	}
	return 0;
}
