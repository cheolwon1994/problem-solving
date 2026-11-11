import java.util.*;
import java.io.*;
import java.lang.*;

class Info implements Comparable<Info> {
    int idx;        //사원번호
    int arrivalTime;      //도착 시간

    Info(int idx, int arrivalTime) {
        this.idx = idx;
        this.arrivalTime = arrivalTime;
    }

    @Override
    public int compareTo(Info o) {
        return Integer.compare(this.idx, o.idx);
    }
}

class Solution {
    public int[] solution(int[] arrival, int[] state){
        //init
        int[] answer = new int[arrival.length];
        PriorityQueue<Info>[] li = new PriorityQueue[2];
        li[0] = new PriorityQueue<>();    //state: 0, in
        li[1] = new PriorityQueue<>();    //state: 1, out
        int prevState = 1;      //현관문 사용한 적 없는 0초 이전을 out으로 설정
        final int maxArrivalTime = 300001;      //200,000에 100,000 명이 전부 올 수 있으므로

        //in, out 구분해서 pq 넣기
        for(int i=0;i<arrival.length;i++){
            li[state[i]].offer(new Info(i, arrival[i]));
        }

        int currTime = 0;
        while(currTime <= maxArrivalTime) {
            if(li[0].isEmpty() && li[1].isEmpty()) {
                break;
            }

            //같은 방향부터 확인
            int nextCurrTime = maxArrivalTime;
            int nextArrivalTime;

            if(!li[prevState].isEmpty()) {
                nextArrivalTime = li[prevState].peek().arrivalTime;

                if (nextArrivalTime <= currTime) {
                    Info ii = li[prevState].poll();
                    answer[ii.idx] = currTime++;
                    continue;
                } else {
                    nextCurrTime = Math.min(nextCurrTime, nextArrivalTime);
                }
            }

            //같은 방향이 없다면, 반대방향 확인
            if(!li[1-prevState].isEmpty()) {
                nextArrivalTime = li[1 - prevState].peek().arrivalTime;
                if (nextArrivalTime <= currTime) {
                    prevState = 1 - prevState;
                    Info ii = li[prevState].poll();
                    answer[ii.idx] = currTime++;
                    continue;
                } else {
                    nextCurrTime = Math.min(nextCurrTime, nextArrivalTime);
                }

            }
            //현재 나갈 사원이 없을 때
            currTime = nextCurrTime;
            prevState = 1;
        }

        return answer;
    }
}