#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int M,N,H;
int cnt;
int flag;
vector<int> box[101][101];
queue<tuple<int, int, int>> ripe_tomatos;

void bfs() {
	tuple<int,int,int> t = ripe_tomatos.front();
	int h = get<0>(t);
	int y = get<1>(t);
	int x = get<2>(t);

	if (h > 0 && box[h-1][y][x] == 0) {
		box[h-1][y][x] = 1;
		ripe_tomatos.push({h-1,y,x});
	}

	if (h < H-1 && box[h+1][y][x] == 0) {
		box[h+1][y][x] = 1;
	
		ripe_tomatos.push({h+1,y,x});
	}

	if (x > 0 && box[h][y][x-1] == 0) {
		box[h][y][x-1] = 1;
		ripe_tomatos.push({h,y,x-1});
	}

	if (x < M-1 && box[h][y][x+1] == 0) {
		box[h][y][x+1] = 1;
	
		ripe_tomatos.push({h,y,x+1});
	}

	if (y > 0 && box[h][y-1][x] == 0) {
		box[h][y-1][x] = 1;
		ripe_tomatos.push({h,y-1,x});
	}

	if (y < N-1 && box[h][y+1][x] == 0) {
		box[h][y+1][x] = 1;
	
		ripe_tomatos.push({h,y+1,x});
	}
}

int main(void) {
	cin >> M >> N >> H;
	int n;
	for (int k=0; k<H; k++) {
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				cin >> n;
				if (n == 0)
					flag = 1;
				box[k][i].push_back(n);
				if (n == 1) {
					ripe_tomatos.push({k,i,j});
				}
			}
		}
	}

	if (flag == 0) {
		cout << 0 << '\n';
		return 0;
	}

	cnt = -1;
	while (!ripe_tomatos.empty()) {
		int size = ripe_tomatos.size();
		for (int i=0; i<size; i++) {
			bfs();
			ripe_tomatos.pop();
		}
		cnt++;
	}

	for (int h=0; h<H; h++) {
		for (int y=0; y<N; y++) {
			for (int x=0; x<M; x++) {
				if (box[h][y][x] == 0) {
					cout << -1 << '\n';
					return 0;
				}
			}
		}
	}

	cout << cnt << '\n';
	return 0;
}