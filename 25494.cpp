#include <iostream>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	while (T-- > 0) {
		int a,b,c;
		int cnt=0;
		cin >> a >> b >> c;

		for (int i=1; i<=a; i++) {
			for (int j=1; j<=b; j++) {
				for (int k=1; k<=c; k++) {
					if ((i % j == j % k) && (i % j == k % i) && (j % k == k % i)) {
						cnt++;
					}
				}
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}