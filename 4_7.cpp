#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 不包含指向父节点的连接
bool covers(TreeNode *root, TreeNode *p) {
	if (root == NULL) {
		return false;
	}

	if (root == p) {
		return true;
	}

	return covers(root->left, p) || covers(root->right, p);
}

TreeNode *commonAncestorHelper(TreeNode *root, TreeNode *p, TreeNode *q) {
	if (root == NULL) {
		return NULL;
	}

	if (root == p || root == q) {
		return root;
	}

	bool is_p_on_left = covers(root->left, p);
	bool is_q_on_left = covers(root->right, q);

	if (is_p_on_left != is_q_on_left) {
		return root;
	}

	TreeNode *child_side = is_p_on_left? root->left : root->right;
	return commonAncestorHelper(child_side, p, q);
}

TreeNode *commonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
	if (!covers(root, p) || !covers(root, q)) {
		return NULL;
	}

	return commonAncestorHelper(root, p, q);
}

int main() {
	// accepted by nowcoders
	return 0;
}
