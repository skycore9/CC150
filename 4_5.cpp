#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Checker {
public:
    bool checkBST(TreeNode* root) {
        vector<int> v;
        check(root, v);
        
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] < v[i - 1]) {
                return false;
            }
        }
        
        return true;
    }
    
    void check(TreeNode *root, vector<int> &v) {
        if (root == NULL) {
            return;
        }
        
        check(root->left, v);
        v.push_back(root->val);
        check(root->right, v);
    }
};

int main() {
    // accepted by nowcoder
    return 0;
}