/*
 * 给定s1和上，检查s2是否为s1旋转而成
 */

#include <iostream>
#include <string>

using namespace std;

bool isSubstring(const string &s1, const string &s2) {
	if (s1.size() < s2.size()) {
		return false;
	}

	for (int i = 0; i <= s1.size() - s2.size(); ++i) {
		if (s2[0] == s1[i]) {
			int k = i;
			int flag = true;
			for (int j = 0; j < s2.size(); ++j, ++k) {
				if (s1[k] != s2[j]) {
					flag = false;
					break;
				}
			}

			if (flag == true) {
				return true;
			}
		}
	}

	return false;
}

bool isRotation(const string &s1, const string &s2) {
	if (s1.size() < s2.size()) {
		return false;
	}

	string ss = s1 + s1;

	return isSubstring(ss, s2);
}

int main() {
	cout << isRotation("waterbottle", "erbottlewat") << endl;
	return 0;
}
