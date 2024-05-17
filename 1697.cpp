#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N,K;
int cnt;
queue<int> q;
int step[100001];
bool visited[100001];

int main(void) {
	cin >> N >> K;

	visited[N] = true;
	q.push(N);
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == K) {
			cout << step[x] << endl;
			break;
		}

		if (x < 100001 && !visited[x+1]) {
			visited[x+1] = true;
			q.push(x+1);
			step[x+1] = step[x] + 1;
		}

		if (x > 0 && !visited[x-1]) {
			visited[x-1] = true;
			q.push(x-1);
			step[x-1] = step[x] + 1;
		}

		if (2*x < 100001 && !visited[2*x]) {
			visited[2*x] = true;
			q.push(2*x);
			step[2*x] = step[x] + 1;
		}
	}
	return 0;
}