#include <iostream>

using namespace std;

int coin[11];
int result;

int main(void) {
	int N,K;
	cin>>N>>K;

	for (int i=0; i<N; i++) {
		cin>>coin[i];
	}

	for (int i=N-1; i>=0; i--) {
		while (K >= coin[i]) {
			K -= coin[i];
			result++;
		}
	}
	cout<<result<<endl;

	return 0;
}