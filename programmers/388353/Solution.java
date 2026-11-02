import java.util.*;
import java.io.*;
import java.lang.*;

class Info{
    int y,x;
    Info(int y, int x) {
        this.y = y;
        this.x = x;
    }
}

class Solution {
    int[] dy = new int[]{-1,0,1,0};
    int[] dx = new int[]{0,1,0,-1};

    public int solution(String[] storage, String[] requests) {
        int row = storage.length;
        int col = storage[0].length();
        int answer = row*col;

        char[][] arr = new char[row+2][col+2];
        for(int i=0;i<row+2;i++){
            for(int j=0;j<col+2;j++){
                arr[i][j] = ' ';
                if(1<= i && i<=row && 1<=j && j<=col) {
                    arr[i][j] = storage[i-1].charAt(j-1);
                } else arr[i][j] = ' ';
            }
        }

        for(String s: requests){
            char c = s.charAt(0);

            //지게차
            if(s.length()==1) {
                Queue<Info> q = new ArrayDeque<>();
                boolean[][] avail = new boolean[row+2][col+2];
                q.offer(new Info(0, 0));
                avail[0][0] = true;

                while(!q.isEmpty()){
                    Info ii = q.poll();
                    int cy = ii.y;
                    int cx = ii.x;
                    for(int k=0;k<4;k++){
                        int nx = cx +dx[k];
                        int ny = cy +dy[k];
                        if(nx>=0 && ny>=0 && nx<col+2 && ny<row+2 && !avail[ny][nx]){
                            avail[ny][nx] = true;
                            if(arr[ny][nx] == c) {
                                answer--;
                                arr[ny][nx] = ' ';
                            } else if(arr[ny][nx]== ' '){
                                q.offer(new Info(ny, nx));
                            }
                        }
                    }
                }

            } else {    //크레인
                for(int i=1;i<=row;i++){
                    for(int j=1;j<=col;j++){
                        if(c==arr[i][j]) {
                            arr[i][j] = ' ';
                            answer--;
                        }
                    }
                }
            }
        }
        return answer;
    }
}