#include <iostream>
#include <vector>

using namespace std;

int N,M;
bool visit[1000];
vector<int> v;

void dfs(int n) {
	if (v.size() == M) {
		for (int i=0; i<M; i++)
			cout << v[i] << ' ';
		cout << endl;
		return ;
	}

	for (int i=n; i<=N; i++) {
		v.push_back(i);
		dfs(i);
		v.pop_back();
	}
}

int main(void) {
	cin >> N >> M;

	dfs(1);

	return 0;
}