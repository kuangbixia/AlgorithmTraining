#include<vector>
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    if (pHead == NULL) {
        return NULL;
    }
    vector<ListNode*>nodes;
    while (pHead != NULL) {
        for (int i = 0; i < nodes.size(); i++) {
            if (pHead == nodes[i]) {
                return pHead;
            }
        }
        nodes.push_back(pHead);
        pHead = pHead->next;
    }
    return NULL;
}
