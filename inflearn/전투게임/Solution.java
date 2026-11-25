import java.util.*;
import java.io.*;
import java.lang.*;

class Info implements Comparable<Info> {
    int idx;            //학생 번호
    String team;        //팀
    int attack;

    public Info(int idx, String team, int attack) {
        this.idx = idx;
        this.team = team;
        this.attack = attack;
    }

    @Override
    public int compareTo(Info o) {
        return Integer.compare(this.attack, o.attack);
    }
}

class Solution {
    public int[] solution(String[] students){
        int n = students.length;
        int[] answer = new int[n];
        HashMap<String, Integer> map = new HashMap<>();     //각 팀, 각 팀의 총 공격력
        PriorityQueue<Info> pq = new PriorityQueue<>();

        //시간복잡도: O(N)
        for(int i=0;i<students.length;i++) {
            String[] ss = students[i].split(" ");
            String team = ss[0];
            int attack = Integer.parseInt(ss[1]);
            pq.offer(new Info(i, team, attack));        //정렬 시간복잡도: O(NlgN)
        }

        int attackSum = 0;
        int previousAttack = 0;

        Queue<Info> q = new LinkedList<>();     //동일 점수에 대해 잡아 저장해놓는 용도
        while(!pq.isEmpty()) {
            Info ii = pq.poll();
            String team = ii.team;
            int attack = ii.attack;

            //갱신 필요
            if(attack > previousAttack) {
                //queue 비우기
                while(!q.isEmpty()) {
                    Info sameAttack = q.poll();
                    int teamAttackSum = map.getOrDefault(sameAttack.team, 0);
                    map.put(sameAttack.team, teamAttackSum + sameAttack.attack);
                    attackSum += sameAttack.attack;
                }

                //이전 공격력 갱신
                previousAttack = attack;
            }
            //계산
            answer[ii.idx] = attackSum-map.getOrDefault(team, 0);
            //queue 추가
            q.offer(ii);
        }

        return answer;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution T = new Solution();
        System.out.println(Arrays.toString(T.solution(new String[]{"a 20", "b 12", "a 10", "c 11", "e 12"})));
        System.out.println(Arrays.toString(T.solution(new String[]{"a 17", "b 12", "a 10", "c 11", "b 24", "a 25", "b 12"})));
        System.out.println(Arrays.toString(T.solution(new String[]{"b 20", "c 15", "a 200", "b 11", "b 24", "a 25", "b 12"})));
        System.out.println(Arrays.toString(T.solution(new String[]{"a 30", "a 25", "a 25", "b 20", "b 25", "a 25", "b 30"})));
    }
}