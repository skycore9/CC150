#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverse(ListNode *head) {
	if (head == NULL) {
		return NULL;
	}

	ListNode *prev = NULL;
	ListNode *current = head;
	while (current != NULL) {
		ListNode *next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	return prev;
}

bool isPalindrome(ListNode *pHead) {
	if (pHead == NULL) {
		return true;
	}

	ListNode dummy(-1);
    ListNode *s = pHead;
    ListNode *r = &dummy;
    while (s != NULL) {
        r->next = new ListNode(s->val);
        r = r->next;
        s = s->next;
    }
        
    s = dummy.next;
    r = reverse(pHead);
	while (r != NULL && s != NULL) {
		if (r->val != s->val) {
			return false;
		}
		r = r->next;
		s = s->next;
	}

	return true;
}

int main() {
	// accepted by nowcoder
	//
    return 0;
}

