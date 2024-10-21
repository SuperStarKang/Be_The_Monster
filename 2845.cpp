#include <iostream>

using namespace std;

int L,P;
int num[5];

int main(void) {
	cin >> L >> P;
	int participants = P*L;

	for (int i=0; i<5; i++) {
		cin >> num[i];
	}
	for (int i=0; i<5; i++) {
		cout << num[i] - participants << ' ';
	}
	cout << '\n';

	return 0;
}