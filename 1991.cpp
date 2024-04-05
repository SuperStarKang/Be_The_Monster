#include <iostream>

using namespace std;

typedef struct node {
	char name;
	char right;
	char left;
} node;

node tree[27];

void	pre_order(char name) {
	if (name != '.') {
		cout << name;
		pre_order(tree[name-65].left);
		pre_order(tree[name-65].right);
	}
}

void	in_order(char name) {
	if (name != '.') {
		in_order(tree[name-65].left);
		cout << name;
		in_order(tree[name-65].right);
	}
}

void	post_order(char name) {
	if (name != '.') {
		post_order(tree[name-65].left);
		post_order(tree[name-65].right);
		cout << name;
	}
}

int main(void) {
	int N;
	cin >> N;

	char parent,child1,child2;
	for (int i=0; i<N; i++) {
		cin >> parent >> child1 >> child2;
		tree[parent-65].name = parent;
		tree[parent-65].left = child1;
		tree[parent-65].right = child2;
	}

	pre_order('A');
	cout << '\n';
	in_order('A');
	cout << '\n';
	post_order('A');
	cout << '\n';

	return 0;
}