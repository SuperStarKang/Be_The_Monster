#include <iostream>

using namespace std;

int main(void) {
	long long N,K,result=1;
	cin>>N>>K;

	for (long long i=1; i<=N; i++) {
		result = result * i % 10007;
		cout<<result<<' ';
	}
	result %= 10007;
	cout<<endl;
	for (long long i=1; i<=K; i++) {
		result /= i;
	}
	for (long long i=1; i<=N-K; i++)
		result /= i;
	cout<<result<<endl;
	return 0;
}