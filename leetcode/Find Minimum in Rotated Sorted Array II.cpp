class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len-1;
        int answer = 5001;

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[l] == nums[mid] && nums[l] == nums[r]){
                answer = min(answer, nums[l]);
                l++;
                r--;
            }
            //l~mid is sorted in ascending order
            else if(nums[l] <= nums[mid]){
                answer = min(answer, nums[l]);
                l = mid + 1;
            }
            else {
                answer = min(answer, nums[mid]);
                r = mid - 1;
            }
        }
        return answer;
    }
};