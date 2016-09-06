#include <iostream>

using namespace std;

class MinimalBST {
public:
    int buildMinimalBST(vector<int> vals) {
        return int(log2(vals.size()) + 1);
    }
};

int main() {
	// accepted by nowcoder
	return 0;
}
