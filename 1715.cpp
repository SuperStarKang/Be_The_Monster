#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;
int sum[100001];

int main(void) {
	cin >> N;

	int num;
	for (int i=0; i<N; i++) {
		cin >> num;
		pq.push(num);
	}

	int i=0;
	while (!pq.empty()) {
		sum[i] += pq.top();
		pq.pop();
		if (pq.size() > 0) {
			sum[i] += pq.top();
			pq.pop();
			pq.push(sum[i]);
		}
		i++;
	}

	int result=0;
	for (int idx=0; idx<i-1; idx++) {
		// cout << sum[idx] << " ";
		result += sum[idx];
	}
	cout<<result<<endl;
	return 0;
}