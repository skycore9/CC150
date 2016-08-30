#include <iostream>
#include <cstring>

using namespace std;

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

int main() {
	cout << isUniqueChars("Hello") << endl;
	cout << isUniqueChars("abcde") << endl;
	return 0;
}
