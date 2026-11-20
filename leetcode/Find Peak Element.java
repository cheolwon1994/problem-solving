// 1 4 3 -> return
// 5 4 5 -> 양쪽 다 큰 경우 -> 아무 방향으로 가도 된다. 배열 밖의 점은 -무한대라 무조건 peak가 있다
// 6 5 4 -> 오른쪽이 더 작은 경우 -> 왼쪽으로 탐색. 단, mid가 peak일 수 있으니 r = m
// 4 5 6 -> 오른쪽이 큰 경우 -> 오른쪽을 탐색. mid가 peak일 수 없으니, l = m+1

import java.util.*;

class Solution {
    public int findPeakElement(int[] nums) {
        int len = nums.length;
        int l = 0;
        int r = len-1;

        while(l<r) {
            int m = l + (r-l)/2;
            int mv = nums[m];

            int rv = nums[m+1];
            //오른쪽값만 확인
            if(mv < rv) {      //우상향
                l = m+1;
            } else {        //우하향
                if(m==0 || (m>0 &&nums[m-1]<mv)) return m;
                r = m;
            }
        }
        return l;
    }
}