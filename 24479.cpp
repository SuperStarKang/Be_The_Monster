#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,R;
vector<int> v[100001];
int order;
int orders[100001];
bool visited[100001];

void dfs(int start) {
	if (!visited[start]) {
		visited[start] = true;
		orders[start] = ++order;

		for (int i=0; i<v[start].size(); i++) {
			if (!visited[v[start][i]]) {
				dfs(v[start][i]);
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

	dfs(R);

	for (int i=1; i<=N; i++) {
		cout << orders[i] << '\n';
	}

	return 0;
}