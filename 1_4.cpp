/*
 * 编写一个方法，将字符串中的空格全部替换为"%20".
 */

#include <iostream>

using namespace std;

void repaceSpaces(char *str) {
	if (str == NULL) {
		return ;
	}

	int spaceCount = 0;
	int newLength = 0;
	int i;
	for (i = 0; str[i] != '\0'; ++i) {
		if (str[i] == ' ') {
			++ spaceCount;
		}
	}

	newLength = i + spaceCount * 2;
	for (int j = i; j >= 0; --j) {
		if (str[j] == ' ') {
			str[newLength] = '0';
			str[newLength - 1] = '2';
			str[newLength - 2] = '%';
			newLength -= 3;
		} else {
			str[newLength] = str[j];
			-- newLength;
		}
	}
}

int main() {
	char str[11] = "wei feng";
	repaceSpaces(str);
	cout << str << endl;
	return 0;
}
