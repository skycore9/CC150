#include <iostream>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<struct UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};

class Path {
public:
    bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
        return check(a, b) || check(b, a);
    }
    
    bool check(UndirectedGraphNode* a, UndirectedGraphNode* b) {
        if (a == NULL || b == NULL) {
            return false;
        }
        
        if (a == b) {
            return true;
        }
        
        queue<UndirectedGraphNode *> q;
        set<UndirectedGraphNode *> m;
        q.push(a);
        UndirectedGraphNode *node;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            m.insert(node);
            for (int i = 0; i < (node->neighbors).size(); ++i) {
                if ((node->neighbors)[i] == b) {
                    return true;
                } 
                
                if ((node->neighbors)[i] && 
                    m.find((node->neighbors)[i]) == m.end()) {
                    q.push((node->neighbors)[i]);
                }
            }
        }
        
        return false;
    }
};

int main() {
    // accepted by nowcoder
    return 0;
}