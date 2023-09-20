#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* makeTree(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir) {
    if (pl > pr || il > ir) return nullptr;
    int rootIdx = -1;
    for (int i = il; i <= ir; i++) {
        if (inorder[i] == preorder[pl]) {
            rootIdx = i;
            break;
        }
    }
    TreeNode* node = new TreeNode(preorder[pl]);
    int leftLen = rootIdx - il;
    node->left = makeTree(preorder, pl + 1, pl + leftLen, inorder, il, rootIdx - 1);
    node->right = makeTree(preorder, pl + leftLen + 1, pr, inorder, rootIdx + 1, ir);

    return node;
}

void printPostorder(TreeNode* node) {
    if (node == nullptr) return;
    if (node->left != nullptr) printPostorder(node->left);
    if (node->right != nullptr) printPostorder(node->right);
    cout << node->val << " ";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test, node, val;
    cin >> test;
    for (int t = 0; t < test; t++) {
        cin >> node;
        vector<int> preorder, inorder;
        for (int i = 0; i < node; i++) {
            cin >> val;
            preorder.push_back(val);
        }
        for (int i = 0; i < node; i++) {
            cin >> val;
            inorder.push_back(val);
        }
        TreeNode* root = makeTree(preorder, 0, node - 1, inorder, 0, node - 1);
        printPostorder(root);
        cout << '\n';
    }
    return 0;
}