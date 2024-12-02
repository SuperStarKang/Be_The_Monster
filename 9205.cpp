#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t,n;
vector<pair<int, int>> v;
queue<pair<int, int>> q;
bool visited[101];

void bfs() {
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		if (cur_x == v[n+1].first && cur_y == v[n+1].second) {
			cout << "happy\n";
			return;
		}

		for (int i=1; i<=n+1; i++) {
			if (!visited[i] && abs(cur_x - v[i].first) + abs(cur_y - v[i].second) <= 1000) {
				visited[i] = true;
				q.push(v[i]);
			}
		}
	}
	cout << "sad\n";
}

int main(void) {
	cin >> t;

	while (t--) {
		cin >> n;

		v.clear();
		q = queue<pair<int, int>>();
		for (int i=0; i<=n+1; i++) {
			visited[i] = false;
		}
		for (int i=0; i<=n+1; i++) {
			int x,y;
			cin >> x >> y;
			v.push_back(make_pair(x,y));
		}
		visited[0] = true;
		q.push(v[0]);
		bfs();
	}

	return 0;
}