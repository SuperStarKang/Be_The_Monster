#include <iostream>

using namespace std;

int map[51][51];
bool visit[51][51];
int N,M,K;
int cnt,ans;

void dfs(int x, int y) {
	if (!visit[y][x] && map[y][x] == 1) {
		visit[y][x] = true;
		cnt++;
		if (x > 0 && map[y][x-1] == 1) {
			dfs(x-1, y);
		}
		if (x < M && map[y][x+1] == 1) {
			dfs(x+1,y);
		}
		if (y > 0 && map[y-1][x] == 1) {
			dfs(x,y-1);
		}
		if (y < N && map[y+1][x] == 1) {
			dfs(x,y+1);
		}
	}
}

int main(void) {
	int T;
	cin >> T;

	for (int i=0; i<T; i++) {
		cin >> M >> N >> K;

		for (int n=0; n<N; n++) {
			for (int m=0; m<M; m++) {
				map[n][m] = 0;
				visit[n][m] = false;
			}
		}
		ans = 0;

		int X,Y;
		for (int i=0; i<K; i++) {
			cin >> X >> Y;
			map[Y][X] = 1;
		}

		for (int y=0; y<N; y++) {
			for (int x=0; x<M; x++) {
				cnt = 0;
				dfs(x,y);
				if (cnt) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}