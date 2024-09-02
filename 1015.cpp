#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int,int>> v;
int order[51];

int main(void) {
	int x;

	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> x;
		v.push_back({x,i});
	}

	sort(v.begin(), v.end());

	for (int i=0; i<N; i++) {
		order[v[i].second] = i;
	}
	for (int i=0; i<N; i++) {
		cout << order[i] << ' ';
	}
	cout << '\n';

	return 0;
}
