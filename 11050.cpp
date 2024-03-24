#include <iostream>

using namespace std;

int main(void) {
	long long N,K,result=1;
	cin>>N>>K;

	for (int i=N; i>N-K; i--) {
		result *= i;
	}
	for (int i=1; i<=K; i++)
		result /= i;
	cout<<result<<endl;
	return 0;
}
