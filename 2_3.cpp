/*
 * 实现一个算法，删除单向链表中间的某个节点，
 * 假定你只能访问该节点，给定带删除的节点，请执行删除操作
 * 若该节点为尾节点，返回false，否则返回true
 */

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool removeNode(ListNode *pNode) {
	if (pNode == NULL) {
		return false;
	}

	ListNode *next = pNode->next;
	if(next == NULL) {
		return false;
	}

	pNode->val = next->val;
	pNode->next = next->next;

	delete next;
	return true;
}

int main() {
	// accepted by nowcoder
	return 0;
}
