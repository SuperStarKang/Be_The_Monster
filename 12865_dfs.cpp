#include <iostream>

using namespace std;

#define MAX_N 100
#define MAX_WEIGHT 100000

int N, K;
int weights[MAX_N], values[MAX_N];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int idx, int weight) {
    if (idx == N || weight <= 0) // 기저 사례: 모든 물건을 고려했거나 배낭의 무게가 0 이하일 때
        return 0;

    // 현재 물건을 배낭에 넣지 않는 경우와 넣는 경우 중 더 큰 가치를 선택
    int not_include = knapsack(idx + 1, weight);
    int include = 0;
    if (weight - weights[idx] >= 0)
        include = values[idx] + knapsack(idx + 1, weight - weights[idx]);

    return max(not_include, include);
}

int main() {
    cin>>N>>K;
    for (int i = 0; i < N; ++i) {
		cin>>weights[i]>>values[i];
    }

	cout<<knapsack(0,K)<<endl;

    return 0;
}
