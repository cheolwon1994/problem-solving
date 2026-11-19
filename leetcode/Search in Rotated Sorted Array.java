import java.io.*;

// 0,1,2,4,5,6,7 -> 왼 < m < 오
// 1,2,4,5,6,7,0
// 4,5,6,7,0,1,2 -> 왼 > 오
// lv: 4, mv: 7, rv: 2
// 7 0 1 2
// lv: 7, mv: 0, rv: 2
// 7 0
// lv: 7, mv: 7, rv: 0
// 6,7,0,1,2,4,5 -> 왼 > 오

class Solution {
    public int binarySearch(int l, int r, int[] nums, int target){
        while(l<=r) {
            int m = l + (r-l)/2;
            int mv = nums[m];
            if(mv == target) {
                return m;
            } else if(mv > target) {
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return -1;
    }

    public int search(int[] nums, int target) {
        int len = nums.length;
        int l = 0;
        int r = len-1;

        while(l < r) {
            int m = l + (r-l)/2;
            int mv = nums[m];
            int rv = nums[r];
            if(mv == target) return m;
            if(mv > rv) {       //pivot은 m~r 사이
                //왼쪽은 정렬
                l = m+1;
            } else {
                r = m;
            }
        }
        int pivot = r;
        //0 ~ r-1, r~len-1
        if(r>1 && nums[0] <= target && target <= nums[r-1]) {
            return binarySearch(0, r-1, nums, target);
        } else {
            return binarySearch(r, len-1, nums, target);
        }
    }
}