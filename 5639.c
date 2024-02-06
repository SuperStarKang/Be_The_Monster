#include <stdio.h>

int node[10001];

void	post(int start, int end) {
    if (start >= end)
		return;

    int root = node[start];
    int middle = start+1;

    while (middle < end) {
        if (root < node[middle]) 
			break;
        middle++;
    }

    post(start+1,middle);
    post(middle,end);
    printf("%d\n", root);
}

int main(void) {
    int key;
    int idx = 0;
    while(!(scanf("%d", &key) == EOF))
		node[idx++] = key;
    post(0,idx);
}