#include <iostream>

using namespace std;

int N,M,K;

int main(void) {
	cin >> N >> M >> K;

	int pa = M/N;

	cout << pa * K << '\n';

	return 0;
}