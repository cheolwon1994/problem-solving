import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        Queue<Integer> q = new ArrayDeque<>();

        for(int i=0;i<players.length;i++) {
            //사라질 증설서버 확인
            int current_player = players[i];
            while(!q.isEmpty()){
                if(q.peek()+k<=i){
                    q.poll();
                } else break;
            }
            //필요한 서버 수
            int need_sever_cnt = current_player/m;
            //추가로 필요한 서버 수
            int server_supply_cnt = need_sever_cnt - q.size();

            while(server_supply_cnt > 0){
                q.offer(i);
                answer++;
                server_supply_cnt--;
            }
        }
        return answer;
    }
}