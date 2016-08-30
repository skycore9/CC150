/*
 * 给定一副由N*N矩阵表示的图像，其中每个像素的大小为4字节，
 * 编写一个方法，将图像旋转90度
 */

#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &matrix) {
	int n = matrix.size();
	for (int i = 0; i < n / 2; ++i) {
		int begin = i;
		int end = n - 1 - i;
		for (int j = begin; j < end; ++j) {
			int offset = j - begin;

			int top = matrix[begin][j];

			matrix[begin][j] = matrix[end - offset][begin];

			matrix[end - offset][begin] = matrix[end][end - offset];

			matrix[end][end - offset] = matrix[j][end];

			matrix[j][end] = top;
		}
	}
}

int main() {
	vector<vector<int>> m{{1,2,3}, {4, 5, 6}, {7, 8, 9}};
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

	rotate(m);

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

