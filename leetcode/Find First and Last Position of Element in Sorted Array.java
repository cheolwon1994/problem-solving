class Solution {
    public int[] searchRange(int[] nums, int target) {
        int len = nums.length;
        int l=0, r = len-1;
        int lidx = -1;
        int ridx = -1;

        //find left idx
        while(l<=r) {
            int m = l + (r-l)/2;
            int lv = nums[l];
            int mv = nums[m];
            int rv = nums[r];

            if(mv < target) {
                l = m+1;
            } else {        //mv >= target
                if(mv == target) {
                    lidx = m;
                }
                r = m-1;
            }
        }
        if(lidx == -1) return new int[]{lidx, ridx};

        //find right idx
        l = 0;
        r = len-1;
        while(l<=r) {
            int m = l + (r-l)/2;
            int lv = nums[l];
            int mv = nums[m];
            int rv = nums[r];

            if(mv <= target) {
                if(mv == target) {
                    ridx = m;
                }
                l = m+1;
            } else {        //mv > target
                r = m-1;
            }
        }

        return new int[]{lidx, ridx};
    }
}