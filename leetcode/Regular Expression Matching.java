import java.util.*;
import java.io.*;
import java.lang.*;

class Solution {
    boolean answer;
    boolean[][] visit;      //sidx, pidx
    List<Character> combined;      //* 앞의 문자
    List<Character> pToList;

    //pidx의 글자가 'C'면 combined의 lidx번째를 이용한다
    public void dfs(int sidx, int pidx, int lidx, String s) {
        if(sidx >= s.length()){
            while(pidx<pToList.size()) {
                if(pToList.get(pidx) == 'C') {
                    pidx++;
                } else break;
            }
            if(pidx == pToList.size()) {
                answer = true;
                return;
            }
            return;
        }
        //s 검사가 먼저 안끝났는데, p가 끝난 경우
        if(pidx >= pToList.size()) {
            return;
        }
        char sc = s.charAt(sidx);
        char pc = pToList.get(pidx);

        //pc는 소문자, ., C만 올 수 있음
        if(sc == pc) {      //소문자 알파벳인 경우
            if(!visit[sidx+1][pidx+1]){
                visit[sidx+1][pidx+1] = true;
                dfs(sidx+1, pidx+1, lidx, s);
            }
        } else {
            if (pc == '.' && !visit[sidx + 1][pidx + 1]) {
                visit[sidx + 1][pidx + 1] = true;
                dfs(sidx + 1, pidx + 1, lidx, s);
            } else if (pc == 'C') {
                //0개
                if (!visit[sidx][pidx + 1]) {
                    visit[sidx][pidx + 1] = true;
                    dfs(sidx, pidx + 1, lidx+1, s);
                }
                //1개 이상
                for (int i = 0; i < s.length() - sidx; i++) {
                    char nextSc = s.charAt(sidx + i);
                    char prev = combined.get(lidx);
                    if (prev == '.') prev = nextSc;
                    if (nextSc == prev && !visit[sidx + i + 1][pidx + 1]) {
                        visit[sidx + i + 1][pidx + 1] = true;
                        dfs(sidx + 1 + i, pidx + 1, lidx+1, s);
                    } else break;
                }
            }
        }
    }

    public boolean isMatch(String s, String p) {
        answer = false;
        combined = new ArrayList<>();
        pToList = new ArrayList<>();

        //*가 올 수 없음
        if(p.length() == 1) {
            pToList.add(p.charAt(0));
        } else {
            for (int i = 1; i < p.length(); i++) {
                char c = p.charAt(i);
                if (c == '*') {
                    combined.add(p.charAt(i - 1));
                    if (!pToList.isEmpty()) {
                        pToList.removeLast();
                    }
                    pToList.add('C');       //결합된 문자 의미
                } else {
                    if (i == 1) {
                        pToList.add(p.charAt(0));
                    }
                    pToList.add(p.charAt(i));
                }
            }
        }
        visit = new boolean[s.length()+1][pToList.size()+1];

        dfs(0,0,0,s);
        return answer;
    }
}
