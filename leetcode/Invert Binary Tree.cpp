class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        TreeNode* node = root->left;
        root->left = root->right;
        root->right = node;
        
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
