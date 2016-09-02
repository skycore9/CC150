#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class TreeLevel {
public:
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        if (root == NULL) {
            return NULL;
        }
        
        queue<TreeNode *> q;
        q.push(root);
        int current = 1;
        int next = 0;
        int level = 1;
        while (!q.empty()) {
            if (level == dep) {
                break;
            }
            
            TreeNode *top = q.front();
            q.pop();
            if (top->left != NULL) {
                q.push(top->left);
                ++ next;
            }
            
            if (top->right != NULL) {
                q.push(top->right);
                ++ next;
            }
            
            -- current;
            if (current == 0) {
                current = next;
                ++ level;
                next = 0;
            }
        }
        
        ListNode head(-1);
        ListNode *p = &head;
        while (!q.empty()) {
            TreeNode *top = q.front();
            q.pop();
            p->next = new ListNode(top->val);
            p = p->next;
        }
        
        return head.next;
    }
};


int main() {
    // accepted by nowcoder
    return 0;
}