// #include <iostream>
// #include <algorithm>

// using namespace std;

// int arr[500001];

// int main(void) {
// 	string num;
// 	int N,K;

// 	cin >> N >> K;
// 	cin >> num;

// 	for (int i=0; i<N; i++) {
// 		arr[i] = num[i] - '0';
// 	}

// 	int i=1;
// 	int remove=0;
// 	while (i < N && remove < K) {
// 		int j=i-1;
// 		while (remove < K && j >= 0) {
// 			if (arr[j] == -1)
// 				break;
// 			if (arr[j] < arr[i]) {
// 				arr[j] = -1;
// 				remove++;
// 			}
// 			j--;
// 		}
// 		i++;
// 	}

// 	int cnt=0;
// 	for (int i=0; cnt<N-K; i++) {
// 		if (arr[i] != -1) {
// 			cout << arr[i];
// 			cnt++;
// 		}
// 	}
// 	cout << endl;
// 	return 0;
// }


#include <iostream>
#include <string>
#include <deque>
using namespace std;

int n,k;
string num;

deque <int> dq;
int main() {
	cin >> n >> k;
	cin >> num;

	for (int i = 0; i < num.length(); i++) {
		while (k && !dq.empty() && dq.back() < num[i]) {
			dq.pop_back();
			k--;
		}
		dq.push_back(num[i]);
	}


	for (int i = 0; i < dq.size() - k; i++) 
		cout << dq[i]-'0';
	
	cout << endl;

	return 0;
}