import java.util.*;
import java.io.*;

class Solution {
    public int solution(int n, int col, int num) {
        int answer = 0;
        int targetX = -1;
        for(int i=1;i<=n;i++){
            int y = (i-1)/col;
            int x;
            if(y%2==0) {
                x = (i-1)%col;
            } else {
                x = (y+1)*col-i;
            }

            if(x == targetX && answer>0){
                answer++;
            }
            if(i==num) {
                answer = 1;
                targetX = x;
            }
        }

        return answer;
    }
}