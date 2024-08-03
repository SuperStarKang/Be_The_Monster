#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int r,c;
string map[1001];
int fire_step[1001][1001];
int step[1001][1001];
bool visited[1001][1001];
bool flag;
queue<pair<int,int>> q;
queue<pair<int,int>> fire;

void bfs(int start_y, int start_x) {
	q.push(make_pair(start_y, start_x));
	visited[start_y][start_x] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		int cnt = step[y][x];
		q.pop();

		if (x == 0 || y == 0 || x == c-1 || y == r-1) {
			cout << cnt+1 << '\n';
			flag = true;
			return;
		}

		if (x+1 < c && cnt+1 < fire_step[y][x+1] && !visited[y][x+1] && map[y][x+1] == '.') {
			q.push(make_pair(y,x+1));
			step[y][x+1] = step[y][x] + 1; 
			visited[y][x+1] = true;
		}
		if (x-1 >= 0 && cnt+1 < fire_step[y][x-1] && !visited[y][x-1] && map[y][x-1] == '.') {
			q.push(make_pair(y,x-1));
			step[y][x-1] = step[y][x] + 1;
			visited[y][x-1] = true;
		}
		if (y+1 < r && cnt+1 < fire_step[y+1][x] && !visited[y+1][x] && map[y+1][x] == '.') {
			q.push(make_pair(y+1,x));
			step[y+1][x] = step[y][x] + 1;
			visited[y+1][x] = true;
		}
		if (y-1 >= 0 && cnt+1 < fire_step[y-1][x] && !visited[y-1][x] && map[y-1][x] == '.') {
			q.push(make_pair(y-1,x));
			step[y-1][x] = step[y][x] + 1;
			visited[y-1][x] = true;
		}
	}
}

void spread_fire() {
	while (!fire.empty()) {
		int fire_y = fire.front().first;
		int fire_x = fire.front().second;
		fire.pop();

		if (fire_x+1 < c && map[fire_y][fire_x+1] == '.' && fire_step[fire_y][fire_x+1] > fire_step[fire_y][fire_x]+1) {
			fire_step[fire_y][fire_x+1] = fire_step[fire_y][fire_x] + 1;
			fire.push(make_pair(fire_y, fire_x+1));
		}
		if (fire_x-1 >= 0 && map[fire_y][fire_x-1] == '.' && fire_step[fire_y][fire_x-1] > fire_step[fire_y][fire_x]+1) {
			fire_step[fire_y][fire_x-1] = fire_step[fire_y][fire_x] + 1;
			fire.push(make_pair(fire_y, fire_x-1));
		}
		if (fire_y+1 < r && map[fire_y+1][fire_x] == '.' && fire_step[fire_y+1][fire_x] > fire_step[fire_y][fire_x]+1) {
			fire_step[fire_y+1][fire_x] = fire_step[fire_y][fire_x] + 1;
			fire.push(make_pair(fire_y+1, fire_x));
		}
		if (fire_y-1 >= 0 && map[fire_y-1][fire_x] == '.' && fire_step[fire_y-1][fire_x] > fire_step[fire_y][fire_x]+1) {
			fire_step[fire_y-1][fire_x] = fire_step[fire_y][fire_x] + 1;
			fire.push(make_pair(fire_y-1, fire_x));
		}
	}
}

int main(void) {
	cin >> r >> c;

	int start_x,start_y;
	for (int i=0; i<r; i++) {
		cin >> map[i];
		for (int j=0; j<c; j++) {
			if (map[i][j] == 'J') {
				start_x = j;
				start_y = i;
				map[i][j] = '.';
			}
		
			if (map[i][j] == 'F') {
				fire.push(make_pair(i, j));
				fire_step[i][j] = 0;
			}
			else {
				fire_step[i][j] = 99999;
			}
		}
	}

	spread_fire();

	bfs(start_y, start_x);

	// for (int i=0; i<r; i++) {
	// 	for (int j=0; j<c; j++) {
	// 		cout << step[i][j] << ' ';
	// 	}
	// 	cout << "\n";
	// }
	// cout << '\n';

	// for (int i=0; i<r; i++) {
	// 	for (int j=0; j<c; j++) {
	// 		cout << fire_step[i][j] << ' ';
	// 	}
	// 	cout << "\n";
	// }

	if (!flag) {
		cout << "IMPOSSIBLE\n";
	}
	return 0;
}