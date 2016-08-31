#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *findBeginning(ListNode *head) {
	if (head == NULL) {
		return NULL;
	}

	ListNode *slow = head;
	ListNode *fast = head;
	while (fast != NULL) {
		slow = slow->next;
		fast = fast->next;
		if (fast != NULL) {
			fast = fast->next;
		}

		if (slow != NULL && fast != NULL && slow == fast) {
			break;
		}
	}

	// 无环
	if (fast == NULL) {
		return NULL;
	}

	slow = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}

	return fast;
}

int main() {
	return 0;
}
