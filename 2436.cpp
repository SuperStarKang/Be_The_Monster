#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd,lcm;
int n1,n2;
vector<pair<int,int>> v;

int find_gcd(int n1, int n2) {
    if (n1 % n2 == 0)
        return n2;
    else
        return find_gcd(n2, n1 % n2);
}

int find_lcm(int n1, int n2) {
    return n1 * n2 / find_gcd(n1,n2);
}

int main(void) {
	cin >> gcd >> lcm;

	int k = lcm/gcd;

	for (int i=1; i<=sqrt(k); i++) {
		if (k % i == 0) {
			int j = k / i;

			if (find_gcd(i,j) == 1) {
				n1 = i * gcd;
				n2 = j * gcd;
			}
		}
	}
	cout << n1 << ' ' << n2 << '\n';
	return 0;
}