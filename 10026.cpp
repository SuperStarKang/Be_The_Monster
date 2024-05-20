#include <iostream>
#include <queue>

using namespace std;

int N;
int cnt_normal,cnt_abnormal;
string map[101];
queue<pair<int, int>> q;
bool visited[101][101];

void dfs(int y, int x, int color) {
	if (!visited[y][x]) {
		visited[y][x] = true;
		if (x > 0 && !visited[y][x-1] && map[y][x-1] == color) {
			dfs(y,x-1,color);
		}
		if (x < N-1 && !visited[y][x+1] && map[y][x+1] == color) {
			dfs(y,x+1,color);
		}
		if (y > 0 && !visited[y-1][x] && map[y-1][x] == color) {
			dfs(y-1,x,color);
		}
		if (y < N-1 && !visited[y+1][x] && map[y+1][x] == color) {
			dfs(y+1,x,color);
		}
	}
}

int main(void) {
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> map[i];
	}

	for (int y=0; y<N; y++) {
		for (int x=0; x<N; x++) {
			if (!visited[y][x]) {
				cnt_normal++;
				dfs(y,x,map[y][x]);
			}
		}
	}

	for (int y=0; y<N; y++) {
		for (int x=0; x<N; x++) {
			visited[y][x] = false;
			if (map[y][x] == 'G')
				map[y][x] = 'R';
		}
	}

	for (int y=0; y<N; y++) {
		for (int x=0; x<N; x++) {
			if (!visited[y][x]) {
				cnt_abnormal++;
				dfs(y,x,map[y][x]);
			}
		}
	}

	cout << cnt_normal << ' ' << cnt_abnormal << '\n';
	return 0;
}