class Solution {
    public int removeDuplicates(int[] nums) {
        int prevNum = -101;
        int cnt = 0;
        for(int i=0;i<nums.length;i++) {
            if(prevNum != nums[i]) {
                prevNum = nums[i];
                nums[cnt++] = nums[i];
            }
        }
        return cnt;
    }
}