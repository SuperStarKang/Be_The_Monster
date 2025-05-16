#include <iostream>
#include <vector>

using namespace std;

int R,C,ans;
bool alphabet[26];
vector<string> map;

bool promising(int y, int x) {
	if (y<0 || y>=R || x<0 || x>=C) {
		return false;
	}
	if (alphabet[map[y][x] - 65] == true) {
		return false;
	}
	return true;
}

void backtracking(int y, int x, int cnt) {
	ans = max(ans, cnt);
	alphabet[map[y][x] - 65] = true;

	if (promising(y + 1, x)) {
		alphabet[map[y + 1][x] - 65] = true;
		backtracking(y + 1, x, cnt + 1);
		alphabet[map[y + 1][x] - 65] = false;
	}
	if (promising(y - 1, x)) {
		alphabet[map[y - 1][x] - 65] = true;
		backtracking(y - 1, x, cnt + 1);
		alphabet[map[y - 1][x] - 65] = false;
	}
	if (promising(y, x + 1)) {
		alphabet[map[y][x + 1] - 65] = true;
		backtracking(y, x + 1, cnt + 1);
		alphabet[map[y][x + 1] - 65] = false;
	}
	if (promising(y, x - 1)) {
		alphabet[map[y][x - 1] - 65] = true;
		backtracking(y, x - 1, cnt + 1);
		alphabet[map[y][x - 1] - 65] = false;
	}
}

int main(void) {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s;

		cin >> s;
		map.push_back(s);
	}

	backtracking(0, 0, 1);

	cout << ans << '\n';
	return 0;
}