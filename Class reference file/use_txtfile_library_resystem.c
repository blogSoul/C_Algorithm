#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	안녕하세요! 프로그래밍 실습 4시 30분 강의를 듣는 1조 
	학번 : 14010384 과 : 수학과 설민욱이라고 합니다. 
	이번 개인 과제 프로젝트로 "도서관 사서용 책 관리 시스템" 을 제작했습니다.
	 * 주요 기능으로는 
	서비스 번호 1 : 보유한 책 검색 기능
    서비스 번호 2 : 책 번호로 정렬하기
	서비스 번호 3 : 해당 자료에 책 추가하기 
	서비스 번호 4 : 해당 자료에 책 삭제하기 
	총, 4가지 기능을 구현했습니다. 
	4가지 기능 안에 세부적인 조건을 통하여 원하는 결과를 도출할 수 있습니다. 
	강의 자료 외에는 아무 것도 참조하지 않았습니다.
	입출력 예시는 코드 밑에 적어두겠습니다!
	해당 자료 파일은 "PersonalHw_input.txt"이고 해당 자료 구조에 맞게 입력해야 4가지 기능을 사용할 수 있습니다.
	코드 제일 밑 부분에 테스트 파일이 적혀져 있습니다.
*/

typedef struct BookNode {
	int BookNumber; // 도서번호 (4자리까지 가능합니다.)
	char BookName[20]; // 책 이름
	char BookWritter[20]; // 책 저자
	char BookKinds[20]; // 책 종류
}BookNode;

int findDataNumber() {
	int N = 0;
	char name[100];
	BookNode *p = (BookNode*)malloc(sizeof(BookNode));
	FILE *in;
	in = fopen("PersonalHw_input.txt", "r");
	fscanf(in, "%*s %*s"); // 처음 문자열 2개 무시
	while (fscanf(in, "%s", &name) == 1)
		N++;
	fclose(in);
	return N;
} // 자료 파일에 들어 있는 데이터의 갯수를 찾아 줍니다.

void scanData(BookNode *p, int N) {
	FILE *in;
	int num;
	char name[100], *ptr;
	in = fopen("PersonalHw_input.txt", "r");
	fscanf(in, "%*s %*s"); // 처음 문자열 2개 무시
	for (int i = 0; i < N; i++) {
		fscanf(in, "%s", &name);
		ptr = strtok(name, ",");
		p[i].BookNumber = atoi(ptr); // 도서번호 (4자로 이루어져 있습니다)
		ptr = strtok(NULL, ",");
		strcpy(p[i].BookName, ptr); // 책 이름
		ptr = strtok(NULL, ",");
		strcpy(p[i].BookWritter, ptr); // 책 저자
		ptr = strtok(NULL, ",");
		strcpy(p[i].BookKinds, ptr); // 책 종류
	}
	fclose(in);
} // 자료 수에 맞게 도서 데이터를 구조체 배열안으로 입력해줍니다.

void saveData(BookNode *p, int N) {
	FILE *out;
	int num;
	char name[100], *ptr;
	out = fopen("PersonalHw_input.txt", "w");
	fprintf(out, "도서번호,책,저자,종류\n");
	fprintf(out, "--------------------------\n");
	for (int i = 0; i < N; i++)
		fprintf(out,"%d,%s,%s,%s\n", p[i].BookNumber, p[i].BookName, p[i].BookWritter, p[i].BookKinds); 
	// 구조체 배열 안에 있는 정보를 txt파일에 저장합니다.
	fclose(out);
} // 자료 수에 맞게 구조체 배열에 있는 정보를 txt파일에 입력해줍니다.

