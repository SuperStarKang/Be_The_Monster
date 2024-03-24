#include <iostream>

using namespace std;

int ans;

int	gcd(int n, int m) {
	if (n % m == 0) {
		ans++;
		return m;
	}
	else
		return gcd(m, n%m);
}

int main(void) {
	int n;
	cin>>n;

	for (int i=1; i<n; i++)
		gcd(n, n-1);
	if (n == 1)
		cout<<1<<endl;
	else
		cout<<ans<<endl;
	return 0;
 }