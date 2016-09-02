#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Balance {
public:
    bool isBalance(TreeNode* root) {
        // write code here
        return balance(root) != -1;
    }
    
    int balance(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        
        int left = balance(root->left);
        if (left == -1) {
            return -1;
        }
        
        int right = balance(root->right);
        if (right == -1) {
            return -1;
        }
        
        if (left == -1 || right == -1 || abs(left - right) > 1) {
            return -1;
        }
        
        return max(left, right) + 1;
    }
};

int main() {
    // accepted by nowcoder
    return 0;
}