void searchBook(BookNode *p, int N) {
	int i, j, orderNumber, check = 1;
	char name[20];
	while (1) {
		printf("원하는 검색 정보를 입력해주세요.\n");
		printf("서비스 번호 1 : 보유한 책 전체 검색\n");
		printf("서비스 번호 2 : 해당 도서 번호 검색\n");
		printf("서비스 번호 3 : 해당 도서 종류에 맞게 검색\n");
		printf("서비스 번호 4 : 종료하기\n");
		printf("해당 원하는 서비스를 입력해주세요! 주문 번호 : ");
		scanf("%d", &orderNumber);
		system("cls"); // 콘솔 초기화
		if (orderNumber == 1) {
			printf("보유한 모든 도서에 대한 정보입니다.\n");
			for (i = 0; i < N; i++)
				printf("%d, %s, %s, %s\n", p[i].BookNumber, p[i].BookName, p[i].BookWritter, p[i].BookKinds);
			printf("\n"); // 모든 정보를 출력합니다.
		}
		else if (orderNumber == 2) {
			printf("검색하고 싶은 도서 번호를 입력하세요.\n");
			printf("도서 번호 : ");
			scanf("%d", &j);
			for (i = 0; i < N; i++) {
				if (p[i].BookNumber == j) {
					printf("%d, %s, %s, %s\n", p[i].BookNumber, p[i].BookName, p[i].BookWritter, p[i].BookKinds);
					break;
				}
				else if (i == N - 1) {
					printf("검색하고 싶은 도서 번호가 자료 안에 없습니다.\n"); // 검색한 내용이 없는 경우
				}
			}
			printf("\n");
		}
		else if (orderNumber == 3) {
			printf("검색하고 싶은 도서 종류를 입력하세요.\n");
			printf("도서 종류 : ");
			scanf("%s", &name);
			for (i = 0; i < N; i++) {
				if (strcmp(p[i].BookKinds, name) == 0) {
					printf("%d, %s, %s, %s\n", p[i].BookNumber, p[i].BookName, p[i].BookWritter, p[i].BookKinds);
					check = 0; // 검색 자료가 있다는 것을 확인하는 변수입니다.
				}
			}
			if (check == 1) {
				printf("검색하고 싶은 도서 종류가 자료 안에 없습니다.\n"); // 검색한 내용이 없는 경우
			}
			check = 1; // 검색 자료가 있다는 것을 확인하는 변수 초기화.
			printf("\n");
		}
		else if (orderNumber == 4) {
			printf("해당 서비스를 종료합니다!");
			break;
		}
		else {
			printf("주문번호를 잘못 입력하셨습니다!. 다시 입력하세요.\n"); // valueError가 생긴 경우
			printf("\n"); 
		}
	}
}; // 해당 구조체에서 조건에 맞는 정보를 출력해줍니다.

void swap(BookNode *p, int a, int b, int N) {
	p[N] = p[a];
	p[a] = p[b];
	p[b] = p[N];
} // 해당 구조체의 노드들을 서로 교환해줍니다.

void sort(BookNode *p, int N) {
	int i, j, min;
	for (i = 0; i < N; i++) {
		min = i;
		for (j = i + 1; j < N; j++) {
			if (p[j].BookNumber < p[min].BookNumber)
				min = j;
		}
		swap(p, i, min, N);
	} // 정렬 알고리즘입니다.
}// 해당 구조체 배열을 오름차순으로 정렬해줍니다.

void sortBook(BookNode *p, int N) {
	int orderNumber, i, j, min;
	while (1) {
		printf("정렬을 실행하시겠습니까?\n");
		printf("서비스 번호 1 : 정렬하기\n");
		printf("서비스 번호 2 : 종료하기\n");
		printf("해당 원하는 서비스를 입력해주세요! 주문 번호 : ");
		scanf("%d", &orderNumber);
		system("cls"); // 콘솔 초기화
		if (orderNumber == 1) {
			sort(p, N);// 정렬 알고리즘입니다.
			printf("정렬 서비스 이후 결과물입니다!\n");
			for (i = 0; i < N; i++)
				printf("%d, %s, %s, %s\n", p[i].BookNumber, p[i].BookName, p[i].BookWritter, p[i].BookKinds);
			printf("\n");
		}
		else if (orderNumber == 2) {
			printf("해당 서비스를 종료합니다!\n");
			break;
		}
		else {
			printf("잘못 입력하셨습니다!. 다시 입력하세요.\n"); // valueError가 생긴 경우
			printf("\n");
		}
	}
}; // 해당 구조체에서 정렬 기능을 제공해줍니다.

