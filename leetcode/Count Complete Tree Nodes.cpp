class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int answer = 1;
        //check left
        if(root->left != nullptr) answer += countNodes(root->left);
        //check right
        if(root->right != nullptr) answer += countNodes(root->right);

        return answer;
    }
};
