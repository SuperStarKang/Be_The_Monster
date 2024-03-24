#include <iostream>
#include <cmath>

using namespace std;

int	find_gcd(int a, int b) {
	if (a%b == 0)
		return b;
	else
		return find_gcd(b, a%b);
}

int main(void) {
	int T;
	cin>>T;

	int M,N,x,y;
	int gcd,lcm;
	int year=1;
	for (int i=0; i<T; i++) {
		cin>>M>>N>>x>>y;

		if (N > M)
			gcd = find_gcd(N,M);
		else
			gcd = find_gcd(M,N);
		lcm = N*M/gcd;
		for (year = x; year <= N*M/gcd; year += M) {
			if ((year-x) % M == 0 && (year-y) % N == 0) {
				cout<<year<<endl;
				break ;
			}
		}
		if (year > lcm)
			cout<<-1<<endl;
	}
	return 0;
}

// int main(void) {
// 	int T;
// 	cin>>T;

// 	int M,N,x,y;
// 	int gcd;
// 	int year=1;
// 	int l;
// 	for (int i=0; i<T; i++) {
// 		cin>>M>>N>>x>>y;

// 		l = 0;
// 		if () {
// 			cout<<-1<<endl;
// 		}
// 		else {
// 			for (int j = 1; ; j++) {
// 				if ((N*j + (y-x)) % M == 0) {
// 					l = j;
// 					break ;
// 				}
// 			}
// 			cout<<y+N*l<<endl;
// 		}
// 	}
// 	return 0;
// }