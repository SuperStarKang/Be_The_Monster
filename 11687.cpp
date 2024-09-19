#include <iostream>

using namespace std;

int M,cnt;

int main(void) {
	cin >> M;

	int left=1,right=M*5;
	while (left <= right) {
		int mid = (right+left)/2;

		cnt=0;
		for (int i=5; i<=mid; i*=5) {
			cnt += mid / i;
		}

		if (cnt >= M) {
			right = mid-1;
		}
		else {
			left = mid+1;
		}
	}

	cnt=0;
	for (int i=5; i<=left; i*=5) {
		cnt += left / i;
	}

	if (cnt == M) {
		cout << left << '\n';
	}
	else {
		cout << -1 << '\n';
	}
	return 0;
}