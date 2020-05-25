#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int N; // 스택의 크기
	int top; // 현재 마지막 원소의 위치
	char word[100]; // 원소가 담길 연결리스트
	int word_priority[100]; // 원소의 우선순위가 담길 연결리스트
} stack; // 구조체 선언

stack* init(int N) {
	stack* p = (stack*)malloc(sizeof(stack));
	p->N = N;
	p->top = -1;
	return p;
} // stack을 초기화해주는 함수입니다.

void push(stack* p, char word) {
	if (p->top == p->N - 1) {
		printf("Stack FULL\n");
		return;
	}
	p->top++;
	p->word[p->top] = word;
	if (word == '!') {
		p->word_priority[p->top] = 6;
	}
	else if (word == '*' || word == '/') {
		p->word_priority[p->top] = 5;
	}
	else if (word == '+' || word == '-') {
		p->word_priority[p->top] = 4;
	}
	else if (word == '>' || word == '<') {
		p->word_priority[p->top] = 3;
	}
	else if (word == '&') {
		p->word_priority[p->top] = 2;
	}
	else if (word == '|') {
		p->word_priority[p->top] = 1;
	}
	else if (word == '(') {
		p->word_priority[p->top] = 0;
	}
} // stack에서 push를 해주는 함수입니다.

void pop(stack* p) {
	if (p->top == -1) {
		// printf("Stack Empty\n");
		return;
	}
	printf("%c", p->word[p->top]);
	p->word[p->top] = "\0";
	p->word_priority[p->top] = -1;
	p->top--;
} // stack에서 pop를 해주는 함수입니다.

void print(stack* p) {
	if (p->top == -1) {
		// printf("Stack Empty\n");
		return;
	}
	for (int i = p->top; i > -1; i--) {
		printf("%c", p->word[i]);
	}
	printf("\n");
	return;
} // stack에서 print를 해주는 함수입니다.

void freeStack(stack* p) {
	free(p->word);
	free(p->word_priority);
	free(p);
	return;
} // stack을 초기화해주는 함수입니다.

void printPostfixformula(char* word) {
	int i, N = strlen(word);
	int checkUnary = 1; // 단항 연산자인지 확인하는 부분입니다. 1이면 단항 연산자이고 0이면 아닙니다.
	stack* p;
	p = init(N); // 스택 초기화 및 선언
	for (i = 0; i < N; i++) {
		if (word[i] == '(') {
			push(p, word[i]);
			checkUnary = 1; // 단항 연산자가 가능해집니다.
		}
		else if (word[i] == ')') {
			while (p->top != -1) {
				if (p->word[p->top] != '(') {
					pop(p);
				}
				else {
					p->word[p->top] = "\0";
					p->word_priority[p->top] = 0;
					p->top--;
					// 스택에서 '(' 인 부분을 만나면 출력하지 않고 지워줍니다.
					break; 
				}
			}
		}
		else if (word[i] == '!') { // 단항 연산자 부분입니다.
			while (p->top != -1) {
				if (p->word_priority[p->top] >= 6) {
					pop(p);
				}
				else {
					break;
				}
			}
			push(p, word[i]);
		}
		else if (word[i] == '*' || word[i] == '/') {
			while (p->top != -1) {
				if (p->word_priority[p->top] >= 5) {
					pop(p);
				}
				else {
					break;
				}
			}
			push(p, word[i]);
			checkUnary = 1; // 단항 연산자가 가능해집니다.
		}
		else if (word[i] == '+' || word[i] == '-') {
			if (checkUnary == 1) {
				// 단항 연산자 부분입니다.
				// 수식에서 +,- 단항연산자가 나올 수 있는 경우는 첫 글자나 괄호 다음 첫 글자일 때입니다.
				while (p->top != -1) {
					if (p->word_priority[p->top] >= 6) {
						pop(p);
					}
					else {
						break;
					}
				}
				p->top++;
				p->word[p->top] = word[i];
				p->word_priority[p->top] = 6;
				continue;
			}
			while (p->top != -1) {
				if (p->word_priority[p->top] >= 4) {
					pop(p);
				}
				else {
					break;
				}
			}
			push(p, word[i]);
			checkUnary = 1; // 단항 연산자가 가능해집니다.
		}
		else if (word[i] == '>' || word[i] == '<') {
			while (p->top != -1) {
				if (p->word_priority[p->top] >= 3) {
					pop(p);
				}
				else {
					break;
				}
			}
			push(p, word[i]);
			checkUnary = 1; // 단항 연산자가 가능해집니다.
		}
		else if (word[i] == '&' && word[i + 1] == '&') {
			while (p->top != -1) {
				if (p->word_priority[p->top] >= 2) {
					pop(p);
				}
				else {
					break;
				}
			}
			push(p, word[i]);
			push(p, word[i + 1]);
			i++;
			checkUnary = 1; // 단항 연산자가 가능해집니다.
		}
		else if (word[i] == '|' && word[i + 1] == '|') {
			while (p->top != -1) {
				if (p->word_priority[p->top] >= 1) {
					pop(p);
				}
				else {
					break;
				}
			}
			push(p, word[i]);
			push(p, word[i+ 1]);
			i++;
			checkUnary = 1; // 단항 연산자가 가능해집니다.
		}
		else {
			printf("%c", word[i]);
			checkUnary = 0;
		}
	}
	print(p);
} // 중위수식을 후위수식으로 출력해주는 함수입니다.

int main() {
	int N, i;
	char word[100] = "\0";
	scanf("%d", &N);
	getchar();
	for (i = 0; i < N; i++) {
		scanf("%s", word);
		getchar();
		// printf("*%d번째 문자열 : %d , %s\n", i, strlen(word), word);
		printPostfixformula(word);
	}
	return 0;
}
