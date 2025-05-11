#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> v;

int main(void) {
	cin >> N;

	int a,b;
	for (int i=0; i<N; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}
	
	int time=0,cnt=0;
	while (cnt < N) {
		if (!(time % (v[cnt].first + v[cnt].second) < v[cnt].second)) {
			cnt++;
		}
		time += 1;
	}
	cout << time << '\n';
	return 0;
}