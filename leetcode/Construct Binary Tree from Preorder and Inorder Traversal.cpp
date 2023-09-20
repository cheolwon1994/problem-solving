class Solution {
public:
    TreeNode* makeTree(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
        if(pl > pr || il > ir) return nullptr;
        //get rootIdx of inorder;
        int ridx = -1;
        for(int i=il;i<=ir;i++){
            if(inorder[i]==preorder[pl]){
                ridx = i;
                break;
            }
        }
        TreeNode* node = new TreeNode(preorder[pl]);
        int leftLen = ridx-il;
        node->left = makeTree(preorder, inorder, pl+1, pl+leftLen, il, ridx-1);
        node->right = makeTree(preorder, inorder, pl+leftLen+1, pr, ridx+1, ir);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        int len = preorder.size();

        return makeTree(preorder, inorder, 0, len-1, 0, len-1);
    }
};