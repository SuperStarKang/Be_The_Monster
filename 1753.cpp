#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2147483647

using namespace std;

int V,E;
int start;
vector<pair<int, int>> v[20001];
int cost[20001];
bool visit[20001];

int linear() {
	int min = INF;
	int idx=0;
	for (int i=1; i<=V; i++) {
		if (cost[i] < min && !visit[i]) {
			min = cost[i];
			idx = i;
		}
	}
	return idx;
}

void dijkstra_linear() {
	for (int i=0; i<v[start].size(); i++) {
		cost[v[start][i].first] = v[start][i].second;
	}
	for (int i=1; i<=V; i++) {
		if (cost[i] == 0 && i != start) {
			cost[i] = INF;
		}
	}

	visit[start] = true;
	for (int i=0; i<V-2; i++) {
		int current = linear();
		visit[current] = true;
		for (int j=0; j<v[current].size(); j++) {
			if (!visit[v[current][j].first]) {
				if (cost[current] + v[current][j].second < cost[v[current][j].first])
					cost[v[current][j].first] = cost[current] + v[current][j].second;
			}
		}
	}
}

void dijkstra_pq() {
	cost[start] = 0;
	priority_queue<pair<int,int>> pq;
	pq.push({0,start});

	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (cost[current] < distance)
			continue;
		for (int i=0; i<v[current].size(); i++) {
			int next = v[current][i].first;
			int next_dis = distance + v[current][i].second;
			if (next_dis < cost[next]) {
				cost[next] = next_dis;
				pq.push({-next_dis, next});
			}
		}
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> V >> E;
	cin >> start;

	int v1,v2,w;
	for (int i=0; i<E; i++) {
		cin >> v1 >> v2 >> w;
		v[v1].push_back({v2,w});
	}
	for (int i=1; i<=V; i++) {
		cost[i] = INF;
	}

	dijkstra_pq();

	for (int i=1; i<=V; i++) {
		if (cost[i] == INF)
			cout << "INF" << endl;
		else
			cout << cost[i] << endl;
	}

	return 0;
}