import java.util.*;
import java.io.*;
import java.lang.*;

class Info{
    int y, x;
    Info(int y, int x) {
        this.y = y;
        this.x = x;
    }
}

class Solution {
    int[] dy = new int[]{-1,0,1,0};
    int[] dx = new int[]{0,1,0,-1};
    public int solution(int[][] land) {
        int answer = 0;
        int row = land.length;
        int col = land[0].length;
        int[] oilSum = new int[col+1];

        boolean[][] visit = new boolean[row][col];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                //땅 또는 이미 계산된 석유 덩어리
                if(land[i][j]==0 || visit[i][j]) continue;
                //석유
                Queue<Info> q = new LinkedList<>();
                q.offer(new Info(i,j));
                visit[i][j] = true;
                int cnt = 1;
                int minX = j;
                int maxX = j;

                while(!q.isEmpty()){
                    Info ii = q.poll();
                    int cy = ii.y;
                    int cx = ii.x;
                    for(int k=0;k<4;k++){
                        int nx = cx +dx[k];
                        int ny = cy +dy[k];
                        if(nx>=0 && ny>=0 && ny<row && nx<col && !visit[ny][nx] && land[ny][nx]==1) {
                            visit[ny][nx] = true;
                            cnt++;
                            q.offer(new Info(ny, nx));
                            minX = Math.min(minX, nx);
                            maxX = Math.max(maxX, nx);
                        }
                    }
                }

                for(int k=minX;k<=maxX;k++) {
                    oilSum[k] += cnt;
                }
            }
        }
        for(int i=0;i<col;i++){
            answer = Math.max(answer, oilSum[i]);
        }
        return answer;
    }
}