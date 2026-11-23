import java.util.*;
import java.lang.*;
import java.io.*;

class Info{
    int idx;
    int team;       //1, 2
    public Info(int idx, int team) {
        this.idx = idx;
        this.team = team;
    }
}

// 0번 node부터 1번 팀으로 시작한다
// 연결된 모든 node에 3-{본인 팀}번팀을 부여한다
// 이미 팀을 부여받은 node인 경우, 본인과 같다면 false 반환
// 모든 node에 부여 성공한 경우, true 반환
class Solution {
    public boolean isBipartite(int[][] graph) {
        int node = graph.length;
        int[] teamNum = new int[node];      //0: 미방문, team: 1 or 2

        for(int i=0;i<node;i++){
            if(teamNum[i]>0) continue;      //이미 팀이 부여된 node
            teamNum[i] = 1;
            Queue<Info> q = new LinkedList<>();
            q.offer(new Info(i, 1));
            while(!q.isEmpty()) {
                Info ii = q.poll();
                int cidx = ii.idx;
                int currentTeam = ii.team;
                for(int k=0;k<graph[cidx].length;k++) {
                    int next = graph[cidx][k];
                    int nt = teamNum[next];
                    if(nt == 0) {        //미방문
                        teamNum[next] = 3 - currentTeam;
                        q.offer(new Info(next, 3-currentTeam));
                    } else if(nt == currentTeam) {      //동일 팀인 경우
                        return false;
                    } else {    //반대 팀
                        continue;
                    }
                }
            }
        }
        return true;
    }
}