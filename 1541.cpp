#include <iostream>
#include <cstdlib>

using namespace std;

char equation[51];

int main(void) {
	cin>>equation;

	char num[5];
	int i=0;
	int	j=0;
	int	result=0;
	int is_minus=0;
	while (equation[i]) {
		if (equation[i] == '-' || equation[i] == '+') {
			if (equation[i] == '-')
				is_minus = 1;
			i++;
		}
		while (equation[i] >= '0' && equation[i] <= '9') {
			num[j++] = equation[i];
			i++;
		}
		num[j] = 0;
		if (is_minus == 1)
			result -= atoi(num);
		else
			result += atoi(num);
		j = 0;
		for (int k=0; k<5; k++)
			num[k] = 0;
	}
	cout<<result<<endl;
	return 0;
}