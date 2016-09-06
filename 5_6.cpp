#include <iostream>

using namespace std;

int swapOddEvenBits(int x) {
	return ( (( x & 0xAAAAAAAA) >> 1) | ((x & 0x55555555) << 1));
}

int main() {
	// accepted by nowcoder
	return 0;
}
