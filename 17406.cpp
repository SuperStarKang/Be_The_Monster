#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,K;
int arr[51][51];
int temp[51][51];
int rotation[10][3];
bool visited[10];
vector<int> current;
vector<vector<int>> permutations;

void generatePermutations(int k) {
    if (current.size() == k) {
        permutations.push_back(current);
        return;
    }

    for (int i = 0; i < k; i++) {
        if (!visited[i]) {
            visited[i] = true;
            current.push_back(i);
            generatePermutations(k);
            current.pop_back();
            visited[i] = false;
        }
    }
}

void rotate(int start_x, int start_y, int dis) {
	int up_right=temp[start_y][start_x + dis];
	for (int i=dis; i>0; i--) {
		temp[start_y][start_x + i] = temp[start_y][start_x + i - 1];
	}
	
	int down_right = temp[start_y + dis][start_x + dis];
	for (int i=dis; i>0; i--) {
		temp[start_y + i][start_x + dis] = temp[start_y + i - 1][start_x + dis];
	}
	temp[start_y + 1][start_x + dis] = up_right;

	int down_left = temp[start_y+dis][start_x];
	for (int i=1; i<=dis; i++) {
		temp[start_y + dis][start_x + i - 1] = temp[start_y + dis][start_x + i];
	}
	temp[start_y+dis][start_x+dis-1] = down_right;

	for (int i=1; i<=dis; i++) {
		temp[start_y + i - 1][start_x] = temp[start_y + i][start_x];
	}
	temp[start_y+dis-1][start_x] = down_left;
}

void copy_arr() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			temp[i][j] = arr[i][j];
		}
	}
}

int main(void) {
	cin >> N >> M >> K;

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			cin>>arr[i][j];
		}
	}

	for (int i=0; i<K; i++) {
		for (int j=0; j<3; j++) {
			cin >> rotation[i][j];
		}
	}

    generatePermutations(K);

	int ans=2147483647;
	for (int i=0; i<permutations.size(); i++) {
		copy_arr();

		for (int j=0; j<permutations[i].size(); j++) {
			int idx = permutations[i][j];

			int dis=2*rotation[idx][2];
			int start_y=rotation[idx][0]-rotation[idx][2]-1, start_x=rotation[idx][1]-rotation[idx][2]-1;
			for (int k=0; k<dis/2; k++) {
				rotate(start_x + k, start_y + k, dis - 2*k);
			}
		}
		int line;
		for (int i=0; i<N; i++) {
			line=0;
			for (int j=0; j<M; j++) {
				line += temp[i][j];
			}
			ans = min(ans, line);
		}
	}

	cout << ans << '\n';

	return 0;
}
