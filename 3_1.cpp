/*
 * 描述如何只用一个数组来实现三个栈
 */
#include <iostream>
 #include <cstring>

using namespace std;

// 栈1，使用[0, n / 3)
// 栈2，使用[n / 3, 2n / 3)
// 栈3，使用[2n / 3, n)

class Stack {
public:
	 explicit Stack(int stackSize) : _stackSize(stackSize) {
	 	_buffer = new int[3 * stackSize];

	 	_stackPointer = new int[3];
		_stackPointer[0] = -1;
		_stackPointer[1] = -1;
		_stackPointer[2] = -1;
	 }

	~ Stack() {
		if (_buffer) {
			delete [] _buffer;
		}

		if (_stackPointer) {
			delete [] _stackPointer;
		}
	}

	int absTopOfStack(int stackNum) {
		return stackNum * _stackSize + _stackPointer[stackNum];
	}

	void push(int stackNum, int value) {
		if (_stackPointer[stackNum] + 1 >= _stackSize) {
			return ;
		}

		++ _stackPointer[stackNum];
		_buffer[absTopOfStack(stackNum)] = value;
	}

	void pop(int stackNum) {
		if (_stackPointer[stackNum] == -1) {
			return;
		}

		_buffer[absTopOfStack(stackNum)] = 0;
		-- _stackPointer[stackNum];
	}

	int top(int stackNum) {
		int index = absTopOfStack(stackNum);
		return _buffer[index];
	}

	bool empty(int stackNum) {
		return _stackPointer[stackNum] == - 1;
	}

private:
	const int _stackSize;
	int *_buffer;
	int *_stackPointer;
};

int main() {
	Stack s(100);
	s.push(0, 1);
	s.push(1, 2);
	s.push(2, 3);
	cout << s.top(0) << " " << s.top(1) << " " << s.top(2) << endl;

	s.push(0, 4);
	s.push(1, 5);
	s.push(2, 6);
	cout << s.top(0) << " " << s.top(1) << " " << s.top(2) << endl;

	s.pop(0);
	s.pop(1);
	s.pop(2);

	cout << s.top(0) << " " << s.top(1) << " " << s.top(2) << endl;

	return 0;
}
