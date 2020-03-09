#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int in;
	int name;
	int weight;
}Node;//노드 구조를 설정합니다.

Node G[100][2]; // 방향그래프
int* Q;// 정점들의 대기열
int topSort[100] = { 0 };//위상순서를 저장하는 배열이다.
int n, m;// n은 정점, m은 간선이다.


void enque(int a) {
	int i = 1;
	while (Q[i] != -1) {
		i++;
	}
	Q[i] = a;
}// 정점 a를 Q에 삽입한다.

int deque() {
	int e;
	int i = 1;
	e = Q[1];
	while (1) {
		Q[i] = Q[i + 1];
		if (Q[i] == -1)
			break;
		i++;
	}
	return e;
}//Q로부터 정점을 삭제하여 반환한다.

void input(int x, int y, int z) {
	int i = 1;
	int j;

	while (1) {
		if (G[x][i].name == -1)
			break;
		i++;
	}
	for (j = i - 1; j >= 1; j--)
		G[x][j + 1].name = G[x][j].name;

	G[x][1].weight = z;
	G[x][1].name = y;
	G[y][0].in++;
}// G에 Node의 정보와 연결 상태를 입력해서 저장합니다.

int corect(int* ch, int x) {
	int i = 0;
	int a;

	for (i = 0; i < n; i++) {
		if (ch[i] == x)
			a = i;
	}
	return a;
}

void buildGraph(int* ch) {
	int i = 0;
	int j;
	int a, b, c;
	int x, y;

	for (i = 0; i < n; i++) {
		G[i][0].in = 0;
		G[i][0].name = i;
		for (j = 1; j <= n; j++)
			G[i][j].name = -1;
	}

	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);

		x = corect(ch, a);
		y = corect(ch, b);

		input(x, y, c);
	}
}//표준입력으로부터 방향그래프 정보를 읽어 들여 그래프 G에 저장

void removeedge(int in) {
	int i = 1;

	while (1) {
		if (G[in][i].name == -1)
			break;
		else {
			G[G[in][i].name][0].in--;
			if (G[G[in][i].name][0].in == 0)
				enque(G[in][i].name);
			G[in][i].name = -1;
			i++;
		}
	}
}//간선을 제거해주는 함수입니다.

void topologicalSort() {
	int i;
	int in = 1;
	int e;

	for (i = 0; i < n; i++) {
		if (G[i][0].in == 0)
			enque(i);
	}

	while (1) {
		e = deque();
		if (e != -1)
			topSort[in] = e;
		else {
			topSort[0] = 0;
			return;
		}
		removeedge(topSort[in]);
		in++;
		if (in == n + 1)
			break;
	}
}// G로부터 위상순서를 구하거나 방향싸이클이 존재함을 보고

void printff(int* ch) {
	int i;
	int j;

	for (i = n; i >= 1; i--) {
		for (j = 0; j < n; j++) {
			if (j == topSort[i]) {
				printf("%d ", ch[j]);
				break;
			}
		}
	}
}// 위상순서를 출력해주는 함수입니다.

void printfweight(int* ch) {
	int i;
	int j;
	int sum = 0;

	for (i = 1; i <= n; i++) {
		for (j = 0; j < n; j++) {
			if (j == topSort[i]) {
				sum += (G[i][1].weight);
				break;
			}
		}
	}
	printf("%d", sum);
}// 위상순서로 가는 경로의 총비중을 출력해주는 함수입니다.

int main() {
	int i;
	int ch[100];
	int num = 0;

	scanf("%d %d", &n, &m);

	Q = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 0; i <= n; i++)
		Q[i] = -1;
	topSort[0] = 1;

	for (i = 0; i < n; i++) {
		num = i + 1;
		ch[i] = num;
	}

	buildGraph(ch);

	topologicalSort();

	if (topSort[0] == 1) {
		printff(ch);
		printf("\n");
		printfweight(ch);
	}
	else {
		printf("0");
	}

	for (i = 0; i <= n; i++)
		free(Q[i]);
	//메모리를 free해줍니다.
}
