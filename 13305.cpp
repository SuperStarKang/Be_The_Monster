#include <iostream>

using namespace std;

long long road[100001];
long long price[100001];

int main(void) {
	long long N;
	cin>>N;

	for (int i=0; i<N-1; i++) {
		cin>>road[i];
	}

	for (int i=0; i<N; i++) {
		cin>>price[i];
	}

	long long result=0;
	long long min_price=price[0];
	long long vertex=0;
	while (vertex < N-1) {
		while (vertex < N-1 && min_price <= price[vertex]) {
			result += min_price * road[vertex];
			vertex++;
		}
		min_price = price[vertex];
	}
	cout<<result<<endl;
	return 0;
}
