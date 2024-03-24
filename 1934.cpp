#include <iostream>

using namespace std;

int	gcd(int A, int B) {
	if (A % B == 0)
		return B;
	else
		return gcd(B, A%B);
}

int main(void) {
	int T;
	cin>>T;

	int A,B;
	int n;
	for (int i=0; i<T; i++) {
		cin>>A>>B;
		if (A > B)
			n = gcd(A,B);
		else
			n = gcd(B,A);
		cout<<A*B/n<<endl;
	}

	return 0;
}