#include <iostream>

using namespace std;

int map[501][501];
int dp[501][501];

int	dfs(int height, int width, int x, int y) {

	if (y == height-1 & x == width-1) {
		return 1;
	}

	if (dp[y][x] != -1) {
		return dp[y][x];
	}

	dp[y][x] = 0;
	if (x < width && map[y][x] > map[y][x+1])
		dp[y][x] += dfs(height, width, x+1, y);
	if (x > 0 && map[y][x] > map[y][x-1])
		dp[y][x] += dfs(height, width, x-1, y);
	if (y < height && map[y][x] > map[y+1][x])
		dp[y][x] += dfs(height, width, x, y+1);
	if (y > 0 && map[y][x] > map[y-1][x])
		dp[y][x] += dfs(height, width, x, y-1);

	return dp[y][x];
}

int main(void) {
	int y,x;
	cin>>y>>x;

	for (int i=0; i<y; i++) {
		for (int j=0; j<x; j++) {
			cin>>map[i][j];
			dp[i][j] = -1;
		}
	}

	cout<<dfs(y,x,0,0)<<endl;

	// for (int i=0; i<y; i++) {
	// 	for (int j=0; j<x; j++)
	// 		cout<<dp[i][j]<<' ';
	// 	cout<<endl;
	// }

	return 0;
}
