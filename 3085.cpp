#include <iostream>
#include <algorithm>

using namespace std;

string map[51];
int N;
int result;

void swap(char *a, char *b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

int find_longest() {
	int col_max=0;
	for (int x=0; x<N; x++) {
		int col_cnt=1;
		for (int y=0; y<N-1; y++) {
			if (map[y][x] == map[y+1][x]) {
				col_cnt++;
			}
			else {
				col_max = max(col_max, col_cnt);
				col_cnt = 1;
			}
		}
		col_max = max(col_max, col_cnt);
	}

	int row_max=0;
	for (int y=0; y<N; y++) {
		int row_cnt=1;
		for (int x=0; x<N-1; x++) {
			if (map[y][x] == map[y][x+1]) {
				row_cnt++;
			}
			else {
				row_max = max(row_max, row_cnt);
				row_cnt = 1;
			}
		}
		row_max = max(row_max, row_cnt);
	}
	return max(row_max, col_max);
}

int main(void) {
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> map[i];
	}

	for (int y=0; y<N; y++) {
		for (int x=0; x<N-1; x++) {
			swap(map[y][x], map[y][x+1]);
			result = max(result, find_longest());
			swap(map[y][x], map[y][x+1]);

			swap(map[x][y], map[x+1][y]);
			result = max(result, find_longest());
			swap(map[x][y], map[x+1][y]);
		}
	}

	cout << result << '\n';
	return 0;
}