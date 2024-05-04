#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int M,N;
int box[1001][1001];
queue<pair<int,int>> ripe_tomato;

void bfs(int y, int x) {
	if (x > 0 && box[y][x-1] == 0) {
		box[y][x-1] = 1;
		ripe_tomato.push({y,x-1});
	}
	if (x < M-1 && box[y][x+1] == 0) {
		box[y][x+1] = 1;
		ripe_tomato.push({y,x+1});
	}
	if (y > 0 && box[y-1][x] == 0) {
		box[y-1][x] = 1;
		ripe_tomato.push({y-1,x});
	}
	if (y < N-1 && box[y+1][x] == 0) {
		box[y+1][x] = 1;
		ripe_tomato.push({y+1,x});
	}
}

int main(void) {
	cin >> M >> N;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1)
				ripe_tomato.push({i,j});
		}
	}

	int date_cnt = -1;
	while (ripe_tomato.size() != 0) {
		date_cnt++;
		int size = ripe_tomato.size();
		for (int i=0; i<size; i++) {
			bfs(ripe_tomato.front().first, ripe_tomato.front().second);
			ripe_tomato.pop();
		}
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (box[i][j] == 0) {
				cout << -1 << '\n';
				return 0;
			}
		}
	}
	cout << date_cnt << '\n';
	return 0;
}