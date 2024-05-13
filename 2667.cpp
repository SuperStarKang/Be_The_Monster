#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int map[26][26];
bool visit[26][26];
vector<int> h;
int cnt_h;

int dfs(int y, int x) {
	if (!visit[y][x]) {
		cnt_h++;
		visit[y][x] = true;
		if (x > 0 && map[y][x-1] == 1) {
			dfs(y, x-1);
		}
		if (x < N && map[y][x+1] == 1) {
			dfs(y, x+1);
		}
		if (y > 0 && map[y-1][x] == 1) {
			dfs(y-1, x);
		}
		if (y < N && map[y+1][x] == 1) {
			dfs(y+1, x);
		}
	}
	return cnt_h;
}

int main(void) {
	cin >> N;

	string line;
	for (int i=0; i<N; i++) {
		cin >> line;
		for (int j=0; j<N; j++) {
			map[i][j] = line[j] - '0';
		}
	}

	int town=0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cnt_h = 0;
			if (map[i][j] == 1) {
				int cnt = dfs(i,j);
				if (cnt) {
					town++;
					h.push_back(cnt);
				}
			}
		}
	}

	sort(h.begin(), h.end());

	cout << town << "\n";
	for (int i=0; i<h.size(); i++)
		cout << h[i] << "\n";
	return 0;
}