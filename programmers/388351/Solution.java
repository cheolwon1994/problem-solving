import java.util.*;
import java.io.*;
import java.lang.*;


class Solution {
    public int toTime(int t) {
        int h = t/100;
        int m = t%100;
        return h*60+m;
    }

    public int solution(int[] schedules, int[][] timelogs, int startday) {
        int answer = 0;
        for(int i=0;i<schedules.length;i++){
            boolean success = true;
            int scheduleTime = toTime(schedules[i]);
            for(int j=0;j<timelogs[i].length;j++){
                int mod = (startday+j)%7;
                if(mod==6 || mod==0) {
                    continue;
                }
                int arriveTime = toTime(timelogs[i][j]);
                if(arriveTime<=scheduleTime+10) continue;
                else {
                    success = false;
                    break;
                }
            }
            System.out.println();
            if(success) answer++;
        }

        return answer;
    }
}