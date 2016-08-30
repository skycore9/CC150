/*
 * 给定两个字符串，请编写程序，确定其中一个字符串的字符重新
 * 排列后，能否编程拧一个字符串
 */

#include <iostream>

using namespace std;

// 排序
bool permutation_sort(string s, string t) {
	if (s.size() != t.size()) {
		return false;
	}

	sort(s.begin(), s.end());
	sort(t.begin(), t.end());

	return s == t;
}

// 用哈希表
bool permutation_hash(string s, string t) {
	if (s.size() != t.size()) {
		return false;
	}

	int letters[256];
	memset(letters, 0, 256);
	for (int i = 0; i < s.size(); ++i) {
		++ letters[s[i]];
	}

	for (int i = 0; i < t.size(); ++i) {
		-- letters[t[i]];
		if (letters[t[i]] < 0) {
			return false;
		}
	}

	return true;
}

int main() {
	cout << permutation_hash("dog", "god") << endl;

	return 0;
}
