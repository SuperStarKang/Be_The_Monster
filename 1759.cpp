#include <iostream>
#include <cstdlib>

using namespace std;

int L,C;
bool visited[20];

int compare(const void *a, const void *b)
{
	const char *x = (char*)a;
	const char *y = (char*)b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;
	return 0;
}

void	print(char alphabet[], int size) {
	int gather=0,consonant=0;
	for (int i=0; i<size; i++) {
		if (visited[i] == true) {
			if (alphabet[i] == 'a' || alphabet[i] == 'e' || alphabet[i] == 'i' || alphabet[i] == 'o' || alphabet[i] == 'u')
				gather++;
			else
				consonant++;
		}
	}
	if (gather < 1 || consonant < 2)
		return ;
	for (int i=0; i<size; i++) {
		if (visited[i] == true)
			cout<<alphabet[i];
	}
	cout<<endl;
}

void	dfs(char alphabet[], int idx, int cnt, int C, int L) {
	if (cnt == L) {
		print(alphabet, C);
		return ;
	}

	for (int i=idx; i<C; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(alphabet, i, cnt+1, C, L);
			visited[i] = false;
		}
	}
}

int main(void) {
	cin>>L>>C;

	char alphabet[C];
	for (int i=0; i<C; i++)
		cin>>alphabet[i];

	qsort(alphabet, C, sizeof(char), compare);
	dfs(alphabet, 0, 0, C, L);
	return 0;
}