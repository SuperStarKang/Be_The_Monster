#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
string Amatrix[51];
string Bmatrix[51];

vector<int> compare() {
	vector<int> list;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (Amatrix[i][j] != Bmatrix[i][j]) {
				list.push_back(i);
				list.push_back(j);
			}
		}
	}
	return list;
}

int main(void) {
	cin >> N >> M;

	for (int i=0; i<N; i++) {
		cin >> Amatrix[i];
	}
	for (int i=0; i<N; i++) {
		cin >> Bmatrix[i];
	}

	int cnt=0;
	while (true) {
		vector<int> list = compare();
		if (list.empty()) {
			cout << cnt << '\n';
			break;
		}

		if (list[0] + 2 >= N || list[1] + 2 >= M) {
			cout << -1 << '\n';
			break;
		}  

		for (int i=list[0]; i<list[0]+3; i++) {
			for (int j=list[1]; j<list[1]+3; j++) {
				if (Amatrix[i][j] == '0') {
					Amatrix[i][j] = '1';
				}
				else {
					Amatrix[i][j] = '0';
				}
			}
		}
		cnt++;
	}
	return 0;
}