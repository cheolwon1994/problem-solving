import java.io.*;

class Solution {
    public void nextPermutation(int[] nums) {
        int len = nums.length;
        int pivot = len-2;
        boolean found = false;

        for(;pivot>=0;pivot--) {
            if(nums[pivot] < nums[pivot+1]) {
                //pivot 발견
                for(int j=len-1;j>pivot;j--) {
                    int val = nums[j];
                    //swap
                    if(val > nums[pivot]) {
                        nums[j] = nums[pivot];
                        nums[pivot] = val;
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }
        }

        // revsere pivot+1 ~ len
        int l = pivot +1;
        int r = len -1;
        while(l<r) {
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
            r--;
        }
    }
}