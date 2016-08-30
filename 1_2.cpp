/*
 * 用C/C++实现void reverse(char *str)函数
 * 即反转一个null结尾的字符串
 */

#include <iostream>

using namespace std;

void reverse(char *str) {
	if (str == NULL) {
		return ;
	}

	char *begin = str;
	char *end = str;
	while (*end != '\0') { ++ end; }
	-- end;

	while (begin < end) {
		char tmp = *begin;
		*begin = *end;
		*end = tmp;
		++ begin;
		-- end;
	}
}

int main() {
	char m[8] = "reverse";
	reverse(m);
	cout << m << endl;
	return 0;
}


