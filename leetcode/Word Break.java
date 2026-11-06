import java.io.*;
import java.lang.*;
import java.util.*;

class Solution {
    boolean avail;
    List<String> li[];      //각 index부터 일치하는 wordDict[] 글자
    boolean[][] visit;      //idx, word / 해당 index에 매칭되는 word를 방문한 적 있는지 확인

    public void dfs(int idx, String s) {
        if(avail) return;
        if(idx == s.length()) {
            avail = true;
            return;
        }
        for(int i=0;i<li[idx].size();i++){
            int len = li[idx].get(i).length();
            if(idx+len > s.length()) continue;
            if(visit[idx][i]) continue;
            visit[idx][i] = true;
            dfs(idx+len, s);
        }
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        //init
        avail = false;
        int len = s.length();
        li = new List[len];
        for(int i=0;i<len;i++){
            li[i] = new ArrayList<>();
        }
        visit = new boolean[len][wordDict.size()];

        for(int i=0;i<wordDict.size();i++){
            String w = wordDict.get(i);
            for(int idx=0;idx<=len-w.length();idx++){
                if(s.startsWith(w, idx)){
                    li[idx].add(w);
                }
            }
        }

        dfs(0, s);
        return avail;
    }
}