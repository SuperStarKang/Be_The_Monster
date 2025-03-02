#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, ans=2147483647;
vector<int> tmp;
vector<int> arr;

int main(void) {
	cin >> N;

	int n;
	for (int i=0; i<N; i++) {
		cin >> n;
		arr.push_back(n);
	}

	sort(arr.begin(), arr.end());

	for (int i=0; i<N; i++) {
		int cnt=5;
		tmp.clear();

		for (int j=0; j<=4 && j < N; j++) {
			tmp.push_back(arr[i]+j);
		}

		for (int j=0; j<=4 && j < N; j++) {
			if (find(tmp.begin(), tmp.end(), arr[i+j]) != tmp.end()) {
				cnt--;
			}
		}

		if (cnt < ans) {
			ans = cnt;
		}
	}

	cout << ans << '\n';
	return 0;
}