#include <iostream>
#include <vector>

using namespace std;

int N,ans;
int arr[10];

int main(void) {
	cin >> N;

	while (N > 0) {
		arr[N%10]++;
		N /= 10;
	}

	int six_nine_cnt = (arr[6] + arr[9] + 1)/2;
	arr[6] = six_nine_cnt;
	arr[9] = six_nine_cnt;

	for (int i=0; i<10; i++) {
		if (ans < arr[i]) {
			ans = arr[i];
		}
	}

	cout << ans << '\n';
	return 0;
}