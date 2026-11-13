import java.util.*;
import java.io.*;
import java.lang.*;

class Solution {
    List<String> ans;
    HashMap<Character, String> m;

    public void initMap() {
        m = new HashMap<>();
        m.put('2', "abc");
        m.put('3',"def");
        m.put('4',"ghi");
        m.put('5',"jkl");
        m.put('6',"mno");
        m.put('7',"pqrs");
        m.put('8',"tuv");
        m.put('9',"wxyz");
    }

    public void dfs(int idx, String s, String digits) {
        if(idx == digits.length()){
            ans.add(s);
            return;
        }
        char c = digits.charAt(idx);
        String ss = m.get(c);
        for(int i=0;i<ss.length();i++){
            char cc = ss.charAt(i);
            dfs(idx+1, s+cc, digits);
        }
    }

    public List<String> letterCombinations(String digits) {
        //init
        ans = new ArrayList<>();
        initMap();

        dfs(0,"",digits);
        return ans;
    }
}