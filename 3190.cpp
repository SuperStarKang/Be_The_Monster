#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N,K,L;
int map[101][101];
vector<pair<int, char>> directions;
deque<pair<int, int>> snake;

int main(void) {
	cin >> N >> K;

	int r,c;
	for (int i=0; i<K; i++) {
		cin >> r >> c;
		map[r-1][c-1] = 2;
	}

	cin >> L;
	int x;
	char direction;
	for (int i=0; i<L; i++) {
		cin >> x >> direction;
		directions.push_back({x,direction});
	}

	snake.push_front({0,0});
	map[0][0] = 1;

	int dir = 0;
	int t=0,idx=0;
	while (true) {
		if (idx < directions.size() && t == directions[idx].first) {
			if (dir == 0) {
				if (directions[idx].second == 'L') {
					dir = 3;
				}
				else {
					dir = 1;
				}
			}
			else if (dir == 1) {
				if (directions[idx].second == 'L') {
					dir = 0;
				}
				else {
					dir = 2;
				}
			}
			else if (dir == 2) {
				if (directions[idx].second == 'L') {
					dir = 1;
				}
				else {
					dir = 3;
				}
			}
			else if (dir == 3) {
				if (directions[idx].second == 'L') {
					dir = 2;
				}
				else {
					dir = 0;
				}
			}
			idx++;
		}


		if (dir == 0) {
			if (snake[0].second + 1 >= N) {
				break;
			}
			else if (map[snake[0].first][snake[0].second + 1] == 1) {
				break;
			}
			else if (map[snake[0].first][snake[0].second + 1] == 2) {
				snake.push_front({snake[0].first, snake[0].second + 1});
				map[snake[0].first][snake[0].second] = 1;
			}
			else {
				map[snake[snake.size()-1].first][snake[snake.size()-1].second] = 0;
				snake.pop_back();
				snake.push_front({snake[0].first, snake[0].second + 1});
				map[snake[0].first][snake[0].second] = 1;
			}
		}
		else if (dir == 1) {
			if (snake[0].first + 1 >= N) {
				break;
			}
			else if (map[snake[0].first + 1][snake[0].second] == 1) {
				break;
			}
			else if (map[snake[0].first + 1][snake[0].second] == 2) {
				snake.push_front({snake[0].first + 1, snake[0].second});
				map[snake[0].first][snake[0].second] = 1;
			}
			else {
				map[snake[snake.size()-1].first][snake[snake.size()-1].second] = 0;
				snake.pop_back();
				snake.push_front({snake[0].first + 1, snake[0].second});
				map[snake[0].first][snake[0].second] = 1;
			}
		}
		else if (dir == 2) {
			if (snake[0].second - 1 < 0) {
				break;
			}
			else if (map[snake[0].first][snake[0].second - 1] == 1) {
				break;
			}
			else if (map[snake[0].first][snake[0].second - 1] == 2) {
				snake.push_front({snake[0].first, snake[0].second - 1});
				map[snake[0].first][snake[0].second] = 1;
			}
			else {
				map[snake[snake.size()-1].first][snake[snake.size()-1].second] = 0;
				snake.pop_back();
				snake.push_front({snake[0].first, snake[0].second - 1});
				map[snake[0].first][snake[0].second] = 1;
			}
		}
		else {
			if (snake[0].first - 1 < 0) {
				break;
			}
			else if (map[snake[0].first - 1][snake[0].second] == 1) {
				break;
			}
			else if (map[snake[0].first - 1][snake[0].second] == 2) {
				snake.push_front({snake[0].first - 1, snake[0].second});
				map[snake[0].first][snake[0].second] = 1;
			}
			else {
				map[snake[snake.size()-1].first][snake[snake.size()-1].second] = 0;
				snake.pop_back();
				snake.push_front({snake[0].first - 1, snake[0].second});
				map[snake[0].first][snake[0].second] = 1;
			}
		}
		t++;

		// cout << "t: " << t << '\n';
		// for (int i=0; i<N; i++) {
		// 	for (int j=0; j<N; j++) {
		// 		cout << map[i][j];
		// 	}
		// 	cout << '\n';
		// }
		// cout << '\n';
	}

	cout << t+1 << '\n';

	return 0;
}