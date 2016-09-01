/*
 * 实现一个min栈
 */

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
	void push(int value) {
		_s.push(value);
		if (_m.empty() || _m.top() > value) {
			_m.push(value);
		}
	}

	void pop() {
		if (_s.top() == _m.top()) {
			_m.pop();
		}
		_s.pop();
	}

	int top() {
		return _s.top();
	}

	int min() {
		return _m.top();
	}
private:
	stack<int> _s;
	stack<int> _m;
};

int main() {
	MinStack m;
	m.push(5);
	cout << m.min() << endl;
	m.push(6);
	cout << m.min() << endl;
	m.push(3);
	cout << m.min() << endl;
	m.push(7);
	cout << m.min() << endl;
	m.pop();
	cout << m.min() << endl;
	m.pop();
	cout << m.min() << endl;

	return 0;
}
