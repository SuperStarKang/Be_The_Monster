#include <iostream>

using namespace std;

int op=1;

int main(void) {
	int A,B;
	cin>>A>>B;

	while (B > 0) {
		if (B == A) {
			cout<<op<<endl;
			return 0;
		}
		if (B % 2 == 0)
			B /= 2;
		else if (B % 10 == 1) {
			B /= 10;
		}
		else {
			break;
		}
		op++;
	}

	cout<<-1<<endl;

	return 0;
}
