import java.util.*;
import java.io.*;
import java.lang.*;

// 풀이: index가 10 차이나는 투포인터
class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        //init
        int answer = 0;
        Map<String, Integer> m = new HashMap<>();

        //want로 map 채우기
        int fruitCnt = 0;
        for(int i=0;i<want.length;i++){
            String s = want[i];
            if(m.putIfAbsent(s, fruitCnt) == null) {
                fruitCnt++;
            }
        }
        int[] select = new int[want.length];
        //0~9 index로 원하는 값 채워넣기
        for(int i=0;i<10;i++){
            String s = discount[i];
            Integer idx = m.get(s);
            if(idx != null) {
                select[idx]++;
            }
        }
        int lidx = 0;
        int ridx = 9;

        while(ridx<discount.length) {
            //compare
            boolean avail = true;
            for(int i=0;i<select.length;i++){
                if(select[i]!=number[i]) {
                    avail =false;
                    break;
                }
            }
            if(avail) answer++;
            if(ridx+1 == discount.length) break;
            //left 빼기
            Integer subtractIdx = m.get(discount[lidx++]);
            if(subtractIdx != null) {
                select[subtractIdx]--;
            }
            //right 추가
            Integer addIdx = m.get(discount[++ridx]);
            if(addIdx != null) {
                select[addIdx]++;
            }
        }
        return answer;
    }
}