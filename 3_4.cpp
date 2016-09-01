#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Tower {
public:
	explicit Tower(int i) : _index(i) {}

	void add(int d) {
		if (!_disks.empty() && _disks.top() <= d) {
			return ;
		} else {
			_disks.push(d);
		}
	}

	int index() {
		return _index;
	}

	void moveTopTo(Tower *t) {
		int top = _disks.top();
		_disks.pop();
		t->add(top);
		cout << "Move disk " << top << " from " << _index << " to " << t->index() << endl;
	}

	void moveDisks(int n, Tower *destination, Tower *buffer) {
		if (n > 0) {
			moveDisks(n - 1, buffer, destination);
			moveTopTo(destination);
			moveDisks(n - 1, destination, this);
		}
	}

private:
	int _index;
	stack<int> _disks;
};

int main() {
	Tower t1(1);
	Tower t2(2);
	Tower t3(3);

	vector<Tower> towers;
	towers.push_back(t1);
	towers.push_back(t2);
	towers.push_back(t3);
	for (int i = 3; i >= 1; --i) {
		towers[0].add(i);
	}

	towers[0].moveDisks(3, &towers[2], &towers[1]);

	return 0;
}
