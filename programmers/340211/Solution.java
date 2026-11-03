import java.util.*;
import java.io.*;
import java.lang.*;

class Solution {
    public int solution(int[][] points, int[][] routes) {
        int answer = 0;
        int robots = routes.length;
        //목표 포인트에 도달한 로봇 여부
        boolean[] arrived = new boolean[robots];
        //각 로봇의 위치. y,x
        int[][] rLoc = new int[robots][2];
        //각 로봇이 가야하는 곳
        int[] target = new int[robots];

        //중복 좌표 위치 구하기
        final int MAXI = 101;
        HashMap<Integer, Integer> map;

        for(int i=0;i<robots;i++){
            //시작 로봇 위치
            int startR = routes[i][0]-1;
            rLoc[i][0] = points[startR][0];
            rLoc[i][1] = points[startR][1];
            //다음 목표 포인트 index 설정
            target[i] = 1;
        }

        while(true) {
            map = new HashMap<>();
            //위험 상황 확인
            for(int i=0;i<robots;i++){
                //이미 도착했다면 무시
                if(arrived[i]) continue;
                int cy = rLoc[i][0];
                int cx = rLoc[i][1];
                int num = cy*MAXI + cx;
                map.put(num, map.getOrDefault(num, 0)+1);
            }

            for(Map.Entry<Integer, Integer> m: map.entrySet()){
                if(m.getValue()>1) {
                    answer++;
                }
            }

            for(int i=0;i<robots;i++){
                //이미 도착했다면 무시
                if(arrived[i]) continue;
                int cy = rLoc[i][0];
                int cx = rLoc[i][1];
                //타겟 포인트 번호
                int targetPoint = routes[i][target[i]];
                //목표 포인트 번호의 위치
                int ty = points[targetPoint-1][0];
                int tx = points[targetPoint-1][1];

                //목표 지점에 도달한 경우
                if(ty == cy && tx == cx) {
                    //최종 목표인 경우
                    if(target[i] == routes[i].length-1) {
                        rLoc[i][0] = -1;
                        rLoc[i][1] = -1;
                        arrived[i] = true;
                    } else {
                        target[i]++;
                    }
                }
            }

            //최종 위치에 모두 도달했는지 확인
            boolean allArrived = true;
            for(int i=0;i<robots;i++){
                if(!arrived[i]) {
                    allArrived = false;
                    break;
                }
            }
            if(allArrived) break;

            //최종 위치에 도달하지 않은 로봇 이동
            for(int i=0;i<robots;i++){
                //이미 도착했다면 무시
                if(arrived[i]) continue;
                int cy = rLoc[i][0];
                int cx = rLoc[i][1];

                //타겟 포인트 번호
                int targetPoint = routes[i][target[i]];
                //목표 포인트 번호의 위치
                int ty = points[targetPoint-1][0];
                int tx = points[targetPoint-1][1];

                //y축부터 이동
                if(ty!=cy) {
                    if(ty>cy) {
                        rLoc[i][0]++;
                    } else {
                        rLoc[i][0]--;
                    }
                } else {    //x축 이동
                    if(tx>cx) {
                        rLoc[i][1]++;
                    } else {
                        rLoc[i][1]--;
                    }
                }
            }

        }

        return answer;
    }
}