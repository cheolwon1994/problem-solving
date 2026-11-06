import java.util.*;
import java.io.*;

class Info implements Comparable<Info>{
    int code, date, maximum, remain;
    int target;     //정렬 값
    Info(int code, int date, int maximum, int remain, int target) {
        this.code = code;
        this.date = date;
        this.maximum = maximum;
        this.remain = remain;
        this.target = target;
    }

    @Override
    public int compareTo(Info o) {
        return Integer.compare(this.target, o.target);
    }
}

class Solution {
    public int[][] solution(int[][] data, String ext, int val_ext, String sort_by) {
        //init
        PriorityQueue<Info> pq = new PriorityQueue<>();
        HashMap<String, Integer> map = new HashMap<>();
        map.put("code", 0);
        map.put("date", 1);
        map.put("maximum", 2);
        map.put("remain", 3);

        int extIdx = map.get(ext);
        int sortIdx = map.get(sort_by);

        for(int i=0;i<data.length;i++){
            if(data[i][extIdx]<val_ext) {
                pq.offer(new Info(data[i][0], data[i][1], data[i][2], data[i][3], data[i][sortIdx]));
            }
        }
        int[][] answer = new int[pq.size()][4];
        int idx = 0;
        while(!pq.isEmpty()) {
            Info ii = pq.poll();
            answer[idx][0] = ii.code;
            answer[idx][1] = ii.date;
            answer[idx][2] = ii.maximum;
            answer[idx][3] = ii.remain;
            idx++;
        }
        return answer;
    }
}