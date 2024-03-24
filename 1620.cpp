#include <iostream>
#include <cstring>
#include <map>

using namespace std;

char list[100001][21];
char question[5][21];

int main(void) {
	int N,M;
	cin>>N>>M;

	map<string, int> m;
	string name;
	for (int i=0; i<N; i++) {
		cin>>name;
		m.insert({name, i+1});
	}






	// int idx=0;
	// for (idx=0; idx<N; idx++) {
	// 	cin>>list[idx];
	// }
	// char name[21];
	// for (int i=0; i<M; i++) {
	// 	cin>>name;
	// 	if (name[0] >= '0' && name[0] <= '9') {
	// 		int num = 0;
	// 		for (int i=strlen(name)-1; i>=0; i--) {
	// 			num = num * 10 + name[i] - '0';
	// 		}
	// 		cout<<list[num-1]<<endl;
	// 	}
	// 	else {
	// 		int cnt=0;
	// 		for (int i=0; i<N; i++) {
	// 			cnt++;
	// 			if (!strcmp(name, list[i])) {
	// 				cout<<cnt<<endl;
	// 				break;
	// 			}
	// 		}
	// 	}
	// }
	return 0;
}