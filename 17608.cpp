#include <iostream>

using namespace std;

int N;
int sticks[100001];

int main(void) {
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> sticks[i];
	}

	int stick=sticks[N-1];
	int ans=1;
	for (int i=N-2; i>=0; i--) {
		if (sticks[i] > stick) {
			ans++;
			stick = sticks[i];
		}
	}

	cout << ans << '\n';
	return 0;
}