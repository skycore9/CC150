#include <iostream>
#include <string>

using namespace std;

class BinDecimal {
public:
    string printBin(double num) {
        if (num < 0 || num > 1) {
            return "";
        }
        
        string result("0.");
        while (num != 0) {
            num *= 2;
            if (num >= 1) {
                result.push_back('1');
                num -= 1;
            } else {
                result.push_back('0');
            }
        }
        
        if (result.size() >= 32) {
            return "Error";
        }
        
        return result;
    }
};

int main() {
	return 0;
}
