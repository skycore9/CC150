#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *parent;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), parent(NULL), left(NULL), right(NULL) {}
};

TreeNode *leftMostChild(TreeNode *p) {
	if (p == NULL) {
		return NULL;
	}

	while (p->left != NULL) {
		p = p->left;
	}

	return p;
}

TreeNode *inorderSucc(TreeNode *p) {
	if (p == NULL) {
		return NULL;
	}

	if (p->right != NULL) {
		return leftMostChild(p->right);
	} else {
		TreeNode *current = p;
		TreeNode *parent = p->parent;
		while (parent != NULL && parent->left != current) {
			current = parent;
			parent = parent->parent;
		}

		return parent;
	}

	return NULL;
}

int main() {
	return 0;
}

