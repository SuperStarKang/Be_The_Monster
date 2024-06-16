#include <iostream>

using namespace std;

string answer;
string map[101];
bool start,flag;

int main(void) {
	int N,M;
	cin >> N >> M;

	int first,last;
	for (int i=0; i<N; i++) {
		cin >> map[i];

		if (flag == 1) {
			continue;
		}

		size_t pos = map[i].find('#');
		if (pos == string::npos) {
			continue;
		}
		size_t rpos = map[i].rfind('#');

		if (start == 0) {
			first = pos;
			last = rpos;
			for (size_t j=pos; j<=rpos; j++) {
				if (map[i][j] == '.') {
					answer = "UP";
					flag = 1;
				}
			}
		}

		if (flag == 0 && map[i][first] == '.') {
			answer = "LEFT";
			flag = 1;
		}

		if (flag == 0 && map[i][last] == '.') {
			answer = "RIGHT";
			flag = 1;
		}

		start = 1;
	}
	if (flag == 1){
		cout << answer << endl;
	}
	else{
		cout << "DOWN" << endl;
	}
	return 0;
}