#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };




int main() {
    
    ListNode* three = new ListNode(3);
    ListNode* two = new ListNode(4);
    ListNode* l1 = new ListNode(2);
    two->next = three;
    l1->next = two;
    three = new ListNode(4);
    two = new ListNode(6);
    ListNode* l2 = new ListNode(5);
    two->next = three;
    l2->next = two;
    

    /*
    ListNode* l1 = new ListNode(5);
    ListNode* l2 = new ListNode(5);
    */

    int carry = 0;
    int sum = l1->val + l2->val;
    carry = sum / 10;
    sum %= 10;
    ListNode* head = new ListNode(sum);
    ListNode** p = &head;
    l1 = l1->next;
    l2 = l2->next;

    while (l1 != nullptr || l2 != nullptr) {
        sum = 0;
        if (l1 != nullptr) {
            sum += l1->val;
        }
        if (l2 != nullptr) {
            sum += l2->val;
        }
        sum += carry;

        carry = sum / 10;
        sum %= 10;
        ListNode* newNode = new ListNode(sum);
        (*p)->next = newNode;

        // ERROR:p会一直指向newNode的地址
        //p = &newNode;
        p = &(*p)->next;

        if (l1 != nullptr) {
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            l2 = l2->next;
        }

    }

    if (carry) {
        ListNode* newNode = new ListNode(carry);
        (*p)->next = newNode;
    }

    while (head != nullptr) {
        cout << head->val << endl;
        head = head->next;
    }

    return 0;
    system("pause");
}