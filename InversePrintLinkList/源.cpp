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

vector<int>ArrayList;

void ToInverse(ListNode* temp) {
    if (temp->next != NULL) {
        ToInverse(temp->next);
        ArrayList.push_back(temp->val);
    }
    else {
        return;
    }
}

int main() {
    ListNode* head = new ListNode(0);
    ListNode* newNode;
    ListNode** p = &head;
    for (int i = 1; i < 7; i++) {
        newNode = new ListNode(i);
        (*p)->next = newNode;
        p = &(*p)->next;
    }
    
    ToInverse(head);
    for (int i = 0; i < ArrayList.size(); i++) {
        cout << ArrayList[i] << endl;
    }

    return 0;
    system("pause");
}