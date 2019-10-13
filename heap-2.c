#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_ELEMENT 100

typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;


HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i = i / 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key) {
			child++;
		}
		if (temp.key >= h->heap[child].key) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void Print_heap(HeapType* h) {
	int i;
	for (i = 0; i < h->heap_size; i = i + 1) {
		printf(" %d", h->heap[i]);
	}
}

int main(void) {
	HeapType* heap;
	element e1;
	
	char a,c;
	int b;

	heap = create();
	init(heap);

	while (1) {
		scanf("%c %d", &a, &b);
		element e1 = { b };
		element e2;
		printf("%d\n", e1.key);
		if (a == 'i') {
			insert_max_heap(heap, e1);
			printf("0\n");
			e1.key = 0;
		}
		else if (a == 'd') {
			e2 = delete_max_heap(heap);
			printf("%d\n", e2.key);
			e2.key = 0;
		}
		else if (a == 'p') {
			Print_heap(heap);
		}
		else if (a == 'q') {
			break;
		}
		
	}

	free(heap);
	return 0;
}
