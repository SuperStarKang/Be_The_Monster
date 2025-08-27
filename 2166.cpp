#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

double N;
double x, y, ans;
vector<pair<double, double>> v;

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back({x, y});
	}

	// v[0]을 기준으로 삼각형 넓이 구하기
	for (int i = 1; i < N - 1; i++) {
		double area = ((v[0].first * v[i].second + v[i].first * v[i + 1].second + v[i + 1].first * v[0].second) -
					   (v[0].second * v[i].first + v[i].second * v[i + 1].first + v[i + 1].second * v[0].first));
		ans += area;
	}
	ans = abs(ans) / 2.0;
	cout << fixed << setprecision(1) << ans << "\n";
	return 0;
}