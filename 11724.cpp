#include <iostream>
#include <vector>

using namespace std;

int V,E;
int cnt;
vector<int> v[1001];
bool visited[1001];

void bfs(int n) {
	if (visited[n]) {
		return ;
	}

	for (int i=0; i<v[n].size(); i++) {
		visited[n] = true;
		bfs(v[n][i]);
	}
}

int main(void) {
	cin >> V >> E;
	int v1,v2;
	for (int i=0; i<E; i++) {
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}

	for (int i=1; i<=V; i++) {
		if (!visited[i]) {
			bfs(i);
			cnt++;
		}
	}

	cout << cnt << '\n';
	return 0;
}