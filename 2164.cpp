#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> q;

int main(void) {
	cin >> N;

	for (int i=1; i<=N; i++) {
		q.push(i);
	}

	int cnt=0;
	while (q.size() != 1) {
		if (cnt % 2) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		else {
			q.pop();
		}
		cnt++;
	}

	cout << q.front() << '\n';
	return 0;
}