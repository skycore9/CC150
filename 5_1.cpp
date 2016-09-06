#include <iostream>

using namespace std;

int binInsert(int n, int m, int j, int i) {
	// 得到一串1
    int allOnes = ~0;
    
	// 获得mask
    int mask = ((allOnes << (i + 1)) | ((1 << j) - 1));
        
    return (n & mask) | (m << j);
}

int main() {
	// accepted by nowcoder
	return 0;
}
