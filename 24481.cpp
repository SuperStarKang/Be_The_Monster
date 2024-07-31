#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,R;
vector<int> v[100001];
int depths[100001];
bool visited[100001];

void dfs(int start, int depth) {
	if (!visited[start]) {
		visited[start] = true;
		depths[start] = depth;

		for (int i=0; i<v[start].size(); i++) {
			if (!visited[v[start][i]]) {
				dfs(v[start][i], depth+1);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin >> N >> M >> R;

	int v1,v2;
	for (int i=0; i<M; i++) {
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}

	for (int i=1; i<=N; i++) {
		sort(v[i].begin(), v[i].end());
	}

	dfs(R,0);

	for (int i=1; i<=N; i++) {
		if (i != R && depths[i] == 0) {
			cout << -1 << '\n';
		}
		else
			cout << depths[i] << '\n';
	}

	return 0;
}