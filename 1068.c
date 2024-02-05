#include <stdio.h>
#include <unistd.h>

typedef struct Tree {
	int parent;
	int	is_alive;
	int has_child;
}	Tree;

int main(void) {
	int N;
	scanf("%d", &N);

	Tree tree[N];

	int parent;
	int root;
	for (int i=0; i<N; i++) {
		tree[i].has_child = 0;
		tree[i].is_alive = 0;
		tree[i].parent = 0;
	}
	for (int i=0; i<N; i++) {
		scanf("%d", &parent);
		tree[i].is_alive = 1;
		tree[i].parent = parent;
		if (parent != -1)
			tree[parent].has_child++;
		else {
			root = i;
		}
	}

	int delete;
	scanf("%d", &delete);

	tree[delete].is_alive = 0;
	if (delete != root) {
			tree[tree[delete].parent].has_child--;
	}
	int leaf_node = 0;

	for (int i=0; i<N; i++) {
		if (tree[i].is_alive == 1 && tree[i].has_child == 0) {
            int parent = tree[i].parent;
            while (parent != -1) {
                if (tree[parent].is_alive == 0)
                    break;
                parent = tree[parent].parent;
            }
            if (parent == -1) {
                leaf_node++;
			}
        }
	}
	printf("%d\n", leaf_node);
	return 0;
}