int addBook(BookNode *p, int N) {
	int orderNumber, i, j, min;
	while (1) {
		printf("책 정보를 추가하시겠습니까?\n");
		printf("서비스 번호 1 : 추가하기\n");
		printf("서비스 번호 2 : 종료하기\n");
		printf("해당 원하는 서비스를 입력해주세요! 주문 번호 : ");
		scanf("%d", &orderNumber);
		system("cls"); // 콘솔 초기화
		if (orderNumber == 1) {
			printf("\n");
			printf("추가하고 싶은 책 정보를 입력하세요.\n");
			printf("도서번호(4자리까지 가능합니다.) : ");
			scanf("%d", &p[N].BookNumber);
			printf("책 이름 : ");
			scanf("%s", &p[N].BookName);
			printf("책 저자 : ");
			scanf("%s", &p[N].BookWritter);
			printf("책 종류 : ");
			scanf("%s", &p[N].BookKinds);
			N++; 
			// 같은 책이 여러 권일 수 있기 때문에, 중복된 책 정보도 추가를 허용합니다.
			printf("추가 서비스 이후 결과물입니다!\n");
			for (i = 0; i < N; i++)
				printf("%d, %s, %s, %s\n", p[i].BookNumber, p[i].BookName, p[i].BookWritter, p[i].BookKinds);
			printf("\n");
		}
		else if (orderNumber == 2) {
			printf("해당 서비스를 종료합니다!\n");
			return N;
		}
		else {
			printf("잘못 입력하셨습니다!. 다시 입력하세요.\n"); // valueError가 생긴 경우
			printf("\n");
		}
	}
}; // 해당 구조체에서 데이터 추가 기능을 제공해줍니다.

int deleteBook(BookNode *p, int N) {
	int orderNumber, i, j, count = 0; 
	// count 변수는 삭제한 노드의 갯수입니다.
	while (1) {
		printf("책 정보를 삭제하시겠습니까?\n");
		printf("서비스 번호 1 : 도서 번호을 입력해서 번호와 일치하는 정보 삭제하기\n");
		printf("서비스 번호 2 : 책 이름을 입력해서 번호와 일치하는 정보 삭제하기\n");
		printf("서비스 번호 3 : 종료하기 (종료하기 선택해야 삭제된 정보가 txt파일에 적용됩니다.)\n");
		printf("해당 원하는 서비스를 입력해주세요! 주문 번호 : ");
		scanf("%d", &orderNumber);
		system("cls"); // 콘솔 초기화
		if (orderNumber == 1) {
			printf("삭제하고 싶은 도서 번호를 입력하세요.\n");
			printf("도서번호(4자리까지 가능합니다.) : ");
			scanf("%d", &p[N].BookNumber);
			for (i = 0; i < N; i++) {
				if (p[i].BookNumber == p[N].BookNumber) {
					count++;
					for (j = i; j < N - 1; j++) {
						p[j] = p[j + 1];
					} // 입력값에 해당되는 노드를 삭제해줍니다.
					i--; // 책 번호가 같은 다른 도서도 같이 삭제해줍니다.
				}
			}
			printf("\n");
			printf("해당 조건에 맞게 삭제 서비스 제공 이후 결과물입니다!\n");
			for (i = 0; i < N - count; i++)
				printf("%d, %s, %s, %s\n", p[i].BookNumber, p[i].BookName, p[i].BookWritter, p[i].BookKinds);
			printf("\n");
		}
		else if (orderNumber == 2) {
			printf("삭제하고 싶은 책 이름을 입력하세요. : ");
			scanf("%s", &p[N].BookName);
			for (i = 0; i < N; i++) {
				if (strcmp(p[i].BookName,p[N].BookName) == 0) {
					count++;
					for (j = i; j < N - 1; j++) {
						p[j] = p[j + 1];
					} // 입력값에 해당되는 노드를 삭제해줍니다.
				}
			}
			printf("\n");
			printf("해당 조건에 맞게 삭제 서비스 제공 이후 결과물입니다!\n");
			for (i = 0; i < N - count; i++)
				printf("%d, %s, %s, %s\n", p[i].BookNumber, p[i].BookName, p[i].BookWritter, p[i].BookKinds);
			printf("\n");
		}
		else if (orderNumber == 3) {
			printf("해당 서비스를 종료합니다!\n");
			printf("삭제한 정보 갯수는 %d입니다.\n", count);
			return N - count;
		}
		else {
			printf("잘못 입력하셨습니다!. 다시 입력하세요.\n"); // valueError가 생긴 경우
			printf("\n");
		}
	}
}; // 해당 구조체에서 데이터 삭제 기능을 제공해줍니다.

