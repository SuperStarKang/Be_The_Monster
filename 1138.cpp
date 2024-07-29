#include <iostream>
#include <algorithm>

using namespace std;

int N;
int result[11];

int main(void) {
	cin >> N;

	int num;
	for (int i=0; i<N; i++) {
		cin >> num;

		int cnt=0;
		for (int j=0; j<N; j++) {
			if (result[j] == 0) {
				if (cnt == num) {
					result[j] = i+1;
					break;
				}
				else {
					cnt++;
				}
			}
		}
	}

	for (int k=0; k<N; k++) {
		cout << result[k] << ' ';
	}
	cout << '\n';
	return 0;
}