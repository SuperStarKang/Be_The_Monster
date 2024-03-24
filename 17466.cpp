#include <iostream>

using namespace std;

int main(void) {
	long long N,P;
	cin>>N>>P;

	long long result = 1;
	for (long long i=1; i<=N; i++) {
		result = (result * i) % P;
	}
	cout<<result<<endl;
	return 0;
}