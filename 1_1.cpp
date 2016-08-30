/*
 * 实现一个算法，确定一个字符串的所有字符是否全都不同，
 * 加入不允许使用额外的数据结构又该如何处理？
 */

#include <iostream>
#include <cstring>

using namespace std;

// 1. 用一个数组作HashMap，时间复杂度为O(n)，空间复杂度为常数空间
bool isUniqueChars(const string &str) {
	if (str.size() > 256) {
		return false;
	}

	bool m[256];
	memset(m, false, 256);
	for (int i = 0; i < str.size(); ++i) {
		if (m[str[i]] == true) {
			return false;
		}
		m[str[i]] = true;
	}

	return true;
}

// 2. 两个for循环，时间复杂度为O(n^2)，空间复杂度为O(1)
// 3. 排序，时间复杂度为O(nlogn)，不需要额外空间


int main() {
	cout << isUniqueChars("Hello") << endl;
	cout << isUniqueChars("abcde") << endl;
	return 0;
}
