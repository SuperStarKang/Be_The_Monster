#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int card[500001];
vector<int> ans;

int binary_search(int find) {
	int flag=0;
	int cnt=0;
	int left = 0,right = N-1;
	int mid;
	int ll=10000001,rr=0;
	while (left <= right) {
		mid = (left+right)/2;

		if (card[mid] == find) {
			ll = min(ll,mid);
			rr = max(rr,mid);
			flag=1;
		}

		if (card[mid] > find) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	if (flag)
		return rr-ll+1;
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
		// ans.push_back(binary_search(find));
		ans.push_back(upper_bound(card,card+N,find) - lower_bound(card,card+N,find));
	}

	for (int i=0; i<ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;
}