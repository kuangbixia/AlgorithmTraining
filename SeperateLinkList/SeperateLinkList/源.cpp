#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* pHead, int x) {
    // write code here
    ListNode* lessHead = new ListNode(0);
    ListNode* less = lessHead;
    ListNode* moreHead = new ListNode(0);
    ListNode* more = moreHead;
    while (pHead) {
        if (pHead->val < x) {
            less->next = pHead;
            less = less->next;
        }
        else {
            more->next = pHead;
            more = more->next;
        }
        pHead = pHead->next;
    }
    less->next = moreHead->next;
    return lessHead->next;
}

int main() {
    ListNode* p = new ListNode(3);
    p->next = new ListNode(3);
    p->next->next = new ListNode(3);
    ListNode* q = partition(p, 3);
    while (q != NULL) {
        cout << q->val << endl;
        q = q->next;
    }
    return 0;
}