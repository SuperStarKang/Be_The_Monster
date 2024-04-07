#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> list;
	priority_queue<int, vector<int>, greater<int>> pq;
	int start, end;
	for (int i = 0; i < N; i++) {
		cin>>start>>end;
		list.push_back({start, end});
	}

	sort(list.begin(), list.end());

	for (int i=0; i<list.size(); i++) {
		pq.push(list[i].second);
		if (pq.top() <= list[i].first)
			pq.pop();
	}
	cout<<pq.size()<<endl;
	return 0;
}