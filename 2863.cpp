#include <iostream>

using namespace std;

double arr[2][2];

int main(void) {
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			cin >> arr[i][j];
		}
	}

	double max_sum=0;
	int rotation=0,ans=0;
	for (int i=0; i<4; i++) {
		double sum = arr[0][0]/arr[1][0] + arr[0][1]/arr[1][1];
		if (max_sum < sum) {
			max_sum = sum;
			ans = rotation;
		}

		double tmp = arr[0][1];
		arr[0][1] = arr[0][0];

		double tmp2 = arr[1][1];
		arr[1][1] = tmp;

		tmp = arr[1][0];
		arr[1][0] = tmp2;

		arr[0][0] = tmp;

		rotation++;
	}

	cout << ans << '\n';

	return 0;
}