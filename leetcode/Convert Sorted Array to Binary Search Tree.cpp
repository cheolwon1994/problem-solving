class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        int midIdx = len/2;
        vector<int> leftNums,rightNums;
        for(int i=0;i<midIdx;i++)
            leftNums.push_back(nums[i]);
        for(int i=midIdx+1;i<len;i++)
            rightNums.push_back(nums[i]);
        TreeNode* midNode = new TreeNode(nums[midIdx]);
        if(!leftNums.empty()) midNode->left = sortedArrayToBST(leftNums);
        if(!rightNums.empty()) midNode->right = sortedArrayToBST(rightNums);

        return midNode;
    }
};
