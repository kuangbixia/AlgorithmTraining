#include<iostream>
using namespace std;


struct TreeLinkNode {
    int val;
    struct TreeLinkNode* left;
    struct TreeLinkNode* right;
    struct TreeLinkNode* next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
    if (pNode == NULL) {
        return NULL;
    }
    if (pNode->right) {
        TreeLinkNode* p = pNode->right;
        while (p->left) {
            p = p->left;
        }
        return p;
    }
    else {
        if (pNode->next) {
            // 中间节点的左节点
            if (pNode->next->left == pNode) {
                return pNode->next;
            }
            // 中间节点的右节点
            else {
                bool rightest = true;
                TreeLinkNode* r = pNode->next;
                while (r->next) {
                    if (r->next->left == r) {
                        rightest = false;
                        break;
                    }
                    r = r->next;
                }
                if (!rightest) {
                    return pNode->next->next;
                }
                else {
                    return NULL;
                }
            }
        }
        else {
            return NULL;
        }
    }
}

int main() {
    TreeLinkNode* r = new TreeLinkNode(7);
    r->next = new TreeLinkNode(6);
    r->next->right = r;
    r->next->left = new TreeLinkNode(5);
    r->next->left->next = r->next;
    TreeLinkNode* res = GetNext(r->next);
    cout << res->val << endl;
    return 0;
}