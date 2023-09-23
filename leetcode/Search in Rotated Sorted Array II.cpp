class Solution {
public:

    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0, r = len-1;

        while(l <= r){
            int mid = l +(r - l) / 2;
            if(nums[mid] == target) return true;
            //1. check if l,mid,r's index has same value
            if(nums[l] == nums[mid] && nums[mid] == nums[r]){
                l++;
                r--;
            }
            //index l ~ mid is sorted in non-decreasing order
            else if(nums[l] <= nums[mid]){
                if(nums[l] <= target && target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            }
            //index mid ~ l is sorted in non-decreasing order
            else{
                if(nums[mid] < target && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            }
        }

        return false;
    }
};
