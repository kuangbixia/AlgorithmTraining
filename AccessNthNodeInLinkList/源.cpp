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

int main() {
    /*ListNode* pListHead = new ListNode(1);
    ListNode* newNode;
    ListNode** temp = &pListHead;
    for (int i = 2; i <= 6; i++) {
        newNode = new ListNode(i);
        (*temp)->next = newNode;
        temp = &(*temp)->next;
    }
    */
    ListNode* pListHead = NULL;
    vector<ListNode*>array;
    while (pListHead != NULL) {
        array.push_back(pListHead);
        pListHead = pListHead->next;
    }

    for (int i = 0; i < array.size(); i++) {
        cout << array[i]->val << endl;
    }
    return 0;
    system("pause");
}