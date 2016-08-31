/*
 * 有两个用链表表示的整数，每个结点包含一个数位
 * 这些数位是反向存放的，也就是个位排在链表的首部
 */

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *plusAB(ListNode *l1, ListNode *l2) {
	if (l1 == NULL) {
		return l2;
	}

	if (l2 == NULL) {
		return l1;
	}

	int carry = 0;
	ListNode dummy(-1);
	ListNode *p = &dummy;

	while (l1 && l2) {
		int sum = l1->val + l2->val + carry;
		p->next = new ListNode(sum % 10);
		carry = sum / 10;
		l1 = l1->next;
		l2 = l2->next;
        p = p->next;
	}

	while (l1) {
		int sum = l1->val + carry;
		p->next = new ListNode(sum % 10);
		carry = sum / 10;
		l1 = l1->next;
        p = p->next;
	}

	while (l2) {
		int sum = l2->val + carry;
		p->next = new ListNode(sum % 10);
		carry = sum / 10;
		l2 = l2->next;
        p = p->next;
	}

	if (carry != 0) {
		p->next = new ListNode(carry);
	}

	return dummy.next;
}

int main() {
	// accepted by nowcoder
	return 0;
}
