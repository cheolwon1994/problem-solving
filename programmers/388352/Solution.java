import java.util.*;
import java.io.*;
import java.lang.*;

class Solution {
    boolean[] selected;
    int answer;

    public void dfs(int max_num, int num, int idx, int[][] q, int[] ans) {
        if(idx ==5) {
            boolean avail = true;
            for(int i=0;i<ans.length;i++){
                int cnt = 0;
                for(int j=0;j<q[i].length;j++){
                    int a = q[i][j];
                    if(selected[a]){
                        cnt++;
                    }
                }
                if(cnt != ans[i]) {
                    avail = false;
                    break;
                }
            }
            if(avail) {

                answer++;
            }
            return;
        }
        if(num>max_num) return;
        //뽑는다
        selected[num] = true;
        dfs(max_num, num+1, idx+1, q, ans);
        selected[num] = false;
        //안뽑는다
        dfs(max_num, num+1, idx, q, ans);
    }

    public int solution(int n, int[][] q, int[] ans) {
        //init
        answer = 0;
        selected = new boolean[31];
        dfs(n, 1, 0, q, ans);
        return answer;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
//1
        int n = 10;

        int[][] q = {
                {1, 2, 3, 4, 5},
                {6, 7, 8, 9, 10},
                {3, 7, 8, 9, 10},
                {2, 5, 7, 9, 10},
                {3, 4, 5, 6, 7}
        };

        int[] ans = {2, 3, 4, 3, 3};

        //2
//        int n = 15;
//
//        int[][] q = {
//                {2, 3, 9, 12, 13},
//                {1, 4, 6, 7, 9},
//                {1, 2, 8, 10, 12},
//                {6, 7, 11, 13, 15},
//                {1, 4, 10, 11, 14}
//        };
//
//        int[] ans = {2, 1, 3, 0, 1};

        System.out.println("정답: " + s.solution(n, q, ans));
    }
}