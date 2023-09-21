class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        //1. sort
        sort(nums.begin(), nums.end());
        int answer = nums[0] + nums[1] + nums[2];

        //2. set first index from [0,len-2)
        for(int i=0;i<len-2;i++){
            //3. get 2 pointer
            int l = i+1;
            int r = len-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(abs(target-answer) > abs(target-sum)){
                    answer = sum;
                }
                if(sum == target){
                    answer = target;
                    goto label;
                }
                else if(sum < target) l++;
                else r--;
            }
        }
        label:

        return answer;
    }
};