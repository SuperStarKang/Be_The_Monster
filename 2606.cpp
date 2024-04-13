#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[101];
bool visit[101];
int ans;

void	dfs(int n) {
	ans++;
	visit[n] = true;

	for (int i=0; i<v[n].size(); i++) {
		int next = v[n][i];
		if (!visit[next]) {
			dfs(next);
		}
	}
}

int main(void) {
	int N,P;
	cin >> N >> P;

	int c1,c2;
	for (int i=0; i<P; i++) {
		cin >> c1 >> c2;
		v[c1].push_back(c2);
		v[c2].push_back(c1);
	}

	dfs(1);

	cout << ans-1 << endl;
	return 0;
}