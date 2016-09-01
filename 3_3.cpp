/*
 * 请实现一种数据结构SetOfStacks，由多个栈组成，每个栈的大小为size
 * 当前一个栈填满时，新建一个栈。
 * 该数据结构应该支持与普通栈相同的push和pop操作。
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class SetOfStacks {
public:
	SetOfStacks(int capacity) : _capacity(capacity) {}

	void push(int value) {
		stack<int> &last = _stacks.back();
		if (!last.empty() && last.size() < _capacity) {
			last.push(value);
		} else {
			stack<int> s;
			s.push(value);
			_stacks.push_back(s);
		}
	}

	void pop() {
		stack<int> &last = _stacks.back();
		last.pop();
		if (last.empty()) {
			_stacks.pop_back();
		}
	}
private:
	int _capacity;
	vector<stack<int>> _stacks;
};

int main() {
	return 0;
}


