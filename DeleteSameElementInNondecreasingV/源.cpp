#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

ListNode* ReorderLinkList(ListNode* newHead, ListNode* newTail, ListNode* head, int base) {
	while (head != NULL) {
		if (head->val < base) {
			newTail->next = head->next;
			head->next = newHead;
			newHead = head;
			head = newTail->next;
		}
		else {
			newTail = head;
			head = head->next;
		}
	}
	return newHead;
}

vector<int> DeleteRepeated(vector<int>L) {
	L.erase(unique(L.begin(), L.end()), L.end());
	return L;
}

vector<int> DeleteCertain(vector<int>L,int x,int y) {
	for (int i = 0; i < L.size(); i++) {
		if (L[i] >= x && L[i] <= y) {
			L.erase(L.begin() + i, L.begin() + i + 1);
			i--;
		}
	}
	return L;
}

int main() {
	// 测试数据 1
	ListNode* TestHead = new ListNode(5);
	ListNode* temp = TestHead;
	temp->next = new ListNode(6);
	temp = temp->next;
	temp->next = new ListNode(1);
	temp = temp->next;
	temp->next = new ListNode(8);
	temp = temp->next;
	temp->next = new ListNode(3);
	ListNode* Result1 = ReorderLinkList(TestHead, TestHead, TestHead, TestHead->val);
	while (Result1 != NULL) {
		cout << Result1->val << " ";
		Result1 = Result1->next;
	}
	cout << "\n-----------------\n";

	// 测试数据 2
	vector<int>TestL({ 2,2,2,3,4,4,5,5,6,6 });
	vector<int>Result2 = DeleteRepeated(TestL);
	for (int i = 0; i < Result2.size(); i++) {
		cout << Result2[i] << " ";
	}
	cout << "\n-----------------\n";

	// 测试数据 3
	int x = 3, y = 5;
	vector<int>Result3 = DeleteCertain(TestL, x, y);
	for (int i = 0; i < Result3.size(); i++) {
		cout << Result3[i] << " ";
	}
	cout << "\n-----------------\n";
	
	return 0;
}