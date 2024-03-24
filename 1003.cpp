#include <iostream>

using namespace std;

int main(void) {
	int T;
	cin>>T;

	int N;
	for (int i=0; i<T; i++) {
		cin>>N;
		int a_0[N+1];
		a_0[0] = 1;
		a_0[1] = 0;
		a_0[2] = 1;
		a_0[3] = 1;
		int a_1[N+1];
		a_1[0] = 0;
		a_1[1] = 1;
		a_1[2] = 1;
		for (int j=3; j<=N; j++) {
			a_1[j] = a_1[j-1] + a_1[j-2];
		}
		for (int j=4; j<=N; j++) {
			a_0[j] = a_0[j-1] + a_0[j-2];
		}
		cout<<a_0[N]<<' '<<a_1[N]<<endl;
	}
	return 0;
}