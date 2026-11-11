import java.util.*;
import java.io.*;
import java.lang.*;

class Info implements Comparable<Info> {
    int idx, arrivalTime, executeTime;
    Info(int idx, int arrivalTime, int executeTime) {
        this.idx = idx;
        this.arrivalTime = arrivalTime;
        this.executeTime = executeTime;
    }

    @Override
    public int compareTo(Info i) {
        if(i.executeTime == this.executeTime) {
            return Integer.compare(this.idx, i.idx);
        }
        return Integer.compare(this.executeTime, i.executeTime);
    }
}

class ArrivalInfo implements Comparable<ArrivalInfo> {
    int idx, arrivalTime, executeTime;
    ArrivalInfo(int idx, int arrivalTime, int executeTime) {
        this.idx = idx;
        this.arrivalTime = arrivalTime;
        this.executeTime = executeTime;
    }

    @Override
    public int compareTo(ArrivalInfo i) {
        if(this.arrivalTime== i.arrivalTime) {
            return Integer.compare(this.idx, i.idx);
        }
        return Integer.compare(this.arrivalTime, i.arrivalTime);
    }
}

//1. 고객 정보 대기열에 넣기
//2. laser 끝난 고객의 시간-1까지 대기실에 있다고 가정
class Solution {
    public int[] solution(int[][] tasks){
        //init
        int[] answer = new int[tasks.length];
        PriorityQueue<ArrivalInfo> pq = new PriorityQueue<>();

        //sort tasks -> 도착시간 오름차순으로 정렬
        for(int i=0;i<tasks.length;i++) {
            pq.offer(new ArrivalInfo(i, tasks[i][0], tasks[i][1]));
        }

        //대기 큐
        PriorityQueue<Info> waitQ = new PriorityQueue<>();
        int cnt = 0;
        int finishTime = 0;

        while(!pq.isEmpty() || !waitQ.isEmpty()) {
            //대기큐에 넣을 작업 넣는다
            while(!pq.isEmpty()) {
                if(pq.peek().arrivalTime <= finishTime) {
                    ArrivalInfo ii = pq.poll();
                    waitQ.offer(new Info(ii.idx, ii.arrivalTime, ii.executeTime));
                } else break;
            }

            //finishTime 갱신
            if(waitQ.isEmpty()) {
                if(!pq.isEmpty()) {
                    finishTime = pq.peek().arrivalTime;
                } else break;
            } else {
                Info ii = waitQ.poll();
                finishTime += ii.executeTime;
                answer[cnt++] = ii.idx;
            }
        }

        return answer;
    }
}

public class Main {
    public static void main(String[] args){
        Solution T = new Solution();
        System.out.println(Arrays.toString(T.solution(new int[][]{{2, 3}, {1, 2}, {8, 2}, {3, 1}, {10, 2}})));
        System.out.println(Arrays.toString(T.solution(new int[][]{{5, 2}, {7, 3}, {1, 3}, {1, 5}, {2, 2}, {1, 1}})));
        System.out.println(Arrays.toString(T.solution(new int[][]{{1, 2}, {2, 3}, {1, 3}, {3, 3}, {8, 2}, {1, 5}, {2, 2}, {1, 1}})));
        System.out.println(Arrays.toString(T.solution(new int[][]{{999, 1000}, {996, 1000}, {998, 1000}, {999, 7}})));
        System.out.println(Arrays.toString(T.solution(new int[][]{{12, 2}, {3, 2}, {12, 2}})));
        System.out.println(Arrays.toString(T.solution(new int[][]{{10, 4}, {1, 6}, {10, 2}})));

    }
}
