#include <stdio.h>

int node[10001];

void	post_order(int start, int end) {
    if (start >= end)
		return;

    int root = node[start];
    int middle = start+1;

    while (middle < end) {
        if (root < node[middle]) 
			break;
        middle++;
    }

    post_order(start+1,middle);
    post_order(middle,end);
    printf("%d\n", root);
}

int main(void) {
    int key;
    int idx = 0;

    while (!(scanf("%d", &key) == EOF))
		node[idx++] = key;
    post_order(0,idx);
}