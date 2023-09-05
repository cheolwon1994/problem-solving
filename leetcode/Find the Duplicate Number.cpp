class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare = nums[0];
        int turtle = nums[0];

        while (true) {
            turtle = nums[turtle];
            hare = nums[nums[hare]];
            if (turtle == hare) break;
        }
        
        int root = nums[0];
        while(root != turtle){
            root = nums[root];
            turtle = nums[turtle];
        }
        return root;
    }
};