#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {}
};

int LastRemaining_Solution(int n, int m)
{
    if (m < 1 || n < 2) {
        return -1;
    }
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    for (int i = 1; i < n; i++) {
        ListNode* newNode = new ListNode(i);
        p->next = newNode;
        p = p->next;
    }
    p->next = head;
    int len = n;
    while (len > 1) {
        int offset = m;
        offset--;
        while (offset > 1) {
            head = head->next;
            offset--;
        }
        head->next = head->next->next;
        head = head->next;
        len--;
    }
    return head->val;
}

int main() {
    cout << LastRemaining_Solution(13, 6);
    return 0;
}