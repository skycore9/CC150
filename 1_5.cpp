/*
 * 利用字符重复出现的次数，编写一个方法，实现基本的字符串压缩功能
 */

#include <iostream>

using namespace std;

int countCompression(const string &str) {
	if (str.empty()) {
		return 0;
	}

	char last = str[0];
	int count = 1;
	int size = 0;
	for (int i = 1; i < str.size(); ++i) {
		if (str[i] == last) {
			++ count;
		} else {
			size += 1 + to_string(count).size();
			last = str[i];
			count = 1;
		}
	}

	size += 1 + to_string(count).size();
	return size;
}

string compression(const string &str) {
	int size = countCompression(str);
	if (size >= str.size()) {
		return str;
	}

	string result;
	int count = 1;
	char last = str[0];
	for (int i = 1; i < str.size(); ++i) {
		if (str[i] == last) {
			++ count;
		} else {
			result.push_back(last);
			result.append(to_string(count));
			count = 1;
			last = str[i];
		}
	}

	return result;
}

int main() {
	cout << compression("aaabbbcccddd") << endl;
	return 0;
}
