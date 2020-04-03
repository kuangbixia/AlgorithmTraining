#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

TreeNode* KthNode(TreeNode* pRoot, int k)
{
    if (pRoot == NULL) {
        return NULL;
    }
    int i = 0;
    stack<TreeNode*>s;
    TreeNode* p = pRoot;
    while (!s.empty() || p != NULL) {
        while (p) {
            s.push(p);
            p = p->left;
        }
        // 保证不压入新元素就只访问右子节点，不重复访问左子节点
        TreeNode* top = s.top();
        s.pop();
        i++;
        if (i == k) {
            return top;
        }
        p = top->right;
    }
    return NULL;
}

int main() {
    TreeNode* r = new TreeNode(2);
    r->left = new TreeNode(1);
    r->right = new TreeNode(3);
    cout << KthNode(r, 2)->val << endl;
    return 0;

}