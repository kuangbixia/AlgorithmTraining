#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

int main() {
    ListNode* pHead = new ListNode(1);
    ListNode* newNode;
    ListNode** tempG = &pHead;
    for (int i = 2; i <= 6; i++) {
        newNode = new ListNode(i);
        (*tempG)->next = newNode;
        tempG = &(*tempG)->next;
    }

    if (pHead == NULL) {
        cout << pHead->val;
        return 0;
    }
    ListNode* p1 = pHead;
    ListNode* p2 = p1->next;
    while (p2!= NULL) {
        ListNode* temp = p2->next;
        if (p1 == pHead) {
            p1->next = NULL;
        }
        p2->next = p1;
        if (temp == NULL) {
            cout << p2->val << endl;
            cout << p2->next->val << endl;
            return 0;
        }
        p1 = p2;
        p2 = temp;
    }
    cout << p1->val << endl;
    return 0;
    system("pause");
}