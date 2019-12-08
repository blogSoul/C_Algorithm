#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int nodenum;
	int edgesize;
	struct Node* next;
}Node; //노드의 구조를 설정합니다.

Node* newnode(int num, int size) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->edgesize = size;
	temp->nodenum = num;
	temp->next = NULL;

	return temp;
}// 새로운 노드를 만듭니다.

void insert(Node** g, int start, int end, int weight) {
	Node* temp;
	Node* n = newnode(end, weight);

	temp = g[start];

	while (1) {
		if (temp->next == NULL) {
			temp->next = n;
			break;
		}
		else {
			if (temp->next->nodenum > end) {
				n->next = temp->next;
				temp->next = n;
				break;
			}
			else {
				temp = temp->next;
			}
		}
	}// start정점인 리스트에서 (b정점 간선 가중치 num)인 노드를 삽입합니다.

	if (start == end)
		return;
}

void dfs_print(Node** g, int num) {
}// 위상순서로 

void putnode(Node** g, int nodenum) {
	int i;
	Node* temp;
	Node* fr;
	for (i = 1; i <= nodenum; i++) {
		temp = g[i];
		while (temp->next != NULL) {
			fr = temp->next;
			temp->next = temp->next->next;
			free(fr);
		}
	}
}//메모리를 해제하는 함수입니다.

int main() {
	int n, m;//정점의 개수: n, 간선의 개수: m
	int start, end, weight;
	
	scanf("%d %d", &n, &m);

	Node** g = (Node * *)malloc(sizeof(Node*) * n);
	for (int i = 0; i < n; i++) {
		g[i] = newnode(i, 0);
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &start, &end, &weight);
		insert(g, start, end, weight);
	}



	putnode(g, n);
	free(g);
}
