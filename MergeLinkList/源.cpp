#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    ListNode* head = NULL;
    ListNode** headP = &head;
    while (pHead1 != NULL && pHead2 != NULL) {
        ListNode* temp = pHead1->val < pHead2->val ? pHead1 : pHead2;
        *headP = temp;
        headP = &(*headP)->next;
        if (pHead1->val < pHead2->val) {
            pHead1 = pHead1->next;
        }
        else {
            pHead2 = pHead2->next;
        }
    }
    if (pHead1 == NULL && pHead2 != NULL) {
        *headP = pHead2;
    }
    if (pHead1 != NULL && pHead2 == NULL) {
        *headP = pHead1;
    }
    return head;
}

int main() {
    ListNode* pHead1 = NULL;
    ListNode* pHead2 = NULL;
    /*ListNode* pHead1 = new ListNode(1);
    ListNode* pHead2 = new ListNode(2);
    ListNode** p1 = &pHead1;
    ListNode* newNode;
    for (int i = 3; i < 8; i += 2) {
        newNode = new ListNode(i);
        (*p1)->next = newNode;
        p1 = &(*p1)->next;
    }
    p1 = &pHead2;
    for (int i = 4; i < 9; i += 2) {
        newNode = new ListNode(i);
        (*p1)->next = newNode;
        p1 = &(*p1)->next;
    }*/
    ListNode* newHead = Merge(pHead1, pHead2);
    while (newHead != NULL) {
        cout << newHead->val;
        newHead = newHead->next;
    }
    return 0;
    system("pause");
}