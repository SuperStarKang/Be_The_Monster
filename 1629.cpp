// #include <iostream>

// using namespace std;

// int arr[10];

// int	check_double(int arr[], int idx) {
// 	for (int i=0; i<idx; i++) {
// 		if (arr[idx] == arr[i])
// 			return (idx-i);
// 	}
// 	return 0;
// }

// int main(void) {
// 	int A,B,C;
// 	cin>>A>>B>>C;

// 	int tmp = A;
// 	int i=1;
// 	int cnt;
// 	arr[0] = A % C;
// 	while (i <= B) {
// 		A = A * tmp % C;
// 		arr[i] = A;
// 		cnt = check_double(arr, i);
// 		if (cnt)
// 			break ;
// 		i++;
// 	}
// 	cout<<"i : "<<i<<' '<<"cnt : "<<cnt<<endl;
// 	if (cnt == 1)
// 		cout<<arr[i]<<endl;
// 	else
// 		cout<<arr[(B+i-cnt)%cnt - 1]<<endl;
// 	return 0;
// }

// long long	moduler2(long long a, long long b, long long c) {
// 	int power[32];
// 	int tmp = b;
// 	int i=0;

// 	for (i=0; tmp>0; i++) {
// 		power[i] = tmp%2;
// 		tmp /= 2;
// 	}
// 	i--;
// 	tmp = a;
// 	int n=1;
// 	for (int j=i; j>=0; j--) {
// 		if (power[j]) {
// 			for (int k=0; k<j; k++) {
// 				power[j] = tmp * a;
// 			}
// 		}
// 		power[j] %= c;
// 		cout<<"j : "<<j<<" power : " <<power[j]<<endl;
// 	}
// 	int result = 1;
// 	for (int j=0; j<=i; j++) {
// 		if (power[j])
// 			result = result * power[j] % c;
// 	}
// 	return result;
// }

#include <iostream>

using namespace std;

long long	moduler(long long a, long long b, long long c) {
	if (b == 0)
		return 1;
	if (b == 1)
		return a%c;

	long long tmp = moduler(a,b/2,c) % c;
	if (b % 2 == 0)
		return (tmp * tmp) % c;
	else
		return tmp * tmp % c * a % c;
}

int main(void) {
	long long a,b,c;
	cin>>a>>b>>c;

	cout<<moduler(a,b,c)<<endl;

	return 0;
}
