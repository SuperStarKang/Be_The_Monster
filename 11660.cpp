#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int x1,x2,y1,y2;
int matrix[1025][1025];

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			cin >> matrix[i][j];
			matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
		}
	}
	for (int i=0; i<M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << matrix[x2][y2] - (matrix[x2][y1-1]+matrix[x1-1][y2] - matrix[x1-1][y1-1]) << '\n';
	}

	return 0;
}