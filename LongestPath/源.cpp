#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

int longest = 0;
void dfs(TreeNode* root, int d) {
    if (root->left == NULL && root->right == NULL) {
        if (d > longest) {
            longest = d;
        }
        return;
    }
    if (root->left) {
        dfs(root->left, d + 1);
    }
    if (root->right) {
        dfs(root->right, d + 1);
    }
}
int TreeDepth(TreeNode* pRoot)
{
    if (pRoot == NULL) {
        return longest;
    }
    dfs(pRoot, 1);
    return longest;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->left->left = new TreeNode(5);
    cout << TreeDepth(NULL);
    return 0;
}