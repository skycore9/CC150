/*
 * 编写代码，以给定值x为基准将链表分割成两部分，
 * 所有小于x的结点排在大于或等于x的结点之前
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {
    }
};

ListNode* partition(ListNode* pHead, int x) {
    if (pHead == NULL) {
        return pHead;
    }
        
    ListNode less(-1);
    ListNode more(-1);
    ListNode *p = &less;
    ListNode *q = &more;
    ListNode *current = pHead;
    while (current != NULL) {
        if (current->val < x) {
            p->next = current;
            p = p->next;
        } else {
            q->next = current;
            q = q->next;
        }
        current = current->next;
    }
        
    q->next = NULL; // important
    if (p == &less) {
        return more.next;
    }
        
    p->next = more.next;
        
    return less.next;
}

int main() {
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(1);
    ListNode n4(3);
    ListNode n5(1);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    partition(&n1, 2);
    
    return 0;
}
