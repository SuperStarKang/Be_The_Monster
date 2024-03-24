// #include <iostream>

// using namespace std;

// int main(void) {
// 	 int E,S,M;
// 	 cin>>E>>S>>M;

// 	int year=1;
// 	while (true) {
// 		if ((year-S) % 28 == 0) {
// 			if ((year-M) % 19 == 0) {
// 					if ((year-E) % 15 == 0) {
// 						cout<<year<<endl;
// 						break;
// 					}
// 			}
// 		}
// 		year++;
// 	}
// 	return 0;
// }

#include <iostream>

using namespace std;

int main(void) {
	 int E,S,M;
	 cin>>E>>S>>M;

	int i=S;
	while (true) {
		if ((i-1) % 28 + 1 == S) {
			if ((i-1) % 19 + 1 == M) {
				if ((i-1)% 15 + 1 == E) {
					cout<<i<<endl;
					break;
				}
			}
		}
		i += 28;
	}
	return 0;
}
