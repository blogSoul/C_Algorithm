#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
	int value;
	char name[20];
	int grade;
	struct NODE *next;
}NODE;
// 노드를 정의합니다.

NODE *insertnode(NODE *head, int grade, char name[]) {
	NODE *ptr = (NODE*)malloc(sizeof(NODE));
	ptr->grade = grade;
	strcpy(ptr->name, name);
	ptr->next = head;
	head = ptr;
	return ptr;
}
// 노드를 추가하는 함수를 만듭니다.

int main() {
	int grade, i;
	char name[21]; // 20자리 문자열까지 가능합니다.
	NODE *head = NULL;
	NODE *tmp; // 메모리 해제를 위한 변수입니다.
	while (true) {
		gets_s(name);
		scanf("%d", &grade);
		// 이름을 입력하고 엔터를 누른후 점수를 입력하고 엔터를 눌러줘야 합니다.
		if (strcmp(name, "0") == 0) {
			break;
		}
		head = insertnode(head, grade, name);
		getchar();
	}

	while (head != NULL) {
		printf("이름: %s  점수: %d\n", head->name, head->grade);
		head = head->next;
	} // 연결리스트에 있는 데이터를 출력합니다.

	tmp = head;
	while (head != NULL) {
		tmp = head->next;
		free(head);
		head = tmp;
	} // 메모리를 해제합니다.

	return 0;
}
