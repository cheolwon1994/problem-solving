import java.util.*;
import java.io.*;
import java.lang.*;

class Solution {
    public int solution(int[] diffs, int[] times, long limit) {
        long answer = 0;
        long l =1, r = limit;
        //이분탐색 통해 시도
        while(l<=r) {
            long mid = l + (r-l)/2;
            long acc = 0;
            boolean success = true;
            for(int i=0;i<diffs.length;i++){
                //틀리지 않는다
                if(mid>=diffs[i]) {
                    acc += times[i];
                } else {
                    // diff[0]은 무조건 1이므로 i=0은 무조건 한번에 통과한다
                    // 그래서 if(i>0)는 생략
                    long diff = (long)diffs[i]-mid;
                    acc += (times[i]*(diff+1)+ times[i-1]*diff);
                }
                //이미 limit을 넘긴 경우 -> 실패
                if(acc > limit) {
                    //레벨 올린다
                    success = false;
                    break;
                }
            }
            if(success) {
                answer = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return (int) answer;
    }
}