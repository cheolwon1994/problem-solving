import java.util.*;
import java.io.*;

class Solution {
    public int longestValidParentheses(String s) {
        int ans = 0;
        int len = s.length();
        Stack<Integer> stack = new Stack<>();       //idx 담기
        stack.push(-1);     //초기 세팅

        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            if(c==')') {
                stack.pop();
                if(stack.isEmpty()) {
                    stack.push(i);      //) 추가해놓기
                } else {
                    ans = Math.max(ans, i-stack.peek());
                }
            } else {
                stack.add(i);
            }
        }

        return ans;
    }
}