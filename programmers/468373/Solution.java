import java.util.*;
import java.lang.*;
import java.io.*;

//1회에 열 수 있는 파이프 수: 3, k는 최대 10 -> 3^10: 243*243으로 1초 이내에 가능할것으로 판단
//모든 경우를 수행해본다.

class Info {
    int to, pipe;       //다른 배양채와 연결된 파이프 종류
    Info(int to, int pipe) {
        this.to = to;
        this.pipe = pipe;
    }
}

class Solution {
    List<Info>[] li;
    int answer;

    //감염 여부, 개방할 파이프 종류, 현재까지 행동 수, 최대 행동 수
    public void spread(boolean[] infected, int openPipeNum, int cnt, int k) {
        Queue<Integer> q = new LinkedList<>();
        for(int i=1;i<infected.length;i++){
            if(infected[i]){
                q.offer(i);
            }
        }
        List<Integer> newAdded = new ArrayList<>();
        while(!q.isEmpty()) {
            //추가로 닿을 수 있는 배양채는 다 담는다
            int curr = q.poll();
            for(int j=0;j<li[curr].size();j++){
                Info ii = li[curr].get(j);
                if(infected[ii.to]) continue;
                //감연된 적 없고, 열어야하는 파이프 종류와 같을 때
                if(ii.pipe == openPipeNum) {
                    infected[ii.to] = true;
                    q.offer(ii.to);
                    newAdded.add(ii.to);
                }
            }
        }
        bruteforce(infected, cnt+1, k);
        for(int n: newAdded) {
            infected[n] = false;
        }
    }

    //감염 여부, 현재까지 행동 수, 최대 행동 수
    public void bruteforce(boolean[] infected, int cnt, int k) {
        if(cnt == k) {
            int sum = 0;
            for(int i=1;i<infected.length;i++){
                if(infected[i]){
                    sum++;
                }
            }
            answer = Math.max(answer, sum);
            return;
        }
        for(int i=1;i<4;i++){
            spread(infected, i, cnt, k);
        }
    }

    public int solution(int n, int infection, int[][] edges, int k) {
        //init
        answer = 1;
        li = new List[n+1];
        for(int i=1;i<=n;i++){
            li[i] = new ArrayList<>();
        }
        boolean[] infected = new boolean[n+1];               //감염된 배양채
        //배양채와 연결된 파이프 정보 저장
        for(int i=0;i<edges.length;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            int p = edges[i][2];
            li[a].add(new Info(b, p));
            li[b].add(new Info(a, p));
        }

        //감염 처리
        infected[infection] = true;
        bruteforce(infected, 0, k);

        return answer;
    }
}