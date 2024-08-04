#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int parent[10001];
bool visited[10001];

int main(void) {
	cin >> T;

	int N;
	while (T--) {
		cin >> N;

		int v1,v2;
		for (int i=0; i<N-1; i++) {
			cin >> v1 >> v2;
			parent[v2] = v1;
		}
		
		cin >> v1 >> v2;

		int p = v1;
		while (p) {
			visited[p] = true;
			p = parent[p];
		}

		p = v2;
		while (true) {
			if (visited[p]) {
				cout << p << '\n';
				break;
			}
			p = parent[p];
		}

		for (int i=0; i<10001; i++) {
			parent[i] = 0;
			visited[i] = false;
		}
	}


	return 0;
}