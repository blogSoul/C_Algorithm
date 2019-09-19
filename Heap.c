// Algorithm_2_힙정렬.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int N[100]; //포인터 변수 선언
int i,k;

int Function1() { return 0; }// 함수 만드는 방법입니다. 

void insertItem(int key) {
   i = N[];
}

void removeMax(void) {
   
   downHeap(1);
}

void upHeap(int i) {
   int a;
   while (1) {
      for (a = i; a >= 1; a = a / 2) {
         if (N[i] < N[i / 2]) {
            k = N[i / 2];
            N[i / 2] = N[i];
            N[i] = k;
         }
         else {
            break;
         }
      }
   }
}

void downHeap(int i) {
   int a;
   while (1) {
      for (a = i; a <= (sizeof(N)/sizeof(int)); a = a * 2) {
         if (N[i] < N[i * 2]) {
            k = N[i * 2];
            N[i * 2] = N[i];
            N[i] = k;
         }
         else {
            break;
         }
      }
   }
}

void printHeap(void) {
   int a;
   for (a = 1; a <= (sizeof(N) / sizeof(int)); a = a + 1) {
      printf(" %d", N[a]);
   }
}

int main(void)
{
   
   int b, c;
   int n;
   char a; // i,d,p,q 확인한다. 

   while (1) {
      scanf("%c %d", &a, &b);

      if (a ==  'i') {
         // <키를> 힙에 삽입한다
         printf("0");
      }
      else if (a == 'd') {
         // 힙에서 삭제하여 키를 반환
      }
      else if (a == 'p') {
         // 힙의 내용을 인쇄
      }
      else if (a == 'q') {
         break;
      }
   }

   free(arr);

   return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
