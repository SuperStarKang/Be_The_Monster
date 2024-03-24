#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int find_max(int q[], int first, int N) {
	int max=0;
	for (int i=first; i<N; i++) {
		if (q[i] > max)
			max = q[i];
	}
	return max;
}

int main(void) {
	int t;
	cin>>t;

	for (int i=0; i<t; i++) {
		int N,M;
		cin>>N>>M;

		int ans=0;

		queue<pair<int, int> > q;
		priority_queue<int> pq;

		int n;
		for (int j=0; j<N; j++) {
			cin>>n;
			q.push({j, n});
			pq.push(n);
		}

		while (!(q.empty())) {
			int idx = q.front().first;
			int priority = q.front().second;
			q.pop();

			if (pq.top() == priority) {
				pq.pop();
				ans++;
				if (idx == M) {
					cout<<ans<<endl;
					break;
				}
			}
			else {
				q.push({idx, priority});
			}
		}
	}
	return 0;
}
