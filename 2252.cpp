#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,M;
int indegree[32001];
vector<int> arr[32001];
bool printed[32001];

void topology_sort() {
	queue<int> q;

	for (int i=1; i<=N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		cout << front << " ";
		printed[front] = true;

		for (int i=0; i<arr[front].size(); i++) {
			int next = arr[front][i];
			indegree[next]--;
			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}
}

int main(void) {
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		int a,b;
		cin >> a >> b;
		arr[a].push_back(b);
		indegree[b]++;
	}

	topology_sort();
	cout << '\n';
	return 0;
}