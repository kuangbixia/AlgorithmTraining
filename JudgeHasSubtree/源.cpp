#include<iostream>
using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
/*
bool ans = false;

bool CheckRoot(TreeNode* head1, TreeNode* head2) {
    if (head1->val != head2->val) {
        return false;
    }
    else {
        if (head2->left != NULL&&head2->right==NULL) {
            if (head1->left == NULL) {
                return false;
            }
            else {
                return CheckRoot(head1->left, head2->left);
            }
        }
        else if (head2->right != NULL&&head2->left==NULL) {
            if (head1->right == NULL) {
                return false;
            }
            else {
                return CheckRoot(head1->right, head2->right);
            }
        }
        else if (head2->left != NULL && head2->right != NULL) {
            if (head1->left == NULL || head1->right == NULL) {
                return false;
            }
            else {
                return CheckRoot(head1->left, head2->left) && CheckRoot(head1->right, head2->right);
            }
        }
        else {
            return true;
        }
    }
}

void preAccess(TreeNode* root, TreeNode* pRoot2) {
    if (root != NULL) {
        ans = CheckRoot(root, pRoot2) || ans;
        if (ans) {
            return;
        }
    }
    else {
        return;
    }
    preAccess(root->left, pRoot2);
    preAccess(root->right, pRoot2);
}
*/

bool CheckSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    // 判断一边子树（即左子树或右子树）是否满足条件
    if (pRoot2 == NULL) {
        return true;
    }
    if (pRoot1 == NULL) {
        return false;
    }
    if (pRoot1->val == pRoot2->val) {
        return CheckSubtree(pRoot1->left, pRoot2->left) && CheckSubtree(pRoot1->right, pRoot2->right);
    }
    else {
        return false;
    }
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    // 空树不是任何树的子结构
    if (pRoot1 == NULL || pRoot2 == NULL) {
        return false;
    }
    /*
    preAccess(pRoot1, pRoot2);
    return ans;
    */

    return CheckSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}

int main() {

}