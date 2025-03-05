#include <iostream>

using namespace std;

int N,ans;
int map[101][101];
bool visited[101][101];
bool flag;

void bfs(int h, int y, int x, int cnt) {
	if (map[y][x] > h && !visited[y][x]) {
		flag = true;
		visited[y][x] = true;

		if (x < N-1) {
			bfs(h, y, x+1, cnt + 1);
		}
		if (y < N-1) {
			bfs(h, y+1, x, cnt + 1);
		}
		if (x > 0) {
			bfs(h, y, x-1, cnt + 1);
		}
		if (y > 0) {
			bfs(h, y-1, x, cnt + 1);
		}
	}
}

int main(void) {
	cin >> N;
	
	int max_h=0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> map[i][j];
			if (map[i][j] > max_h) {
				max_h = map[i][j];
			}
		}
	}

	for (int height=0; height<=max_h; height++) {
		int cnt=0;
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				bfs(height, i, j, 0);
				if (flag) {
					cnt++;
				}
				flag = false;
			}
		}

		if (cnt > ans) {
			ans = cnt;
		}

		flag = false;
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				visited[i][j] = false;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}