#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int>>ans;
    if (pRoot == NULL) {
        return ans;
    }
    queue<TreeNode*>q1;
    queue<TreeNode*>q2;
    q1.push(pRoot);
    while (q1.size() || q2.size()) {
        vector<int>R;
        if (q1.size()) {
            while (q1.size()) {
                if (q1.front()->left) {
                    q2.push(q1.front()->left);
                }
                if (q1.front()->right) {
                    q2.push(q1.front()->right);
                }
                R.push_back(q1.front()->val);
                q1.pop();
            }
        }
        else {
            while (q2.size()) {
                if (q2.front()->left) {
                    q1.push(q2.front()->left);
                }
                if (q2.front()->right) {
                    q1.push(q2.front()->right);
                }
                R.push_back(q2.front()->val);
                q2.pop();
            }
        }
        ans.push_back(R);
    }
    return ans;
}

int main() {
    TreeNode* r = new TreeNode(8);
    r->left = new TreeNode(6);
    r->right = new TreeNode(10);
    vector<vector<int>>ans = Print(r);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].size() << endl;
    }
    return 0;
}