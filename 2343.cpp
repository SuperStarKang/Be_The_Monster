#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int lecture[100001];

int main(void) {
	cin >> N >> M;

	long long left=0, right=0;
	for (int i=0; i<N; i++) {
		cin >> lecture[i];
		if (left < lecture[i])
			left = lecture[i];
		right += lecture[i];
	}

	long long sum=0;
	int cnt=0;
	while (left <= right) {
		long long mid = (left+right)/2;

		sum = 0;
		cnt = 0;
		for (int i=0; i<N; i++) {
			if (mid < sum + lecture[i]) {
				cnt++;
				sum = 0;
			}
			sum += lecture[i];
		}
		if (sum != 0) {
			cnt++;
		}

		if (cnt > M) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << left << '\n';
	return 0;
}