int main() {
	int i, N, orderNumber;
	char input_txt[16] = "PersonalHw_input";
	BookNode *p = (BookNode*)malloc(101 * sizeof(BookNode));
	N = findDataNumber(); // 초기 자료에서 자료 갯수를 확인합니다.
	scanData(p, N); // txt 자료를 구조체 배열 안에 입력해줍니다.
	for (i = 0; i < N; i++) {
		// printf("%d, %s, %s, %s\n", p[i].BookNumber, p[i].BookName, p[i].BookWritter, p[i].BookKinds);
	}
	while (1) {
		printf("안녕하세요! 도서관 사서용 책 관리 시스템에 들어오신 것을 환영합니다!\n");
		printf("서비스 번호 1 : 보유한 책 검색 기능\n");
		printf("서비스 번호 2 : 책번호로 정렬하기\n");
		printf("서비스 번호 3 : 해당 자료에 책 추가하기\n");
		printf("서비스 번호 4 : 해당 자료에 책 삭제하기\n");
		printf("서비스 번호 5 : 종료하기\n");
		printf("해당 원하는 서비스를 입력해주세요! 주문 번호 : ");
		scanf("%d", &orderNumber);
		system("cls"); // 콘솔 초기화
		if (orderNumber == 1) {
			searchBook(p, N); // 검색 기능을 제공해주는 함수입니다.
		}
		else if (orderNumber == 2) {
			sortBook(p, N); // 정렬 기능을 제공해주는 함수입니다.
		}
		else if (orderNumber == 3) {
			N = addBook(p, N); // 책 정보를 추가해주는 함수입니다.
		}
		else if (orderNumber == 4) {
			N = deleteBook(p, N); // 책 정보를 삭제해주는 함수입니다.
		}
		else if (orderNumber == 5) {
			printf("해당 서비스를 종료합니다!");
			break;
		}
		else {
			printf("서비스 번호를 잘못 입력하셨습니다!. 다시 입력하세요.\n"); // valueError가 생긴 경우
			printf("\n");
		}
		saveData(p, N); // 데이터 처리로 인해 만들어진 정보를 txt 파일에 저장해줍니다.
		N = findDataNumber(); // 바뀐 txt파일에 대한 자료 갯수를 확인해줍니다.
		system("cls"); // 콘솔 초기화
	}
	return 0;
}

/*
코드에 해당되는 테스트 txt파일입니다.
해당 자료 파일은 "PersonalHw_input.txt"로 저장하셔야 합니다.

도서번호,책,저자,종류
--------------------------
0101,나니야연대기,C.S.루이스,소설
0102,She,헨리라이더해거드,소설
0103,다빈치코드,댄브라운,소설
0104,호밀밭의파수꾼,J.D.샐린저,소설
0105,연금술사,파울루코엘류,소설
0106,덤,묵인환,시
0107,고양이는어떻게단련되는가,김금희,시
0108,레이스커튼,한강,시
0109,진눈깨비,기형도,시
0110,빈산,최북,시
0111,고요할수록밝아지는것들,혜민스님,에세이
0112,꽃을보듯너를본다,나태주,시
0113,여행의이유,김영하,에세이
0114,나미야잡화점의기적,히가시노게이고,소설
0115,언어의온도,이기주,에세이
0116,역사의역사,유시민,에세이
0117,죽고싶지만떡볶이는먹고싶어,백세희,시
0118,82년생김지영,조남주,소설
0119,자존감수업,윤홍균,에세이
0120,살인자의기억법,김영하,소설

정확하게 이 양식대로 txt파일에 저장하셔야 코드가 기능을 수행할 수 있습니다.
*/
