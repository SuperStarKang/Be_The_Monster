#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int card[500001];
vector<int> ans;

int binary_search(int find) {
	int left = 0,right = N-1;
	while (left <= right) {
		int mid = (left+right)/2;

		if (card[mid] == find) {
			return 1;
		}

		if (card[mid] > find) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return 0;
}

int main(void) {
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> card[i];
	}

	sort(card, card+N);

	cin >> M;
	int find;
	for (int i=0; i<M; i++) {
		cin >> find;

		if (binary_search(find)) {
			ans.push_back(1);
		}
		else {
			ans.push_back(0);
		}
	}

	for (int i=0; i<ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;
}