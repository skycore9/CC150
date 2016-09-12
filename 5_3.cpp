#include <iostream>
#include <vector>

using namespace std;

class CloseNumber {
public:
    vector<int> getCloseNumber(int x) {
        int bigger = getNext(x);
        int smaller = getPrev(x);
        
        vector<int> result{smaller, bigger};
        return result;
    }
    
    int getNext(int x) {
        int c = x;
        int c0 = 0;
        int c1 = 0;
        while ((c & 1) == 0 && (c != 0)) {
            ++ c0;
            c >>= 1;
        }
        
        while ((c & 1) == 1) {
            ++ c1;
            c >>= 1;
        }
        
        if (c0 + c1 == 31 || c0 + c1 == 0) {
            return -1;
        }
        
        int p = c0 + c1;
        
        x |= (1 << p);
        x &= ~((1 << p) - 1);
        x |= (1 << (c1 - 1)) - 1;
        
        return x;
    }
    
    int getPrev(int x) {
        int c = x;
        int c0 = 0;
        int c1 = 0;
        while (c & 1 == 1) {
            ++ c1;
            c >>= 1;
        }
        
        if (c == 0) {
            return -1;
        }
        
        while ((c & 1) == 0) {
            ++ c0;
            c >>= 1;
        }
        
        int p = c0 + c1;
        x &= ((~0) << (p + 1));
        
        int mask = (1 << (c1 + 1)) - 1;
        x |= mask << (c0 - 1);
        
        return x;
    }
};

int main() {
    // Accepted By NowCoder
    return 0;
}