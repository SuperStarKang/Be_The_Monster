#include <iostream>

using namespace std;

int N,M,cnt;
char cur;
string map[51];
bool visited[51][51];

void dfs(int y, int x) {
	if (cur != map[y][x]) {
		return;
	}
	visited[y][x] = true;
	if (x < M-1 && !visited[y][x+1] && map[y][x] == '-') {
		dfs(y,x+1);
	}
	if (y < N-1 && !visited[y+1][x] && map[y][x] == '|') {
		dfs(y+1,x);
	}
}

int main(void) {
	cin >> N >> M;
	for (int i=0; i<N; i++) {
		cin >> map[i];
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (!visited[i][j])  {
				cnt++;
				cur = map[i][j];
				dfs(i,j);
			}
		}
	}

	cout << cnt << '\n';
	return 0;
}