#include <stdio.h>
#include <stdlib.h>

typedef int element; // 항목의 정의
typedef struct {
	element Array[100]; // 배열 정의
	int size; // 현재 리스트에 들어있는 항목들의 수
}ArrayListType;

int main() {
	int a;
	scanf("%d", &a);
	return 0;
}
