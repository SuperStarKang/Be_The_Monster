#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,w,L;
int ans=1;
int times[100001];
vector<int> v;

int main(void) {
	cin >> n >> w >> L;
	int truck;
	for (int i=0; i<n; i++) {
		cin >> truck;
		v.push_back(truck);
	}

	queue<int> trucks;
	int weights=0;

	int idx=0;
	while (times[n-1] < w) {
		bool flag=false;
		if (idx < n && !flag && trucks.size() < w && weights + v[idx] <= L) {
			weights += v[idx];
			trucks.push(idx);
			idx++;
			flag = true;
		}

		queue<int> que = trucks;
		while (!que.empty()) {
			int j=que.front();
			que.pop();
			times[j]++;

			if (times[j] > w) {
				weights -= v[trucks.front()];
				trucks.pop();
				if (idx < n && !flag && trucks.size() < w && weights + v[idx] <= L) {
					weights += v[idx];
					trucks.push(idx);
					times[idx]++;
					idx++;
					flag = true;
				}
			}
		}
		ans++;
	}

	cout << ans << '\n';

	return 0;
}