#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tree[1000001];
int dp[1000001][2];
bool visit[1000001];

void	dfs(int n) {
	visit[n] = true;

	dp[n][1] = 1;
	for (int i=0; i<tree[n].size(); i++) {
		int next = tree[n][i];
		if (!(visit[next])) {
			dfs(next);
			dp[n][0] += dp[next][1];
			dp[n][1] += min(dp[next][0], dp[next][1]);
		}
	}
}

int main(void) {
	int N;
	cin >> N;

	int u,v;
	for (int i=0; i<N-1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(1);

	cout << min(dp[1][0], dp[1][1]) << endl;
	return 0;
}
