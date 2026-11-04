import java.util.*;
import java.io.*;
import java.lang.*;

class Solution {
    public String longestPalindrome(String s) {
        String ans = "";
        for(int len = 1;len<=s.length();len++){
            for(int i=0;i<=s.length()-len;i++){
                boolean avail = true;
                int l = i, r = i+len-1;

                while(avail && l<=r) {
                    if(s.charAt(l) != s.charAt(r)) {
                        avail =false;
                        break;
                    }
                    l++;
                    r--;
                }
                if(avail) {
                    ans = s.substring(i, i+len);
                    break;
                }
            }
        }
        return ans;
    }
}