#include <iostream>
#include <vector>

using namespace std;

int ans;
bool flag;
string map[13];
bool visited[13][13];
vector<pair<int,int>> puyos;

void clear_puyos() {
	if (puyos.size() >= 4) {
		for (int j=0; j<puyos.size(); j++) {
			map[puyos[j].first][puyos[j].second] = '.';
		}
		flag = true;
	}

	for (int j=0; j<puyos.size(); j++) {
		visited[puyos[j].first][puyos[j].second] = false;
	}
	puyos.clear();
}

void dfs(int y, int x, char color) {
	puyos.push_back({y,x});
	visited[y][x] = true;

	if (x < 5 && !visited[y][x+1] && map[y][x+1] == color) {
		dfs(y,x+1,color);
	}
	if (x > 0 && !visited[y][x-1] && map[y][x-1] == color) {
		dfs(y,x-1,color);
	}
	if (y < 11 && !visited[y+1][x] && map[y+1][x] == color) {
		dfs(y+1,x,color);
	}
	if (y > 0 && !visited[y-1][x] && map[y-1][x] == color) {
		dfs(y-1,x,color);
	}
}

void fall_down() {
	for (int x=0; x<6; x++) {
		while (true) {
			bool f=false;
			for (int y=11; y>=1; y--) {
				if (map[y][x] == '.' && map[y-1][x] != '.') {
					map[y][x] = map[y-1][x];
					map[y-1][x] = '.';
					f = true;
				}
			}
			if (!f) {
				break;
			}
		}
	}
}

int main(void) {
	for (int i=0; i<12; i++) {
		cin >> map[i];
	}

	while (true) {
		flag = false;
		for (int i=0; i<12; i++) {
			for (int j=0; j<6; j++) {
				if (map[i][j] != '.') {
					char color = map[i][j];
					dfs(i,j,color);
					clear_puyos();
				}
			}
		}
		if (!flag) {
			break;
		}
		fall_down();
		ans++;
	}

	cout << ans << '\n';

	return 0;
}
