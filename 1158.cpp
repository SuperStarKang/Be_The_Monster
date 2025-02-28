#include <iostream>
#include <queue>

using namespace std;

int N,K;
queue<int> q;
int ans[5001];

int main(void) {
	cin >> N >> K;

	for (int i=1; i<=N; i++) {
		q.push(i);
	}

	int idx=0;
	while (!q.empty()) {
		for (int i=0; i<K-1; i++) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		ans[idx++] = q.front();
		q.pop();
	}

	cout << "<";
	for (int i=0; i<N; i++) {
		cout << ans[i];
		if (i < N-1){
			cout << ", ";
		}
	}
	cout << ">\n";

	return 0;
}