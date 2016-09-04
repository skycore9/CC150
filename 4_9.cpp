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

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > result;
        if (root == NULL) {
            return result;
        }
        vector<int> elem;
        DFindPath(root, expectNumber, result, elem, 0);
        return result;
    }
private:
    void DFindPath(TreeNode *root, int expectNumber, 
                   vector<vector<int> > &result, vector<int> &elem,  
                   int sum) {
        sum += root->val;
        elem.push_back(root->val);
        
        if (root -> left == NULL && root->right == NULL && sum == expectNumber) {
            result.push_back(elem);
            sum -= root->val;
            elem.pop_back();
            return;
        }

        if (root->left) {
            DFindPath(root->left, expectNumber, result, elem, sum);
        }
        
        if (root->right) {
            DFindPath(root->right, expectNumber, result, elem, sum);
        }
        
        sum -= root->val;
        elem.pop_back();
    }
};

int main() {
    // accepted by nowcoder
    return 0;
}