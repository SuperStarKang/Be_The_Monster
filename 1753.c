// 우선 순위 큐를 이용하여 바꾸기
#include <stdio.h>

int main(void) {
	int V,E;
	scanf("%d %d", &V, &E);

	int K;
	scanf("%d", &K);

	int graph[V][V];
	int visited[V];
	int dis[V];


	for (int i=0; i<V; i++) {
		visited[i] = 0;
		for (int j=0; j<V; j++) {
			graph[i][j] = 0;
		}
	}

	for (int i=0; i<E; i++) {
		int u,v,w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u-1][v-1] = w;
	}

	for (int i=0; i<V; i++) {
		if (graph[K-1][i] != 0)
			dis[i] = graph[K-1][i];
		else
			dis[i] = 100;
	}

	int v=K-1;
	dis[K-1] = 0;
	for (int i=0; i<V; i++) {
		int min=100;
		for (int i=0; i<V; i++) {
			if (graph[v][i] != 0 && !visited[i] && dis[i] < min) {
				min = dis[i];
				v = i;
			}
		}
		visited[v] = 1;

		for (int j=0; j<V; j++) {
			if (!visited[j]) {
				if (graph[v][j] != 0 && dis[j] > dis[v] + graph[v][j])
					dis[j] = dis[v] + graph[v][j];
			}
		}
	}

	for (int i=0; i<V; i++) {
		if (dis[i] == 100)
			printf("INF\n");
		else
			printf("%d\n", dis[i]);
	}

	return 0;
}
