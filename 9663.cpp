#include <iostream>

using namespace std;

int board[15][15];
int cnt;

int check(int x, int y, int N) {
	for (int i=0; i<N; i++) {
		if (i != y && board[i][x] == 1)
			return 1;
	}
	for (int i=0; i<N; i++) {
		if (i != x && board[y][i] == 1)
			return 1;
	}
	int i=x,j=y;
	while (i > 0 && j > 0) {
		if (board[j-1][i-1] == 1)
			return 1;
		i--;
		j--;
	}
	i=x,j=y;
	while (i < N && j < N) {
		if (board[j+1][i+1] == 1)
			return 1;
		i++;
		j++;
	}
	i=x,j=y;
	while (i < N && j > 0) {
		if (board[j-1][i+1] == 1)
			return 1;
		i++;
		j--;
	}
	i=x,j=y;
	while (i > 0 && j < N) {
		if (board[j+1][i-1] == 1)
			return 1;
		i--;
		j++;
	}
	return 0;
}

void	dfs(int depth, int N) {
	if (depth == N) {
		cnt++;
		return ;
	}

	for (int j=0; j<N; j++) {
		board[depth][j] = 1;
		if (check(j, depth, N)) {
			board[depth][j] = 0;
		}
		else {
			dfs(depth+1, N);
			board[depth][j] = 0;
		}
	}
}

int main(void) {
	int N;
	cin>>N;

	dfs(0, N);
	cout<<cnt<<endl;
	return 0;
}
