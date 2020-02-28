#include<iostream>
#include<vector>
using namespace std;

//Definition for binary tree
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

int nextPre = 0;

TreeNode* findSons(TreeNode* root, vector<int> pre, vector<int> vin, vector<int> sub) {
    nextPre++;

    if (sub[0]==sub[1]) {
        TreeNode* leaf = new TreeNode(vin[sub[0]]);
        return leaf;
    }

    vector<int>left;
    vector<int>right;
    int leftLength = find(vin.begin(), vin.end(), root->val) - find(vin.begin(), vin.end(), vin[sub[0]]);
    int rightLength = find(vin.begin(), vin.end(), vin[sub[1]]) - find(vin.begin(), vin.end(), root->val);
    if (leftLength) {
        left.push_back(sub[0]);
        left.push_back(sub[0] + leftLength - 1);
    }
    if (rightLength) {
        right.push_back(sub[1] - rightLength + 1);
        right.push_back(sub[1]);
    }
    
    if (!left.empty()) {
        TreeNode* nextRoot = new TreeNode(pre[nextPre]);
        root->left = findSons(nextRoot, pre, vin, left);
    }

    if (!right.empty()) {
        TreeNode* nextRoot = new TreeNode(pre[nextPre]);
        root->right = findSons(nextRoot, pre, vin, right);
    }
    return root;
}

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    TreeNode* root = new TreeNode(pre[0]);
    int length = pre.size();
    vector<int>sub({ 0,length - 1 });
    root = findSons(root, pre, vin, sub);
    return root;
}

int main() {
    vector<int> pre({ 1,2,4,7,3,5,6,8 });
    vector<int> vin({ 4,7,2,1,5,3,8,6 });
    TreeNode* root = reConstructBinaryTree(pre, vin);
    while (root != NULL) {
        cout << root->val << endl;
        root = root->left;
    }
 
    return 0;
    system("pause");
}