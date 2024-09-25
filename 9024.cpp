#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int T,N,K;
vector<int> nums;

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> N >> K;

		nums.clear();
		int num;
		for (int i=0; i<N; i++) {
			cin >> num;
			nums.push_back(num);
		}

		sort(nums.begin(), nums.end());

		int left=0,right=N-1;
		int cnt=0,minimum=2147483647;
		while (left < right) {
			int n1=nums[left],n2=nums[right];

			if (n1+n2 > K) {
				right--;
			}
			else {
				left++;
			}

			if (minimum == abs(K - (n1+n2))) {
				cnt++;
			}
			else if (minimum > abs(K - (n1+n2))) {
				minimum = abs(K - (n1+n2));
				cnt = 1;
			}
		}
		cout << cnt << '\n';
	}
	
	return 0;
}