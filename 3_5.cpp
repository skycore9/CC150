#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                int tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
        }
        
        int result = stack2.top();
        stack2.pop();
        return result;
    }

private:
    // in
    stack<int> stack1;
    // out
    stack<int> stack2;
};

int main() {
    // accepted by nowcoer
    return 0;
}