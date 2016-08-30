/*
 * 编写一个算法，若矩阵中某个元素为0，清零所在行和列
 */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void setZeros(vector<vector<int>> &matrix) {
	if (matrix.size() == 0) {
		return;
	}

	bool *rows = new bool[matrix.size()];
	bool *cols = new bool[matrix[0].size()];
	memset(rows, false, matrix.size());
	memset(cols, false, matrix[0].size());

	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			if (matrix[i][j] == 0) {
				rows[i] = true;
				cols[j] = true;
			}
		}
	}

	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			if (rows[i] || cols[j]) {
				matrix[i][j] = 0;
			}
		}
	}
}

int main() {
	vector<vector<int>> m{{1, 2, 3}, {1, 0, 2}, {1, 1, 2}};
	setZeros(m);

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
