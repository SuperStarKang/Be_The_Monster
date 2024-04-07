#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	while (T) {
		int N,M;
		cin >> N >> M;

		int a,b;
		for (int i=0; i<M; i++) {
			cin >> a >> b;
		}

		cout << N-1 << endl;

		T--;
	}
	return 0;
}