#include <iostream>
#include <vector>

using namespace std;

int T,N,result;
vector<int> nums;
char ops[10];
char list[3] = {' ', '+', '-'};

void make_ops(int N, int depth) {
	if (depth == N-1) {
		nums.clear();
		int i=0;
		while (i < N) {
			if (i<N-1 && ops[i] == ' ') {
				nums.push_back(10*(i+1) + (i+2));
				i += 1;
			}
			else {
				nums.push_back(i+1);
			}
			i++;
		}

		int j=0;
		result = nums[j];
		for (int i=0; i<N-1; i++) {
			if (ops[i] == '-') {
				result -= (nums[j+1]);
				j++;
			}
			else if (ops[i] == '+') {
				result += (nums[j+1]);
				j++;
			}
		}

		if (result == 0) {
			for (int i=0; i<N; i++) {
				cout << i+1;
				if (i < N-1) {
					cout << ops[i];
				}
			}
			cout << "\n";
		}

		return;
	}

	for (int i=0; i<3; i++) {
		ops[depth] = list[i];

		if (depth > 0 && ops[depth] == ' ' && ops[depth-1] == ' ') {
            continue;
        }

		make_ops(N,depth+1);
	}
}

int main(void) {
	cin >> T;


	while (T--) {
		cin >> N;

		make_ops(N,0);
		cout << '\n';
	}


	return 0;
}