#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

char* ans = new char[100000];
int i = 0;
void InOrder(TreeNode* r) {
    if (r == NULL) {
        ans[i++] = '#';
        ans[i++] = ' ';
        return;
    }
    else {
        int rVal = r->val;
        vector<char>num;
        while (rVal) {
            num.push_back(char(rVal % 10 + '0'));
            rVal /= 10;
        }
        for (int k = num.size()-1; k >=0; k--) {
            ans[i++] = num[k];
        }
        ans[i++] = ' ';
    }
    InOrder(r->left);
    InOrder(r->right);
}
char* Serialize(TreeNode* root) {
    InOrder(root);
    ans[i++] = '!';
    ans[i++] = '\n';
    return ans;
}


int GetValue(char**pStr) {
    int val = 0;
    int bit = 1;
    vector<char>bits;
    while (**pStr != ' ') {
        bits.push_back(**pStr);
        (*pStr)++;
    }
    (*pStr)++;
    for (int i = bits.size() - 1; i >= 0; i--) {
        val += (bits[i] - '0') * bit;
        bit *= 10;
    }
    return val;
}
TreeNode* Reconstruct(char**pStr) {
    if (**pStr == '#') {
        (*pStr) += 2;
        return NULL;
    }
    TreeNode* newNode = new TreeNode(GetValue(pStr));
    newNode->left = Reconstruct(pStr);
    newNode->right = Reconstruct(pStr);
    return newNode;
}
TreeNode* Deserialize(char* str) {
    if (*str == '#') {
        return NULL;
    }
    TreeNode* head = Reconstruct(&str);
    return head;
}

int main() {
    TreeNode* input = new TreeNode(8);
    input->left = new TreeNode(6);
    input->right = new TreeNode(100);
    input->left->left = new TreeNode(5);
    input->left->right = new TreeNode(7);
    input->right->left = new TreeNode(9);
    input->right->right = new TreeNode(11);
    char* s = Serialize(input);

    int k = 0;
    while (s[k] != '!') {
        cout << s[k++] << " ";
    }
    cout << endl;
    
    TreeNode* output = Deserialize(s);
    char* str = Serialize(output);
    k = 0;
    while (s[k] != '!') {
        cout << s[k++] << " ";
    }
    cout << endl;


	return 0;
}