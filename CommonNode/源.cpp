#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

/*ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
    vector<int>arr1;
    vector<int>arr2;
    ListNode* cHead1 = pHead1;
    ListNode* cHead2 = pHead2;
    while (cHead1 || cHead2) {
        if (cHead1) {
            arr1.push_back(cHead1->val);
            cHead1 = cHead1->next;
        }
        if (cHead2) {
            arr2.push_back(cHead2->val);
            cHead2 = cHead2->next;
        }
    }
    int nodeCnt = 0;
    int minSize = arr1.size() < arr2.size() ? arr1.size() : arr2.size();
    int offset = arr1.size() - minSize;
    offset = offset == 0 ? arr2.size() - minSize : offset;
    for (int i = minSize - 1; i >= 0; i--) {
        if (minSize == arr1.size()) {
            if (arr1[i] != arr2[i + offset]) {
                break;
            }
        }
        else {
            if (arr1[i + offset] != arr2[i]) {
                break;
            }
        }
        nodeCnt++;
    }
    if (nodeCnt == 0) {
        return NULL;
    }
    else {
        int clip = arr1.size() - nodeCnt;
        cHead1 = pHead1;
        while (clip) {
            cHead1 = cHead1->next;
            clip--;
        }
        return cHead1;
    }
}*/

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
    ListNode* p1 = pHead1;
    ListNode* p2 = pHead2;
    int len1 = 0;
    int len2 = 0;
    int offset;
    while (p1) {
        len1++;
        p1 = p1->next;
    }
    while (p2) {
        len2++;
        p2 = p2->next;
    }
    if (len1 > len2) {
        offset = len1 - len2;
        p1 = pHead1;
        p2 = pHead2;
    }
    else {
        offset = len2 - len1;
        p1 = pHead2;
        p2 = pHead1;
    }
    while (offset) {
        p1 = p1->next;
        offset--;
    }
    while (p1 && p2) {
        if (p1 == p2) {
            return p1;
        }
        else {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return NULL;
}

int main() {
    ListNode* pHead1 = new ListNode(1);
    pHead1->next = new ListNode(2);
    pHead1->next->next = new ListNode(3);

    ListNode* pHead2 = new ListNode(0);
    pHead2->next = pHead1->next->next;

    ListNode* p = FindFirstCommonNode(pHead1, pHead2);
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    return 0;
}