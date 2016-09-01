#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {
        // write code here
        stack<int> sorted;
        stack<int> cache;
        for (int i = 0; i < numbers.size(); ++i) {
            if (sorted.empty() || numbers[i] <= sorted.top()) {
                sorted.push(numbers[i]);
            } else {
                while (!sorted.empty() && sorted.top() < numbers[i]) {
                    cache.push(sorted.top());
                    sorted.pop();
                }
                
                sorted.push(numbers[i]);
                while (!cache.empty()) {
                    sorted.push(cache.top());
                    cache.pop();
                }
            }
        }
        
        vector<int> result;
        while (!sorted.empty()) {
            result.push_back(sorted.top());
            sorted.pop();
        }
        
        int i = 0;
        int j = result.size() - 1;
        while (i < j) {
            int tmp = result[i];
            result[i] = result[j];
            result[j] = tmp;
            ++ i;
            -- j;
        }
        
        return result;
    }
};


int main() {
    // accept by nowcoder
    return 0;
}