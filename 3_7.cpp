/*
 * 有家动物收容所只收留猫和狗，但有特殊的收养规则，
 * 收养人有两种收养方式，第一种为直接收养所有动物中最早进入收容所的，
 * 第二种为选择收养的动物类型（猫或狗），并收养该种动物中最早进入收容所的
 */
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Animal {
public:
	Animal(string name) : _name(name) {}

	void setOrder(int order) {
		_order = order;
	}

	int getOrder() {
		return _order;
	}

	bool isOrderThan(Animal &a) {
		return _order < a.getOrder();
	}

	virtual int id() = 0;
protected:
	string _name;
private:
	int _order;
};

class Dog: public Animal {
	Dog(string name) : Animal(name) {}

	virtual int id() {
		return 1;
	}
};

class Cat : public Animal {
	Cat(string name) : Animal(name) {}

	virtual int id() {
		return 2;
	}
};

class AnimalQueue {
public:
	void enqueue(Animal &a) {
		a.setOrder(_order);
		++ _order;

		if (a.id() == 1) {
			_dogs.push(dynamic_cast<Dog &>(a));
		} else {
			_cats.push(dynamic_cast<Cat &>(a));
		}
	}

	void dequeueAny() {
		if (_dogs.empty()) {
			_cats.pop();
		} 

		if (_cats.empty()) {
			_dogs.pop();
		}

		Dog dog = _dogs.front();
		Cat cat = _cats.front();

		if (dog.isOrderThan(cat)) {
			_dogs.pop();
		} else {
			_cats.pop();
		}

	}

	Dog dequeueDogs() {
		Dog dog = _dogs.front();
		_dogs.pop();
		return dog;
	}

	Cat dequeueCats() {
		Cat cat = _cats.front();
		_cats.pop();
		return cat;
	}

private:
	queue<Dog> _dogs;
	queue<Cat> _cats;
	static int _order;
};

int AnimalQueue::_order = 0;

int main() {
	return 0;
}
