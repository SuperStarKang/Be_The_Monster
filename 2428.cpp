#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long ans;
vector<long long> sizes;

int main(void) {
	cin >> N;
	long long size;

	for (int i=0; i<N; i++) {
		cin >> size;
		sizes.push_back(size);
	}
	sort(sizes.begin(), sizes.end());

	int left,mid,right,j;
	for (int i=0; i<N-1; i++) {
		left = i;
		right = N-1;
		j = i;

		while (left <= right) {
			mid = (left+right)/2;
			if (sizes[i] >= sizes[mid]*0.9) {
				j = max(j,mid);
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		ans += j-i;
	}

	cout << ans << '\n';
	return 0;
}