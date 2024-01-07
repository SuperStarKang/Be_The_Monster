#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int	bfs_visited[1000000];
int	dfs_visited[1000000];

typedef struct
{
	int	data[1000000];
	int front;
	int	rear;
}	QueueType;

void initQueue(QueueType* Q)
{
	Q->front = Q->rear = 0;
}

int isQueueEmpty(QueueType* Q)
{
	return Q->rear == Q->front;
}

int isQueueFull(QueueType* Q)
{
	return (Q->rear + 1) % 1000000 == Q->front;
}

void enqueue(QueueType* Q, int d)
{
	if (isQueueFull(Q))
    	printf("Overflow!!\n");
	else
	{
	    Q->rear = (Q->rear + 1) % 1000000;
	    Q->data[Q->rear] = d;
	}
}

int dequeue(QueueType* Q)
{
	if (isQueueEmpty(Q))
	{
		printf("Empty!!\n");
        return -1;
	}
	Q->front = (Q->front + 1) % 1000000;
	return Q->data[Q->front];
}

typedef struct	Grapgh {
	int	n;
	int	adj_mat[1005][1005];
}	Grapgh;

void	init_graph(Grapgh *g, int N) {
	g->n = 0;
	for (int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			g->adj_mat[i][j] = 0;
}

void	insert_edge(Grapgh *g, int v1, int v2) {
	g->adj_mat[v1][v2] = 1;
	g->adj_mat[v2][v1] = 1;
}

void	dfs(Grapgh *g, int start) {
	dfs_visited[start] = TRUE;
	printf("%d ", start);

	for (int t=1; t<=g->n; t++) {
		if (g->adj_mat[start][t] == 1 && dfs_visited[t] == FALSE)
			dfs(g,t);
	}
}
void	bfs(Grapgh *g, int start) {
	QueueType	Q;
	initQueue(&Q);

	bfs_visited[start] = TRUE;
	printf("%d ", start);
	enqueue(&Q, start);

	while (!(isQueueEmpty(&Q))) {
		start = dequeue(&Q);
		for (int t=1; t<=g->n; t++) {
			if (g->adj_mat[start][t] == 1 && bfs_visited[t] == FALSE) {
				bfs_visited[t] = TRUE;
				printf("%d ", t);
				enqueue(&Q,t);
			}
		}
	}
}

int main(void) {
	int N,M,V;
	scanf("%d %d %d", &N,&M,&V);

	int v1,v2;
	Grapgh g;
	init_graph(&g, N);
	g.n = N;
	for (int i=0; i<M; i++) {
		scanf("%d %d", &v1, &v2);
		insert_edge(&g, v1, v2);
	}

	dfs(&g,V);	printf("\n");
	bfs(&g,V);	printf("\n");

	return 0;
}