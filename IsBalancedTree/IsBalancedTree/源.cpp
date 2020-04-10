#include<iostream>
#include<math.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

int getHeight(TreeNode* r) {
    if (r == NULL) {
        return 0;
    }
    int hl = 0;
    int hr = 0;
    if (r->left) {
        hl = getHeight(r -> left);
    }
    if (r->right) {
        hr = getHeight(r->right);
    }
    int h = hl < hr ? hr : hl;
    h += 1;
    return h;
}

bool IsBalanced_Solution(TreeNode* pRoot) {
    if (pRoot == NULL) {
        return true;
    }
    return (abs(getHeight(pRoot->left) - getHeight(pRoot->right)) <= 1) && IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(4);
    cout << IsBalanced_Solution(root) << endl;
	return 0;
}