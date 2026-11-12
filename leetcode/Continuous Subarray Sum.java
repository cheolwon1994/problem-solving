import java.util.*;
import java.io.*;
import java.lang.*;

// 모든 원소를 k로 나눈 나머지로 치환한다
// map을 이용하여 <0~i번째 index까지의 합, index>를 저장하여, 0~i까지 순회하면서 일치하는 합이 나오고, i-index>1인 부분이 있으면 true 반환
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int len = nums.length;
        if(len == 1) return false;

        HashMap<Integer, Integer> m = new HashMap<>();
        m.put(0,-1);      //합이 0인 부분 init

        int sum = 0;
        for(int i=0;i<len;i++){
            nums[i] = nums[i]%k;
            if(i==0){
                sum = nums[i];
            } else {
                sum = (sum + nums[i])%k;
            }

            if(m.get(sum)==null) {
                m.put(sum, i);
            } else {
                int prevIdx = m.get(sum);
                if(i-prevIdx>1) {
                    return true;
                }
            }
        }

        return false;
    }
}