#include <iostream>

using namespace std;

int N;
double arr[101];

int main(void) {
	cin >> N;

	double sum=0;
	for (int i=0; i<N; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	if (N == 0 || sum == 0) {
		cout << "divide by zero\n";
		return 0;
	}

	cout << "1.00\n";

	return 0;
}