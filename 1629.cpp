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


#include <iostream>

using namespace std;

long long moduler(long long a, long long b, long long c) {
	if (b == 0)
		return 1;
	if (b == 1)
		return a%c;
	
	long long tmp = moduler(a,b/2,c) % c;
	if (b % 2 == 0)
		return tmp * tmp % c;
	else
		return tmp * tmp % c * a % c;
}

int main(void) {
	long long a,b,c;
	cin>>a>>b>>c;

	cout<<moduler(a,b,c)<<endl;

	return 0;
}
