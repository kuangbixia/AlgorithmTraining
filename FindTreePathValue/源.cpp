#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
    
vector<vector<int>>ans;
vector<int>path;
void checkLeaf(TreeNode* root, int sum, int expectNumber) {
    path.push_back(root->val);
    sum += root->val;
    if (sum > expectNumber) {
        path.pop_back();
        return;
    }
    if (root->left) {
        checkLeaf(root->left, sum, expectNumber);
    }
    if (root->right) {
        checkLeaf(root->right, sum, expectNumber);
    }
    if (!root->left && !root->right) {
        if (sum == expectNumber) {
            ans.push_back(path);
        }

    }
    path.pop_back();
    return;
}

vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
    if (root == NULL) {
        return ans;
    }
    checkLeaf(root, 0, expectNumber);
    for (int i = 1; i < ans.size(); i++) {
        ans.push_back(ans[i]);
        int j;
        for (j = i - 1; j >= 0; j--) {
            if (ans[j].size() > ans[i].size()) {
                break;
            }
            else {
                ans[j + 1] = ans[j];
            }
        }
        ans[j + 1] = ans[ans.size() - 1];
        ans.pop_back();
    }
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(3);
    root->left = left;
    root->right = right;
    left = new TreeNode(1);
    right = new TreeNode(5);
    root->left->left = left;
    root->left->right = right;

    vector<vector<int>>ans;
    ans = FindPath(root, 4);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}