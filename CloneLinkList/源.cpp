#include<iostream>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode* next, * random;
    RandomListNode(int x) :
        label(x), next(NULL), random(NULL) {
    }
};

RandomListNode* Clone(RandomListNode* pHead)
{
    if (pHead == NULL) {
        return NULL;
    }
    RandomListNode* cHead = new RandomListNode(pHead->label);
    RandomListNode* tempC = cHead;
    RandomListNode* tempP = pHead;
    while (tempP->next) {
        tempC->next = new RandomListNode(tempP->next->label);
        tempP = tempP->next;
        tempC = tempC->next;
    }
    tempC = cHead;
    RandomListNode* find = cHead;
    tempP = pHead;
    while (tempC) {
        while (tempP->random && find) {
            if (find->label == tempP->random->label) {
                tempC->random = find;
                break;
            }
            else {
                find = find->next;
            }
        }

        tempC = tempC->next;
        tempP = tempP->next;
        find = cHead;
    }
    return cHead;
}

int main() {
    RandomListNode* head = new RandomListNode(1);
    head->next = new RandomListNode(2);
    head->next->next = new RandomListNode(3);
    head->next->next->random = head->next;
    head->next->random = head->next->next;
    head->random = head->next->next;
    RandomListNode* ans = Clone(head);
    while (ans) {
        cout << ans->label << " " << ans->random->label << endl;
        ans = ans->next;
    }
    return 0;
}