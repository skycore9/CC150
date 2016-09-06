#include <iostream>

using namespace std;

class Transform {
public:
    int calcCost(int A, int B) {
        // write code here
        int result = 0;
        A ^= B;
        while (A != 0) {
            if ((A & 1) == 1) {
                ++ result;
            }
            
            A >>= 1;
        }
        return result;
    }
};

int main() {
	// accepted by nowcoder
	return 0;
}
