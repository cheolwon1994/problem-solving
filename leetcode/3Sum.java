import java.util.*;
import java.io.*;
import java.lang.*;

//1. 오름차순 정렬 -> 시간복잡도: O(NlgN)
//2. i를 뽑고, 그 이후 index에서 합이 -nums[i] 인것을 투포인터로 찾는다 -> 시간 복잡도: O(N^2)
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        //정렬
        Arrays.sort(nums);
        int len = nums.length;
        List<List<Integer>> li = new ArrayList<>();

        for(int i=0;i<len-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;     //같은 수 중복 제거
            if(nums[i] > 0 || nums[i]+nums[i+1]+nums[i+2] > 0) break;      //0보다 큰 수
            int l = i+1;
            int r = len-1;
            while(l<r) {
                int sum = nums[i]+nums[l]+nums[r];
                if(sum == 0){
                    li.add(Arrays.asList(nums[i], nums[l], nums[r]));
                    l++;
                    r--;
                    while(l<r && nums[l] == nums[l-1]){
                        l++;
                    }
                    while(l<r && nums[r]==nums[r+1]){
                        r--;
                    }
                }
                else if(sum>0) {
                    r--;
                } else {
                    l++;
                }
            }
        }

        return li;
    }
}