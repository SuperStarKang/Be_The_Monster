#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main(void) {
	int N;
	cin>>N;

	int cnt=0;
	int num=666;
	string str;
	while (true) {
		str = to_string(num);
		if (str.find("666") != string::npos) {
			cnt++;
		}
		if (cnt == N) {
			cout<<num<<endl;
			break;
		}
		num++;
	}
	return 0;
}