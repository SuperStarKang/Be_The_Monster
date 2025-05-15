#include <iostream>
#include <cmath>

using namespace std;

// 방법1: 이분 탐색
unsigned long long T,N;

int main(void) {
	cin >> T;

	for (int i=0; i<T; i++) {
		cin >> N;

		unsigned long long ans=0,left=0,mid,right=1e9;

		while (left<=right) {
			mid=(left+right)/2;

			if (mid*(mid+1)/2<=N) {
				ans=mid;
				left=mid+1;
			} else {
				right=mid-1;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}

// 방법2: 근의 공식 이용
long long T,N,ans;

int main(void) {
	cin >> T;

	for (int i=0; i<T; i++) {
		cin >> N;

		ans = (sqrt(1+8*N)-1)/2;
		cout << ans << '\n';
	}

	return 0;
}