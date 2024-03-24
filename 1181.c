#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *str) {
	int len=0;
	while (str[len])
		len++;
	return (len);
}

int my_strcmp(char *s1, char *s2) {
	int i=0;
	while (s1[i] && s2[i] && s1[i] == s2[i]) {
		i++;
	}
	return (s1[i] - s2[i]);
}

int main(void) {
	int N;
	scanf("%d", &N);

	char **words = (char **)malloc(sizeof(char *) * N);
	char *temp;
	for (int i=0; i<N; i++) {
		int idx=0;
		words[i] = (char *)malloc(sizeof(char) * 51);
		scanf(" %s", words[i]);
		for (int j=0; j<i; j++) {
			if (my_strlen(words[j]) > my_strlen(words[i])) {
				idx = j;
				break ;
			}
			else if (my_strlen(words[j]) == my_strlen(words[i])) {
				if (my_strcmp(words[j], words[i]) > 0) {
					idx = j;
					break ;
				}
				else {
					idx++;
					if (j<i && my_strlen(words[j+1]) > my_strlen(words[i]))
						break ;
				}
			}
			else
				idx++;	
		}
		temp = words[i];
		for (int j=i; j>idx; j--) {
			words[j] = words[j-1];
		}
		words[idx] = temp;
	}

	for (int i=0; i<N; i++) {
		if (i > 0 && !my_strcmp(words[i], words[i-1])) ;
		else
			printf("%s\n", words[i]);

	}
	return 0;
}