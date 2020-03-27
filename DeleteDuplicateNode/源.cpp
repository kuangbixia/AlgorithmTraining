#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

ListNode* deleteDuplication(ListNode* pHead)
{
    if (pHead == NULL) {
        return NULL;
    }

    ListNode* p = pHead;
    // 删除开头的重复节点
    while (p->next) {
        if (p->val == p->next->val) {
            p = p->next;
        }
        else {
            if (p != pHead) {
                pHead = p->next;
                p = pHead;
            }
            else {
                break;
            }
        }
    }
    if (p != pHead) {
        return NULL;
    }
    // 删除后面的重复节点
    while (p->next) {
        ListNode* f = p->next;
        while (f->next) {
            if (f->next->val == f->val) {
                f = f->next;
                if (f->next == NULL) {
                    f = NULL;
                    break;
                }
            }
            else {
                if (f != p->next) {
                    f = f->next;
                    p->next = f;
                }
                else {
                    break;
                }
            }
        }
        p->next = f;
        p = p->next;
        if (p == NULL) {
            break;
        }
    }
    return pHead;
}

int main() {
    ListNode* pHead = new ListNode(1);
    pHead->next = new ListNode(1);
    pHead->next->next = new ListNode(2);
    pHead->next->next->next = new ListNode(3);
    pHead->next->next->next->next = new ListNode(3);
    pHead->next->next->next->next->next = new ListNode(4);
    pHead->next->next->next->next->next->next = new ListNode(5);
    pHead->next->next->next->next->next->next->next = new ListNode(5);
    ListNode* newHead = deleteDuplication(pHead);
    while (newHead) {
        cout << newHead->val << endl;
        newHead = newHead->next;
    }
    return 0;
}