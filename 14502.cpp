#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int N,M;
int result;
int map[10][10];
int test_map[10][10];
bool visit[10][10];
vector<pair<int, int>> virus;
vector<pair<int, int>> safe;
vector<pair<int, int>> temp;
vector<vector<pair<int,int>>> combinations;

void spreads_virus(int y, int x) {
	if (!(visit[y][x])) {
		visit[y][x] = true;
		test_map[y][x] = 2;
		if (x > 0 && test_map[y][x-1] != 1) {
			spreads_virus(y, x-1);
		}
		if (x < M-1 && test_map[y][x+1] != 1) {
			spreads_virus(y, x+1);
		}
		if (y > 0 && test_map[y-1][x] != 1) {
			spreads_virus(y-1, x);
		}
		if (y < N-1 && test_map[y+1][x] != 1) {
			spreads_virus(y+1, x);
		}
	}
}

void generateCombinations(int start, int count) {
    if (count == 0) {
        combinations.push_back(temp);
        return;
    }

    for (int i = start; i < safe.size(); i++) {
        temp.push_back(safe[i]);
        generateCombinations(i + 1, count - 1);
        temp.pop_back();
    }
}

void test() {
	for (int n=0; n<combinations.size(); n++) {
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				test_map[i][j] = map[i][j];
				visit[i][j] = false;
			}
		}
		test_map[combinations[n][0].first][combinations[n][0].second] = 1;
		test_map[combinations[n][1].first][combinations[n][1].second] = 1;
		test_map[combinations[n][2].first][combinations[n][2].second] = 1;

		for (int i=0; i<virus.size(); i++) {
			spreads_virus(virus[i].first, virus[i].second);
		}
		int safe_place=0;
		// cout << endl;
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				// cout << test_map[i][j] << ' ';
				if (test_map[i][j] == 0)
					safe_place++;
			}
			// cout << endl;
		}
		// cout << endl;
		result = max(result, safe_place);
	}
}

int main(void) {
	cin >> N >> M;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				safe.push_back({i,j});
			}
			else if (map[i][j] == 2) {
				virus.push_back({i,j});
			}
		}
	}
	generateCombinations(0,3);
	test();
	cout << result << endl;
	return 0;
}
