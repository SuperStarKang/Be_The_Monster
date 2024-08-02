#include <iostream>
#include <queue>

using namespace std;

int n,m;
int target[2];
int map[1001][1001];
int ans[1001][1001];
bool visited[1001][1001];
queue<pair<int, int>> q;

void bfs(int y, int x) {
	q.push(make_pair(y,x));
	visited[y][x] = true;
	ans[y][x] = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		if (x+1 < m && !visited[y][x+1] && map[y][x+1] == 1) {
			ans[y][x+1] = ans[y][x] + 1;
			q.push(make_pair(y,x+1));
			visited[y][x+1] = true;
		}

		if (x-1 >= 0 && !visited[y][x-1] && map[y][x-1] == 1) {
			ans[y][x-1] = ans[y][x] + 1;
			q.push(make_pair(y,x-1));
			visited[y][x-1] = true;
		}

		if (y+1 < n && !visited[y+1][x] && map[y+1][x] == 1) {
			ans[y+1][x] = ans[y][x] + 1;
			q.push(make_pair(y+1,x));
			visited[y+1][x] = true;
		}

		if (y-1 >= 0 && !visited[y-1][x] && map[y-1][x] == 1) {
			ans[y-1][x] = ans[y][x] + 1;
			q.push(make_pair(y-1,x));
			visited[y-1][x] = true;
		}
	}
}

int main(void) {
	cin >> n >> m;

	int target_x,target_y;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				target_y = i;
				target_x = j;
			}
			else if (map[i][j] == 1) {
				ans[i][j] = -1;
			}
			else {
				ans[i][j] = 0;
			}
		}
	}

	bfs(target_y, target_x);

	for (int y=0; y<n; y++) {
		for (int x=0; x<m; x++) {
			cout << ans[y][x] << ' ';
		}
		cout << '\n';
	}

	return 0;
}