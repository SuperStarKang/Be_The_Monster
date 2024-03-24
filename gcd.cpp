#include <iostream>

using namespace std;

int gcd(int n, int m) {
	if (n % m == 0)
		return m;
	else
		return gcd(m, n%m);
}

int main(void) {
	int n,m;
	cin>>n>>m;

	cout<<gcd(n,m)<<endl;

	return 0;
}