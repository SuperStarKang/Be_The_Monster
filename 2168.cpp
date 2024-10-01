#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int x,y;
int ans=0;

int gcd() {
	int a=x,b=y;
	while (b != 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

int main(void) {
	cin >> x >> y;

	int n = gcd();
	cout << x + y - n << '\n';

	return 0;
}