class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int left = 0,mid = 0,right = len-1;
        while(mid<=right){
            int val = nums[mid];
            if(val == 0){
                swap(nums[left],nums[mid]);
                left++;
                mid++;
            }
            else if(val==1){
                mid++;
            }
            //2
            else{
                swap(nums[mid], nums[right]);
                right--;
            }
        }
    }
};
