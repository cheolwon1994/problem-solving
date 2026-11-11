import java.util.*;
import java.io.*;
import java.lang.*;

class Info {
    int arrivalTime;
    int laserNum;

    Info(int arrivalTime, int laserNum) {
        this.arrivalTime = arrivalTime;
        this.laserNum = laserNum;
    }
}

//1. 고객 정보 대기열에 넣기
//2. laser 끝난 고객의 시간-1까지 대기실에 있다고 가정
class Solution {
    public int solution(int[] laser, String[] enter) {
        //init
        int answer = 0;
        Queue<Info> q = new LinkedList<>();         //고객 큐
        Queue<Info> waitQ = new LinkedList<>();     //대기실 대기 큐
        for (String ss : enter) {
            String[] sep = ss.split(" ");
            String[] hm = sep[0].split(":");
            q.offer(new Info(Integer.parseInt(hm[0]) * 60 + Integer.parseInt(hm[1]), Integer.parseInt(sep[1])));
        }

        //첫 시술 고객 끝나는 idx
        Info ii = q.poll();
        int finishTime = ii.arrivalTime+laser[ii.laserNum];

        while(!q.isEmpty() || !waitQ.isEmpty()){
            //첫 고객이 끝날동안 대기큐에 쌓일 고객 추가
            while(!q.isEmpty()) {
                Info w = q.peek();
                if(w.arrivalTime < finishTime) {
                    w = q.poll();
                    waitQ.offer(w);
                } else break;
            }
            //최대 대기인원 갱신
            answer = Math.max(answer, waitQ.size());

            //시술중인 고객이 끝나도 다음 고객이 오지 않는 경우
            if(waitQ.isEmpty()) {
                if(q.isEmpty()) {
                    break;
                }
                finishTime = q.peek().arrivalTime+laser[q.peek().laserNum];
                q.poll();
            } else {        //대기중인 손님
                finishTime += laser[waitQ.peek().laserNum];
                waitQ.poll();
            }
        }

        return answer;
    }
}

public class Main {

    public static void main(String[] args) {
        Solution T = new Solution();
        System.out.println(T.solution(new int[]{30, 20, 25, 15}, new String[]{"10:23 0", "10:40 3", "10:42 2", "10:52 3", "11:10 2"}));
        System.out.println(T.solution(new int[]{30, 20, 25, 15}, new String[]{"10:23 0", "10:40 3", "10:42 2", "10:52 3", "15:10 0", "15:20 3", "15:22 1", "15:23 0", "15:25 0"}));
        System.out.println(T.solution(new int[]{30, 20, 25, 15}, new String[]{"10:20 1", "10:40 1", "11:00 1", "11:20 1", "11:40 1"}));
        System.out.println(T.solution(new int[]{30, 20, 25, 15}, new String[]{"10:00 0", "10:10 0", "10:20 0", "10:45 3", "10:50 3"}));

    }
}
