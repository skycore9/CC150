/*
 * 编写代码，移除未排序链表中的重复节点
 */
#include <iostream>
#include <unordered_set>

using namespace std;

struct LinkedList {
	int val;
	LinkedList *next;
	LinkedList(int val) : val(val), next(NULL) {}
};

void deleteDups(LinkedList *head) {
	unordered_set<int> table;
	LinkedList *prev = NULL;
	LinkedList *current = head;
	while (current != NULL) {
		if (table.find(current->val) != table.end()) {
			LinkedList *tmp = current;
			prev->next = current->next;
			current = current->next;
			// delete tmp;
		} else {
			table.insert(current->val);
			prev = current;
			current = current->next;
		}
	}
}

// 2. 可以使用O(n^2)时间复杂度，不需要缓存空间

int main() {
	LinkedList n1(1);
	LinkedList n2(2);
	LinkedList n3(1);
	LinkedList n4(3);
	LinkedList n5(1);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	deleteDups(&n1);

	LinkedList *p = &n1;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}

	return 0;
}
