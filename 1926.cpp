#include <iostream>

using namespace std;

int n,m;
int map[501][501];
bool visited[501][501];
int max_area = 0;
int area = 1;
int picture_count = 0;

void calculate_area(int y, int x) {
	visited[y][x] = true;
	if (x > 0 && !visited[y][x-1] && map[y][x-1] == 1) {
		area++;
		calculate_area(y, x-1);
	}
	if (x+1 < m && !visited[y][x+1] && map[y][x+1] == 1) {
		area++;
		calculate_area(y, x+1);
	}
	if (y > 0 && !visited[y-1][x] && map[y-1][x] == 1) {
		area++;
		calculate_area(y-1, x);
	}
	if (y+1 < n && !visited[y+1][x] && map[y+1][x] == 1) {
		area++;
		calculate_area(y+1, x);
	}
}

int main(void) {
	cin >> n >> m;

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				area = 1;
				picture_count++;
				calculate_area(i, j);
				if (area > max_area) {
					max_area = area;
				}
			}
		}
	}

	cout << picture_count << '\n';
	cout << max_area << '\n';

	return 0;
}