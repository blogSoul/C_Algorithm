#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key;
}element;

typedef struct HeapType {
	element heap[100];
	int heap_size;
}HeapType;

void insertHeap(HeapType * h, element item){
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i = i / 2;
	}
	h->heap[i] = item;
}

void printHeap(HeapType * h) {
	int i;
	for (i = 1; i <= h->heap_size; i = i + 1) {
		printf(" %d", h->heap[i]);
	}
}

int main() {
	HeapType* heap;
	heap = (HeapType *)malloc(sizeof(HeapType));
	heap->heap_size = 0;

	element e[100];
	int N, b;
	int i = 0;
	scanf("%d", &N);
	while (1) {
		i = i + 1;
		scanf(" %d", &b);
		e[i].key = b;
		insertHeap(heap, e[i]);

		if (i == N) {
			break;
		}
	}
	
	printHeap(heap);
	return 0;
}
