/*
 * 输入一个链表，输出该链表中倒数第k个结点
 */

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if (pListHead == NULL) {
        return pListHead;
    }
        
    ListNode *p = pListHead;
    int len = 0;
    while (p != NULL) {
        ++ len;
        p = p->next;
    }
        
    if (len < k) {
        return NULL;
    }
        
    int gap = len - k;
    p = pListHead;
    for (int i = 0; i < gap; ++i) {
        p = p->next;
    }
        
    return p;
}

int main() {
	return 0;
}
