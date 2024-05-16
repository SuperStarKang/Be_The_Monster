#include <iostream>
#include <utility>
#include <stack>

using namespace std;

int N;
int map[10][10];
bool visited[10][10];
bool flag;
int mv[2][2] = {{1,0}, {0,1}};

void dfs() {
	stack<pair<int, int>> s;
	s.push({0,0});
	visited[0][0] = true;

	while (!s.empty()) {
		int y = s.top().first;
		int x = s.top().second;
		s.pop();
	
		if (map[y][x] == -1) {
			flag = 1;
			return ;
		}
		for (int i=0; i<2; i++) {
			int xx = x + mv[0][i] * map[y][x];
			int yy = y + mv[1][i] * map[y][x];
			
			if (xx >= 0 && xx < N && yy >= 0 && yy < N) {
				if (!visited[yy][xx]) {
					visited[yy][xx] = true;
					s.push({yy,xx});
				}
			}
		}
	}
}

int main(void) {
	cin >> N;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++)
			cin >> map[i][j];
	}

	dfs();
	if (flag) {
		cout << "HaruHaru\n";
	}
	else {
		cout << "Hing\n";
	}
	return 0;
}