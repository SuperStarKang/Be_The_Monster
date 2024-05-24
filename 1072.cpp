#include <iostream>
#include <cmath>

using namespace std;

long long X,Y;

int main(void) {
	cin >> X >> Y;
	long long rate = Y*100 / X;

	if (rate >= 99) {
		cout << -1 << '\n';
		return 0;
	}

	int left=0,right=1000000000;
	while (left <= right) {
		long long mid = (left+right)/2;
		long long change_rate = (Y+mid)*100 / (X+mid);

		if (rate < change_rate) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << left << '\n';
	return 0;
}