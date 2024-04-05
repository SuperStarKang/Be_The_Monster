#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	vector<pair<int, int>> v;

	for (int t=0; t<T; t++) {
		int N;
		cin>>N;

		int ans=1;

		v.clear();
		int score1,score2;
		for (int i=0; i<N; i++) {
			cin>>score1>>score2;
			v.push_back({score1, score2});
		}
		sort(v.begin(), v.end());

		int nxt=0;
		for (int i=1; i<N; i++) {
			if (v[nxt].second > v[i].second) {
				ans++;
				nxt = i;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
