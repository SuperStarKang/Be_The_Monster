#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
int N,M;

queue<pair<int,int>> q;
bool check[101][101];
int dis[101][101];
int ans;

void bfs(int y, int x) {
	q.push({y,x});
	check[y][x] = true;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		dis[0][0] = 1;
		q.pop();
		
		if (p.first < N && map[p.first+1][p.second] == 1 && !check[p.first + 1][p.second]) {
			check[p.first + 1][p.second] = true;
			q.push({p.first+1, p.second});
			dis[p.first+1][p.second] = dis[p.first][p.second] + 1;
		}
		if (p.first > 0 && map[p.first-1][p.second] == 1 && !check[p.first - 1][p.second]) {
			check[p.first - 1][p.second] = true;
			q.push({p.first-1, p.second});
			dis[p.first-1][p.second] = dis[p.first][p.second] + 1;
		}
		if (p.second < M && map[p.first][p.second+1] == 1 && !check[p.first ][p.second+1]) {
			check[p.first ][p.second+1] = true;
			q.push({p.first, p.second+1});
			dis[p.first][p.second+1] = dis[p.first][p.second] + 1;
		}
		if (p.second > 0 && map[p.first][p.second-1] == 1 && !check[p.first][p.second-1]) {
			check[p.first][p.second-1] = true;
			q.push({p.first, p.second-1});
			dis[p.first][p.second-1] = dis[p.first][p.second] + 1;
		}
	}
}

int main(void) {
	cin >> N >> M;

	string line;
	for (int i=0; i<N; i++) {
		cin >> line;
		for (int j=0; j<line.size(); j++) {
			map[i][j] = line[j] - '0';
		}
	}

	bfs(0,0);

	cout << dis[N-1][M-1] << endl;
	return 0;
}
