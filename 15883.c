#include <stdio.h>
#include <stdlib.h>

int hexToDecimal(char hex[]) {
	int result=0;
    for (int i = 0; i < 4; i++ )
    {
        if (hex[i] >= 'a' && hex[i] <= 'f' )
            result = result * 16 + hex[i] - 'a' + 10;
        else if (hex[i] >= '0' && hex[i] <= '9' )
            result = result * 16 + hex[i] - '0';
    }
	return (result);
}

void	print_result(char *num1, char *num2) {
    char hex[5];
	int sum = hexToDecimal(num1) + hexToDecimal(num2);
	int i = 4;
	while (sum > 0) {
		hex[i] = "0123456789abcdef"[sum % 16];
		i--;
		sum /= 16;
	}

	if (hex[2] == num1[0] || hex[2] == num1[1] || hex[2] == num1[2] || hex[2] == num1[3] ||
		hex[3] == num1[0] || hex[3] == num1[1] || hex[3] == num1[2] || hex[3] == num1[3] || 
		hex[4] == num1[0] || hex[4] == num1[1] || hex[4] == num1[2] || hex[4] == num1[3] ||
		hex[2] == num2[0] || hex[3] == num2[0] || hex[4] == num2[0] ||
		hex[2] == num2[3] || hex[3] == num2[3] || hex[4] == num2[3] ||
		hex[2] == hex[3] || hex[2] == hex[4] || hex[3] == hex[4])
			return ;
	printf("%c%c%c%c + ", num1[0], num1[1], num1[2], num1[3]);
	printf("%c%c%c%c = ", num2[0], num2[1], num2[2], num2[3]);
	printf("%c%c%c%c%c\n", hex[0], hex[1], hex[2], hex[3], hex[4]);
}

int main(void) {
	char list[] = "0123456789abcdef";
	char arr[4];
	char num[4];

	for (int i=2; i<16; i++) {
		arr[0] = num[2] = list[i]; // 세모
		for (int j=1; j<16; j++) {
			if (i+j < 16 || j == i)
				continue ;
			num[0] = list[j];
			arr[2] = list[(i+j) / 16]; // 네모
			for (int k=0; k<16; k++) {
				if (k == i || k == j || k == arr[2] - '0')
					continue;
				arr[1] = num[1] = list[k]; // 동그라미

				// 별
				int tmp = (i+j) % 16;
				if (k > 7) {
					arr[3] = list[(tmp + 1) % 16];
				}
				else
					arr[3] = list[tmp];
				if (arr[3] == arr[0] || arr[3] == arr[1] || arr[3] == arr[2])
					continue;

				for (int n=0; n<16; n++) {
					if (n == i || n == j || n == k || n == arr[3] - '0')
						continue;
					num[3] = list[n];

					print_result(arr, num);
				}
			}
		}
	}

	return 0;
}