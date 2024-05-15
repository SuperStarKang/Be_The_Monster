#include <iostream>
#include <vector>

using namespace std;

int T,N;
int cnt;
bool visited[1001];
vector<int> v[1001];

void bfs(int n) {
	if (visited[n]) {
		cnt++;
		return ;
	}

	visited[n] = true;
	bfs(v[n][0]);
}

int main(void) {
	cin >> T;
	while (T--) {
		cin >> N;
		cnt = 0;
		int n;
		for (int i=1; i<=N; i++) {
			cin >> n;
			v[i].push_back(n);
		}

		for (int i=1; i<=N; i++) {
			if (!visited[i])
				bfs(i);
		}
		cout << cnt << endl;

		for (int i=1; i<=N; i++) {
			v[i].pop_back();
			visited[i] = false;
		}
	}
	return 0;
}