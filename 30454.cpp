#include <iostream>

using namespace std;

int N,L,ans;
string arr[1001];

int main(void) {
	cin >> N >> L;

	int max_stripe=0,stripe;
	for (int i=0; i<N; i++) {
		cin >> arr[i];

		stripe=0;
		bool flag = false;
		for (int j=0; j<arr[i].size(); j++) {
			if (!flag && arr[i][j] == '1') {
				flag = true;
				stripe++;
			}
			if (arr[i][j] == '0') {
				flag = false;
			}
		}
		if (max_stripe < stripe) {
			ans = 1;
			max_stripe = stripe;
		}
		else if (max_stripe == stripe) {
			ans++;
		}
	}

	cout << max_stripe << ' ' << ans << '\n';

	return 0;
}