#include <iostream>

using namespace std;

int main(void) {
	long long S;
	cin >> S;

	long long N=0,i=1;
	while (S > 0) {
		if (S < i) {
			break;
		}
		S -= i;
		i++;
		N++;
	}

	cout << N << '\n';
	return 0;
}