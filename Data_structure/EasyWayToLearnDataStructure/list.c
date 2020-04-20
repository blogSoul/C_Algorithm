#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element; // 항목의 정의
typedef struct {
	element array[MAX_LIST_SIZE]; // 배열 정의
	int size; // 현재 리스트에 들어있는 항목들의 수
}ArrayListType;

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
} // 오류 처리 함수

void init(ArrayListType *L) {
	L->size = 0;
} // 리스트 초기화 함수

int is_empty(ArrayListType *L) {
	return L->size == 0;
} // 리스트가 비어 있으면 1을 반환, 아니면 0을 반환

int is_full(ArrayListType *L) {
	return L->size == MAX_LIST_SIZE;
} // 리스트에 가득 차있으면 1을 반환, 아니면 0을 반환

element get_entry(ArrayListType *L, int pos) {
	if (pos < 0 || pos > MAX_LIST_SIZE) {
		error("위치에 오류가 있습니다.");
	}	
	return L->array[pos];
} // 순회 함수입니다.

void print_list(ArrayListType *L) {
	int i;
	for (i = 0; i < L->size - 1; i++) {
		printf("%d->", L->array[i]);
	}
	if (L->size > 0) {
		printf("%d", L->array[L->size - 1]);
	}
	printf("\n");
} // 출력 함수입니다.

void insert_last(ArrayListType *L, element item) {
	if (L->size >= MAX_LIST_SIZE) {
		error("List overflow");
	}
	L->array[L->size++] = item;
} // 삽입함수입니다.

void insert(ArrayListType *L, int pos, element item) {
	for (int i = (L->size - 1); i >= pos; i--) {
		L->array[i + 1] = L->array[i];
	}
	L->array[pos] = item;
	L->size++;
} // pos에 맞게 삽입해주는 함수입니다.

element delete(ArrayListType *L, int pos) {
	element item;
	if (pos < 0 || pos >= L->size) {
		error("Location Error");
	}
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++) {
		L->array[i] = L->array[i + 1];
	}
	L->size--;
	return item;
} // pos에 맞게 삭제해주는 함수입니다.

void clear(ArrayListType *L) {
	for (int i = L->size - 1; i >= 0; i--) {
		delete(L, i);
	}
}

void replace(ArrayListType *L, int pos, element item) {
	L->array[pos] = item;
}

int get_length(ArrayListType *L) {
	return L->size;
}

int main() {
	ArrayListType List;

	init(&List);
	insert(&List, 0, 10);
	insert_last(&List, 20);
	print_list(&List);
	printf("%d\n", get_length(&List));
	replace(&List, 1, 30);
	print_list(&List);
	clear(&List);
	print_list(&List);
	printf("%d\n", get_length(&List));
	return 0;
}
