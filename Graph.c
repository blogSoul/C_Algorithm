#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

void init(GraphType *g) {
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}
 
void insert_vertex(GraphType *g, int v) {
	if (((g->n) + 1) > MAX_VERTICES){
	return;
    }
	g->n++;
}

int main() {
	int a;
	scanf("%d", &a);
	return 0;
}
