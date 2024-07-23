#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
double dp[10001];
vector<double> numbers;

int main(void) {
	cin >> N;
	double num;
	for (int i=0; i<N; i++) {
		cin >> num;
		numbers.push_back(num);	
	}

	dp[0] = numbers[0];

	for (int i=1; i<N; i++) {
		if (dp[i-1] * numbers[i] > numbers[i]) {
			dp[i] = numbers[i] * dp[i-1];
		}
		else {
			dp[i] = numbers[i];
		}
	}

	double result = 0.0;
	for (int i=0; i<N; i++) {
		if (dp[i] > result) {
			result = dp[i];
		}
	}
	printf("%.3f\n", result);
	return 0;
}