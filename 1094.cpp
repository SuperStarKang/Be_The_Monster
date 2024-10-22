#include <iostream>

using namespace std;

int X;

int main(void) {
	cin >> X;

	int ans=0;
	while (X>0) {
		if (X % 2) {
			ans++;
		}
		X /= 2;
	}
	cout << ans << '\n';

	return 0;
}